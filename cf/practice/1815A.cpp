#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // 2 1 4 3
    // [-1, 3, -1]

    // in the difference array d[n - 1], if we perfrom operation on a[i - 1] and a[i], then d[i - 1] increases/decreases and d[i + 1] decreases/increases by 1

    // so possible if we can make every element of d >= 0 with operations 

    // we can redistribute numbers in odd and even indices of d
    // we can arbitrarily increase a[1] and a[n - 2] as much as we want
    // so doesnt work if exists d[i] < 0 such that i has different parity to both 1 and n - 3
    // otherwise works

    ll d[n - 1];
    for(int i = 0; i < n - 1; i++) d[i] = a[i + 1] - a[i];

    if(n == 2){
        if(d[0] < 0){
            cout << "NO\n";
            return;
        }
        else{
            cout << "YES\n";
            return;
        }
    }

    if(n % 2 == 1){
        cout << "YES\n";
        return;
    }

    ll sum = 0;
    for(int i = 0; i < n - 1; i++){
        if(i % 2 == 0){
            sum += d[i];
        }
    }

    if(sum < 0){
        cout << "NO\n";
        return;
    }


    cout << "YES\n";
    return;

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
