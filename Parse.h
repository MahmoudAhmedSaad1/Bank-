#pragma once
#include<string>
#include<sstream>
#include"Client.h"
#include"Admin.h"
#include"Employee.h"
#include<vector>
using namespace std;
class Parse
{
public:
	static vector<string> split(string line) {
		stringstream s(line);
		string part;
		vector<string> info;
		while (getline(s,part,';'))
		{
			info.push_back(part);
		}
		return info;
	}
	static Client parseToClient(string line) {
		vector <string>info = split(line);
		Client c(stoi(info[0]), info[1], info[2], stod(info[3]));
		return c;
	}
	static Employee parseToEmployee(string line) {
		vector<string>info = split(line);
		Employee e(stoi(info[0]), info[1], info[2], stod(info[3]));
		return e;
	}
	static Admin parseToAdmin(string line) {
		vector<string> info = split(line);
		Admin a(stoi(info[0]), info[1], info[2], stod(info[3]));
		return a;
	}
};

