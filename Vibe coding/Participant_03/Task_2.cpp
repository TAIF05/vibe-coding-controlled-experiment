#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    if (!(cin >> n >> m))
        return 0;
    vector<int> numberOfTeams(m);
    for (int i = 0; i < m; ++i)
        cin >> numberOfTeams[i];

    vector<int> selected(m, 0);
    int remaining = n;
    while (remaining > 0)
    {
        bool anyTaken = false;
        for (int i = 0; i < m && remaining > 0; ++i)
        {
            if (numberOfTeams[i] > 0)
            {
                numberOfTeams[i]--;
                selected[i]++;
                remaining--;
                anyTaken = true;
            }
        }
        if (!anyTaken)
            break;
    }
    for (int i = 0; i < m; ++i)
        cout << selected[i] << '\n';

    return 0;
}