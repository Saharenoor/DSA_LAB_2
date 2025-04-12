/*
Design an abstract class Employee with a pure virtual function calculateSalary(). Derive two
classes: FullTimeEmployee and PartTimeEmployee, from Employee.
Requirements:
• FullTimeEmployee should have a fixed salary, while PartTimeEmployee should be paid
based on hours worked and an hourly rate.
• Implement the calculateSalary() method in both classes.
• Write a main function that creates one full-time and one part-time employee, sets their details,
and prints their salaries.
*/
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
