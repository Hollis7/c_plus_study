#ifndef SCREEN_H
#define SCREEN_H

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default; // 默认构造函数
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; } // 获取当前光标位置的字符
    inline char get(pos ht, pos wd) const;        // 获取指定位置的字符
    Screen &move(pos r, pos c);                   // 移动光标到指定位置
    void some_member() const;
    Screen &set(char c);
    Screen &set(pos r, pos c, char ch);

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr = 0; // 可变成员变量，用于跟踪访问次数
};
inline char Screen::get(pos r, pos c) const
{
    return contents[r * width + c]; // 返回指定位置的字符
}

inline Screen &Screen::move(pos r, pos c)
{
    cursor = r * width + c; // 计算光标的新位置
    return *this;           // 返回当前对象的引用
}

void Screen::some_member() const
{
    ++access_ctr; // 增加访问计数
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c; // 设置光标位置的字符
    return *this;         // 返回当前对象的引用
}
inline Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch; // 设置指定位置的字符
    return *this;                 // 返回当前对象的引用
}
class Window_mgr
{
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')}; // 存储屏幕对象的向量
};
#endif
