#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
/*-----只能计算2^n次方数字的计算
 *
 * */
using namespace std;
string BigNumberMultiply(string s1, string s2);
string AddString(string s1, string s2);
string InvertString(string str);
int Max(int x, int y);
string Mul(string s1, string s2);
int str2num(string s);
string num2str(int i);
/*----------数字转字符串--------*/
string num2str(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}
/*---------字符串转数字---------*/
int str2num(string s)
{
    int num;
    stringstream ss(s);
    ss >> num;
    return num;
}

int Max(int x, int y)
{
    return x > y ? x : y;
}

string Mul(string s1, string s2)
{
    int num = str2num(s1) * str2num(s2);
    return num2str(num);
}

string InvertString(string str)
{
    string result;
    for(int i = str.size() - 1; i >= 0; i--)
    {
        result = result + str[i];
    }
    return result;
}

string AddString(string s1, string s2)
{
    int max;
    string result;
    int addflag = 0;
    int temp = 0;
    if(s1.size() > s2.size())
    {
        max = s1.size();
        s2 = string(max - s2.size(), '0') + s2;
    } else {
        max = s2.size();
        s1 = string(max- s1.size(), '0') + s1;
    }

    for(int i = max - 1; i >= 0; i--)
    {
        temp = (s1[i] - '0') + (s2[i] - '0') + addflag;
        if(temp >= 10)
        {
            addflag = temp / 10;
            temp = temp % 10;
        } else {
            addflag = 0;
        }
        result = result + num2str(temp);
    }
    if(addflag != 0)
    {
        result = result + num2str(addflag);
    }
    return result; //需要倒序
}

/*---------递归乘法-----------*/
string BigNumberMultiply(string s1, string s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    int max = Max(len1, len2);
    int half = max / 2;
    string aL, aR, bL , bR;
    string ac, bd, bc, ad;
    string result, temp1, temp2, temp3;

    if(max == len1) {
        s2 = string(max - len2, '0') + s2;
    } else {
        s1 = string(max - len1, '0') + s1;
    }

    if (max == 1)
    {
        return Mul(s1, s2);
    }

    aL = s1.substr(0, half);
    aR = s1.substr(half);
    bL = s2.substr(0, half);
    bR = s2.substr(half);
    ac = BigNumberMultiply(aL,bL);
    bd = BigNumberMultiply(aR,bR);
    bc = BigNumberMultiply(aR,bL);
    ad = BigNumberMultiply(aL,bR);
    temp1 = ac + string(max, '0');
    temp2 = InvertString(AddString(bc, ad)) + string(half,'0');
    temp3 = InvertString(AddString(temp1, temp2));
    result = InvertString(AddString(temp3, bd));

    return result;
}

int main()
{
    string s1 = "1234567812345678";
    string s2 = "1234567812345678";

    cout << BigNumberMultiply(s1,s2) << endl;

    return 0;
}
