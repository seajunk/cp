#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n];
    ll mn = LLONG_MAX;
    ll idx = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < mn){
            idx = i;
            mn = a[i];
        }
    }

    for(int i = idx + 2; i < n; i++){
        if(a[i - 1] > a[i]){
            cout << -1 << '\n';
            return;
        }
    }

    cout << idx << '\n';




    

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
