#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
class Account
{
private:
    std::string owner;          // 账户所有者
    double amount;              // 账户余额
    static double interestRate; // 静态成员变量，存储利率
    static double initRate();   // 静态成员函数，初始化利率
    static constexpr int period = 30; // 静态常量，表示利率周期
    double daily_tbl[period]; // 静态数组，存储每天的利率
public:
    Account(const std::string &own, double amt)
        : owner(own), amount(amt) 
    {
        // 初始化daily_tbl数组
        for (int i = 0; i < period; ++i) {
            daily_tbl[i] = 0.0;
        }
    }
    void calculate()
    {
        amount += amount * interestRate; // 计算利息并更新余额
    }
    static double rate()
    {
        return interestRate;
    }
    static void rate(double newRate)
    {
        interestRate = newRate; // 设置新的利率
    }
};
double Account::interestRate = Account::initRate(); // 定义并初始化静态成员变量
double Account::initRate()
{
    return 0.02; // 默认利率2%
}
#endif // ACCOUNT_H