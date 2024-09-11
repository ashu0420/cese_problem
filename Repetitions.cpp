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
#define out(a, n) \
    fr(ll, 0, n) { cout << a[i] << " "; }

using namespace std;

void solve()
{
    // Your code here
    string s;
    cn(s);
    int ans = 0, count = 1;
    int n=s.size();
    for (int i = 1; i < n; i++)
    {
        // ct("hi");
        if (s[i] != s[i - 1])
        {
            ans = max(ans, count);
            count = 1;
        }
        else
        {
            // ct("ds");
            count++;
        }
    }
    ans=max(ans,count);
    ct(ans);
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}