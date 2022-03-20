#include <iostream>
#include <cmath>

using namespace std;
typedef long long BigInteger;

int MaxDigit(BigInteger x, BigInteger y)
{
    BigInteger max;
    int i = 0;
    if (x>y)
        max = x;
    else max = y;

    while(max>0)
    {
        max /= 10;
        i++;
    }
    return i;
}


BigInteger Multiply(BigInteger x, BigInteger y)
{
    int n = MaxDigit(x, y);
    int m ;
    BigInteger al, ar, bl, br;
    BigInteger x1, x2, x3;

    if (n == 1)
        return x*y;
    else
    {
        m = floor(n / 2);
        al = x / (int)pow(10, m);
        ar = x % (int) pow(10, m);
        bl = y / (int)pow(10, m);
        br = y % (int) pow(10, m);
        x1 = Multiply(al, bl);
        x2 = Multiply(ar, br);
        x3 = Multiply(al + ar, bl + br);

        return x1 * (int)pow(10, m * 2) + (x3 - x1 - x2) * (int)pow(10, m) + x2;
    }

}


int main()
{
        BigInteger a, b;
        cin >> a >> b;

        cout<<Multiply(a,b)<<endl;
        return 0;
}
