#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    ll I = -1;

    for(int i = 0; i < n; i++){
        if(a[i] != 0){
            I = i;
            break;
        }
    }

    if(I == -1){
        cout << 0 << '\n';
        return;
    }

    // k
    cout << (n - 1 + n - 1 + 5) << '\n';

    // 5
    cout << I + 1 << ' ' << I + 1 << '\n';
    cout << I + 1 << ' ' << I + 1 << '\n';
    cout << I + 1 << ' ' << I + 1 << '\n';
    cout << I + 1 << ' ' << I + 1 << '\n';
    cout << I + 1 << ' ' << I + 1 << '\n';
    // a[I] >= 32

    if(a[I] > 0){
        // n - 1
        for(int i = 0; i < n; i++){
            if(i != I){
                cout << i + 1 << ' ' << I + 1 << '\n';
            }
        }
        // now every guy is positive

        // n - 1
        for(int i = 1; i < n; i++){
            cout << i + 1 << ' ' << i << '\n';
        }

    }
    else{
        // n - 1
        for(int i = 0; i < n; i++){
            if(i != I){
                cout << i + 1 << ' ' << I + 1 << '\n';
            }
        }
        // now every guy is negative

        // n - 1
        for(int i = n - 1; i >= 1; i--){
            cout << i << ' ' << i + 1 << '\n';
        }
    }




} 

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

