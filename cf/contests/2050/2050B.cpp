#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];

    if(sum % n != 0){
        cout << "NO\n";
        return;
    }


    ll needed = sum / n;

    ll sumodd = 0;
    ll sumeven = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) sumeven += a[i];
        else sumodd += a[i];
    }

    if((sumodd % needed != 0) || (sumeven % needed != 0)){
        cout << "NO\n";
        return;
    }


    if(sumodd < (needed * (n/2))){
        cout << "NO\n";
        return;
    }

    if(sumeven < (needed * (n/2 + (n%2==1)))){
        cout << "NO\n";
        return;
    }



    cout << "YES\n";


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
