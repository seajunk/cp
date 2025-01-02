#include<iostream>
#include<algorithm>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
		ll n, a[N], e, ans, mxo;
		mxo = 1;
		e = 0;
		ans = 0;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++){
				if(a[i] % 2 == 0) e++;
				else mxo = max(mxo, a[i]);
		}
		if(e == n){
				cout << 0 << '\n';
				return;
		}
		sort(a, a + n);
		
		for(int i = 0; i < n; i++){
				if(a[i] % 2 == 0){
						if(mxo < a[i]){cout << e + 1 << '\n'; return;}
						else{
								a[i] += mxo;
								ans++;
								mxo = a[i];
						}
				}
		}

		cout << ans << '\n';

		


		}

int main(){
		ll t;
		cin >> t;
		for(int i = 0; i < t; i++) solve();
}
