#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    vector<char> ops = {'+', '-', '*', '/'};
    int min_non_neg = 2147483647;
    for (char op1 : ops)
    {
        for (char op2 : ops)
        {
            int result = a;
            if (op1 == '+')
            {
                result += b;
            }
            else if (op1 == '-')
            {
                result -= b;
            }
            else if (op1 == '*')
            {
                result *= b;
            }
            else if (op1 == '/')
            {
                if (b == 0 || result % b != 0)
                    continue;
                result /= b;
            }
            if (op2 == '+')
            {
                result += c;
            }
            else if (op2 == '-')
            {
                result -= c;
            }
            else if (op2 == '*')
            {
                result *= c;
            }
            else if (op2 == '/')
            {
                if (c == 0 || result % c != 0)
                    continue;
                result /= c;
            }
            if (result >= 0)
            {
                min_non_neg = min(min_non_neg, result);
            }
        }
    }
    cout << min_non_neg << endl;
    return 0;
}