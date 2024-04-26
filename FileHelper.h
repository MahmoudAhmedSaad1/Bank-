#pragma once
#include<string>
#include<fstream>
#include"Client.h"
#include"Admin.h"
#include"Employee.h"
#include<vector>
#include"Parse.h"
class FileHelper
{
public:
	static void SaveClient(Client c) {
		fstream file;
		file.open("client.txt", ios::app);
		file << c.getId() << ";" << c.getName() << ";" << c.getPassword() << ";" << c.getBalance()<<"\n";
		file.close();
	}
	static void SaveEmployee(Employee e) {
		fstream file;
		file.open("employee.txt", ios::app);
		file << e.getId() << ";" << e.getName() << ";" << e.getPassword() << ";" << e.getSalary() << "\n";
		file.close();
	}
	static void SaveAdmin(Admin a) {
		fstream file;
		file.open("admin.txt", ios::app);
		file << a.getId() << ";" << a.getName() << ";" << a.getPassword() << ";" << a.getSalary() << "\n";
		file.close();
	}
	static void getAllClients() {
		fstream file;
		string line;
		file.open("client.txt", ios::in);
		while (getline(file, line)) {
			Client c = Parse::parseToClient(line);
			AllClients.push_back(c);
		}
		file.close();
	}
	static void getAllEmployees() {
		fstream file;
		string line;
		file.open("employee.txt", ios::in);
		while (getline(file,line))
		{
			Employee e =Parse::parseToEmployee(line);
			AllEmployees.push_back(e);
		}
		file.close();
	}
	static void getAllAdmins() {
		fstream file;
		file.open("admin.txt", ios::in);
		string line;
		while (getline(file, line)) {
		Admin a = Parse::parseToAdmin(line);
		AllAdmins.push_back(a);
		}
		file.close();
	}
	static void clearFile(string fileName) {
		fstream file;
		file.open(fileName, ios::out, ios::trunc);
		file.close();
	}
};

