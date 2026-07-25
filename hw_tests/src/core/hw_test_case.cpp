#include <iostream>

#include "detail/hw_test_case.h"


#include "detail/hw_types.h"
#include "detail/hw_utils.h"


#include "detail/colored/hw_colored_output.h"

namespace hwtest
{
	void test_case::print_result() const
	{
		if (!this->is_failed())
		{
			return;
		}

		std::cout << hwtest::colored::blue(this->get_name()) << std::endl;

		for (const auto& check : this->get_checks())
		{
			const bool is_check_failed = check.result == check_type_result::failed;

			std::string result(result_to_string(check.result));
			std::cout << hwtest::colored::white(std::string(type_to_string(check.type))) << " : " 
				<< (is_check_failed ? hwtest::colored::red(result) : hwtest::colored::green(result)) << std::endl;

			if (is_check_failed)
			{
				std::cout << "\tFile: " << hwtest::colored::magenta(std::string(check.location.file_name())) << std::endl;
				std::cout << "\tFunction: " << hwtest::colored::magenta(std::string(check.location.function_name())) << std::endl;
				std::cout << "\tLine: " << hwtest::colored::magenta(check.location.line()) << std::endl;
			}

			std::string expected_world = "\texpected: ";
			std::string actual_world = "\tactual: ";
			if (is_check_failed)
			{
				expected_world = "\t" + expected_world;
				actual_world = "\t" + actual_world;
			}
			std::cout << expected_world << hwtest::colored::green(check.expected) << std::endl;
			std::cout << actual_world << (is_check_failed ? hwtest::colored::red(check.actual) : hwtest::colored::green(check.actual)) << std::endl;
		}

		std::cout << std::endl;
	}
}