#include <gtest/gtest.h>
#include "shapes.hpp"

// Test Rectangle calculateArea()
TEST(RectangleTest, CalculateArea) {
    Rectangle rectangle(4.0, 3.0);
    EXPECT_EQ(rectangle.calculateArea(), 12.0);
}

// Test Circle calculateArea()
TEST(CircleTest, CalculateArea) {
    Circle circle(5.0);
    EXPECT_NEAR(circle.calculateArea(), 78.5, 0.1);
}

// Test Circle constructor with positive radius
TEST(CircleTest, ConstructorPositiveRadius) {
    EXPECT_NO_THROW(Circle circle(5.0));
}

// Test Circle constructor with negative radius
TEST(CircleTest, ConstructorNegativeRadius) {
    EXPECT_THROW(Circle circle(-5.0), std::invalid_argument);
}

// Test Rectangle constructor with positive width and height
TEST(RectangleTest, ConstructorPositiveWidthAndHeight) {
    EXPECT_NO_THROW(Rectangle rectangle(4.0, 3.0));
}

// Test Rectangle constructor with negative width
TEST(RectangleTest, ConstructorNegativeWidth) {
    EXPECT_THROW(Rectangle rectangle(-4.0, 3.0), std::invalid_argument);
}

// Test Rectangle constructor with negative height
TEST(RectangleTest, ConstructorNegativeHeight) {
    EXPECT_THROW(Rectangle rectangle(4.0, -3.0), std::invalid_argument);
}

// Test printArea() with Rectangle
TEST(PrintAreaTest, Rectangle) {
    Rectangle rectangle(4.0, 3.0);
    ::testing::internal::CaptureStdout();
    printArea(rectangle);
    std::string output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Area: 12\n");
}

// Test printArea() with Circle
TEST(PrintAreaTest, Circle) {
    Circle circle(5.0);
    ::testing::internal::CaptureStdout();
    printArea(circle);
    std::string output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Area: 78.5\n");
}

// Test printArea() with invalid Shape
TEST(PrintAreaTest, InvalidShape) {
    class InvalidShape : public Shape {
    public:
        double calculateArea() {
            throw std::runtime_error("Invalid shape");
        }
    };

    InvalidShape invalidShape;
    EXPECT_THROW(printArea(invalidShape), std::runtime_error);
}