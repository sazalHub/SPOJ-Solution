#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll multiply(string st, ll mod){
	ll ret = 0;
	for (ll i=0;st[i];i++){
		ret = (ret*10 + (st[i] - '0'))%mod;
	}
	return ret;
}

bool binry(ll n){
	while(n!=0){
		ll r = n%10;
		if (r!=0 && r!=1) return false;
		n/=10;
	}
	return true;
}

string mul(ll n){
	bool visited[n+2];
	for (ll i=0;i<=n;i++) visited[i] = false;

	queue<string>Q;
	string s = "1";
	Q.push(s);

	while(!Q.empty()){

		s = Q.front();
		Q.pop();

		ll r = multiply(s,n);

		if (r==0) return s;

		if (!visited[r]){
			visited[r] = true;
			Q.push(s+"0");
			Q.push(s+"1");
		}
	}
}

string num2string(ll n){
	string str="";
	while(n!=0){
		ll r = n%10;
		str+=(r+'0');
		n/=10;
	}
	reverse(str.begin(),str.end());
	return str;
}

int main (){
	ll N,cases;

	scanf("%lld",&cases);
	while(cases--){
		scanf("%lld",&N);

		string str = "";

		if (binry(N)){
			str = num2string(N);
		}
		else {
			str = mul(N);
		}
		cout<<str<<endl;

	}

	return 0;
}

