#pragma once
#include<iostream>
#include"Client.h"
#include "Person.h"
#include<iterator>
#include<vector>
using namespace std;
class Employee :
    public Person
{
protected:
    double salary;
    static int  counter;
public:

    Employee ():Person()
    {
        this->salary = 0;
        counter++;
        this->id =counter;
    }
    Employee(int id, string name, string password, double salary) :Person(id, name, password) {
        setsalary(salary);
        counter++;
        this->id = counter;
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
        }else
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
        Person::Display();
        cout << " Employee Salary : " << getSalary() << "\n";
        
    }
    void AddClient(Client&c) {
        AllClients.push_back(c);
    }
    Client* searchClient(int id) {
        for (int i = 0; i < AllClients.size(); i++) {
            if (AllClients[i].getId() == id) {
                Client* c = & AllClients[i];
                return c;
            }
        }
        return nullptr;
    }
    void listClient(Client c) {
        cout<<" I D of Client : " << c.getId() << "\n";
        cout<<" Name of Client : " << c.getName() << "\n";
        cout<<" Password of Client : " << c.getPassword() << "\n";
        cout<<" Balance of Client : " << c.getBalance() << "\n";
    }
    void editClient(int id, string name, string password, double balance) {
        Client* c = searchClient(id);
        c->setName(name);
        c->setPassword(password);
        c->setBalancce(balance);

    }
};

static vector<Employee>AllEmployees;