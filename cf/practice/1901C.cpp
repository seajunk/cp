#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){

    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // conj: x remains constat* 
    // heur: # of iterations is proportional to the value furthest from x in a 
    // conj: because of ceil division, if a[i] < x, (a[i] + x)/2 will never reach x

    // 1 3 -> 2
    // 1 4 -> 2|3  






    


    sort(a, a + n);

    ll mean = (a[0] + a[n - 1])/2;

    ll ans = 0;

    while(mean < a[n - 1]){
        a[n - 1] = (a[n - 1] + mean)/2;
        ans++;
    }


    if(a[0] < mean){
        cout << ans + 1 << '\n';
        if(ans > n) return;
        for(int i = 0; i < ans; i++) cout << mean << ' ';
        cout << mean - 1 << '\n';
    }
    else{
        cout << ans << '\n';
        if(ans > n) return;
        for(int i = 0; i < ans; i++) cout << mean << ' ';
        cout << '\n';
    }






























}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

