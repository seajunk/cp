#include<iostream>
#include<unordered_map>
#define ll long long
using namespace std;

void solve(){
		unordered_map<ll, ll> h;
		ll n, in;
		cin >> n;
		for(int i = 0; i < n; i++){
				cin >> in;
				if(h.find(in) == h.end()) h[in] = 1;
				else h[in] += 1;
		}

		if(h.size() == 1) cout << "YES" << '\n';
		else if(h.size() == 2){
				for(auto e : h){
						if(e.second == n / 2){
								cout << "YES" << '\n';
								return;
						}
				}
				cout << "NO" << '\n';
		}
		else cout << "NO" << '\n';
}

int main(){
		ll t; 
		cin >> t;
		for(int i = 0; i < t; i++) solve();
}
