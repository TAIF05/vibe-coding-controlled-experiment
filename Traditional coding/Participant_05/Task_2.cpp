#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int teams[105];
    int accept[105];

    for (int i = 0; i < m; i++) {
        cin >> teams[i];
        accept[i] = 0;
    }

    while (n > 0) {
        bool distribution = false;

        for (int i = 0; i < m; i++) {
            if (accept[i] < teams[i] && n > 0) {
                accept[i]++;
                n--;
                distribution = true;
            }
        }

        if (distribution == false) {
            break;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << accept[i] << endl;
    }

}
