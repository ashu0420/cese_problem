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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    pair<int, int> a;
    queue<pair<int, int>> q;
    vector<vector<char>> par(n, vector<char>(m, '0'));
    vector<tuple<int, int, char>> dir = {{1, 0, 'D'}, {-1, 0, 'U'}, {0, 1, 'R'}, {0, -1, 'L'}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'M') q.push({i, j});
            if (v[i][j] == 'A') a = {i, j};
        }
    }

    q.push(a);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy, d] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (v[nx][ny] == '.') {
                    q.push({nx, ny});
                    par[nx][ny] = d;
                    v[nx][ny] = v[x][y];
                }
            }
        }
    }

    pair<int, int> st = {-1, -1};
    for (int i = 0; i < n; i++) {
        if (v[i][0] == 'A') st = {i, 0};
        if (v[i][m-1] == 'A') st = {i, m-1};
    }
    for (int j = 0; j < m; j++) {
        if (v[0][j] == 'A') st = {0, j};
        if (v[n-1][j] == 'A') st = {n-1, j};
    }

    if (st.first == -1) {
        pn;
        return;
    }

    vector<char> ans;
    auto [x, y] = st;
    while (par[x][y] != '0') {
        ans.push_back(par[x][y]);
        if (par[x][y] == 'L') y++;
        else if (par[x][y] == 'R') y--;
        else if (par[x][y] == 'U') x++;
        else if (par[x][y] == 'D') x--;
    }

    rev(ans);
    py;
    ct(ans.size());
    for (char c : ans) cout << c;
    cout << endl;
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