#include <format>
#include <string>
#include <stdexcept>
#include <source_location>
#include <vector>
#include <memory>

#include "hw_types.h"
#include "hw_test_case.h"

#include "hw_utils.h"


namespace hwtest
{
	// exeption
	class assertion_failed : public std::runtime_error
	{
	public:
		explicit assertion_failed() : std::runtime_error("") {}
	};


	class test_creator
	{
	public:

		inline static test_creator& get_instance()
		{
			static test_creator instance;
			return instance;
		}

		//
		template<typename T1, typename T2>
		void expect_equal(const T1& lhs, const T2& rhs, const std::source_location& location = std::source_location::current())
		{
			if (lhs == rhs)
			{
				process_passed(to_string(rhs), to_string(lhs), location, check_type_result::passed, check_type::expect_eq);
			}
			else
			{
				process_failed(to_string(rhs), to_string(lhs), location, check_type_result::failed, check_type::expect_eq);
			}
		}

		template<typename T1, typename T2>
		void expect_not_equal(const T1& lhs, const T2& rhs, const std::source_location& location = std::source_location::current())
		{
			if (lhs != rhs)
			{
				process_passed(to_string(rhs), to_string(lhs), location, check_type_result::passed, check_type::expect_neq);
			}
			else
			{
				process_failed(to_string(rhs), to_string(lhs), location, check_type_result::failed, check_type::expect_neq);
			}
		}

		template <typename Throw>
		void expect_throw(Func func, const std::source_location& location = std::source_location::current())
		{
			try
			{
				func();
				process_failed(type_name<Throw>(), "no exception thrown", location, check_type_result::failed, check_type::expect_throw);
			}
			catch (const Throw& expected_type_throw)
			{
				process_passed(type_name<Throw>(), type_name(expected_type_throw), location, check_type_result::passed, check_type::expect_throw);
			}
			catch (const std::exception& excep)
			{
				process_failed(type_name<Throw>(), type_name(excep), location, check_type_result::failed, check_type::expect_throw);
			}
		}

		void expect_no_throw(Func func, const std::source_location& location = std::source_location::current())
		{
			try
			{
				func();
			}
			catch (const std::exception& excep)
			{
				process_failed("no exception throw", type_name(excep), location, check_type_result::failed, check_type::expect_no_throw);
				return;
			}

			process_passed("no exception throw", "no exception throw", location, check_type_result::passed, check_type::expect_no_throw);
		}

		inline void assert_true(bool cond, const std::source_location& location = std::source_location::current())
		{
			condition_test_impl(true, cond, check_type::assert_true, location);
		}

		inline void assert_false(bool cond, const std::source_location& location = std::source_location::current())
		{
			condition_test_impl(false, cond, check_type::assert_false, location);
		}

		inline void expect_true(bool cond, const std::source_location& location = std::source_location::current())
		{
			condition_test_impl(true, cond, check_type::expect_true, location);
		}

		inline void expect_false(bool cond, const std::source_location& location = std::source_location::current())
		{
			condition_test_impl(false, cond, check_type::expect_false, location);
		}

		void register_test_case(std::string test_desc, std::string test_name, Func func);
		void run_all_tests();

	private:
		void condition_test_impl(bool expect_cond, bool cond, check_type type, const std::source_location& location = std::source_location::current());
		void process_passed(const std::string& expected_value, const std::string& actual_value, const std::source_location& location, check_type_result result, check_type type);
		void process_failed(const std::string& expected_value, const std::string& actual_value, const std::source_location& location, check_type_result result, check_type type);
		void try_throw_assertion_failed(check_type type);

	private:
		std::vector<std::unique_ptr<test_case>> test_cases;
		test_case* curent;
	};


	// register
	struct register_test
	{
		register_test(std::string desc, std::string name, Func func)
		{
			hwtest::test_creator::get_instance().register_test_case(desc, name, func);
		}
	};

}
