#pragma once
#include "hw_sequance.h"
#include "detail/hw_utils.h"

namespace hwtest
{
namespace colored
{
	template<typename T>
	using storage_t = std::conditional_t< std::is_same_v<T, const char*>, std::string, T>;

	template <typename T>
	static ou_sequance<storage_t<T>> make_colored_sequence(T line, color_code color)
	{
		ou_sequance<storage_t<T>> seq;
		seq.emplace_back(line, color);
		return seq;
	}

	template <typename T>
	static ou_sequance<storage_t<T>> blue(T line)
	{
		return make_colored_sequence(line, color_code::blue);
	}

	template <typename T>
	static ou_sequance<storage_t<T>> white(T line)
	{
		return make_colored_sequence(line, color_code::white);
	}

	template <typename T>
	static ou_sequance<storage_t<T>>red(T line)
	{
		return make_colored_sequence(line, color_code::red);
	}

	template <typename T>
	static ou_sequance<storage_t<T>> green(T line)
	{
		return make_colored_sequence(line, color_code::green);
	}

	template <typename T>
	static ou_sequance<storage_t<T>> cyan(T line)
	{
		return make_colored_sequence(line, color_code::cyan);
	}

	template <typename T>
	static ou_sequance<storage_t<T>> magenta(T line)
	{
		return make_colored_sequence(line, color_code::magenta);
	}
} // colored
} // hwtest
