#include<iostream>
#include<string>
#define ll long long
using namespace std;

void solve(){
		ll n, a, b, c, d, q, ans;
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		q = 0;
		string s;
		cin >> n;
		cin >> s;

		for(int i = 0; i < 4*n; i++){
				if(s[i] == 'A') a++;
				if(s[i] == 'B') b++;
				if(s[i] == 'C') c++;
				if(s[i] == 'D') d++;
				if(s[i] == '?') q++;
		}

		ans = min(a, n) + min(b, n) + min(c, n) + min(d, n);

		cout << ans << '\n';

}

int main(){
		ll T;
		cin >> T;
		for(int t = 0; t < T; t++) solve();
}
