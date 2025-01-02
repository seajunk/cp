#include<iostream>
#define ll long long
using namespace std;

void solve(){
		ll n, in, mx;
		cin >> n;
		mx = 0;
		for(int i = 0; i < n; i++){
				cin >> in;
				if(i != n - 1) mx = max(mx, in);
				else cout << mx + in << '\n';
		}
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}

