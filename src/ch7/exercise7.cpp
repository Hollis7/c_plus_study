#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "sales_data.h"
#include "Account.h"
using namespace std;

int main()
{
	double rate = Account::rate(); // 获取当前利率
	cout << "Current interest rate: " << rate << endl;
	cout<<"Hello, C++17!" << endl;
	return 0;
}