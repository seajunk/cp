#include<iostream>
#define ll long long
using namespace std;

void solve(){
		ll n, in;
		cin >> n;
		for(int i = 0; i < n; i++){
				cin >> in;
				cout << in % n + 1 << ' ';
		}
		cout << '\n';
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}
