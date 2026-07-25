#include "pch.h"

#include "detail/hw_test_manager.h"

namespace hwtest
{
	void test_creator::register_test_case(std::string test_desc, std::string test_name, Func func)
	{
		test_cases.emplace_back(std::make_unique<test_case>(test_desc, test_name, func));
	}

	void test_creator::run_all_tests()
	{
		for (auto& test : test_cases)
		{
			try
			{
				{
					// current test will use for checks
					curent = test.get();
					test->run();
				}

				test->print_result();
			}
			catch (const assertion_failed&)
			{
				test->print_result();
			}
		}
	}

	void test_creator::condition_test_impl(bool expect_cond, bool cond, check_type type, const std::source_location& location)
	{
		if (cond)
		{
			process_passed(to_string(expect_cond), to_string(cond), location, check_type_result::passed, type);
		}
		else
		{
			process_failed(to_string(expect_cond), to_string(cond), location, check_type_result::failed, type);
			try_throw_assertion_failed(type);
		}
	}

	void test_creator::process_passed(const std::string& expected_value, const std::string& actual_value, const std::source_location& location, check_type_result result, check_type type)
	{
		curent->increment_passed();
		curent->get_checks().emplace_back(expected_value, actual_value, location, result, type);
	}

	void test_creator::process_failed(const std::string& expected_value, const std::string& actual_value, const std::source_location& location, check_type_result result, check_type type)
	{
		curent->increment_failed();
		curent->get_checks().emplace_back(expected_value, actual_value, location, result, type);
	}

	void test_creator::try_throw_assertion_failed(check_type type)
	{
		const bool is_assert_check = type == check_type::assert_true || type == check_type::assert_false;
		if (is_assert_check)
		{
			throw assertion_failed();
		}
	}
}