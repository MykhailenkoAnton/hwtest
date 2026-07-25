#pragma once

#include "detail/hw_test_manager.h"

#define TEST_CASE(Description, Name) \
static void Description##Name(); \
static hwtest::register_test Description##Name##test(#Description, #Name, Description##Name); \
static void Description##Name() \

#define EXPECT_EQ(a, b) hwtest::test_creator::get_instance().expect_equal(a, b);
#define EXPECT_NEQ(a, b) hwtest::test_creator::get_instance().expect_not_equal(a, b);

#define EXPECT_THROW(func, exeption_type) hwtest::test_creator::get_instance().expect_throw<exeption_type>(func);
#define EXPECT_NO_THROW(func) 	hwtest::test_creator::get_instance().expect_no_throw(func);

#define ASSERT_TRUE(cond) hwtest::test_creator::get_instance().assert_true(cond);
#define ASSERT_FALSE(cond) hwtest::test_creator::get_instance().assert_false(cond);

#define EXPECT_TRUE(cond) hwtest::test_creator::get_instance().expect_true(cond);
#define EXPECT_FALSE(cond) hwtest::test_creator::get_instance().expect_false(cond);

#define RUN_ALL_TESTS() hwtest::test_creator::get_instance().run_all_tests();