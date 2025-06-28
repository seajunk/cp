#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;

    if(n == 1){
        cout << 1 << '\n';
        return;
    }

    if(n % 2 == 1){
        cout << -1 << '\n';
        return;
    } 


    // n, 1, n-2, 3, n-4 ... 2
    // n, n+1, n-1, n+2, n-2, n+3,    

    cout << n << ' ';
    for(int i = 1; i < n; i++){
        if(i % 2 == 1){
            cout << i << ' ';
        }
        else{
            cout << n - i << ' ';
        }
    }
    cout << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
