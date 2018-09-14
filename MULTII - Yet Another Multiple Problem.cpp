#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[15];

ll multiply(string st, ll mod){
	ll ret = 0;
	for (ll i=0;st[i];i++){
		ret = (ret*10 + (st[i] - '0'))%mod;
	}
	return ret;
}

string num2string(ll n){
	if (n==0) return "0";
	string str="";
	while(n!=0){
		ll r = n%10;
		str+=(r+'0');
		n/=10;
	}
	reverse(str.begin(),str.end());
	return str;
}

bool have(ll n){
	while(n!=0){
		ll r = n%10;
		if (arr[r]==1) return true;
		n/=10;
	}
	return false;
}

string mul(ll n){
	bool visited[n+2];
	for (ll i=0;i<=n;i++) visited[i] = false;

	queue<string>Q;
	string s = "";
	for (ll i=1;i<=9;i++){
		if (arr[i]==0) Q.push(num2string(i));
	}
	///cout<<1<<endl;

	while(!Q.empty()){

		s = Q.front();
		Q.pop();

		ll r = multiply(s,n);

		if (r==0) return s;

		if (!visited[r]){
			visited[r] = true;
			for (ll i=0;i<=9;i++){
				if (arr[i]==0){
					///cout<<s+num2string(i)<<endl;
					Q.push(s+num2string(i));
				}
			}
		}
	}
	return s;
}

int main (){
	ll N,caseno = 0,m,num;
	///freopen("out.txt","w",stdout);

	while(scanf("%lld%lld",&N,&m)==2){

		for (ll i=0;i<13;i++) arr[i] = 0;

		for (ll i=0;i<m;i++){
			scanf("%lld",&num);
			arr[num] = 1;
		}
		///cout<<1<<endl;

		string str = "";

		if (!have(N)){
			str = num2string(N);
		}
		else {
			str = mul(N);
		}

		bool fl = true;
		for (ll i=0;str[i] && fl;i++){
			ll idx = str[i] - '0';
			if (arr[idx]==1) fl = false;
		}

		if (multiply(str,N)!=0 || str.size()==0) fl = false;

		printf("Case %lld: ",++caseno);
		if (fl) cout<<str<<endl;
		else cout<<-1<<endl;
	}

	return 0;
}


