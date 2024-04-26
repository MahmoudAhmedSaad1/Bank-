#pragma once
#include<string>
#include<iostream>
using namespace std;
class Validation
{
public:
	string name;
	string password;
	double balance;
public:
	static bool NameValidation(string name) {
		for (int i = 0; i < name.length(); i++) {
			if (!isalpha(name[i])) {
				return false;
			}
		}
		if (name.length() < 5 || name.length() > 20) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool PasswordValidation(string password) {
		if (password.length() >= 8 || password.length() <= 20) {
			return true;
		}
		else { return false;
		}
	}
	static bool ValidateBalance(double balance) {
		if (balance >= 1500) {
			return true;
		}else
		{
			return false;
		}
	}
	static bool ValidateSalary(double balance) {
		if (balance >= 5000) {
			return true;
		}
		else
		{
			return false;
		}
	}
};

