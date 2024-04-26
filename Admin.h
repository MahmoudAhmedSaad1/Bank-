#pragma once
#include<vector>
#include"Employee.h"
#include"Client.h"
#include<iostream>
#include"Validation.h"
#include"Person.h"
using namespace std;
class Admin:public Employee
{
    static int Counter;
public:
  

    Admin(){
        Counter++;
        Employee::counter--;
        this->id = Counter;
    }
	Admin(int id, string name, string password, double salary) :Employee (id, name, password,salary) {
        Counter++;
        Employee::counter--;
        this->id = Counter;
	}
    void setNameAndPassword(string name, string password) {
        Person::setName(name);
        Person::setPassword(password);
    }
    void setName(string name) {
        Person::setName(name);
    }
    void setPassword(string password) {
        Person::setPassword(password);
    }
    void setId(int id) {
        this->id = id;
    }
    void setsalary(double salary) {
        if (salary < 5000) {
            cout << " The minimum salary is 5000\n";
        }
        else
            this->salary = salary;
    }
    string getName() {
        return name;
    }
    string getPassword() {
        return password;
    }
    int getId() {
        return id;
    }
    double getSalary() {
        return salary;
    }
    void Display() {
        Employee::Display();
    }
    void AddEmployee(Employee & e) {
        AllEmployees.push_back(e);
    }
    Employee* searchEmployee(int id) {
        for (int i = 0; i < AllEmployees.size(); i++) {
            if (AllEmployees[i].getId() == id) {
                Employee* e = &AllEmployees[i];
                return e;
            }
        }
        return nullptr;
    }
    void listEmployee(Employee e) {
        cout << " I D of Employee : " << e.getId() << "\n";
        cout << " Name of Employee : " << e.getName() << "\n";
        cout << " Password of Employee : " << e.getPassword() << "\n";
        cout << " Balance of Employee : " << e.getSalary() << "\n";
    }
    void editEmployee(int id, string name, string password, double salary) {
        Employee* e = searchEmployee(id);
        e->setName(name);
        e->setPassword(password);
        e->setsalary(salary);

    }
};

static vector<Admin>AllAdmins;
