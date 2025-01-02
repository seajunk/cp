#include<iostream>
#include<string>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

// 1 1 1 0 1 1 1
//-1 0 0 1 1 1 1
//-1 0 0-1 0 0 0 1

string rbin(ll x){
		string b;
		b = "";
		if(x == 0){
				return "0";
		}
		else{
				while(x > 0){
						b = b + (x % 2 == 0 ? "0" : "1");
						x /= 2;
				}
				return b;
		}
}

void solve(){
		ll x, d[N], n, mx;
		cin >> x;
		string b = rbin(x);
		n = b.size();
		mx = n;

		for(int i = 0; i < n; i++) d[i] = (ll)(b[i] - '0');


		for(ll i = 0; i < n - 1;){
				if(d[i] != 0 && d[i + 1] != 0){
						d[i] = -1;
						i++;
						while(i < n && d[i] != 0){
								d[i] = 0;
								i++;
						}
						d[i] = 1;
						mx = max(mx, i + 1);
				}
				else i++;
		}
		cout << mx << '\n';
		for(ll i = 0; i < mx; i++) cout << d[i] << ' ';
		cout << '\n';
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}
