#include <iostream>
using namespace std;

class Employee {
public:
    virtual double calculateSalary() const = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
private:
    double salary;
public:
    FullTimeEmployee(double s) : salary(s) {}
    double calculateSalary() const override {
        return salary;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hours;
    double rate;
public:
    PartTimeEmployee(int h, double r) : hours(h), rate(r) {}
    double calculateSalary() const override {
        return hours * rate;
    }
};

int main() {
    FullTimeEmployee ft(45000);
    PartTimeEmployee pt(120, 20.5);

    cout << "Full-Time Salary: " << ft.calculateSalary() << endl;
    cout << "Part-Time Salary: " << pt.calculateSalary() << endl;

    return 0;
}
