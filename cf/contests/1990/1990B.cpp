#include<iostream>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;
//TODO: 
//
//
void solve(){
		ll n, x, y;
		cin >> n >> x >> y;
		x--;
		y--;
		for(int i = 0; i < n; i++){
				if(i < y){
						if(i % 2 != y % 2) cout << -1 << " ";
						else cout << 1 << " ";
				}
				else if(y <= i && i <= x) cout << 1 << " ";
				else{
						if(i % 2 != x % 2) cout << -1 << " ";
						else cout << 1 << " ";
				}
		}
		cout << '\n';
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}

// 5 2 1
// 1 1 -1 1 -1
//
// 6 2 1
// 1 1 -1 1 -1 1
// 6 3 4
// 1 -1 1 1 -1 1
