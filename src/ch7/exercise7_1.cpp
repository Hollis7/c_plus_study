#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Screen.h"
int main()
{
    Screen myScreen(5, 5, 'X'); // 创建一个5x5的屏幕，初始字符为'X'
    myScreen.move(2, 3); // 移动光标到第2行第3列
    std::cout << "Character at cursor: " << myScreen.get() << std::endl; // 获取光标位置的字符
    std::cout << "Character at (2, 3): " << myScreen.get(2, 3) << std::endl; // 获取指定位置的字符
    myScreen.move(1, 1); // 移动光标到第1行第1列
    std::cout << "Character at cursor after move: " << myScreen.get() << std::endl; // 获取
    
    return 0;
}