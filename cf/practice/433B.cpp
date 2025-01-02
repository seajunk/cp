#include<iostream>
#include<algorithm>
#define ll long long
const ll N = 2e5;
using namespace std;


int main(){
		ll n, m, a[N], b[N], ra[N], rb[N], t, l, r;
		cin >> n;
		for(int i = 0; i < n; i++){cin >> a[i]; b[i] = a[i];};
		sort(b, b + n); ra[0] = 0; rb[0] = 0;


		for(int i = 1; i <= n; i++){ra[i] = ra[i - 1] + a[i - 1]; rb[i] = rb[i - 1] + b[i - 1];}
		cin >> m;
		for(int i = 0; i < m; i++){
				cin >> t >> l >> r;
				l--;
				r--;
				if(t == 1) cout << ra[r + 1] - ra[l] << '\n';
				else cout << rb[r + 1] - rb[l] << '\n';
		}
}

