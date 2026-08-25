#include <iostream>
#include <string>
using namespace std;

bool ge(string a, string b) {
    if (b == "") return true;
    if (a.length() != b.length())
        return a.length() > b.length();
    return a >= b;
}

bool lessNum(string a, string b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}

string flip(string s) {
    for (char &c : s) {
        if (c == '6') c = '9';
        else if (c == '9') c = '6';
    }
    return s;
}

int main() {
    int n;
    cin >> n;

    string prev = "";
    string result[10000];

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;

        string f = flip(x);

        bool okX = ge(x, prev);
        bool okF = ge(f, prev);

        if (!okX && !okF) {
            cout << "impossible";
            return 0;
        }

        string chosen;
        if (okX && okF)
            chosen = lessNum(x, f) ? x : f;
        else if (okX)
            chosen = x;
        else
            chosen = f;

        prev = chosen;
        result[i] = chosen;
    }

    cout << "possible\n";
    for (int i = 0; i < n; i++)
        cout << result[i] << "\n";

    return 0;
}
