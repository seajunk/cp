#include<iostream>
#include<cassert>
#define ll long long
using namespace std;


void solve(){
		int  x, y, k;
		cin >> x >> y >> k;

		for(int i = min(y - (x%y), k); x > 1 && k > 0; i = min(y - (x%y), k)){
				k -= i;
				x += i;
				while(x % y == 0) x = x/y;
		}

		cout << x + k % (y - 1) << '\n';
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}

// 24 -> (25 -> 5 -> 1) -> 2 -> 3 -> 4 -> 1
