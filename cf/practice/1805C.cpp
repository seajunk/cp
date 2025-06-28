#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;

    ll k[n];
    for(int i = 0; i < n; i++) cin >> k[i];
    sort(k, k + n);


    for(int i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        // D = (b - k)^2 - 4ac < 0
        // need k such that 
        // (b - k)^2 < 4ac

        // two cases
        // if 4ac > 0, want to minimize (b - k)^2, so binary search closest k to b?  
        // if 4ac <= 0, impossible since (b-k)^2 >= 0 
        // binary search twice?

        // parabola crosses x axis
        if(a * c <= 0){
            cout << "NO\n";
            continue;
        }


        ll lo, hi;


        // want smallest k >= b
        lo = 0, hi = n;
        while(lo < hi){
            ll mid = (hi - lo)/2 + lo;
            if(k[mid] >= b) hi = mid;
            else lo = mid + 1;
        }
        if(lo != n){
            if((b - k[lo])*(b - k[lo]) < 4*a*c){
                cout << "YES\n";
                cout << k[lo] << '\n';
                continue;
            }
        }

        // want largest k < b
        lo = -1, hi = n - 1;
        while(lo < hi){
            ll mid = (hi - lo + 1)/2 + lo;
            if(k[mid] < b) lo = mid; 
            else hi = mid - 1;
        }
        if(lo != -1){
            if((b - k[lo])*(b - k[lo]) < 4*a*c){
                cout << "YES\n";
                cout << k[lo] << '\n';
                continue;
            }
        }

        cout << "NO\n";
    }




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

