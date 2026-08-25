#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

// Helper function to perform operations
// Returns a pair: {result, is_valid}
// is_valid is false if division is impossible (by zero or non-integer result)
pair<int, bool> apply_op(int a, int b, char op)
{
    if (op == '+')
        return {a + b, true};
    if (op == '-')
        return {a - b, true};
    if (op == '*')
        return {a * b, true};
    if (op == '/')
    {
        // Check for division by zero AND non-integer division
        if (b != 0 && a % b == 0)
        {
            return {a / b, true};
        }
        return {0, false}; // Invalid division
    }
    return {0, false};
}

int main()
{
    int a, b, c;

    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> a >> b >> c)
    {
        vector<char> ops = {'+', '-', '*', '/'};
        int min_result = INT_MAX;
        bool found_solution = false;

        // Iterate through all permutations of two operators
        // Logic: ((a op1 b) op2 c)
        for (char op1 : ops)
        {
            for (char op2 : ops)
            {

                // Step 1: First operation
                pair<int, bool> res1 = apply_op(a, b, op1);

                // If first step is invalid (bad division), skip
                if (!res1.second)
                    continue;

                // Step 2: Second operation
                pair<int, bool> res2 = apply_op(res1.first, c, op2);

                // If second step is invalid, skip
                if (!res2.second)
                    continue;

                // Constraint Check: Final result must be non-negative (>= 0)
                if (res2.first >= 0)
                {
                    if (res2.first < min_result)
                    {
                        min_result = res2.first;
                        found_solution = true;
                    }
                }
            }
        }

        if (found_solution)
        {
            cout << min_result << endl;
        }
    }

    return 0;
}