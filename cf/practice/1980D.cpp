#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll mod(ll n, ll k){
    return ((n % k + k) % k);
} 

ll gcd(ll a, ll b){
    if(a == 0) return b; 
    else return gcd(mod(b, a), a);
}


void solve(){
    // have
    // gcd(a, b) divides a, divides b
    // gcd(b, c) divides divies b, divides c

    // want 
    // gcd(a, c) divides a, divides c, largest 


    // 1 2 3 4 5 6 7 8
    // (1, 2)/(2 ,3)/(3, 4)/(4, 5)/(5, 6)/(6, 7)/(7, 8)

    // 1 2 3 4   6 7 8
    // (1, 2) (2, 3) (3, 4)        (4, 6) (6, 7) (7, 8)




    ll n; cin >> n;
    ll a[n], b[n - 1];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++) b[i] = gcd(a[i], a[i + 1]);

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
