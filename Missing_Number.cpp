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
    int n;
    cn(n);
    vector<bool> v(n+1,0);
   for(int i=1;i<n+1;i++)
   {
    int x;
    cn(x);
    v[x]=1;
   }
   for(int i=1;i<n+1;i++)
   {
    if(v[i]==0)
    {
        ct(i);
        break;
    }
   }
   return;


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