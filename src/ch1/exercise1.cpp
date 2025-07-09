#include <iostream>
using namespace std;
int main()
{
    int sum = 0, i = 50;

    while (i <= 100)
    {
        sum += i;
        ++i;
    }

    std::cout << sum << std::endl;

    sum = sum + 3;

    cout << sum << endl;
    return 0;
}