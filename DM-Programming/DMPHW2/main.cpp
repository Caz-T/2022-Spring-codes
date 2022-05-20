#include <iostream>
#include <vector>
#define maxint 0x3f3f3f3f
using namespace std;

vector<int> p, q, r;
int node_count, side_count;

class Troute
{
public:
    vector<int> route;
    int length = 0;
};
vector<Troute> routes;
ostream& operator<<(ostream& out, Troute& rt)
{
    if (rt.route.empty()) out << "NO PATH";
    else
    {
        out << '[';
        for (int i = rt.route.size() - 1; i >= 0; i--)
        {
            if (i != rt.route.size() - 1) out << "->";
            out << rt.route[i];
        }
        out << ' ' << rt.length << ']';
    }
    out << endl;
    return out;
}

int main()
{
    cin >> node_count >> side_count;
    int temp, i;
    i = node_count + 1;
    while (i--)
    {
        cin >> temp;
        p.emplace_back(temp);
    }
    i = side_count;
    while (i--)
    {
        cin >> temp;
        q.emplace_back(temp);
    }
    i = side_count;
    while (i--)
    {
        cin >> temp;
        r.emplace_back(temp);
    }
    cin >> i;
    int start, end;
    while (i--)
    {
        cin >> start >> end;
        int j;
        vector<bool> flag;
        vector<int> pi;
        vector<int> prec;
        for (j = 0; j < node_count; j++)
        {
            flag.emplace_back(true);
            pi.emplace_back(maxint);
            prec.emplace_back(-1);
        }
        flag[start] = false;
        pi[start] = 0;
        for (j = p[start]; j < p[start + 1]; j++)
        {
            pi[q[j]] = r[j];
            prec[q[j]] = start;
        }
        while (true)
        {
            int minpi = maxint, nextnode;
            for (j = 0; j < node_count; j++)
            {
                if (flag[j] and pi[j] < minpi)
                {
                    nextnode = j;
                    minpi = pi[j];
                }
            }
            if (nextnode == end or minpi == maxint) break;
            bool toexit = true;
            for (bool tempbool : flag)
                if (tempbool)
                {
                    toexit = false;
                    break;
                }
            if (toexit) break;
            else flag[nextnode] = false;
            for (j = p[nextnode]; j < p[nextnode + 1]; j++)
            {
                if (flag[q[j]])
                {
                    if (pi[q[j]] > pi[nextnode] + r[j])
                    {
                        prec[q[j]] = nextnode;
                        pi[q[j]] = pi[nextnode] + r[j];
                    }
                }
            }
        }
        Troute newroute;
        if (pi[end] != maxint)
        {
            newroute.length = pi[end];
            int curr = end;
            while (curr != start)
            {
                newroute.route.emplace_back(curr);
                curr = prec[curr];
            }
            newroute.route.emplace_back(start);
        }
        routes.emplace_back(newroute);
    }
    for (Troute rt : routes) cout << rt;
    return 0;
}
