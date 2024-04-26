#pragma once
#include"DataSourceInterface.h"
#include"FileHelper.h"
class FileManager:public DataSourceInterface
{
public:
	static void AddClients(Client c) {
		FileHelper::SaveClient(c);
	}
	static void AddEmployee(Employee e) {
		FileHelper::SaveEmployee(e);
	}
	static void AddAdmin(Admin a) {
		FileHelper::SaveAdmin(a);
	}
	static void getAllClients() {
		FileHelper::getAllClients();
	}
	static void getAllEmployees() {
		FileHelper::getAllEmployees();
	}
	static void getAllAdmins() {
		FileHelper::getAllAdmins();
	}
	static void GetAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}
};

