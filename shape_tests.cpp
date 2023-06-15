#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "shapes.hpp"

// Mock class for the Shape interface
class MockShape : public Shape {
public:
    MOCK_METHOD(double, calculateArea, (), (override));
};

// Test fixture for the Shape class
class ShapeTest : public ::testing::Test {
protected:
    Rectangle rectangle;
    Circle circle;

    ShapeTest()
        : rectangle(4.0, 3.0), circle(5.0) {}
};

// Tests the calculateArea() function of Rectangle
TEST_F(ShapeTest, RectangleCalculateArea) {
    double area = rectangle.calculateArea();
    EXPECT_EQ(area, 12.0);
}

// Tests the calculateArea() function of Circle
TEST_F(ShapeTest, CircleCalculateArea) {
    double area = circle.calculateArea();
    EXPECT_NEAR(area, 78.5, 0.1);
}

// Tests the printArea() function with a mocked shape
TEST_F(ShapeTest, PrintAreaWithMockShape) {
    MockShape mockShape;
    EXPECT_CALL(mockShape, calculateArea()).WillOnce(::testing::Return(10.0));

    ::testing::internal::CaptureStdout();
    printArea(mockShape);
    std::string output = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Area: 10\n");
}

// Tests the constructor of Rectangle with negative width
TEST(ShapeExceptionTest, RectangleConstructorWithNegativeWidth) {
    EXPECT_THROW(Rectangle rectangle(-4.0, 3.0), std::invalid_argument);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
