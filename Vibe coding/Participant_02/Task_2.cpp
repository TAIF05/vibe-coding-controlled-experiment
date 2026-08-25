#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;

    // MESSAGE 1: Prompt for n and m
    cout << "Enter the Site Capacity (n) and Number of Schools (m): ";
    if (!(cin >> n >> m)) return;

    vector<int> requested(m);
    
    // MESSAGE 2: Prompt for the specific teams
    cout << "Enter the number of teams requested by each of the " << m << " schools:" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> requested[i];
    }

    // --- LOGIC STARTS HERE ---
    vector<int> accepted(m, 0);

    while (n > 0) {
        int schools_needing_spot = 0;
        for (int i = 0; i < m; ++i) {
            if (accepted[i] < requested[i]) {
                schools_needing_spot++;
            }
        }

        if (schools_needing_spot == 0) break;

        if (n >= schools_needing_spot) {
            n -= schools_needing_spot;
            for (int i = 0; i < m; ++i) {
                if (accepted[i] < requested[i]) {
                    accepted[i]++;
                }
            }
        } else {
            for (int i = 0; i < m && n > 0; ++i) {
                if (accepted[i] < requested[i]) {
                    accepted[i]++;
                    n--;
                }
            }
            break;
        }
    }

    // MESSAGE 3: Clear separation for the result
    cout << "\n--- Results (Teams Accepted) ---" << endl;
    for (int i = 0; i < m; ++i) {
        cout << accepted[i] << endl;
    }
}

int main() {
    // Note: I removed the "fast I/O" lines (cin.tie) because 
    // they can sometimes mess up the order of text prompts on the screen.
    solve();
    return 0;
}