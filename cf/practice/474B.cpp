#include<iostream>
#define ll long long
const ll N = 2e5;
using namespace std;

int main(){
		ll n, a[N], m, q[N], rs[N];
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		cin >> m;
		for(int i = 0; i < m; i++) cin >> q[i];

		rs[0] = a[0];
		for(int i = 1; i < n; i++){
				rs[i] = rs[i - 1] + a[i];
		}

		for(int i = 0; i < m; i++){
				ll l = 0;
				ll r = n;
				ll mid;
				while(l < r){
						mid = l + (r - l) / 2;
						if(rs[mid] < q[i]) l = mid + 1;
						else r = mid;
				}
				cout << l + 1 << '\n';
		}
		


}
