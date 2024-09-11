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
    int n;
    cn(n);
    if(n==2||n==3)
    {
        ct("NO SOLUTION");
        return;
    }
    for(int i=2;i<=n;i+=2)
    {
        cout<<i<<" ";
    }
    for(int i=1;i<=n;i+=2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    // Your code here
}

int main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}