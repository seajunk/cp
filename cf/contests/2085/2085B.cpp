#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];



    vector<ll> zeros;


    for(int i = 0; i < n; i++){
        if(a[i] == 0) zeros.push_back(i);
    }

    if(zeros.size() == 0){
        cout << 1 << '\n';
        cout << 1 << ' ' << n << '\n';
        return;
    }

    if(a[0] != 0 && a[n - 1] != 0){
        cout << 2 << '\n';
        cout << 2 << ' ' << n - 1 << '\n';
        cout << 1 << ' ' << 3 << '\n';
    }
    else if(a[n - 1] != 0){
        cout << 2 << '\n';
        cout << 1 << ' ' << n - 1 << '\n';
        cout << 1 << ' ' << 2 << '\n';
    }
    else if(a[0] != 0){
        cout << 2 << '\n';
        cout << 2 << ' ' << n << '\n';
        cout << 1 << ' ' << 2 << '\n';
    }
    else{
        cout << 3 << '\n';
        cout << 1 << ' ' << n - 2 << '\n';
        cout << 2 << ' ' << 3 << '\n';
        cout << 1 << ' ' << 2 << '\n';
        return;
    }









}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
