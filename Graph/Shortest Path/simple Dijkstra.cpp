/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    const int INF = 1e9;
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> adj[N + 1];
    for (int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w}); // if undirected add this this .
    }
    vector<int> dis(N + 1, INF);
    vector<bool> vis(N + 1, 0);
    dis[1] = 0;
    priority_queue<pair<int, int>> Q;
    Q.push({0, 1});
    while (!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto b : adj[u]){
            int v = b.first, w = b.second;
            if (dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                Q.push({-dis[v], v});
            }
        }
    }
    for (int i = 2; i <= N; i++)
        cout << dis[i] << " \n"[i == N];
}
