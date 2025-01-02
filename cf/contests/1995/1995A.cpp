#include<iostream>
#define ll long long
using namespace std;

void solve(){
		ll n, k, ans, p;
		cin >> n >> k;
		p = 0;
		ans = 0;
		while(k > 0){
				k -= n;
				if(p % 2 == 0) n--;
				p++;
				ans++;
		}
		
		cout << ans << '\n';
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}
