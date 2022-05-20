#include <iostream>
#include <vector>
using namespace std;
const int maxnum = 100;

bool been_here[maxnum] = {false};
int p[maxnum] = {0};
int q[maxnum] = {0};
vector<int> roads;
vector<int> pp;
int node_count;
class Troute
{
public:
    vector<int> route;
};
ostream& operator<< (ostream& out, Troute& route)
{
    for (auto & i : route.route)
    {
        if (i != 0) out << "->";
        out << i;
    }
    out << endl;
    return out;
}
vector<Troute> routes;
Troute curr_route;
void dfs(int node)
{
    curr_route.route.emplace_back(node);
    if (node == node_count - 1) routes.emplace_back(curr_route);
    else
    {
        for (int i = pp[node]; i < pp[node + 1]; i++)
        {
            if (!been_here[roads[i]])
            {
                been_here[roads[i]] = true;
                dfs(roads[i]);
                been_here[roads[i]] = false;
            }
        }
    }
    curr_route.route.pop_back();
}
int main()
{
    int e;
    cin >> node_count >> e;
    for (int i = 0; i <= node_count; i++) cin >> p[i];
    int side_count = 0;
    for (int i = 0; i < node_count; i++)
    {
        for (int j = p[i]; j < p[i + 1]; j++) cin >> q[side_count++];
        //sort(q + p[i], q + p[i + 1]);
    }
    pp.emplace_back(0);
    for (int i = 0; i < node_count; i++)
    {
        for (int j = p[i]; j < p[i + 1]; j++)
            if (j == p[i] or q[j] != q[j - 1]) roads.emplace_back(q[j]);
        pp.emplace_back(roads.size());
    }
    been_here[0] = true;
    dfs(0);
    cout << routes.size() << endl;
    for (auto & i : routes) cout << i;
    return 0;
}