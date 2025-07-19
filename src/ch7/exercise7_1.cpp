#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Screen.h"
int main()
{
    Window_mgr wm; // 创建一个Window_mgr对象
    wm.display(0); // 显示第一个屏幕
    wm.clear(0);  // 清除第一个屏幕的内容
    wm.display(0); // 再次显示第一个屏幕，应该是空的

    return 0;
}