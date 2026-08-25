#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Apply operation safely
bool applyOp(long long a, long long b, char op, long long &result) {
    if (op == '+') {
        result = a + b;
        return true;
    }
    if (op == '-') {
        result = a - b;
        return true;
    }
    if (op == '*') {
        result = a * b;
        return true;
    }
    if (op == '/') {
        if (b != 0 && a % b == 0) {
            result = a / b;
            return true;
        }
        return false; // invalid division
    }
    return false;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    vector<char> ops = {'+', '-', '*', '/'};
    long long answer = LLONG_MAX;

    // Try all operator combinations
    for (char op1 : ops) {
        for (char op2 : ops) {
            long long firstResult;

            // Apply first operation (left-to-right)
            if (!applyOp(a, b, op1, firstResult))
                continue;

            long long finalResult;
            if (!applyOp(firstResult, c, op2, finalResult))
                continue;

            if (finalResult >= 0)
                answer = min(answer, finalResult);
        }
    }

    cout << answer << endl;
    return 0;
}
