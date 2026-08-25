#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int teams[101];
    int accepted[101] = { 0 };

    for (int i = 0; i < m; i++) {
        cin >> teams[i];
    }

    int remaining = n;
    bool added = true;

    while (remaining > 0 && added) {
        added = false;
        for (int i = 0; i < m && remaining > 0; i++) {
            if (accepted[i] < teams[i]) {
                accepted[i]++;
                remaining--;
                added = true;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cout << accepted[i] << endl;
    }

    return 0;
}
