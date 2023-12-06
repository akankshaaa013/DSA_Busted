#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
    vector<int> rank, parent, size;

public:
    disjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ul_pu = parent[u];
        int ul_pv = parent[v];

        if (ul_pu == ul_pv)
            return;

        if (rank[ul_pu] > rank[ul_pv])
        {
            parent[ul_pv] = ul_pu;
        }
        else if (rank[ul_pu] < rank[ul_pv])
        {
            parent[ul_pu] = ul_pv;
        }
        else
        {
            parent[ul_pu] = ul_pv;
            rank[ul_pv]++;
        }
    }

    // Union by Size
    void unionBySize(int u, int v)
    {
        int ul_pu = parent[u];
        int ul_pv = parent[v];

        if (ul_pu == ul_pv)
            return;

        if (size[ul_pu] > size[ul_pv])
        {
            parent[ul_pv] = ul_pu;
            size[ul_pu] += size[ul_pv];
        }
        else
        {
            parent[ul_pu] = ul_pv;
            size[ul_pv] += size[ul_pu];
        }
    }
};

int kruskalMST(int n, vector<vector<int>> &edges, vector<pair<int, int>> &MST)
{
    vector<pair<int, pair<int, int>>> adj;

    for (auto it : edges)
    {
        adj.push_back({it[2], {it[0], it[1]}});
    }

    sort(adj.begin(), adj.end());

    int MSTcost = 0;

    disjointSet d(n);

    for (auto it : adj)
    {
        int u = it.second.first;
        int v = it.second.second;

        if (d.findParent(u) != d.findParent(v))
        {
            MSTcost += it.first;
            MST.push_back({u,v});
            d.unionBySize(u, v);
        }
    }

    return MSTcost;
}

int main()
{

    vector<vector<int>> edges;
    vector<pair<int, int>> MST;

    int n, m;

    cout << "Enter the no. of vertices & edges : ";
    cin >> n >> m;

    while (m--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back({u, v, wt});
    }

    cout << "Cost of Minimum Spanning Tree is : " << kruskalMST(n, edges, MST);

    cout << endl
         << "Edges in connected component : " << endl;

    for (auto it : MST)
    {
        cout << it.first << " " << it.second << "   ";
    }
}