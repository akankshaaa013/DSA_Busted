#include<bits/stdc++.h>
using namespace std;

// T.C -> O(4*alpha) which is as good as a constant. 

class disjointSet
{
    vector<int> rank, parent, size;

    public:

    disjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
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

    // Union by Size
    void unionBySize(int u, int v)
    {
        int ul_pu = parent[u];
        int ul_pv = parent[v];

        if(ul_pu == ul_pv) return;

        if(size[ul_pu] > size[ul_pv])
        {
            parent[ul_pv] = ul_pu;
            size[ul_pu] += size[ul_pv];
        }
        else{
           parent[ul_pu] = ul_pv;
           size[ul_pv] += size[ul_pu]; 
        }
        
    }

};

int main()
{
    disjointSet ds(7);

    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);

    if(ds.findParent(5) == ds.findParent(6)) cout<<"Same Component"<<endl;
    else  cout<<"Not Same Component"<<endl;

    ds.unionBySize(5,6);
    
    if(ds.findParent(5) == ds.findParent(6)) cout<<"Same Component"<<endl;
    else  cout<<"Not Same Component"<<endl;

    ds.unionBySize(3,7);

}