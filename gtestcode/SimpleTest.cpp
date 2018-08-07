/*
 * SimpleTest.cpp
 *
 *  Created on: 2017Äê9ÔÂ27ÈÕ
 *      Author: Administrator
 */

#include "Simple1.h"
#include  "gmock/gmock.h"
#include "gtest/gtest.h"


//
//int main(int argc, char **argv)
//{
//    testing::InitGoogleTest(&argc,argv);
//    testing::InitGoogleMock(&argc, argv);
//
//    int a=  RUN_ALL_TESTS();
//    a=1;
//    return 0;
//}



TEST(Add, less)
{
EXPECT_EQ(Add(-1,-2),-3);
EXPECT_EQ(Add(-1,-3),-3);

}

TEST(Add, more)
{
EXPECT_EQ(Add(1,2),2);
EXPECT_EQ(Add(2,2),5);

}
