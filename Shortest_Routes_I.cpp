#include <bits/stdc++.h>
#define ll long long
#define li long
#define cn(n) cin >> n
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define ct(c) cout << c << endl
#define fr(dt, a, b) for (dt i = a; i < b; i++)
#define in(a, n) \
    fr(ll, 0, n) { cn(a[i]); }
#define in1(a, n) \
    fr(ll, 1, n + 1) { cn(a[i]); }
#define out(a, n)                         \
    fr(ll, 0, n) { cout << a[i] << " "; } \
    cout << endl;
#define out1(a, n)                            \
    fr(ll, 1, n + 1) { cout << a[i] << " "; } \
    cout << endl;
#define X ct('X')
#define srt(a) sort(a.begin(), a.end());
#define rev(a) reverse(a.begin(), a.end());
#define vin(a, n)    \
    vector<ll> a(n); \
    in(a, n);
#define vin1(a, n)       \
    vector<ll> a(n + 1); \
    in1(a, n);
const int MOD = 1e9 + 7;

using namespace std;

ll mod_pow(ll x, ll y)
{
    ll result = 1;
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

ll modular_inverse(ll denom)
{
    return mod_pow(denom, MOD - 2);
}

void solve()
{
    // Your code here
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    vector<ll> dis(n + 1, LONG_LONG_MAX);

    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> q;
    for (auto i : adj[1])
    {

        q.push(make_tuple(i.first, 1, i.second));
    }
    dis[1] = 0;
    vector<int> vis(n + 1, 0);
    vis[1] = 1;
    while (!q.empty())
    {
        auto [w, u, v] = q.top();
        q.pop();
        if (dis[v] < w)
            continue;
        else
            dis[v] = w;
        // dis[v] = min( w, dis[v]);
        // vis[v] = 1;
        for (auto i : adj[v])
        {
            // if (vis[i.second] == 0)
            if (dis[i.second] > dis[v] + i.first)
            {
                dis[i.second] = dis[v] + i.first;
                q.push({dis[i.second], v, i.second});
            }
        }
    }
    out1(dis, n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout.setf(ios::fixed);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}