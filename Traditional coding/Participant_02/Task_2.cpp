#include <iostream>
using namespace std;

int main() {
    int capacity, schools;
    cin >> capacity >> schools;

    int teams[100];
    int accepted[100] = { 0 };

    for (int i = 0; i < schools; i++)
        cin >> teams[i];

    int remaining = capacity;
    int stage = 1;

    while (remaining > 0) {
        bool found = false;
        for (int i = 0; i < schools; i++) {
            if (teams[i] >= stage && remaining > 0) {
                accepted[i]++;
                remaining--;
                found = true;
            }
        }
        if (!found) break;
        stage++;
    }

    for (int i = 0; i < schools; i++)
        cout << accepted[i] << endl;

    return 0;
}
