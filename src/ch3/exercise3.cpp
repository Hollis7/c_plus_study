#include <iostream>
#include "sales_data.h"
#include <cctype>
#include <vector>
using namespace std;
int main()
{
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // ia是一个含有10个整数的数组
    vector<int> vec1(begin(ia), end(ia));
    for(auto a:vec1){
        cout<<a<<endl;
    }
    return 0;
}