#include "shapes.hpp"

Rectangle::Rectangle(double width, double height)
    : width_(width), height_(height) {}

double Rectangle::calculateArea() {
    return width_ * height_;
}

Circle::Circle(double radius) : radius_(radius) {}

double Circle::calculateArea() {
    return 3.14 * radius_ * radius_;
}

void printArea(Shape& shape) {
    double area = shape.calculateArea();
    std::cout << "Area: " << area << std::endl;
}