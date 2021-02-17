#include "arraylist.h"
#include "gtest/gtest.h"

class ArrayListTest : public testing::Test {
protected:
	// You can remove any or all of the following functions if its body is empty.

	ArrayListTest() {
		// You can do set-up work for each test here.
	}

	virtual ~ArrayListTest() {
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
		list.add(1);
		list.add(2);
		list.add(3);
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
	ArrayList list;
};

TEST_F(ArrayListTest, GetNominal) {
	// Exepct 0th element to be 1, 1st elemnt to be 2, etc.
	for (int i = 0 ; i < 3; i++) {
		EXPECT_EQ(i + 1, list.get(i));
	}
}

TEST_F(ArrayListTest, AddNominal) {
	// Checks for increase in size
	for (int i = 3; i < 7; i++)  {
		list.add(i);
		EXPECT_EQ(i + 1, list.size());
	}

	// Checks for correct storage in index
	for (int i = 0; i < 7; i++) {
		EXPECT_EQ(i + 1 , list.get(i));
	}
}

TEST_F(ArrayListTest, RemoveNominal) {
	// Check if the element has been deleted
	list.remove(1);
	EXPECT_EQ(2, list.get(1));

	// Check if the size has been decremented
	EXPECT_EQ(2, list.size());
}

TEST_F(ArrayListTest, SetOffNominal) {
	// Check if it replaces the value in correct index
	list.set(2,10);
	EXPECT_EQ(10, list.get(2));

	for (int i = 0; i < list.size(); i++) {
		list.set(i,i);
	}
	
	// Check that it does not do anything when the value is invalid
	list.set(-2,10);
	
	for (int i = 0; i < list.size(); i++) {
		EXPECT_EQ(i, list.get(i));
	}
}
