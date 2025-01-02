#include<iostream>
#define ll long long
using namespace std;

void solve(){
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if((x1 < y1 && x2 > y2) || (x1 > y1 && x2 < y2)) cout << "NO" << '\n';
		else cout << "YES" << '\n';
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}
