#include<iostream>
#define ll long long
using namespace std;

void solve(){
		ll a;
		cin >> a;
		// fact: a = ((n - 2) * 180) / n
		// so n is whole number iff 360 / (180 - a) is a whole number
		if(360 % (180 - a) == 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
}

int main(){
		ll t;
		cin >> t;
		for(int i = 0; i < t; i++) solve();
}
