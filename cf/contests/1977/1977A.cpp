#include<iostream>
#define ll long long
using namespace std;

void solve(){
		ll n, m;
		cin >> n >> m;
		if(n < m || n % 2 != m % 2) cout << "NO" << '\n';
		else cout << "YES" << '\n';
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}
