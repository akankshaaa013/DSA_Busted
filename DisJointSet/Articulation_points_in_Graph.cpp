#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[],
         vector<int> &low, vector<int> &TimeOfInsertion, vector<int> &mark)
{

    vis[node] = 1;
    TimeOfInsertion[node] = low[node] = timer;
    timer++;
    int child = 0;
    for (auto i : adj[node])
    {
        if (i == parent)
            continue;
        if (!vis[i])
        {
            dfs(i, node, vis, adj, low, TimeOfInsertion, mark);
            low[node] = min(low[node], low[i]);
            if (low[i] >= TimeOfInsertion[node] && parent != -1)
                mark[node] = 1;
            child++;
        }
        else
        {
            low[node] = min(low[node], TimeOfInsertion[i]);
        }
    }
    if (child > 1 && parent == -1)
        mark[node] = 1;
}

vector<int> articulation_point(int v, vector<int> adj[])
{
    vector<int> vis(v, 0);
    vector<int> low(v);
    vector<int> TimeOfInsertion(v);
    vector<int> mark(v, 0), ans;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, adj, low, TimeOfInsertion, mark);
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (mark[i])
            ans.push_back(i);
    }

    if (ans.size() == 0)
        return {-1};

    return ans;
}

int main()
{

    int n, m;

    cout << "Enter the no. of vertices & edges respectively : ";
    cin >> n >> m;

    vector<int> adj[n];

    vector<pair<int, int>> edges;

    cout << "Enter the edge pairs (0-based edges): ";

    while (m--)
    {
        int x, y;
        cin >> x >> y;

        edges.push_back({x, y});
    }

    for (auto it : edges)
    {
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }

    vector<int> ans = articulation_point(n, adj);

    for (auto it : ans)
        cout << it << "  ";
}