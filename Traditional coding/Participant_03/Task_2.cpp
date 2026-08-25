#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cap, school;
    cin >> cap >> school;

    vector<int> teams(school); 
    vector<int> accepted(school, 0);

    for (int i = 0; i < school; i++)
        cin >> teams[i];

    int round = 1; 

    while (cap > 0) {
        bool added = false;

        for (int i = 0; i < school; i++) {
            if (teams[i] >= round) {
                accepted[i]++;
                cap--;
                added = true;

                if (cap == 0)
                    break;
            }
        }

        if (!added)
            break;

        round++;
    }
    for (int i = 0; i < school; i++)
        cout << accepted[i] << endl;

    return 0;
}