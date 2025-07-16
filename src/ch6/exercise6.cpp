#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

void correct_num(int num[], const int num_size)
{
    for (int i = 0; i < num_size; i++)
        num[i] *= 3;
}
int main(void)
{
    int num[10];
    for (int i = 0; i < 10; i++)
    {
        num[i] = i;
    }

    correct_num(num, 10);
    cout << num[2] << " " << num[3] << endl;
    return 0;
}