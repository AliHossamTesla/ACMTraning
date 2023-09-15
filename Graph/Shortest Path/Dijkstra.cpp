/* The blessings of God to the Prophet Muhammad
 * Description: shortest path - using dijkstra's Algorithm
 * by : OWN .
 * Verification : https://codeforces.com/problemset/problem/20/C
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
class dijkstra{
private:
    const int INF = 1e12;
    int N, M, x;
    vector<vector<pair<int, int>>> adj;
    vector<int> sucess;
    vector<bool> vis;
    vector<int> dis;

public:
    dijkstra(int N, int M);
    vector<int> root(int u) const;
    vector<int> getDis() const;
    void readGraph(bool unDirected);
    void Run(int u);
};
dijkstra::dijkstra(int N, int M) : N(N), M(M){
    adj = vector<vector<pair<int, int>>>(N + 1);
    sucess = vector<int>(N + 1, -1);
    vis = vector<bool>(N + 1, 0);
    dis = vector<int>(N + 1, INF);
}
void dijkstra::readGraph(bool unDirected = 0){
    for (int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        if (unDirected)
            adj[v].push_back({u, w});
    }
}
void dijkstra::Run(int u){
    x = u;
    priority_queue<pair<int, int>> Q;
    dis[u] = 0;
    Q.push({0, u});
    while (!Q.empty()){
        int v = Q.top().second;
        Q.pop();
        if (vis[v])
            continue;
        vis[v] = 1;
        for (auto node : adj[v]){
            int son = node.first, w = node.second;
            if (dis[son] > dis[v] + w){
                dis[son] = dis[v] + w;
                sucess[son] = v;
                Q.push({-dis[son], son});
            }
        }
    }
}
vector<int> dijkstra::getDis() const { return dis; }
vector<int> dijkstra::root(int u) const{
    if (dis[u] == INF)
        return {-1};
    vector<int> ans;
    for (; u != x; u = sucess[u])
        ans.push_back(u);
    ans.push_back(x);
    reverse(ans.begin(), ans.end());
    return ans;
}
