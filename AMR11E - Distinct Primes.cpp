#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool vis[10500];
ll primes[10500],len;

void PrimeGenerator()
{
    primes[(len=0)++] = 2;

    for (ll i=3;i<=10000;i+=2)
    {
        if (!vis[i])
        {
            primes[len++] = i;
            for (ll j=i*i;j<=10000;j+=2*i)
                vis[j] = true;
        }
    }
}

int main ()
{
    PrimeGenerator();

    ll lucky[1005],idx;
    lucky[1] = 30,lucky[2] = 42,idx = 3;

    for (ll l = 44;;l++)
    {
        ///cout<<l<<" "<<idx<<endl;
        ll c = 0,n = l;
        for (ll i=0;i<len&&primes[i]*primes[i]<=n;i++)
        {
            if (n%primes[i]==0)
            {
                c++;
                while(n%primes[i]==0)
                    n/=primes[i];
            }
            if (c>=3)
                break;
        }
        if (n>1) c++;
        if (c>=3) lucky[idx++] = l;
        if (idx>1005) break;
    }

    ll cases,N;

    scanf("%lld",&cases);

    while(cases--)
    {
        scanf("%lld",&N);
        printf("%lld\n",lucky[N]);
    }

    return 0;
}
