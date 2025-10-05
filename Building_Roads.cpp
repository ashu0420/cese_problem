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
    fr(ll, 1, n+1) { cn(a[i]); }
#define out(a, n) \
    fr(ll, 0, n) { cout << a[i] << " "; } cout << endl;
#define out1(a, n) \
    fr(ll, 1, n+1) { cout << a[i] << " "; } cout << endl;
#define X ct('X')
#define srt(a) sort(a.begin(), a.end());
#define rev(a) reverse(a.begin(), a.end());
#define vin(a,n) vector<ll> a(n); in(a,n);
#define vin1(a,n) vector<ll> a(n+1); in1(a,n);
const int MOD = 1e9 + 7;

using namespace std;

ll mod_pow(ll x, ll y) {
    ll result = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            result = (result * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return result;
}

ll modular_inverse(ll denom) {
    return mod_pow(denom, MOD - 2);
}
vector<vector<int>> adj;
vector<int> vis;
void dfs(int node)
{
    vis[node]=1;
    for(auto child: adj[node])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}
void solve() {
    // Your code here
    int n,m;
    cin>>n>>m;
    // vector<vector<int>> adj(n+1);
    adj.assign(n+1,{});
    vis.assign(n+1,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // vector<int> vis(n+1,0);
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            ans.push_back(i);
        }
    }
    ct(ans.size()-1);
    for(int i=0;i<ans.size()-1;i++)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout.setf(ios::fixed);
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}