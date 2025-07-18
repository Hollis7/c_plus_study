#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default; // 默认构造函数
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; } // 获取当前光标位置的字符
    inline char get(pos ht, pos wd) const; // 获取指定位置的字符
    Screen &move(pos r, pos c); // 移动光标到指定位置

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
#endif
