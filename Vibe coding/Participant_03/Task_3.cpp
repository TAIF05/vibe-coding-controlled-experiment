#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Compare two non-negative integers given as strings (no leading + sign).
// Numeric order: shorter length => smaller, if same length => lex compare.
bool lessNum(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}
bool leqNum(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a <= b;
}

// For one digit, return its minimum and maximum possible after optional 6/9 flip.
static inline pair<char, char> digitRange(char d) {
    if (d == '6') return { '6','9' };
    if (d == '9') return { '6','9' };
    return { d,d };
}

// Given original string s, produce the smallest string t achievable by flipping any subset of 6/9
// such that t >= prev (numeric). If impossible, return "".
string smallestGE(const string& s, const string& prev) {
    // If prev is empty, just return the minimum possible version of s (replace any 9 with 6).
    if (prev.empty()) {
        string t = s;
        for (char& c : t) {
            if (c == '9') c = '6';
        }
        return t;
    }

    // Numeric constraint: if lengths differ, decide quickly.
    if (s.size() < prev.size()) return "";             // cannot reach a bigger length
    if (s.size() > prev.size()) {                      // any value of this length is >= prev
        string t = s;
        for (char& c : t) if (c == '9') c = '6';
        return t;
    }

    // Same length: we need lexicographically >= prev (since same length => numeric order = lex).
    int n = (int)s.size();
    string t(n, '?');

    bool greater = false;

    // stack of positions where we chose the smaller option but can increase later
    vector<int> canBump;

    for (int i = 0; i < n; i++) {
        auto [mn, mx] = digitRange(s[i]);

        if (greater) {
            t[i] = mn; // already greater -> take minimum everywhere
            continue;
        }

        char need = prev[i];

        if (mn > need) {
            t[i] = mn;
            greater = true;
        }
        else if (mn == need) {
            t[i] = mn;
            if (mn != mx) canBump.push_back(i);
        }
        else { // mn < need
            if (mx >= need) {
                t[i] = mx;
                if (mx > need) greater = true;
                // if mx == need, still equal; but here mx can be ==need only if need is 6 or 9
            }
            else {
                // even the max is too small -> backtrack to bump an earlier position
                bool done = false;
                while (!canBump.empty()) {
                    int j = canBump.back();
                    canBump.pop_back();

                    // bump position j to its max
                    auto [jmn, jmx] = digitRange(s[j]);
                    t[j] = jmx;

                    // After bumping, fill everything after j with minimum
                    for (int k = j + 1; k < n; k++) {
                        auto [kmn, kmx] = digitRange(s[k]);
                        t[k] = kmn;
                    }

                    done = true;
                    greater = true; // because at j we increased relative to prev (we had matched prev up to j)
                    break;
                }
                if (!done) return ""; // no place to bump -> impossible

                // We already filled the tail, so we can return now.
                return t;
            }
        }
    }

    // If we built t without early return, it's valid as long as t >= prev (lex).
    if (t >= prev) return t;
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<string> result;
    string prev = "";

    for (int i = 0; i < n; i++) {
        string chosen = smallestGE(nums[i], prev);
        if (chosen.empty()) {
            cout << "impossible\n";
            return 0;
        }
        result.push_back(chosen);
        prev = chosen;
    }

    cout << "possible\n";
    for (auto& x : result) cout << x << "\n";
    return 0;
}
