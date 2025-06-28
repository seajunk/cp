#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*

       a has min(a), max(a)
       b has min(b), max(b)

       jell takes b largest swap with a smallest,
       a has max(a), max(b)
       b has min(a), min(b)


       gell takes a largest swap with b smallest,
       a has min(a, b)
       b has max(a, b)


       then alternates swapping min(a, b) and max(a, b) 
    */

    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n];
    ll b[m];

    ll suma = 0, sumb = 0;
    ll mna = LLONG_MAX, mnb = mna; 
    ll mxa = LLONG_MIN, mxb = mxa; 

    for(int i = 0; i < n; i++){
        cin >> a[i];
        suma += a[i];
        mxa = max(mxa, a[i]);
        mna = min(mna, a[i]);
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        sumb += b[i];
        mxb = max(mxb, b[i]);
        mnb = min(mnb, b[i]);
    }

    // first round
    suma += max(0ll, mxb - mna);
    sumb -= max(0ll, mxb - mna);

    if(k == 1){
        cout << suma << '\n';
        return;
    }

    // second round
    suma -= max(mxa, mxb);
    suma += min(mna, mnb);
    sumb += max(mxa, mxb);
    sumb -= min(mna, mnb);


    if(k % 2 == 0){
        cout << suma << '\n';
        return;
    }

    suma += max(mxa, mxb);
    suma -= min(mna, mnb);

    cout << suma << '\n';
    return;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
