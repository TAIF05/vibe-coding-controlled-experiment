#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

// Generate all possible values by flipping 6 <-> 9
void generate(string s, int idx, string current, vector<long long> &values) {
    if (idx == s.size()) {
        values.push_back(stoll(current));
        return;
    }

    if (s[idx] == '6') {
        generate(s, idx + 1, current + '6', values);
        generate(s, idx + 1, current + '9', values);
    } 
    else if (s[idx] == '9') {
        generate(s, idx + 1, current + '9', values);
        generate(s, idx + 1, current + '6', values);
    } 
    else {
        generate(s, idx + 1, current + s[idx], values);
    }
}

int main() {
    int n;
    cin >> n;

    vector<long long> result;
    long long last = -1;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        vector<long long> candidates;
        generate(s, 0, "", candidates);

        sort(candidates.begin(), candidates.end());

        bool found = false;
        for (long long val : candidates) {
            if (val >= last) {
                result.push_back(val);
                last = val;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "impossible\n";
            return 0;
        }
    }

    cout << "possible\n";
    for (long long x : result)
        cout << x << "\n";

    return 0;
}

