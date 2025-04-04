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
#define out(a, n)                         \
    fr(ll, 0, n) { cout << a[i] << " "; } \
    cout << endl;
#define X ct('X')
#define sort(a) sort(a.begin(), a.end());
#define vin(a, n)    \
    vector<ll> a(n); \
    in(a, n);
const int MOD = 1e9 + 7;

using namespace std;

void solve()
{
    // Your code here
    int n, x;
    cin >> n >> x;
    vin(c, n);
    vector<int> dp(x + 1);
    vector<int> vis(x + 1, 0);
    dp[0] = 0;
    vis[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        dp[i] = INT32_MAX;
        for (auto k : c)
        {
            if (i - k >= 0 && vis[i - k] == 1)
                dp[i] = min(dp[i - k] + 1, dp[i]);
        }
        if (dp[i] != INT32_MAX)
        {
            vis[i] = 1;
        }
    }
    if(dp[x]==INT32_MAX)
    {
        ct(-1);
        return;
    }
    ct(dp[x]);
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