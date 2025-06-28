#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll b[n*(n-1)/2];
    for(int i = 0; i < n*(n-1)/2; i++) cin >> b[i];

    /*
       1st smallest value in a should appear n-1 times in b
       2nd smallest value in a should appear n-2 times in b
       3rd smallest value in a should appear n-3 times in b
       ...
       biggest value in a should appear 0 times in b

       so b[0] is smallest in a,
       b[n - 1] is second smallest in a,
       b[n - 1 + n - 2] is third smallest in a,
       ...
    */

    sort(b, b + (n*(n-1)/2));


    ll a[n];
    for(int i = 0; i < n - 1; i++){
        a[i] = b[i * n - (i*(i+1)/2)];
    }
    a[n - 1] = a[n - 2];

    for(int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

