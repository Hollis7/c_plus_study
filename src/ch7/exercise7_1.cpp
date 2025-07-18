#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Screen.h"
int main()
{
    Screen myScreen(5, 5, 'X'); // 创建一个5x5的屏幕，初始字符为'X'
    const Screen blank(5, 3, 'c');
    myScreen.set('#').display(std::cout); // 设置光标位置的字符为'#'并显示屏幕内容
    std::cout << std::endl;
    blank.display(std::cout); // 显示另一个屏幕内容
    return 0;
}