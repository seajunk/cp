#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];


    /*
       in one operation, can do one of,
       (1) a[i] = b[i + 1]
       (2) b[i] = a[i + 1]


       Additionally, before operations we can choose at most one i such that a[i] and b[i] are revmoed.


       want to maximize match of a and b after any number of operations



       a[i], b[i] <= n
       n <= 2e5


       how to get max match if we didnt have the one additonal operation at the start?


       x0x0x0x0x0x0
       0x0x0x0x0x0x

       call the x's the main diagonal and 0's the anti diagonals


       wlog suppose a[i] lies on diagonal and b[i] lies on anti diaognal
       if some x = a[i] appears in the antidiagonal after b[i] or some y = b[i] appears on the main diagonal after a[i], then we can match every element of a[0, i] and b[0, i]

       then we can just iterate from right to left while keeping some suffix set main/anti diagonals and get the largest prefix we can match completely

       the single deletion operation at the start is kind of like antidiagonal and main diagonal suffxi arrays
    */


    set<ll> diag, adiag;
    ll ans = 0;


    // a[i] is on diag if i % 2 == 0
    // a[i] is on adiag if i % 2 == 1

    for(ll i = n - 1; i >= 0; i--){
        // first do the diagonal swapping, then the normal operation
        if(i > 0){
            // deleting a[i], b[i] 
            if((i-1)%2 == 0){
                if(adiag.find(b[i-1]) != adiag.end()) ans = max(ans, i);
                if(diag.find(a[i-1]) != diag.end()) ans = max(ans, i);;
            }
            else{
                if(diag.find(b[i-1]) != diag.end()) ans = max(ans, i);
                if(adiag.find(a[i-1]) != adiag.end()) ans = max(ans, i);
            }
        }

        if(a[i] == b[i]) ans = max(ans, i + 1);

        if(i%2==0){
            if(diag.find(b[i]) != diag.end()) ans = max(ans, i + 1);
            if(adiag.find(a[i]) != adiag.end()) ans = max(ans, i + 1);;
            diag.insert(a[i]);
            adiag.insert(b[i]);
        }
        else{
            if(adiag.find(b[i]) != adiag.end()) ans = max(ans, i + 1);
            if(diag.find(a[i]) != diag.end()) ans = max(ans, i + 1);;
            adiag.insert(a[i]);
            diag.insert(b[i]);
        }
    }


    cout << ans << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
