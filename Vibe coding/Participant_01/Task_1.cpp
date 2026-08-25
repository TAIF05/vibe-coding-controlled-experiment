#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    char ops[4] = {'+', '-', '*', '/'};
    int answer = -1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            int first = 0;
            bool valid = true;

            // First operation: a op1 b
            if (ops[i] == '+')
                first = a + b;
            else if (ops[i] == '-')
                first = a - b;
            else if (ops[i] == '*')
                first = a * b;
            else { // division
                if (b == 0 || a % b != 0)
                    valid = false;
                else
                    first = a / b;
            }

            if (!valid) continue;

            int result = 0;

            // Second operation: first op2 c
            if (ops[j] == '+')
                result = first + c;
            else if (ops[j] == '-')
                result = first - c;
            else if (ops[j] == '*')
                result = first * c;
            else { // division
                if (c == 0 || first % c != 0)
                    valid = false;
                else
                    result = first / c;
            }

            if (!valid) continue;

            if (result >= 0) {
                if (answer == -1 || result < answer)
                    answer = result;
            }
        }
    }

    cout << answer << endl;
    return 0;
}

