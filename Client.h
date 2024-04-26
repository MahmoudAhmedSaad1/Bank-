#pragma once
#include<iostream>
#include"Validation.h"
#include "Person.h"
#include<vector>
#include <string>
using namespace std;
class Client :
    public Person
{
private:
    double balance;
    static int Clientcounter ;
public:
   
    Client() :Person() {
        this->balance = 0;
        Clientcounter++;
        this->id = Clientcounter;
    }
   
    Client(int id, string name, string password,double balance):Person(id,name,password) {
        setBalancce(balance);
        Clientcounter++;
        this->id = Clientcounter;
    }
    void setNameAndPassword(string name,string password) {
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
    void setBalancce(double balance) {
        if (Validation::ValidateBalance(balance))
            this->balance = balance;
        else
            cout << "enter valid balance \n";
       
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
    double getBalance() {
        return this->balance;
    }
    void Deposite(double amount) {
        balance += amount;
        cout << "\nSuccessful transaction.\n";
    }
   /* double BalanceAfterDeposite(double amount) {
        balance += amount;
        return balance;
    }*/
    void Withdraw(double amount) {
        if (amount > balance) {
            cout << " amount exceed the balance \n";
        }
        else
           this->balance -= amount;
        cout << "\nSuccessful transaction.\n";
    }
    void transfere(double amount,Client &another) {
        if (amount <= balance) {
           this->balance -= amount;
            another.Deposite(amount);
            cout << "\nSuccessful transaction.\n";
        }
        else {
            cout << " Amount exceeded the balance \n";
        }
    }
    void checkBalance() {
        cout << " Your balance is : " <<this->balance << "\n";
    }
    void Display() {
        Person::Display();
        cout << " Client Balance : " << getBalance() << "\n";
        
    }
};
static vector<Client> AllClients;