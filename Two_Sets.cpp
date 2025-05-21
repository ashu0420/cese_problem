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
    int n;
    cn(n);
    if (n % 4 == 0 || (n + 1) % 4 == 0)
    {
        py;
        vector<int> a, b;
        for (int i = n; i > 0; i -= 4)
        {
            a.push_back(i);
            if (i - 1 > 0)
            {
                b.push_back(i - 1);
            }
            if (i - 2 > 0)
            {
                b.push_back(i - 2);
            }
            if (i - 3 > 0)
            {
                a.push_back(i - 3);
            }
        }
        ct(a.size());
        out(a, a.size());
        ct(b.size());
        out(b, b.size());
    }
    else
    {
        pn;
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