#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    // [1, 3] [2, 4] -> 1 
    // [2, 4] [1, 3] -> 3 inversion

    // [3, 4] [1, 2] -> 4 inversion
    // [1, 2] [3, 4] -> 0 inversion 

    // is sum of left > sum of right, swapping nessecarily results in le inversions???

    // [1, 10] [4, 5]


    // [10 9] [15 1] 


    // l1 + l2 > r1 + r2 -> either max(l1, l2) > r1, r2 or max(l1, l2) > max(r1, r2) and min(l1, l2) > min(r1, r2)
    // nessecarily max(l1, l2) > min(r1, r2)
    // if max(l1, l2) <= max(r1, r2) then since max(l1, l2) + min(l1, l2) > max(r1, r2) + min(r1, r2), 
    // 0 <= max(r1, r2) - max(l1, l2) < min(l1, l2) - min(r1, r2) -> 0 < min(l1, l2) - min(r1, r2) ->
    // min(l1, l2) > min(r1, r2)

    // so when sum of left is greater, nessecarily atleast 2 inversions exists -> swapping is always atleast neurtral  





    // 10 + 9 > 15 + 1


    // 


    ll n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(2));

    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
    }

    sort(a.begin(), a.end(), [](auto l, auto r){
            return l[0] + l[1] < r[0] + r[1];
            });

    for(auto e : a){
        cout << e[0] << ' ' << e[1] << ' ';
    }
    cout << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
