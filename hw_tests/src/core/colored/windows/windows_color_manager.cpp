#include "detail/colored/windows/windows_color_manager.h"

#include <memory>


#ifdef _WIN32
#include <windows.h>
#endif


namespace hwtest
{
namespace colored
{
	std::unique_ptr<color_output_manager> color_output_manager::create_color_oputput_manager()
	{
		return std::make_unique<windows_color_output_manager>();
	}

	void windows_color_output_manager::set_color(color_code color)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD windows_color = static_cast<WORD>(color);
		SetConsoleTextAttribute(hConsole, windows_color);
	}

	void windows_color_output_manager::reset_color()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD windows_default_color = static_cast<WORD>(get_default_color());
		SetConsoleTextAttribute(hConsole, windows_default_color);
	}

	color_code windows_color_output_manager::get_default_color()
	{
		return color_code::light_gray;
	}

} //colored
} //hwtest