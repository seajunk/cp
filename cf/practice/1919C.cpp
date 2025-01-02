#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // want to split a into two subsequences such that total amount of strict increases is minimized 


    // 3 30 2 20 1 10 -> 3 2 1, 30 20 10  

    // conj: if the split is optimal and # of increases in a > 0 -> # of increase s + t < # of increase of a ?

    // conj: want to sepereate at an increase in a 
    // 1 1 2 -> nessecarily need to slit an increase  1 1, 2


    // 8 2 3 1 1 7 4 3
    // 8 2 1 1 7 
    // 3

    // if new <= both -> choose smaller of the two
    // if new > both -> choose smaller of the two
    // if new > one and < other choose >

    vector<ll> t, s;
    t.push_back(a[0]);

    for(int i = 1; i < n; i++){

        ll ttop = t[t.size() - 1];
        ll stop = (s.size() > 0) ? s[s.size() - 1] : LLONG_MAX;

        if(a[i] <= ttop && a[i] <= stop){
            if(ttop > stop) s.push_back(a[i]);
            else t.push_back(a[i]);
        }
        else if(a[i] > ttop && a[i] > stop){
            if(ttop > stop) s.push_back(a[i]);
            else t.push_back(a[i]);
        }
        else if(a[i] > ttop){
            s.push_back(a[i]);
        }
        else{ // a[i] > stop
            t.push_back(a[i]);
        }
    }

    ll ans = 0;

    for(int i = 1; i < t.size(); i++){
        if(t[i] > t[i - 1]) ans++;
    }
    for(int i = 1; i < s.size(); i++){
        if(s[i] > s[i - 1]) ans++;
    }

    cout << ans << '\n';












}


int main(){
    ll t; cin >> t;
    while(t--) solve();
}
