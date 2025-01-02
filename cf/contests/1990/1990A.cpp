#include<iostream>
#include<set>
#define ll long long
using namespace std;

void solve(){
		multiset<ll> S;
		ll n, in;
		cin >> n;
		for(int i = 0; i < n; i++){
				cin >> in;
				S.insert(in);
		}
		for(auto it = S.begin(); it != S.end(); it = S.upper_bound(*it)){
				if(S.count(*it) % 2 == 1){
						cout << "YES" << '\n';
						return;
				}
		}
		cout << "NO" << '\n';
		return;


}
int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}
