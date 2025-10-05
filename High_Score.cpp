#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    struct Edge { int u, v, w; };
    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].w = -edges[i].w; // negate weights to convert max to min problem
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i < n; i++) {
        for (auto &e : edges) {
            if (dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w)
                dist[e.v] = dist[e.u] + e.w;
        }
    }

    // detect negative cycle (which means positive cycle in original graph)
    vector<int> affected(n + 1, 0);
    for (auto &e : edges) {
        if (dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w)
            affected[e.v] = 1;
    }

    // build adjacency for reachability
    vector<vector<int>> adj(n + 1);
    for (auto &e : edges) adj[e.u].push_back(e.v);

    // BFS from all affected nodes to mark nodes reachable from a cycle
    queue<int> q;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
        if (affected[i]) q.push(i), vis[i] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) vis[v] = 1, q.push(v);
        }
    }

    if (vis[n]) {
        cout << -1 << "\n";
    } else {
        cout << -dist[n] << "\n"; // negate back the result
    }

    return 0;
}
