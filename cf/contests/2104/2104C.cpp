#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;


    /*

    */
    ll bob = true;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            bool found = false;

            if(i == n - 1){
                if(s[0] == 'B') found = true;
            }

            else if(i == 0){
                for(int j = 0; j < n - 1; j++){
                    if(s[j] == 'B') found = true;
                }
            }
            else{
                for(int j = i + 1; j < n; j++){
                    if(s[j] == 'B') found = true;
                }
            }
            bob &= found;
        }
    }

    if(bob) cout << "Bob\n";
    else cout << "Alice\n";



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
