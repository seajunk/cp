#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    set<ll> a;
    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        a.insert(in);
    }
    
    // conj: always want to place extra black next to black

    // 0 1 1 0 0 0 0 1 0 0 0 0 1 1 0





    if(n % 2 == 0){
        ll ans = LLONG_MIN;

        for(auto it = next(a.begin()); it != a.end(); it++){
            ans = max(ans, *it -  *prev(it));
            it++;
            if(it == a.end()) break;
        }
        cout << ans << '\n';
        return;
    }

    ll ans = LLONG_MAX;
    for(auto it = a.begin(); it != a.end(); it++){

        if(a.find(*it - 1) == a.end()){
            set<ll> b = a;
            b.insert(*it - 1);
            ll currans = LLONG_MIN;
            for(auto it2 = next(b.begin()); it2 != b.end(); it2++){
                currans = max(currans, *it2 - *prev(it2));
                it2++;
                if(it2 == b.end()) break;
            }

            ans = min(ans, currans);
        }
        if(a.find(*it + 1) == a.end()){
            set<ll> b = a;
            b.insert(*it + 1);
            ll currans = LLONG_MIN;
            for(auto it2 = next(b.begin()); it2 != b.end(); it2++){
                currans = max(currans, *it2 - *prev(it2));
                it2++;
                if(it2 == b.end()) break;
            }

            ans = min(ans, currans);
        }
    }


    // awful code


    cout << ans << '\n';

    

















}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
