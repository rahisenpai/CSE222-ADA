//rahisenpai's implementation/code
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto __untie_cin = std::cin.tie(nullptr);
auto __untie_cout = std::cout.tie(nullptr);
auto __unsync_ios_stdio = std::ios_base::sync_with_stdio(false);

void BFS(const vector<vector<int>>& adj, const int start_vertex, vector<int>& res) {
    //use bfs on every cycle vertex and mark as -1
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    int curr_vertex;

    visited[start_vertex] = true;
    q.push(start_vertex);

    while(!q.empty()) {
        curr_vertex = q.front();
        q.pop();
        for(int v : adj[curr_vertex]) {
            if(!visited[v]) {
                visited[v] = true;
                res[v] = -1;
                q.push(v);
            }
        }
    }
}

void markCycle(const vector<vector<int>>& adj, const int start, int end, vector<int>& res, const vector<int>& parent) {
    while(end != start) {//mark cycle vertices as -1 by backtracking using parent array
        res[end] = -1;
        BFS(adj, end, res);
        end = parent[end];
    }
    res[start] = -1;
    BFS(adj,start, res);
}

void DFS(const int v, const vector<vector<int>>& adj, vector<bool>& path, vector<int>& res, vector<int>& parent) {
    path[v] = true;//mark in path

    for(int i : adj[v]) {
        if(path[i]) {//a vertex is in loop if its neighbor is already in path
            if(i==v) {//if self loop, mark all neighbors with -1
                res[i]=-1;
                BFS(adj, v, res);
            }
            else{//mark the cycle in path as -1
                markCycle(adj, i, v, res, parent);
            }
        }
        else if(res[i]!=-1) {
            res[i]++;
            parent[i] = v;
            DFS(i, adj, path, res, parent);
        }
    }
    path[v] = false;//unmark in path
}

int main() {
    //initialize vars, take input using adjacency list
    vector<vector<int>> adj;
    vector<int> res, parent;
    vector<bool> path;
    int t,n,m,x,y;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        adj.resize(n+1, vector<int>());
        res.resize(n+1, 0);//initially no paths, so 0
        path.resize(n+1, false);
        parent.resize(n+1, 0);
        while(m--) {
            cin>>x>>y;
            adj[x].emplace_back(y);
        }

        res[1] = 1;//base case for path between 1 to 1
        DFS(1, adj, path, res, parent);

        for(int i=1; i<=n; i++) {//print result for each vertex
            if(res[i]<=2) cout<<res[i]<<" ";
            else cout<<"2 ";
        }
        cout<<"\n";
        parent.clear();
        path.clear();
        res.clear();
        adj.clear();
    }
    return 0;
}