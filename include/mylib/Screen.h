#ifndef SCREEN_H
#define SCREEN_H
// 前向声明
class Screen;

class Window_mgr
{
public:
    Window_mgr();                                       // 初始化一个默认屏幕
    using ScreenIndex = std::vector<Screen>::size_type; // 定义屏幕索引类型
    void clear(ScreenIndex);                            // 清除指定屏幕的内容
    Screen &display(ScreenIndex i, std::ostream &os = std::cout);
    

private:
    std::vector<Screen> screens; // 存储屏幕对象的向量
};

class Screen
{
    // 声明Window_mgr为Screen的友元类
    friend void Window_mgr::clear(ScreenIndex);
    friend Screen &Window_mgr::display(ScreenIndex, std::ostream &);

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
    Screen &display(std::ostream &os);
    const Screen &display(std::ostream &os) const;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr = 0; // 可变成员变量，用于跟踪访问次数
    void do_display(std::ostream &os) const
    {
        os << contents; // 显示屏幕内容
    }
};

Window_mgr::Window_mgr()
    : screens{Screen(10, 5, '#')} // 初始化一个默认屏幕，大小为24行80列，内容为空格
{
}
Screen &Window_mgr::display(ScreenIndex i, std::ostream &os)
{
    Screen &s = screens[i]; // 获取指定索引的屏幕
    s.display(os);          // 调用屏幕的display方法
    return s;              // 返回屏幕对象的引用
}
// 现在可以声明Window_mgr::clear为友元函数
inline void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];                            // 获取指定索引的屏幕
    s.contents = std::string(s.height * s.width, ' '); // 清空屏幕内容
    s.cursor = 0;                                      // 重置光标位置
}

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

Screen &Screen::display(std::ostream &os)
{
    do_display(os); // 调用私有成员函数显示内容
    return *this;   // 返回当前对象的引用
}

const Screen &Screen::display(std::ostream &os) const
{
    do_display(os); // 调用私有成员函数显示内容
    return *this;   // 返回当前对象的引用
}
#endif // SCREEN_H