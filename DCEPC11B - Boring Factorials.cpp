#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll BigMod(ll base,ll power,ll mod)
{
    if (power==0) return 1;
    if (power==1) return base;
    ll y = BigMod(base,power/2,mod);
    ll ret = (y*y)%mod;
    if (power%2) ret = (ret*base)%mod;
    return ret;
}

int main ()
{
    ll cases,N,P,B,ans;
    scanf("%lld",&cases);

    while(cases--)
    {
        scanf("%lld%lld",&N,&P);
        if (N>=P) ans = 0;
        else
        {
            B = 1;
            for (ll i=1;i<P-N;i++) B = (B*(P-i))%P;
            ans = ((P-1)*BigMod(B,P-2,P))%P;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
