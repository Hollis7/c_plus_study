#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Screen.h"
int main()
{
    Screen::pos ht = 3, wd = 4;
    Screen screen(ht, wd, '#'); // 创建一个10行20列的屏

    Window_mgr wm;
    Window_mgr::ScreenIndex idx = wm.addScreen(screen);
    wm.display(idx); // 显示屏幕内容

    return 0;
}