#include <iostream>
#include <cctype>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<int> vec = {-1, -5, -4, -5, -4, 0, 2, 3, 5};
    auto p = vec.begin();

    unsigned int bits = 0233;
    cout << bits << endl;
    bits = bits << 1;
    cout << bits << endl;
    return 0;
}