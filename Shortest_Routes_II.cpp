#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ct(c) cout << c << "\n"

const ll INF = 1e18;

void solve()
{
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));
    vector<bool> computed(n + 1, false);
    // int t = n;
    for(int t=1;t<=n;t++)
    {
        // int st, en;
        // cin >> st >> en;

        if (!computed[t])
        {
            // Run Dijkstra from st
            vector<ll> dis(n + 1, INF);
            dis[t] = 0;
            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
            pq.push({0, t});

            while (!pq.empty())
            {
                auto [d, v] = pq.top();
                pq.pop();
                if (dis[v] < d)
                    continue;

                for (auto i : adj[v])
                {
                    int to = i.first, w = i.second;
                    if (dis[to] > d + w)
                    {
                        dis[to] = d + w;
                        pq.push({dis[to], to});
                    }
                }
            }

            // Save distances in dp
            for (int i = 1; i <= n; i++)
                dp[t][i] = dis[i];

            computed[t] = true;
        }

        // if (dp[st][en] == INF)
        //     ct(-1);
        // else
        //     ct(dp[st][en]);
    }
    while (q--)
    {
        int st, en;
        cin >> st >> en;
        if (dp[st][en] == INF)
            ct(-1);
        else
            ct(dp[st][en]);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
