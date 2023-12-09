#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st)
{   
    vis[node] = 1;

    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }

    st.push(node);

}

// Step 3 : DFS traversal on individual strongly connected components
void dfs3(int node, vector<int>& vis, vector<int> adjT[])
{
    vis[node] = 1;

    for(auto it : adjT[node])
    {
        if(!vis[it]) dfs3(it, vis, adjT);
    }
}

int kosaraju(int v, vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(v, 0);

    // Step 1 : Sort the edges according to the finishing time using DFS traversal
    for(int i = 0; i < v; i++)
    {
        if(!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    // Step 2 : Reverse the graph
    vector<int> adjT[v];

    for(int i = 0; i < v; i++)
    {
        vis[i] = 0;
        for(auto it : adj[i])
        {
            // i --> it - orignal
            // it --> i - reversed
            adjT[it].push_back(i);
        }
    }

    int scc = 0; // Strongly Connected Components

    while(!st.empty())
    {
        int node = st.top(); 
        st.pop();

        if(!vis[node])
        {
            scc++;
            dfs3(node, vis, adjT);
        }
    }

    return scc;
}

int main()
{

    int n, m;
    
    cout<<"Enter the no. of vertices & edges respectively : ";
    cin>>n>>m;

    vector<int> adj[n];

    vector<pair<int, int>> edges;

    cout<<"Enter the edge pairs (0-based edges): ";

    while(m--)
    {
        int x,y;
        cin>>x>>y;

        edges.push_back({x,y});
    }
    
    for(auto it : edges)
    {
        adj[it.first].push_back(it.second);
    }

    cout<< "No. of Strongly Connected Components are : "<<kosaraju(n, adj);

}