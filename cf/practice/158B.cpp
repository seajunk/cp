#include<iostream>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

int main(){
		ll n, a[N], ans = 0;
		ll b[4] = {0};
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];

		for(int i = 0; i < n; i++){
				b[a[i] - 1]++;
		}
		
		ans = 0;
		ans += b[3];
		ans += min(b[0], b[2]);
		ll t = min(b[0], b[2]);
		b[0] -= t;
		b[2] -= t;
		ans += b[1] / 2;
		b[1] -= 2 * (b[1] / 2);




		if(b[0] == 0 && b[2] == 0){
				ans += b[1];
		}
		else if(b[0] == 0){
				ans += b[2] + b[1];
		} else{
				ans += b[0] / 4;
				b[0] -= 4 * (b[0] / 4);
				if(b[0] <= 2){
						ans += (b[0] || b[1]);
				}
				else{
						ans += (bool)b[0];
						ans += (bool)b[1];
				}
		}

		cout << ans << '\n';



		

 
 

		




		


}
