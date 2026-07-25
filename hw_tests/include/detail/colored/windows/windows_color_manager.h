#pragma once

#include "detail/colored/color_manager.h"

#include "detail/hw_types.h"

namespace hwtest
{
namespace colored
{

	class windows_color_output_manager : public color_output_manager
	{
		virtual void set_color(color_code color) override;
		virtual void reset_color() override;

		virtual color_code get_default_color() override;
	};

} //colored
} //hwtest