#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>
class Sales_data
{
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
public:
    // 新增的构造函数
    Sales_data() = default;                         // 默认构造函数
    Sales_data(const std::string &s) : bookNo(s) {} // 带参数的构造函数
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data(std::istream &is){read(is, *this);} // 使用read函数从输入流初始化} // 从输入流构造
    // 新成员：关于Sales_data对象的操作
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

private:
    double avg_price() const
    {
       return units_sold ? revenue / units_sold : 0.0; // 计算平均价格
    }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// 非成员函数
Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
#endif