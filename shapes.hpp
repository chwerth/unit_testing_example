#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>

class Shape {
public:
    virtual double calculateArea() = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height)
        : width_(width), height_(height) {}

    double calculateArea() {
        return width_ * height_;
    }

private:
    double width_;
    double height_;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {}

    double calculateArea() {
        return 3.14 * radius_ * radius_;
    }

private:
    double radius_;
};

void printArea(Shape& shape) {
    double area = shape.calculateArea();
    std::cout << "Area: " << area << std::endl;
}

#endif  // SHAPES_H