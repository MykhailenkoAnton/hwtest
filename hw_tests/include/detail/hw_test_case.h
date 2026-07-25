#pragma once

#include <source_location>
#include <vector>
#include <string>

#include "hw_types.h"

namespace hwtest
{
	struct check_status
	{
		std::string expected;
		std::string actual;

		std::source_location location;

		check_type_result result;
		check_type type;

		explicit check_status(const std::string& expected_temp, const std::string& actual_temp, const std::source_location& location_temp, check_type_result result_temp, check_type type_temp)
			: expected(expected_temp), actual(actual_temp), location(location_temp), result(result_temp), type(type_temp) {}
	};


	class test_case
	{
	public:
		test_case(std::string& desc, std::string& name, const Func& func) : _desc(desc), _name(name), _func(func) {}

		inline bool is_failed() const { return _failed > 0; }
	
		inline const std::string& get_name() const { return _name; }
		inline const std::string& get_description() const { return _desc; }

		inline const std::vector<check_status>& get_checks() const { return _checks; }
		inline std::vector<check_status>& get_checks() { return _checks; }

		inline void increment_passed() { ++_passed; }
		inline void increment_failed() { ++_failed; }

		void run() const { _func(); }
		void print_result() const;

	private:
		std::string _name;
		std::string _desc;
		Func _func;

		int _passed = 0;
		int _failed = 0;

		std::vector<check_status> _checks;
	};
}
