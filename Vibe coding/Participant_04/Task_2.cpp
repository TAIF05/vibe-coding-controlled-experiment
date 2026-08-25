#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> teams(m);
    vector<int> accepted(m, 0);

    for (int i = 0; i < m; i++) {
        cin >> teams[i];
    }

    int remaining = n;
    int wave = 1;

    // Wave-based allocation
    while (true) {
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (teams[i] >= wave)
                count++;
        }

        if (count == 0 || remaining < count)
            break;

        for (int i = 0; i < m; i++) {
            if (teams[i] >= wave) {
                accepted[i]++;
                remaining--;
            }
        }
        wave++;
    }

    // Distribute remaining spots one by one
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

