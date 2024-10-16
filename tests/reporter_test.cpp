#include<iostream>
#include "../Reporter/include/ReporterLib/ReporterLib.h"
#include<gtest/gtest.h>

TEST(ReporterTest, TestIntegerOne_One)
{
	int expected = 1;
	int actual = Divide(1, 1);
	ASSERT_EQ(expected, actual);
}