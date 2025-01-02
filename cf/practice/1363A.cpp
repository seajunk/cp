#include<iostream>
#define ll long long
const ll N = 2e5;
using namespace std;


void solve(){
		ll n, x, a[N], o, e;
		o = 0;
		e = 0;
		cin >> n >> x;
		for(int i = 0; i < n; i++){ cin >> a[i]; if(a[i] % 2 == 0) e++; else o++;}

		for(int i = 1; i <= min(o, x); i+= 2){
				if(x - i <= e){cout << "YES" << '\n'; return;}
		}

		cout << "NO" << '\n';



		
		

}


int main(){
		ll T; 
		cin >> T;
		for(int t = 0; t < T; t++) solve();
}
