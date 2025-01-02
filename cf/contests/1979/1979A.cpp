#include<iostream>
#include<climits>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;
void solve(){
		ll n, a[N], ans;
		ans = LLONG_MAX;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];

		for(int i = 0; i < n - 1; i++){
				ans =  min(ans, max(a[i], a[i + 1]) - 1);
		}
		cout << ans << '\n';
}

int main(){
		int t;
		cin >> t;
		while(t--) solve();
}
