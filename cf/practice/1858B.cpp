#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, d; cin >> n >> m >> d;
    set<ll> s;

    ll same = 0;
    ll decrease = 0;
    ll cookies = 0;

    for(int i = 0; i < m; i++){
        ll in; cin >> in;
        if(in == 1) same++; // this is bullshit
        s.insert(in);
    }
    s.insert(1);

    /*
       the change in cookes eaten when removing a salesman is determined by the salesman left and right of the guy getting removed
    */



    for(auto it = next(s.begin()); it != s.end(); it++){
        ll prv, nxt, curr;
        ll before, after;

        if(next(it) == s.end()){
            prv = *prev(it);
            curr = *it;

            // add cookies eaten in [prv, n]
            cookies += (curr - prv)/d + 1 - ((curr - prv)%d == 0);
            cookies += (n - curr)/d + 1;

            before = 1 + (curr - prv)/d + ((curr - prv)%d != 0) + (n - curr)/d;
            after = 1 + (n - prv)/d;
        }
        else{
            prv = *prev(it);
            nxt = *next(it);
            curr = *it;


            // add cookies eaten in [prv, curr)
            cookies += (curr - prv)/d + 1 - ((curr - prv)%d == 0);

            before = 1 + (curr - prv)/d + ((curr - prv)%d != 0) + (nxt - curr)/d + ((nxt - curr)%d != 0);
            after = 1 + (nxt - prv)/d + ((nxt - prv)%d != 0);
        }

        assert(before == after || before == after + 1);

        if(before == after) same++;
        else decrease++;
    }


    if(decrease == 0) cout << cookies << ' ' << same << '\n';
    else cout << (cookies - 1) << ' ' << decrease << '\n';
    return;

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

