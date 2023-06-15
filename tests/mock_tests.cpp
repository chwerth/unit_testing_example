#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "shapes.hpp"

// Mock class for testing the Shape class
class MockShape : public Shape {
public:
    // Signature: MOCK_METHOD(return_type, method_name, (parameter_types), (qualifiers));
    MOCK_METHOD(double, calculateArea, (), ());
};

// Test calculateArea() using a mock object
TEST(MockShapeTest, CalculateArea) {
    MockShape mockShape;

    // Set up the expectation for the calculateArea() method
    EXPECT_CALL(mockShape, calculateArea())
        .WillOnce(testing::Return(10.0));

    double area = mockShape.calculateArea();
    EXPECT_EQ(area, 10.0);
}

// Test printArea() using a mock object
TEST(MockPrintAreaTest, PrintArea) {
    MockShape mockShape;

    // Set up the expectation for the calculateArea() method
    EXPECT_CALL(mockShape, calculateArea())
        .WillOnce(testing::Return(20.0));

    testing::internal::CaptureStdout();
    printArea(mockShape);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Area: 20\n");
}

// Test calculateArea() using a strict mock object
TEST(MockStrictShapeTest, CalculateArea) {
    testing::StrictMock<MockShape> strictMockShape;

    // Set up the expectation for the calculateArea() method
    EXPECT_CALL(strictMockShape, calculateArea())
        .WillOnce(testing::Return(30.0));

    double area = strictMockShape.calculateArea();
    EXPECT_EQ(area, 30.0);
}

// Test calculateArea() using a nice mock object
TEST(MockNiceShapeTest, CalculateArea) {
    testing::NiceMock<MockShape> niceMockShape;

    // No expectations set

    double area = niceMockShape.calculateArea();
    EXPECT_EQ(area, 0.0); // The default return value is used (0.0 for double)
}


/**
In Google Mock, the default behavior for mocks is to be "nice" mocks. Nice mocks have a relaxed behavior and
do not enforce strict expectations by default. 
They allow unexpected calls to mock methods and return default values for uninteresting methods.
Nice mocks are more permissive and are useful when you want to focus on specific expectations and allow flexibility in the test code.

On the other hand, strict mocks have a stricter behavior. 
They enforce strict expectations, meaning that any unexpected calls to mock methods or uninteresting methods will cause the test to fail. 
Strict mocks help ensure that all interactions with the mock are explicitly defined and verified, leaving no room for accidental or unintended calls.

By default, when you define a mock class using MOCK_METHOD, the resulting mock object is a nice mock.
If you want to use strict mocks, you need to explicitly specify it when creating the mock object by using the ::testing::StrictMock class template.
*/