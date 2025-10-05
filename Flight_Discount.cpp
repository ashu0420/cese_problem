#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define li long
#define cn(n) cin >> n
#define py cout << "YES\n"
#define pn cout << "NO\n"
#define ct(c) cout << c << "\n"
#define fr(dt, a, b) for (dt i = a; i < b; i++)
#define in(a, n) \
    fr(int, 0, n) { cn(a[i]); }
#define in1(a, n) \
    fr(int, 1, n + 1) { cn(a[i]); }
#define out(a, n)                          \
    fr(int, 0, n) { cout << a[i] << " "; } \
    cout << "\n";
#define out1(a, n)                             \
    fr(int, 1, n + 1) { cout << a[i] << " "; } \
    cout << "\n";
#define X ct('X')
#define srt(a) sort(a.begin(), a.end());
#define rev(a) reverse(a.begin(), a.end());
#define vin(a, n)     \
    vector<int> a(n); \
    in(a, n);
#define vin1(a, n)        \
    vector<int> a(n + 1); \
    in1(a, n);
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int mod_pow(int x, int y)
{
    int result = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            result = (result * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return result;
}

int modular_inverse(int denom)
{
    return mod_pow(denom, MOD - 2);
}

void solve()
{
    // Your code here
    int n;
    int m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    vector<vector<pair<int, int>>> adj(n + 1), r_adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        r_adj[v].push_back({u, w});
        edges[i] = {u, v, w};
    }
    vector<int> dis1(n + 1, INF);
    vector<int> disN(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);
    dis1[1] = 0;
    while (!pq.empty())
    {
        auto [w, v] = pq.top();
        pq.pop();
        if (dis1[v] < w)
        {
            continue;
        }
        // dis1[v] = w;
        for (auto [child, d] : adj[v])
        {
            if (dis1[child] > dis1[v] + d)
            {
                dis1[child] = dis1[v] + d;
                pq.emplace(dis1[child], child);
            }
        }
    }
    // pq.();
    pq.emplace(0, n);
    disN[n] = 0;
    while (!pq.empty())
    {
        auto [w, v] = pq.top();
        pq.pop();
        if (disN[v] < w)
        {
            continue;
        }
        // disN[v] = w;
        for (auto [child, d] : r_adj[v])
        {
            if (disN[child] > disN[v] + d)
            {
                disN[child] = disN[v] + d;
                pq.emplace(disN[child], child);
            }
        }
    }
    // out1(dis1,n);
    // out1(disN,n);
    int ans = INF;
    for (auto [u, v, w] : edges)
    {
        ans = min(ans, dis1[u] + w / 2 + disN[v]);
    }
    ct(ans);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout.setf(ios::fixed);

    solve();
    return 0;
}