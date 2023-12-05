#include<bits/stdc++.h>
using namespace std;

class disjointSet
{

    vector<int> rank, parent;

    public:

    disjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }


    int findParent(int node)
    {
        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ul_pu = parent[u];
        int ul_pv = parent[v];

        if(ul_pu == ul_pv) return;

        if(rank[ul_pu] > rank[ul_pv])
        {
            parent[ul_pv] = ul_pu;
        }
        else if(rank[ul_pu] < rank[ul_pv])
        {
            parent[ul_pu] = ul_pv;
        }
        else{
            parent[ul_pu] = ul_pv;
            rank[ul_pv]++;
        }
    }

};

int main()
{

    disjointSet ds(7);

    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.findParent(5) == ds.findParent(6)) cout<<"Same Component"<<endl;
    else  cout<<"Not Same Component"<<endl;

    ds.unionByRank(3,7);

}