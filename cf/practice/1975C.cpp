#include <iostream>
#include <algorithm>
#include <deque>
#include <utility>
#include <stack>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
    ll n, a[N];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];


    if(n == 2){
        cout << min(a[0], a[1]) << '\n';
        return;
    }

    // base case
    deque<ll> d;
    ll w[3] = {a[0], a[1], a[2]};
    sort(w, w+3);
    ll ans = w[1];
    d.push_front(a[0]);
    d.push_front(a[1]);
    d.push_front(a[2]);

    for(int i = 3; i < n; i++){
        d.pop_back();
        d.push_front(a[i]);
        for(int i = 0; i < 3; i++) w[i] = d[i];
        sort(w, w + 3);
        ans = max(ans, w[1]);
    }

    cout << ans << '\n';
}

int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}


/*
   stack<pair<ll, ll>> s1, s2;
   ll ans, mx;
   mx = -1;
   ans = --1;
   mx = -1;
   ans = -1;
   for(int i = 0; i < n; i++){
   if(i < 3){
   mx = max(mx, a[i]);
   ans = max(ans, mx);
   s1.push({a[i], mx});
   }
   else{

   s1.push({a[i], });

   }
   }
   */

