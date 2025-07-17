#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "sales_data.h"
using namespace std;
int main(){
Sales_data total;
	if (read(std::cin, total))
	{
		Sales_data trans;
		while (read(std::cin, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	}
	else
	{
		std::cerr << "No data?!" << std::endl;
		return -1;
	}

    
    return 0;
}