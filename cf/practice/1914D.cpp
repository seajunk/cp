#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(2));
    vector<vector<ll>> b(n, vector<ll>(2));
    vector<vector<ll>> c(n, vector<ll>(2));


    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        a[i] = {i, in};
    }
    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        b[i] = {i, in};
    }
    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        c[i] = {i, in};
    }
    sort(a.begin(), a.end(), [](auto l, auto r){ return l[1] < r[1];});
    sort(b.begin(), b.end(), [](auto l, auto r){ return l[1] < r[1];});
    sort(c.begin(), c.end(), [](auto l, auto r){ return l[1] < r[1];});

    vector<vector<ll>> A = {a[n - 1], a[n - 2], a[n - 3]};
    vector<vector<ll>> B = {b[n - 1], b[n - 2], b[n - 3]};
    vector<vector<ll>> C = {c[n - 1], c[n - 2], c[n - 3]};

    ll mx = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                set<ll> s;
                s.insert(A[i][0]);
                s.insert(B[j][0]);
                s.insert(C[k][0]);
                if(s.size() == 3) mx = max(mx, A[i][1] + B[j][1] + C[k][1]);
            }
        }
    }

    cout << mx << '\n';




}

int main(){
    ll t; cin >> t; 
    while(t--) solve();
}
