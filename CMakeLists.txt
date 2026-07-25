

cmake_minimum_required(VERSION 3.30)
set(PROJECT_NAME hwtest)
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE
    hw_tests/src/pch.h
    hw_tests/src/pch.cpp

    hw_tests/src/core/hw_test_manager.cpp
    hw_tests/include/detail/hw_test_manager.h

    hw_tests/include/detail/hw_test_case.h
    hw_tests/src/core/hw_test_case.cpp

    hw_tests/include/hw_tests.h

    hw_tests/include/detail/colored/hw_item.h
    hw_tests/include/detail/colored/hw_sequance.h
    hw_tests/include/detail/colored/hw_colored_output.h

    hw_tests/include/detail/colored/color_manager.h
    hw_tests/include/detail/colored/windows/windows_color_manager.h
    hw_tests/src/core/colored/windows/windows_color_manager.cpp

    hw_tests/include/detail/hw_utils.h
    hw_tests/include/detail/hw_types.h
)


add_library(${PROJECT_NAME} STATIC ${SOURCE})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake Targets")

set(CMAKE_SUPPRESS_REGENERATION true)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hw_tests/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/hw_tests/src)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

include(${CMAKE_CURRENT_SOURCE_DIR}/auto/cmake/cmakehelper.cmake)
setup_precompiled_headers(${PROJECT_NAME} hw_tests/src/pch.cpp hw_tests/src/pch.h ${SOURCE})