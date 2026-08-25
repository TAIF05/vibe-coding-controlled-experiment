#include <bits/stdc++.h>
using namespace std;

int cmpNum(const string &a, const string &b) {
    if (a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
    if (a == b) return 0;
    return a < b ? -1 : 1;
}

string replaceMin(const string &s) {
    string t = s;
    for (char &c : t) if (c == '9') c = '6';
    return t;
}
string replaceMax(const string &s) {
    string t = s;
    for (char &c : t) if (c == '6') c = '9';
    return t;
}

// Build minimal achievable string of same length >= prev (prev length equals L)
// allowed[i] contains sorted allowed chars for position i
// Returns empty string if impossible
string minimal_ge_same_len(const vector<string> &allowed, const string &prev) {
    int L = (int)allowed.size();
    string res(L, '0');
    // First try greedy, copying prev where possible
    for (int i = 0; i < L; ++i) {
        const string &al = allowed[i];
        char p = prev[i];
        bool has_equal = binary_search(al.begin(), al.end(), p);
        if (has_equal) {
            res[i] = p;
            continue;
        }
        // find smallest digit in al > p
        auto it = upper_bound(al.begin(), al.end(), p);
        if (it != al.end()) {
            res[i] = *it;
            // fill rest with minimal allowed
            for (int k = i+1; k < L; ++k) res[k] = allowed[k][0];
            return res;
        }
        // need to backtrack
        int j = i-1;
        while (j >= 0) {
            // at positions < i, res[j] == prev[j]
            const string &alj = allowed[j];
            char prevj = prev[j];
            auto it2 = upper_bound(alj.begin(), alj.end(), prevj);
            if (it2 != alj.end()) {
                // we can increase at j
                res[j] = *it2;
                for (int k = j+1; k < L; ++k) res[k] = allowed[k][0];
                return res;
            }
            --j;
        }
        // no backtrack possible
        return string();
    }
    // If we copied all digits and didn't return, res == prev and is valid
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<string> mn(n), mx(n);
    vector<vector<string>> allowed(n);
    for (int i = 0; i < n; ++i) {
        mn[i] = replaceMin(a[i]);
        mx[i] = replaceMax(a[i]);
        int L = (int)a[i].size();
        allowed[i].resize(L);
        for (int j = 0; j < L; ++j) {
            char c = a[i][j];
            if (c == '6' || c == '9') {
                string s = "69";
                sort(s.begin(), s.end());
                allowed[i][j] = s;
            } else {
                string s(1, c);
                allowed[i][j] = s;
            }
        }
    }

    vector<string> chosen(n);
    string prev = ""; // empty means no previous; treat length 0
    for (int i = 0; i < n; ++i) {
        // quick impossible check: if mx[i] < prev then impossible
        if (!prev.empty() && cmpNum(mx[i], prev) < 0) {
            cout << "impossible\n";
            return 0;
        }
        // if prev empty -> pick minimal
        if (prev.empty()) {
            chosen[i] = mn[i];
            prev = chosen[i];
            continue;
        }
        int Li = (int)a[i].size();
        int Lprev = (int)prev.size();
        if (Li > Lprev) {
            // any Li-digit number >= any smaller-digit number
            chosen[i] = mn[i];
            prev = chosen[i];
            continue;
        }
        if (Li < Lprev) {
            // even mx < prev would have been caught earlier; but be safe
            if (cmpNum(mx[i], prev) < 0) {
                cout << "impossible\n";
                return 0;
            } else {
                // Li < Lprev but mx >= prev shouldn't happen numerically
                cout << "impossible\n";
                return 0;
            }
        }
        // same length
        // prepare allowed strings sorted (they already are)
        vector<string> al(Li);
        for (int j = 0; j < Li; ++j) al[j] = allowed[i][j];
        string res = minimal_ge_same_len(al, prev);
        if (res.empty()) {
            cout << "impossible\n";
            return 0;
        }
        chosen[i] = res;
        prev = res;
    }

    cout << "possible\n";
    for (int i = 0; i < n; ++i) cout << chosen[i] << '\n';
    return 0;
}
