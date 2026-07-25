#pragma once
#include <ostream>

#include "detail/hw_types.h"

#include "detail/colored/color_manager.h"


namespace hwtest
{
namespace colored
{
	template<typename T>
	class ou_item
	{
	public:
		ou_item(T line) : _line(line), _color() {}
		ou_item(T  line, color_code color) : _line(line), _color(color) {}

		template<typename U>
		friend std::ostream& operator<<(std::ostream& os, const ou_item<U>& item);

		inline color_code get_color() const { return _color; }
	private:
		T _line;
		color_code _color;
	};

	template<typename U>
	std::ostream& operator<<(std::ostream& os, const ou_item<U>& item)
	{
		hwtest::colored::color_output_manager::get_color_manager().set_color(item.get_color());
		os << item._line;
		hwtest::colored::color_output_manager::get_color_manager().reset_color();

		return os;
	}
} //colored
} //hwtest
