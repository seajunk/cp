#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, a, b; cin >> n >> a >> b;

    // 0 1 0 1 0 

    if((a - b) % 2 == 0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
