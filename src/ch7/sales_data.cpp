#include <iostream>   
#include "sales_data.h"
using namespace std;


Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this; // 返回调用该函数的对象
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
    {
        item.revenue = item.units_sold * price; // 计算总收入
    }
    else
    {
        item = Sales_data(); // 重置为默认状态
    }
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // 创建一个新的Sales_data对象
    sum.combine(rhs);     // 使用combine方法合并数据
    return sum;           // 返回合并后的对象
}
