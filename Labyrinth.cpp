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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<tuple<int, int, char>> dir = {
        {1, 0, 'D'}, {-1, 0, 'U'}, {0, -1, 'L'}, {0, 1, 'R'}
    };

    pair<int, int> st, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A') st = {i, j};
            if (v[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<char>> par(n, vector<char>(m, '0'));
    queue<pair<int, int>> q;
    q.push(st);
    par[st.first][st.second] = 'p';

    while (!q.empty())
    {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy, c] : dir)
        {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (par[nx][ny] == '0' && (v[nx][ny] == '.' || v[nx][ny] == 'B'))
                {
                    q.push({nx, ny});
                    par[nx][ny] = c;
                }
            }
        }
    }

    if (par[end.first][end.second] == '0')
    {
        pn;
        return;
    }

    py;
    string ans = "";
    int i = end.first, j = end.second;

    while (!(par[i][j] == 'p'))
    {
        ans += par[i][j];
        if (par[i][j] == 'L') j++;
        else if (par[i][j] == 'R') j--;
        else if (par[i][j] == 'U') i++;
        else if (par[i][j] == 'D') i--;
    }

    reverse(ans.begin(), ans.end());
    ct(ans.size());
    ct(ans);
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