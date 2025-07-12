#include <iostream>
#include "sales_data.h"
using namespace std;

int main()
{
    string s5 = "hiya"; // 拷贝初始化
    string s6("hiya");  // 直接初始化
    string s7(10, 'c'); // 直接初始化，s7的内容是cccccccccc

    return 0;
}