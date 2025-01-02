#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    if(k >= 3){
        cout << 0 << '\n';
        return;
    }
    if(k == 1){
        sort(a, a + n);
        ll mn = LLONG_MAX;
        for(int i = 0; i < n; i++) mn = min(mn, a[i]);
        for(int i = 1; i < n; i++) mn = min(abs(a[i] - a[i - 1]), mn);
        cout << mn << '\n';
        return;
    }

    // k == 2

    // this question is stupid

    map<ll, ll> b;

    for(int i = 0; i < n; i++){
        if(b.find(a[i]) == b.end()) b[a[i]] = 1;
        else b[a[i]]++;
    }


    ll mn = LLONG_MAX;
    for(int i = 1; i < n; i++) mn = min(mn, abs(a[i] - a[i - 1]));


    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ll temp = abs(a[i] - a[j]);
            mn = min(mn, temp);

            if(b.find(temp) == b.end()) b[temp] = 1;
            else{
                cout << 0 << '\n';
                return;
            }

            auto tempit = b.find(temp);

            if(next(tempit) != b.end()) mn = min(mn, abs(temp - next(tempit)->first));
            if(tempit != b.begin()) mn = min(mn, abs(temp - prev(tempit)->first));


            if(b[temp] == 1) b.erase(temp);
            else b[temp]--;
        }
    }

    cout << mn << '\n';

















}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
