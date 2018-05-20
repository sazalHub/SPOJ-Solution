#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>tree[120050];
ll arr[30010],N,Q,a,b,c;

void marge(ll node,ll l,ll r){
	ll lft_len = tree[l].size();
	ll rgt_len = tree[r].size();

	ll i = 0,j = 0;

	while(i<lft_len && j<rgt_len){
		if (tree[l][i]<=tree[r][j]){
			tree[node].push_back(tree[l][i]);
			i++;
		}
		else{
			tree[node].push_back(tree[r][j]);
			j++;
		}
	}

	while(i<lft_len){
		tree[node].push_back(tree[l][i]);
		i++;
	}

	while(j<rgt_len){
		tree[node].push_back(tree[r][j]);
		j++;
	}
}

void build(ll node,ll l,ll r){
	if (l==r){
		tree[node].clear();
		tree[node].push_back(arr[l]);
		return;
	}

	tree[node].clear();

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	build(lft,l,mid);
	build(rgt,mid+1,r);

	marge(node,lft,rgt);
	///cout<<"node = "<<node<<endl;
	///for (ll i=0;i<tree[node].size();i++) cout<<tree[node][i]<<" ";
	///cout<<endl;
}

ll query(ll node,ll l,ll r,ll to,ll from,ll val){
	if (l>from || r<to) return 0;
	if (to<=l&&r<=from){
		ll pos = upper_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();
		///cout<<node<<" "<<pos<<endl;
		return (tree[node].size()-pos);
	}

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	ll ret1 = query(lft,l,mid,to,from,val);
	ll ret2 = query(rgt,mid+1,r,to,from,val);

	return ret1+ret2;
}

int main ()
{
	while(scanf("%lld",&N)==1){
		for (ll i=1;i<=N;i++) scanf("%lld",&arr[i]);

		build(1,1,N);

		scanf("%lld",&Q);

		ll i,j,k,ans = 0;
		while(Q--){
			scanf("%lld%lld%lld",&a,&b,&c);
			i = a xor ans;
			j = b xor ans;
			k = c xor ans;

			if (i<1) i = 1;
			if (j>N) j = N;

			if (i>j) ans = 0;
			else ans = query(1,1,N,i,j,k);
			printf("%lld\n",ans);
		}

	}
	return 0;
}

