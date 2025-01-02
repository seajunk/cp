#include<iostream>
#include<string>
#define ll long long
using namespace std;

void solve(){
		string s;
		bool done = false;
		cin >> s;

		for(int i = 0; i < s.size(); i++){
				if(i == 0){
						cout << s[i];
				}
				else{
						if(!done && s[i] == s[i - 1]){
								cout << (char)((s[i] - 'a' + 1) % 26 + 'a');
								done = true;
						}
						cout << s[i];
				}

		}
		if(!done){
				cout << (char)((s[s.size() - 1] - 'a' + 1) % 26 + 'a');
		}
		cout << '\n';


}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();



}
