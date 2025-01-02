// integer array of size n with values k1...kn.
// want to choose k1...kn such that sum is closest to m and no two ki kj have abs diff > 1.

#include<iostream>
#include<algorithm>
#define ll long long
const ll N = 2e5 + 20;
using namespace std;



void solve(){
		ll n, m, a[N], mx;
		cin >> n >> m;
		mx = -1;
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		a[n] = -1;
		
		for(int i = 0; i < n;){
				ll j = i;
				while(a[i] == a[j]) j++;
				ll k = j;
				while(a[k] == a[i] + 1) k++;
				
				for(int c = 0; c <= j - i; c++){
						if(c * a[i] > m) continue;
						ll val = c * a[i]; // we have m - c * a[i] coins left. need to maximize d * (a[i] + 1) <= m - c * a[i]. Note also k - j could be 0.
						ll val2 = min(k - j, (m - c * a[i]) / (a[i] + 1)) * (a[i] + 1);
						mx = max(mx, val + val2);
				}
		i = j;
		}
		cout << mx << '\n';
}

int main(){
		ll T;
		cin >> T;
		for(int t = 0; t < T; t++) solve();

}
