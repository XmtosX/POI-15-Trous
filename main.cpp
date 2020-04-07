#include <bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int n,d;
long long p,a[N],pfx[N],b[N];
multiset <long long> s;
int main()
{
    scanf("%d%lld%d",&n,&p,&d);
    for (int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for (int i=1;i<=n;i++)
        pfx[i]=pfx[i-1]+a[i];
    for (int i=1;i+d-1<=n;i++)
    {
        b[i]= pfx[i+d-1]-pfx[i-1];
    }
    long long cur=pfx[d];
    s.insert(b[1]);
    int ans=d;
    for (int i=1,j=d+1;j<=n;j++)
    {
        s.insert(b[j-d+1]);
        cur+=a[j];
        while (cur-(*s.rbegin())>p)
        {
            cur-=a[i];
            s.erase(s.lower_bound(b[i]));
            i++;
        }
        ans=max(ans,j-i+1);
    }
    printf("%d",ans);
    return 0;
}
