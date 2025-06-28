#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<ll> a(n - 1);
    for(int i = 0; i < n - 1; i++) cin >> a[i];

    // 1 6 8 12 15
    // 1 6 12 15
    // 1 5 6 3

    // 1 3 6
    // 3 6
    // 3 3

    // this whole thing is so bad
    if(a[n - 2] != n*(n+1)/2){
        a.push_back(n*(n+1)/2);
        vector<ll> b(n);
        b[0] = a[0];
        for(int i = 1; i < n; i++) b[i] = a[i] - a[i - 1];
        vector<bool> seen(n + 1, false);
        for(int i = 0; i < n; i++){
            if(!(1 <= b[i] && b[i] <= n)){
                cout << "NO\n";
                return;
            }
            seen[b[i]] = true;
        }
        for(int i = 1; i <= n; i++){
            if(!seen[i]){
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }



    ll odd = LLONG_MAX;
    vector<bool> seen(n + 1, false);

    if(!(1 <= a[0] && a[0] <= n)){
        odd = a[0];
    }
    else seen[a[0]] = true;

    for(int i = 1; i < n - 1; i++){
        ll curr = a[i] - a[i - 1];
        if(!(1 <= curr && curr <= n)){
            if(odd != LLONG_MAX){
                cout << "NO\n";
                return;
            }
            odd = curr;
            continue;
        }

        if(seen[curr]){
            if(odd != LLONG_MAX){
                cout << "NO\n";
                return;
            }
            odd = curr;
        }
        seen[curr] = true;
    }

    ll cnt = 0;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        if(!seen[i]){
            cnt++;
            sum += i;
        }
    }
    if(cnt > 2){
        cout << "NO\n";
        return;
    }

    if(odd != sum){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    return;

    // i hope to god this shit doesnt actually work

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
