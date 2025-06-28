#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    ll n, k; cin >> n >> k;

    if(n % 2 == 0){
        if((k - 1) % 4 == 0 || (k - 1) % 4 == 3){
            cout << "YES\n";
            return;
        }
        else{
            cout << "NO\n";
            return;
        }
    }

    // 1 2 3 4 5 6 7

    else{
        if((k - 1) % 4 == 0 || (k - 1) % 4 == 1){
            cout << "NO\n";
            return;
        }
        else{
            cout << "YES\n";
            return;
        }
    }


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
