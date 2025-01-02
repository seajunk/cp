#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const ll N = 2e5;




int main(){
		ll n, a[N], q, b[N];

		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		cin >> q;
		for(int i = 0; i < q; i++) cin >> b[i];
		
		sort(a, a + n);

		for(int i = 0; i < q; i++){
				ll l = 0;
				ll r = n;
				ll m = l + (r - l)/2;
				// 1 1 3 4 5 7 7 8 9
				// x = 11
				// 1 1 3 4 5 7 7 8 9
				//           7 7 8 9
				//               8 9
				//                 9 
	
				while(l < r){
						m = l + (r - l) / 2;
						if(a[m] <= b[i]) l = m + 1;
						else r = m;
				}
				
				if(a[l] <= b[i]) cout << n << '\n';
				else cout << l << '\n';

				

		
		}
}
