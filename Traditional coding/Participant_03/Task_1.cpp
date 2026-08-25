#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int result=10000000;
    char op[4] = {'+', '-', '*', '/'};
    for (char i: op)
    {
        for (char j : op)
        {
            int r1, r2;
            if (i == '+')
                r1 = x + y;
            if (i == '-')
                r1 = x - y;
            if (i == '*')
                r1 = x * y;
            if (i == '/' && y != 0 && x % y == 0)
                r1 = x / y;
            else if (i == '/')
                continue;
            
            if (j == '+') 
                r2 = r1 + z;
            if (j == '-')
                r2 = r1 - z;
            if (j == '*') 
                r2 = r1 * z;
            if (j == '/' && z != 0 && r1 % z == 0) 
                r2 = r1 / z;
            else if (j == '/')
                continue;

            if (r2 >= 0 && r2 < result)
                result = r2;

            
        }
    }
    cout << result << endl;
    return 0;
}