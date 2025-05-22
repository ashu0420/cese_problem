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
#define out(a, n)                  \
    fr(ll, 0, n) { cout << a[i]; } \
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
    int n;
    cn(n);
    vector<string> v1, v2;
    v1.push_back("0");
    v1.push_back("1");
    n--;
    while (n--)
    {
        v2.clear();
        for (int i = v1.size() - 1; i >= 0; i--)
        {
            v2.push_back(v1[i]);
        }
        for (int i = 0; i < v1.size(); i++)
        {
            v1[i] = "0" + v1[i];
            v2[i] = "1" + v2[i];
        }
        // for (int i = 0; i < v2.size(); i++)
        // {
        //     // v1[i] = "0" + v1[i];
        //     v2[i] = "1" + v2[i];
        // }
        // ct(v2.size());
        for (int i = 0; i < v2.size(); i++)
        {
            v1.push_back(v2[i]);
        }
    }
    for (auto i : v1)
    {
        ct(i);
    }
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