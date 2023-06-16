#include "shapes.hpp"

Rectangle::Rectangle(double width, double height) : width_(width), height_(height) {
    if (width_ < 0.0 || height_ < 0.0) {
        throw std::invalid_argument("Negative values are not allowed for width or height.");
    }
}

double Rectangle::calculateArea()
{
    return width_ * height_;
}

Circle::Circle(double radius) : radius_(radius) {
    if (radius_ < 0.0) {
        throw std::invalid_argument("Negative value is not allowed for radius.");
    }
}

double Circle::calculateArea() {
    return 3.14 * radius_ * radius_;
    // Should we use more digits for pi? NASA uses 3.141592653589793
    // https://www.jpl.nasa.gov/edu/news/2016/3/16/how-many-decimals-of-pi-do-we-really-need
}

void printArea(Shape& shape) {
    double area = shape.calculateArea();
    std::cout << "Area: " << area << std::endl;
}