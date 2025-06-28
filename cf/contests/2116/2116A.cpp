#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a, b, c, d; 
    cin >> a >> b >> c >> d;


    /*
       a c
       b d

       knight dying is same thing as killing

       so each guy will try to kill others  min(health, knight health)
    */


    if(min(a, c) >= min(b, d)) cout << "Gellyfish" << '\n';
    else cout << "Flower" << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

