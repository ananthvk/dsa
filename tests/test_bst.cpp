#include "gtest/gtest.h"

TEST(BST, TestEmpty)
{
    ASSERT_EQ(3, 3);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}