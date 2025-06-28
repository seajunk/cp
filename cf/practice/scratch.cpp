#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void lst(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll lst[2*n];
    for(int i = 0; i < n; i++) lst[i + n] = a[i];
    for(int i = n - 1; i > 0; i--) lst[i] = min(lst[2*i], lst[2*i+1]);

    ll lazy[n];
    for(int i = 0; i < n; i++) lazy[i] = 0;


    auto apply = [&](ll i, ll x){
        lst[i] += x;
        if(i < n) lazy[i] += x;
    };

    auto fix = [&](ll i){
        while(i > 1){
            lst[i/2] = min(lst[i], lst[i^1]) + lazy[i/2];
            i /= 2;
        }
    };

    auto propogate = [&](ll i){
        ll h = 64 - __builtin_clzll(n) - 1;
        for(int a = h; a > 0; a--){
            if(lazy[i>>a] != 0){
                apply(2*(i>>a), lazy[i>>a]);
                apply(2*(i>>a)+1, lazy[i>>a]);
                lazy[i>>a] = 0;
            }
        }
    };

    auto update = [&](ll l, ll r, ll x){
        l += n, r += n;
        ll l0 = l, r0 = r;
        for(; l < r; l /= 2, r /= 2){
            if(l&1) apply(l++, x);
            if(r&1) apply(--r, x);
        }
        fix(l0);
        fix(r0 - 1);
    };

    auto query = [&](ll l, ll r){
        l += n; r += n;
        propogate(l);
        propogate(r - 1);
        ll ans = LLONG_MAX;
        for(; l < r; l /= 2, r /= 2){
            if(l&1) ans = min(ans, lst[l++]);
            if(r&1) ans = min(ans, lst[--r]);
        }
        return ans;
    };

    cout << "now accepting queries\n";

    while(true){
        ll type; cin >> type;
        if(type == 0){
            ll l, r, x; cin >> l >> r >> x;
            update(l, r, x);
        }
        else if(type == 1){
            ll l, r; cin >> l >> r;
            cout << query(l, r) << '\n';
        }
        else{
            for(int i = 0; i < n; i++) cout << query(i, i + 1) << ' ';
            cout << '\n';
        }
    }











}


void st(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll st[2*n];
    for(int i = 0; i < n; i++) st[i + n] = a[i];
    for(int i = n - 1; i > 0; i--) st[i] = min(st[2*i], st[2*i+1]);

    auto update = [&](ll i, ll x){
        for(st[i += n] = x; i > 1; i /= 2) st[i/2] = min(st[i], st[i^1]); 
    };


    auto query = [&](ll l, ll r){
        ll ans = LLONG_MAX;
        for(l += n, r += n; l < r; l /= 2, r /= 2){
            if(l&1) ans = min(ans, st[l++]);
            if(r&1) ans = min(ans, st[--r]);
        }
        return ans;
    };



    cout << "now accepting queries\n";
    while(true){
        ll type; cin >> type;
        if(type == 0){
            ll i, x; cin >> i >> x;
            update(i, x);
        }
        else if(type == 1){
            ll l, r; cin >> l >> r;
            cout << query(l, r) << '\n';
        }
        else{
            for(int i = 0; i < 2*n; i++) cout << st[i] << ' ';
            cout << '\n';

        }


    }









}




