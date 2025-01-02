#include<iostream>
#define ll long long
const ll N = 2e5;
using namespace std;


int main(){
		ll n, a[N], s;
		s = 0;
		cin >> n;
		for(int i = 0; i < n; i++){ cin >> a[i]; s += a[i];}

		ll curr, mx;
		mx = -1;
		curr = 0;
		for(int i = 0; i < n; i++){
				ll v = a[i] == 0 ? 1 : -1;
				curr = max(v, curr + v);
				mx = max(mx, curr);
		}
		cout << mx + s << '\n';





}
