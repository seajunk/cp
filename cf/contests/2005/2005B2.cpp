#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n, m, q; cin >> n >> m >> q;
    ll b[m], a[q];
    set<ll> S;


    for(int i = 0; i < m; i++){ cin >> b[i]; b[i]--; S.insert(b[i]);}
    for(int i = 0; i < q; i++){ cin >> a[i]; a[i]--;}




    for(int i = 0; i < q; i++){

        set<ll>::iterator ub;
        ub = S.upper_bound(a[i]);

        // a[i] > every teacher
        if(ub == S.end()){
            cout << (n - 1) - *(prev(ub)) << '\n';
        }

        // smallest teaher is greater than a[i]
        else if(ub == S.begin()){
            cout << *ub << '\n';
        }

        else{
            ll right = *ub, left = *(prev(ub));
            cout << (right - left) / 2 << '\n';
        }
    }

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
