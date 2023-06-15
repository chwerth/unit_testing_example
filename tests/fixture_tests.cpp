#include <gtest/gtest.h>
#include "shapes.hpp"

// Test fixture for the Shape class
class ShapeTest : public ::testing::Test {
protected:
    Rectangle* rectangle;
    Circle* circle;

    ShapeTest() : rectangle(nullptr), circle(nullptr) {}

    void SetUp() override {
        rectangle = new Rectangle(4.0, 3.0);
        circle = new Circle(5.0);
    }

    void TearDown() override {
        delete rectangle;
        delete circle;
        rectangle = nullptr;
        circle = nullptr;
    }
};

// Test Rectangle calculateArea()
TEST_F(ShapeTest, RectangleCalculateArea) {
    EXPECT_EQ(rectangle->calculateArea(), 12.0);
}

// Test Circle calculateArea()
TEST_F(ShapeTest, CircleCalculateArea) {
    EXPECT_NEAR(circle->calculateArea(), 78.5, 0.1);
}

// Test Circle constructor with positive radius
TEST_F(ShapeTest, ConstructorPositiveRadius) {
    EXPECT_NO_THROW(Circle circle(5.0));
}

// Test Circle constructor with negative radius
TEST_F(ShapeTest, ConstructorNegativeRadius) {
    EXPECT_THROW(Circle circle(-5.0), std::invalid_argument);
}

// Test Rectangle constructor with positive width and height
TEST_F(ShapeTest, ConstructorPositiveWidthAndHeight) {
    EXPECT_NO_THROW(Rectangle rectangle(4.0, 3.0));
}

// Test Rectangle constructor with negative width
TEST_F(ShapeTest, ConstructorNegativeWidth) {
    EXPECT_THROW(Rectangle rectangle(-4.0, 3.0), std::invalid_argument);
}

// Test Rectangle constructor with negative height
TEST_F(ShapeTest, ConstructorNegativeHeight) {
    EXPECT_THROW(Rectangle rectangle(4.0, -3.0), std::invalid_argument);
}

// Test printArea() with Rectangle
TEST_F(ShapeTest, PrintAreaRectangle) {
    ::testing::internal::CaptureStdout();
    printArea(*rectangle);
    std::string output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Area: 12\n");
}

// Test printArea() with Circle
TEST_F(ShapeTest, PrintAreaCircle) {
    ::testing::internal::CaptureStdout();
    printArea(*circle);
    std::string output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Area: 78.5\n");
}

// Test printArea() with invalid Shape
TEST_F(ShapeTest, PrintAreaInvalidShape) {
    class InvalidShape : public Shape {
    public:
        double calculateArea() {
            throw std::runtime_error("Invalid shape");
        }
    };

    InvalidShape invalidShape;
    EXPECT_THROW(printArea(invalidShape), std::runtime_error);
}
