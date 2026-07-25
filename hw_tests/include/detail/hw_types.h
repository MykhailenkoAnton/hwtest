#pragma once

#include <functional>

namespace hwtest
{
namespace colored
{
	enum class color_code : uint8_t
	{
		black = 0,
		blue = 1,
		green = 2,
		cyan = 3,
		red = 4,
		magenta = 5,
		yellow = 6,
		light_gray = 7,

		dark_gray = 8,
		light_blue = 9,
		light_green = 10,
		light_cyan = 11,
		light_red = 12,
		light_magenta = 13,
		light_yellow = 14,
		white = 15
	};
} // colored


	using Func = std::function<void()>;

	enum class check_type
	{
		none = 0,

		expect_eq,
		expect_neq,
		expect_true,
		expect_false,
		expect_throw,
		expect_no_throw,
		assert_true,
		assert_false
	};

	enum class check_type_result : uint8_t
	{
		none = 0,

		passed,
		failed
	};
}