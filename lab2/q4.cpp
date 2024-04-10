//rahisenpai's implementation/code
#include <bits/stdc++.h>
using namespace std;
#define int long long

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto __untie_cin = std::cin.tie(nullptr);
auto __untie_cout = std::cout.tie(nullptr);
auto __unsync_ios_stdio = std::ios_base::sync_with_stdio(false);

void dijkstra(const vector<vector<pair<int,int>>>& adj, const int src, vector<int>& dist) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pair<int,int> cur_min;
    int u,v,w,d;
    //src vertex base case
    dist[src] = 0;
    pq.emplace(0,src);

    while(!pq.empty()) {
        cur_min = pq.top();
        pq.pop();
        d = cur_min.first;
        u = cur_min.second;

        if(d > dist[u]) continue;

        for(auto i : adj[u]) {
            v = i.second;
            w = i.first;
            if(dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

signed main() {
    //initialize variables, take input and create data for reverse graph simultaneously
    int n,m,u,v,w;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(2*n+1); //1 to n normal graph, n+1 to 2n reverse graph

    while(m--) {
        cin>>u>>v>>w;
        adj[u].emplace_back(w,v);
        adj[v+n].emplace_back(w,u+n); //u+n,v+n corresponds to u,v resp
    }

    for(int i=1; i<=n; i++) {
        adj[i].emplace_back(0,i+n); //dist bw u and u+n is 0
    }

    vector<int>dist(2*n+1, LLONG_MAX);
    dijkstra(adj, 1, dist);

    for(int i=2; i<=n; i++) {
        if(dist[i+n]==LLONG_MAX) cout<<"-1 ";
        else cout<<dist[i+n]<<" ";
    }
    return 0;
}