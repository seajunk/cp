#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, b, c; cin >> n >> b >> c;

    if(b == 0){
        if(c < n - 2){
            cout << -1 << '\n';
            return;
        }
        else if(c == n - 2){
            cout << n - 1 << '\n';
            return;
        }
        else{
            cout << n << '\n';
            return;
        }
    }

    if(c > n - 1){
        cout << n << '\n';
        return;
    }

    ll temp = ((n - 1) - c) / b;


    if((n - 1 - c) % b != 0) temp++;

    cout << n - temp << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
