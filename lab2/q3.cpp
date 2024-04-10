//rahisenpai's implementation/code
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto __untie_cin = std::cin.tie(nullptr);
auto __untie_cout = std::cout.tie(nullptr);
auto __unsync_ios_stdio = std::ios_base::sync_with_stdio(false);

void DFS(const int v, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& longest_path) {
    visited[v] = true;//mark as visited

    for(int i : adj[v]) {
        if(!visited[i]) DFS(i, adj, visited, longest_path);
        longest_path[v] = max(longest_path[v], 1+longest_path[i]);//update path length
    }
}

int main() {
    //initialize vars, take input using adjacency list
    int n,m,x,y,res=0;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> numEdge (n+1,0);//stores number of edges to/from a vertex
    while(m--) {
        cin>>x>>y;
        //convert the graph to a directed graph with edges from upper vertex to lower vertex
        if(x>y) adj[x].emplace_back(y);
        else adj[y].emplace_back(x);
        numEdge[x]++; numEdge[y]++;
    }

    //find connected components using dfs, and use dp to find longest path from vertices
    vector<bool> visited(n+1, false);
    vector<int> longest_path(n+1,1);//initializing as 1 because i need num of vertices in the path/face
    for(int v=1; v<=n; v++) {
        if(!visited[v]) {
            DFS(v, adj, visited, longest_path);
        }
    }

    //find max beauty from dp array
    for(int i=1; i<=n; i++) {
        res = max(res, longest_path[i]*numEdge[i]);
    }
    cout<<res;
    return 0;
}