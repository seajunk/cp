#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    if(a[0] == 1){
        cout << "BOB\n";
        return;
    }

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i] - 1;
    }

    if(sum % 2 == 0){
        cout << "BOB\n";
    }
    else{
        cout << "ALICE\n";
    }

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
