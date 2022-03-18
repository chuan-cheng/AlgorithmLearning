#include <iostream>
using namespace std;
int RussianPeasant(int a, int b)
{
    int res = 0;
    while (b > 0)
    {
        if (b & 1)
            res = res + a;
        a = a << 1;
        b = b >> 1;
    }
    return res;
}
int main()
{
    int a,b;
    cout << "Enter two numbers:" << endl;
    cin >> a >> b;
    cout << RussianPeasant(a, b) << endl;
    return 0;
}

