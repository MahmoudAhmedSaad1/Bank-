#pragma once
#include<string>
#include"Validation.h"
#include<iostream>
using namespace std;
class Person
{
protected:
	int id;
	string name;
	string password;
public:
	Person(int id,string name,string password) {
		this->id = id;
		this->setName(name);
		this->setPassword(password);
	}
	Person() {
		id = 0;
		name = " ";
		password = " ";
	}
	void setName(string name) {
		cout << "Enter  valid name \n";
		if (Validation::NameValidation(name)) {
			this->name = name;
		}
		else
		{
			cout << " Enter valid name\n";
		}
	}
	void setId(int id) {
		this->id = id;
	}
	void setPassword(string password)
	{
		if (Validation::PasswordValidation(password)) {
			this->password = password;
		}
		else
		{
			cout << "Enter valid Password \n";
		}
	}
	string getName() {
		return name;
	}
	int getId() {
		return id;
	}
	string getPassword() {
		return password;
	}
	void Display() {
		cout << " Client name : " << getName() << "\n";
		cout << " Client Id : " << getId() << "\n";
		cout << " Client Password : " << getPassword() << "\n";
	}
};

