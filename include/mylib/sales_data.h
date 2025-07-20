#ifndef SALES_DATA_H
#define SALES_DATA_H
class Sales_data
{
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

public:
    // 非委托构造函数使用对应的实参初始化成员
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(n * p) {}

    // 委托构造函数：从字符串初始化
    Sales_data() : Sales_data("", 0, 0.0) {}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) {}
    Sales_data(std::istream &is) : Sales_data() { read(is, *this); }
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