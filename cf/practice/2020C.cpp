#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll b, c, d; cin >> b >> c >> d;

    ll a = 0;

    for(int i = 0; i < 62; i++){
        if(!(b & (1ll << i)) && (d & (1ll << i)) && (c & (1ll << i))){
            cout << -1 << '\n';
            return;
        }
        if((b & (1ll << i)) && !(d & (1ll << i)) && !(c & (1ll << i))){
            cout << -1 << '\n';
            return;
        }
    }

    for(int i = 0; i < 62; i++){
        if(!(b & (1ll << i)) && (d & (1ll << i))){
            a |= (1ll << i);
        }
        if((b & (1ll << i)) && !(d & (1ll << i))){
            a |= (1ll << i);
        }
    }

    cout << a << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
