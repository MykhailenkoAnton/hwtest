#pragma once

#include <format>
#include "hw_types.h"

namespace hwtest
{
	template <typename T>
	static std::string to_string(const T& value)
	{
		return std::format("{}", value);
	}

	template <typename Throw>
	static std::string type_name(const Throw& value)
	{
		return typeid(value).name();
	}

	template <typename Throw>
	static std::string type_name()
	{
		return typeid(Throw).name();
	}

	constexpr static std::string_view result_to_string(check_type_result result)
	{
		switch (result)
		{
		case hwtest::check_type_result::none:
			return { "None" };
		case hwtest::check_type_result::passed:
			return { "PASSED" };
		case hwtest::check_type_result::failed:
			return { "FAILED" };

		default:
			break;
		}

		return { "NOT FOUND" };
	}

	constexpr static std::string_view type_to_string(check_type type)
	{
		switch (type)
		{
		case hwtest::check_type::none:
			return { "INVALID" };
		case hwtest::check_type::expect_eq:
			return { "EXPECT_EQ" };
		case hwtest::check_type::expect_neq:
			return { "EXPECT_NEQ" };
		case hwtest::check_type::expect_true:
			return { "EXPECT_TRUE" };
		case hwtest::check_type::expect_false:
			return { "EXPECT_FALSE" };
		case hwtest::check_type::expect_throw:
			return { "EXPECT_THROW" };
		case hwtest::check_type::expect_no_throw:
			return { "EXPECT_THROW" };
		case hwtest::check_type::assert_true:
			return { "ASSERT_TRUE" };
		case hwtest::check_type::assert_false:
			return { "ASSERT_FALSE" };

		default:
			break;
		}

		return { "NOT FOUND" };
	}
}