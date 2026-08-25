#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b, c;
    cin >> a >> b >> c;
    
    long long minVal = LLONG_MAX;
    bool found = false;
    
    // Try all 16 combinations of two operators
    // Operators: 0=+, 1=-, 2=*, 3=/
    for (int op1 = 0; op1 < 4; op1++) {
        for (int op2 = 0; op2 < 4; op2++) {
            long long result = 0;
            bool valid = true;
            
            // First operation: a op1 b (left-to-right)
            if (op1 == 0) {  // +
                result = a + b;
            } else if (op1 == 1) {  // -
                result = a - b;
            } else if (op1 == 2) {  // *
                result = a * b;
            } else if (op1 == 3) {  // /
                if (b != 0 && a % b == 0) {
                    result = a / b;
                } else {
                    valid = false;
                }
            }
            
            if (!valid) continue;
            
            // Second operation: result op2 c (left-to-right)
            if (op2 == 0) {  // +
                result = result + c;
            } else if (op2 == 1) {  // -
                result = result - c;
            } else if (op2 == 2) {  // *
                result = result * c;
            } else if (op2 == 3) {  // /
                if (c != 0 && result % c == 0) {
                    result = result / c;
                } else {
                    valid = false;
                }
            }
            
            if (!valid) continue;
            
            // Only consider non-negative results
            if (result >= 0) {
                found = true;
                minVal = min(minVal, result);
            }
        }
    }
    
    cout << minVal << endl;
    
    return 0;
}
