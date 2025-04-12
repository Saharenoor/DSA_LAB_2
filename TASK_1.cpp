#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.1416 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length * width;
    }
};

int main() {
    Circle c(4);
    Rectangle r(5, 3);

    cout << "Circle Area: " << c.area() << endl;
    cout << "Rectangle Area: " << r.area() << endl;

    return 0;
}
