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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    vector<string> v(n);
    in(v, n);
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && v[i][j] == '.')
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1; // FIX here
                while (!q.empty())
                {
                    auto [l, r] = q.front();
                    q.pop();
                    for (auto [x, y] : dir)
                    {
                        int nx = l + x, ny = r + y;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                        {
                            if (v[nx][ny] == '.' && vis[nx][ny] == 0)
                            {
                                q.push({nx, ny});
                                vis[nx][ny] = 1; // also mark here when pushing
                            }
                        }
                    }
                }
                cnt++;
            }
        }
    }
    ct(cnt);
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