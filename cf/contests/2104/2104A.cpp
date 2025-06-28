#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a, b, c; cin >> a >> b >> c;



    if((a + b + c) % 3 != 0){
        cout << "NO\n";
        return;
    }


    ll target = (a + b + c) / 3;



    if(a > target){
        cout << "NO\n";
        return;
    }

    if(b > target){
        cout << "NO\n";
        return;
    }

    if(c < target){
        cout << "NO\n";
        return;
    }



    if(target - a + target - b == c - target){
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    return;






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


