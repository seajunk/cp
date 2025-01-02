#include<iostream>
#define ll long long
using namespace std;

void solve(){
		ll n, k;
		cin >> n >> k;
		cout << (n - 1 + k - 1 - 1) / (k - 1) << '\n';
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
		return 0;
}
