#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int teams[100];
    int accepted[100];

    for (int i = 0; i < m; i++) {
        cin >> teams[i];
        accepted[i] = 0;
    }

    int remaining = n;
    int round = 0;

    // Accept teams in rounds
    while (true) {
        bool anyAccepted = false;

        for (int i = 0; i < m; i++) {
            if (teams[i] > round && remaining > 0) {
                accepted[i]++;
                remaining--;
                anyAccepted = true;
            }
        }

        if (!anyAccepted || remaining == 0)
            break;

        round++;
    }

    // Extra spots (if any)
    for (int i = 0; i < m && remaining > 0; i++) {
        if (accepted[i] < teams[i]) {
            accepted[i]++;
            remaining--;
        }
    }

    // Output result
    for (int i = 0; i < m; i++) {
        cout << accepted[i] << endl;
    }

    return 0;
}
