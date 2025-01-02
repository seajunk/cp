#include<iostream>
#include<string>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
		string a, b;
		cin >> a >> b;
		ll cnt, mx;

		mx = 0;

		for(int i = 0; i < b.size(); i++){
				cnt = 0;
				for(int j = 0, ptr = i; j < a.size() && ptr < b.size(); j++){
						if(a[j] == b[ptr]){
								cnt++;
								ptr++;
						}
				}
				mx = max(mx, cnt);
		}

		cout << a.size() + b.size() - mx << '\n';
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}
