#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, l, r; cin >> n >> l >> r;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // 1 3 [3 4 8 9 19] 3 4 20 3

    // inside: 3 4 8 9 19
    // outside: 1 3 3 3 4 20

    // C: can swap at most min(outside, inside); elements

    // greedily swap largest guy in inside with smallest guy in outside?

    l--;
    ll ans = 0; // sum on a[l, r)

    vector<ll> left, right , middle;

    for(int i = 0; i < n; i++){
        if(l <= i && i < r){
            ans += a[i];
            middle.push_back(a[i]);
        }
        else if(i < l) left.push_back(a[i]);
        else right.push_back(a[i]);
    }

    sort(middle.begin(), middle.end(), [](ll l, ll r){ return l > r;});
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    ll ansl = ans;
    for(int i = 0; i < min(middle.size(), left.size()); i++){
        if(middle[i] < left[i]){
            break;
        }
        ansl += left[i];
        ansl -= middle[i];
    }
    ll ansr = ans;
    for(int i = 0; i < min(middle.size(), right.size()); i++){
        if(middle[i] < right[i]){
            break;
        }
        ansr += right[i];
        ansr -= middle[i];
    }

    cout << min(ansr, ansl) << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
