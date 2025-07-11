#include <iostream>
#include "Version_test.h"

using namespace std;
int main()
{

    int errNumb = 0;
    int *const curErr = &errNumb;
    const double pi = 3.14159;
    const double *const pip = &pi;
    *curErr = 2;
    cout << "errNumb: " << *curErr << endl;

    return 0;
}