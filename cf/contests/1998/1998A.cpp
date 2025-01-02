#include<iostream>
#define ll long long
using namespace std;

void solve(){
		ll xc, yc, k;
		cin >> xc >> yc >> k;

		if(k % 2 == 1) cout << xc << ' ' << yc << '\n';

		for(int i = 1; i <= k / 2; i++){
				cout << xc + i << ' ' << yc << '\n';
				cout << xc - i << ' ' << yc << '\n';
		}


}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}
