#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    ll a[n], b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(b, b + m);

    a[0] = min(a[0], b[0] - a[0]);

    for(int i = 1; i < n; i++){
        // want smallest a[i] such that a[i] >= a[i - 1]

        ll lo = 0, hi = m;
        while(lo < hi){
            ll mid = (hi - lo)/2 + lo;
            if(b[mid] - a[i] >= a[i - 1]) hi = mid;
            else lo = mid + 1;
        }
        ll temp;
        if(lo == m) temp = a[i];
        else{
            if(a[i] >= a[i - 1]) temp = min(a[i], b[lo] - a[i]);
            else temp = b[lo] - a[i];
        }
        if(temp < a[i - 1]){
            cout << "NO\n";
            return;
        }
        a[i] = temp;
    }

    cout << "YES\n";





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
