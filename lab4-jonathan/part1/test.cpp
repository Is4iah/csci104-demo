#include "fib.h"
#include "gtest/gtest.h"

TEST(FibTest, Nominal) {
	Fibonacci f;
	EXPECT_EQ(5, f.get(5));
	EXPECT_EQ(13, f.get(7));
}

TEST(FibTest, Boundary) {
    Fibonacci f;
    EXPECT_EQ(1, f.get(1));
    EXPECT_EQ(1, f.get(1));
}


TEST(FibTest, Bad_Input) {
    Fibonacci f;
    EXPECT_EQ(1, f.get(-1));
    EXPECT_EQ(1, f.get(-2));
}
