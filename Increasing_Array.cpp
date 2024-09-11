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
    // vector<int> v(n);
    li count=0;
    int y;
    fr(int,0,n)
    {
        int x;
        cn(x);
        // ct(x);
        if(i>0)
        {
            if(x<y)
            {
                count+=(y-x);
            }
            // else continue;
        }
        y=max(x,y);
        // cout<<y<<" "<<x<<" "<<count<<endl;
    }
    ct(count);
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