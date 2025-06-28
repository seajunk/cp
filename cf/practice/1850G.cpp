#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }



    /*
       each diagonal, antidiagonal, horizontal, vertical line is characterized by one integer 


       iterate over points and get every line that exists and count of points on that line

       then for each points (x[i], y[i]), fix compass as (x[i], y[i]), then count of points that the star can be at is the count of points on all lines that compass is on minus 4
    */


    map<ll, ll> diag, adiag, hori, vert;

    for(int i = 0; i < n ; i++){
        if(hori.find(y[i]) == hori.end()) hori[y[i]] = 1;
        else hori[y[i]]++;

        if(vert.find(x[i]) == vert.end()) vert[x[i]] = 1;
        else vert[x[i]]++;

        if(diag.find(x[i] - y[i]) == diag.end()) diag[x[i] - y[i]] = 1;
        else diag[x[i] - y[i]]++;

        if(adiag.find(x[i] + y[i]) == adiag.end()) adiag[x[i] + y[i]] = 1;
        else adiag[x[i] + y[i]]++;
    }

    ll ans = 0;

    for(int i = 0; i < n; i++){
        ans += hori[y[i]] + vert[x[i]] + diag[x[i] - y[i]] + adiag[x[i] + y[i]] - 4;
    }

    cout << ans << '\n';







}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
