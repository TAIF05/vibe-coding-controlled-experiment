#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> teams(m), qteams(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> teams[i];
    }
    while (n > 0)
    {
        bool flag = false;
        for (int i = 0; i < m; i++)
        {
            if (teams[i] <= 0)
            {
                continue;
            }
            if (n > 0)
            {
                flag = true;
                teams[i]--;
                n--;
                qteams[i]++;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << qteams[i] << endl;
    }
    return 0;
}