#include <iostream>
using namespace std;

bool calc(int num1, int num2, char oper, int& result) {
    if (oper == '+') result = num1 + num2;
    else if (oper == '-') result = num1 - num2;
    else if (oper == '*') result = num1 * num2;
    else {
        if (num2 == 0 || num1 % num2 != 0) return false;
        result = num1 / num2;
    }
    return true;
}

int main()
{
    int N1, N2, N3;
    cin >> N1 >> N2 >> N3;
    char op[4] = { '+', '-', '*', '/' };
    int answer = 0;
    bool found = false;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int FirstRes, FinallRes;
            if (!calc(N1, N2, op[i], FirstRes)) continue;
            if (!calc(FirstRes, N3, op[j], FinallRes)) continue;
            if (FinallRes < 0) continue;
            if (!found || FinallRes < answer) {
                answer = FinallRes;
                found = true;
            }
        }
    }

    if (!found) answer = 0;
    cout << answer << endl;

    return 0;
}
