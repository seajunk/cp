#include<iostream>
#include<string>
#define ll long long
using namespace std;

// notice that either 2 D's are lost, 2 D's are gained, or the number of D's remains the same.
// DUD -> U U
// UUU -> D D
// DUU -> U D
// so parity of D remains same after any operation(?)

// simillarly for U, the count changes parity after each operation(*)


// UUUU -> D DU -> U U -> U -> ""

void solve(){
		ll n, u;
		string s;

		cin >> n;
		cin >> s;
		u = 0;
		for(int i = 0; i < n; i++){
				if(s[i] == 'U') u++;
		}

		if(u % 2 == 0) cout << "NO" << '\n';
		else cout << "YES" << '\n';
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}
