#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){

    // need exactly x a[i] > b[i]

    // a = [1, 2, 3, 3, 10] 
    // b = [0, 1, 2, 7, 9]

    // prefix "a bigger than b" array
    // 1 2 3 3 5 

    // heur: want to start from biggest a[i] and continue in decreasing order since if we went in increasing order and used up all the small guys and reached x, we might not be able to maintain x if remaining a[i] are too big

    // sort a, while curr < x match a[i] with lb in b? then when curr == x, match a[i] with smallest b ge than a[i]

    ll n, x; cin >> n >> x;
    vector<vector<ll>> a(n, vector<ll>(2));
    map<ll, ll> b;

    for(int i = 0; i < n; i++){
        a[i][0] = i;
        cin >> a[i][1];
    }

    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        if(b.find(in) == b.end()) b[in] = 1;
        else b[in]++;
    }

    ll curr = 0;

    sort(a.begin(), a.end(), [](auto l, auto r){
            return l[1] < r[1];
            });

    ll ans[n];
    for(int i = 0; i < n; i++){
        if(curr < x){
            auto it = b.lower_bound(a[i][1]);



        }
    }



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
