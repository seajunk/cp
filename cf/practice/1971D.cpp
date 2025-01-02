#include<iostream>
#include<string>
#define ll long long
using namespace std;
const ll N = 2e5 + 20;


void solve(){
		string s;
		ll n, ans;
		bool found;
		found = false;
		cin >> s;
		n = s.size();
		ans = 1;
		for(int i = 1; i < n; i++){
				if(s[i] != s[i - 1]) ans++;
				if(s[i - 1] == '0' && s[i] == '1') found = true;
		}
		cout << ans - found << '\n';
	}

int main(){

		ll T;
		cin >> T;
		for(int t = 0; t < T; t++) solve();


}
