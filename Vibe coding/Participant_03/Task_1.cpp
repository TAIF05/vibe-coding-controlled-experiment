#include <iostream>
#include <vector>

using namespace std;

bool apply_op(long long x, long long y, char op, long long &res)
{
    if (op == '+')
    {
        res = x + y;
        return true;
    }
    if (op == '-')
    {
        res = x - y;
        return true;
    }
    if (op == '*')
    {
        res = x * y;
        return true;
    }
    if (op == '/')
    {
        if (y == 0)
            return false;
        if (x % y != 0)
            return false;
        res = x / y;
        return true;
    }
    return false;
}

int main()
{

    long long a, b, c;
    if (!(cin >> a >> b >> c))
        return 0;

    vector<char> ops = {'+', '-', '*', '/'};
    vector<long long> validResults;

    for (char op1 : ops)
    {
        long long r1;
        if (!apply_op(a, b, op1, r1))
            continue;
        for (char op2 : ops)
        {
            long long r2;
            if (!apply_op(r1, c, op2, r2))
                continue;
            if (r2 >= 0)
                validResults.push_back(r2);  }
    }

    if (validResults.empty())
    {
        cout << "There is no valid non-negative result" << endl;
    }
    else
    {
        long long mn = validResults[0];
        for (long long v : validResults)
            if (v < mn)
                mn = v;
        cout << mn << endl;
    }

    return 0;
}
