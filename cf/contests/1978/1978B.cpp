#include<iostream>
#define ll long long
using namespace std;

void solve(){
		ll n, a, b;
		cin >> n >> a >> b;
		// b - i + 1 = a
		// i = b - a + 1
	
		// b - i = b - b + a - 1
		// b - i = a - 1
		
		
		// 5 2 3
		// 3 2 2 2 2
		
		// 5 2 8
		// 8 7 6 5 4
		
		// 3 2 8
		// 8 7 6 
		
		// 8 4 8
		// 8 7 6 5 4 4 4 4
		
	
		if(b <= a){
				cout << a * n << '\n';
		}
		else{
				if(b - a + 1 > n){
						cout << b * (b + 1) / 2 - ((b - n) * (b - n + 1) / 2) << '\n';
				}
				else{
						//cout << b * (b + 1) / 2 << ' ' << a * (a + 1) / 2 << ' ' << a * (n - (b - a)) << '\n';
						cout << b * (b + 1) / 2 - (a * (a + 1) / 2) + a * (n - (b - a)) << '\n';
				}
		}
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}
