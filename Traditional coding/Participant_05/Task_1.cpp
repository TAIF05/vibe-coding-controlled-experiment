#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int smallestNonNeg = -1;

    int operations[4] = { a + b, a - b, a * b, 0 };
    int count = 3;

    if (b != 0 && a % b == 0) {
        operations[3] = a / b;
        count = 4;
    }

    for (int i = 0; i < count; i++) {
        int x = operations[i];

        int result[4] = { x + c, x - c, x * c, 0 };
        int count2 = 3;
        if (c != 0 && x % c == 0) {
            result[3] = x / c;
            count2 = 4;
        }

        for (int i = 0; i < count2; i++) {
            int y = result[i];
            if (y >= 0) {
                if (smallestNonNeg == -1 || y < smallestNonNeg) {
                    smallestNonNeg = y;
                }
            }
        }
    }

    cout << smallestNonNeg << endl;
}

