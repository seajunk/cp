#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll lacking = 0;
    ll mn = LLONG_MAX;
    ll cnt = 0;


    for(int i = 0; i < n; i++){
        if(a[i] < b[i]){
         lacking += b[i] - a[i];
         cnt++;
        }
        else mn = min(mn, a[i] - b[i]);
    }
    if(lacking == 0){
        cout << "YES\n";
    }
    else if(cnt > 1){
        cout << "NO\n";
    }
    else if(mn >= lacking){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }


    // 9 2 2 9
    // 0 3 3 0 
    // 8 3 1 8
    // 8 





    




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

