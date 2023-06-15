#include <gtest/gtest.h>
#include "shapes.hpp"

// Test calculateArea() with different widths and heights
class ParameterizedRectangleTest : public ::testing::TestWithParam<std::pair<double, double>> {};

TEST_P(ParameterizedRectangleTest, ParameterizedCalculateArea) {
    double width = GetParam().first;
    double height = GetParam().second;

    Rectangle rectangle(width, height);
    double area = rectangle.calculateArea();
    EXPECT_EQ(area, width * height);
}

// Define parameter values for the tests
INSTANTIATE_TEST_CASE_P(ParameterizedRectangleDimensions, ParameterizedRectangleTest, ::testing::Values(
    std::make_pair(4.0, 3.0),
    std::make_pair(2.0, 2.0),
    std::make_pair(10.0, 5.0)
));

// Test calculateArea() with different radii
class ParameterizedCircleTest : public ::testing::TestWithParam<double> {};

TEST_P(ParameterizedCircleTest, ParameterizedCalculateArea) {
    double radius = GetParam();

    Circle circle(radius);
    double area = circle.calculateArea();
    EXPECT_NEAR(area, 3.14 * radius * radius, 0.1);
}

// Define parameter values for the tests
INSTANTIATE_TEST_CASE_P(ParameterizedCircleRadii, ParameterizedCircleTest, ::testing::Values(5.0, 2.5, 10.0));

// Test calculateArea() with a range of values for width
class ParameterizedWidthTest : public ::testing::TestWithParam<double> {};

TEST_P(ParameterizedWidthTest, ParameterizedCalculateArea) {
    double width = GetParam();
    double height = 3.0; // Use a fixed height for testing

    Rectangle rectangle(width, height);
    double area = rectangle.calculateArea();
    EXPECT_EQ(area, width * height);
}

// Define parameter range for the tests
INSTANTIATE_TEST_CASE_P(ParameterizedWidthRange, ParameterizedWidthTest, ::testing::Range(1.0, 6.0, 1.0));

// Test calculateArea() with a range of values for height
class ParameterizedHeightTest : public ::testing::TestWithParam<double> {};

TEST_P(ParameterizedHeightTest, ParameterizedCalculateArea) {
    double width = 4.0; // Use a fixed width for testing
    double height = GetParam();

    Rectangle rectangle(width, height);
    double area = rectangle.calculateArea();
    EXPECT_EQ(area, width * height);
}

// Define parameter range for the tests
INSTANTIATE_TEST_CASE_P(ParameterizedHeightRange, ParameterizedHeightTest, ::testing::Range(2.0, 7.0, 1.0));