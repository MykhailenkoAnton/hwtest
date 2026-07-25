#pragma once

#include <memory>

#include "detail/hw_types.h"

namespace hwtest
{
namespace colored 
{
    class color_output_manager
    {
    public:

        virtual void set_color(color_code color) = 0;
        virtual void reset_color() = 0;

        virtual color_code get_default_color() = 0;

        static std::unique_ptr<color_output_manager> create_color_oputput_manager();
        static color_output_manager& get_color_manager()
        {
            static std::unique_ptr<color_output_manager> instance = create_color_oputput_manager();
            return *instance;
        }
    };
} //colored
} //hwtest