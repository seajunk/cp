#include <bits/stdc++.h> 
typedef long long ll;
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    bool zero = false;

    ll neg = 0;
    for(int i = 0; i < n; i++) if(a[i] < 0) neg++;

    for(int i = 0; i < n; i++) if(a[i] == 0) zero = true;


    if(zero){
        cout << 0 << '\n';
    }
    else if(neg % 2 == 0){
        cout << 1 << '\n';
        cout << 1 << ' ' << 0 << '\n';
    }
    else{
        cout << 0 << '\n';
    }


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
