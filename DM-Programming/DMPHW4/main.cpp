#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;
#define INF 0x3f3f3f3f

long long connect[105][105];

int main()
{
    int n;
    int i, j, k;
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            connect[i][j] = INF;
    int e;
    cin >> e;
    string str_sidestart, str_connect, str_weight;
    getchar();
    getline(cin, str_sidestart);
    getline(cin, str_connect);
    getline(cin, str_weight);
    istringstream ss(str_sidestart), cn(str_connect), w(str_weight);
    int prev, temp;
    ss >> prev;
    for (i = 0; i < n; i++)
    {
        ss >> temp;
        temp -= prev;
        prev += temp;
        while (temp--)
        {
            cn >> j;
            w >> k;
            connect[i][j] = k;
            connect[j][i] = k;
        }
    }
    set<int> in_tree;
    long long tree_weight = 0;
    long long mindist[105], pre[105];
    for (i = 0; i < n; i++)
    {
        mindist[i] = INF;
        pre[i] = -1;
    }
    in_tree.emplace(0);
    for (i = 1; i < n; i++)
    {
        if (connect[0][i] < INF)
        {
            mindist[i] = connect[0][i];
            pre[i] = 0;
        }
    }
    int next;
    while (in_tree.size() < n)
    {
        long long min = INF;
        for (i = 0; i < n; i++)
        {
            if (not in_tree.count(i) and mindist[i] < min)
            {
                min = mindist[i];
                next = i;
            }
        }
        in_tree.emplace(next);
        tree_weight += min;
        cout << "[" << pre[next] << "->" << next << "]";
        for (i = 0; i < n; i++)
            if (not in_tree.count(i) and connect[next][i] < mindist[i])
            {
                mindist[i] = connect[next][i];
                pre[i] = next;
            }
    }
    cout << " " << tree_weight << endl;
    return 0;
}
