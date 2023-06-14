#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>

class Shape {
public:
    virtual double calculateArea() = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height);
    double calculateArea();

private:
    double width_;
    double height_;
};

class Circle : public Shape {
public:
    Circle(double radius);
    double calculateArea();

private:
    double radius_;
};

#endif  // SHAPES_H
