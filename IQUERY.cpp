#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll arr[100005],ans,cn[50];

struct Tree{
    ll sum,cnt[50];
}tree[5*100005];

void BuildTree(ll node,ll i,ll j)
{
    if (i==j)
    {
        tree[node].sum = arr[j];
        for (ll l=0;l<=35;l++) tree[node].cnt[l] = 0;
        ll tmp = arr[j],l = 0;
        while(tmp!=0)
        {
            tree[node].cnt[l++] = tmp%2;
            tmp/=2;
        }
        return;
    }

    ll lft=2*node;
    ll rgt=2*node+1;
    ll mid=(i+j)/2;

    BuildTree(lft,i,mid);
    BuildTree(rgt,mid+1,j);

    tree[node].sum = ((tree[lft].sum+1)*(tree[rgt].sum+1)-1)%mod;
    for (ll l=0;l<=35;l++) tree[node].cnt[l] = tree[lft].cnt[l] + tree[rgt].cnt[l];
}

void update(ll node,ll i,ll j,ll loc,ll val)
{
    if (loc<i || loc>j)
        return;
    if (i==j&&i==loc)
    {
        tree[node].sum = val;
        for (ll l=0;l<=35;l++) tree[node].cnt[l] = 0;
        ll tmp = val,l = 0;
        while(tmp!=0)
        {
            tree[node].cnt[l++] = tmp%2;
            tmp/=2;
        }
        return;
    }

    ll lft=node*2;
    ll rgt=node*2+1;
    ll mid=(i+j)/2;

    update(lft,i,mid,loc,val);
    update(rgt,mid+1,j,loc,val);

    tree[node].sum = ((tree[lft].sum+1)*(tree[rgt].sum+1)-1)%mod;
    for (ll l=0;l<=35;l++) tree[node].cnt[l] = tree[lft].cnt[l] + tree[rgt].cnt[l];
}

void query(ll node,ll i,ll j,ll l,ll r,ll tpe)
{
    if (i>r || j<l) return;
    if (i>=l && j<=r)
    {
        if (tpe==1)
            ans = ((ans+1)*(tree[node].sum+1)-1)%mod;
        else
            for (ll k=0;k<=35;k++) cn[k]+=tree[node].cnt[k];
        return;
    }

    ll lft = node*2;
    ll rgt = node*2 + 1;
    ll mid = (i+j)/2;

    query(lft,i,mid,l,r,tpe);
    query(rgt,mid+1,j,l,r,tpe);
}

int main ()
{
    ll N,Q,L,R;
    char type[5];

    ll pwr[100010];
    pwr[0] = 0,pwr[1] = 1;
    for (ll i=2;i<=100005;i++) pwr[i] = (pwr[i-1]*2+1)%mod;

    ///freopen("n.txt","r",stdin);
    ///freopen("o.txt","w",stdout);

    while(scanf("%lld",&N)==1)
    {
        for (ll i=1;i<=N;i++) scanf("%lld",&arr[i]);
        BuildTree(1,1,N);

        scanf("%lld",&Q);
        while(Q--)
        {
            scanf("%s%lld%lld",&type,&L,&R);
            if (type[0]=='M')
            {
                ans = 0;
                query(1,1,N,L,R,1);
                printf("%lld\n",ans);
            }
            else if (type[0]=='A')
            {
                ans = 0;
                for (ll l=0;l<=35;l++) cn[l] = 0;
                query(1,1,N,L,R,2);
                for (ll l=35;l>=0;l--)
                    ans = (ans*2+pwr[cn[l]])%mod;
                    ///cout<<l<<" "<<pwr[cn[l]]<<endl;
                printf("%lld\n",ans);
            }
            else
                update(1,1,N,L,R);
        }
        ///cout<<endl;
    }
    return 0;
}
