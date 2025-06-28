#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll x[n];
    for(int i = 0; i < n; i++) cin >> x[i];

    ll missing = 0;

    vector<bool> has(n + 1, false);
    for(int i = 0; i < n; i++){
        has[x[i]] = true;
    }

    for(int i = 1; i <= n; i++){
        if(!has[i]){
            missing = i;
            break;
        }
    }


    if(missing != 0){
        //printf("MISSING = %lld\n", missing);
        cout << "? " << missing << ' ' << (missing) % n + 1 << '\n';
        cout.flush();
        ll in; cin >> in;
        if(in != 0) cout << "! B\n"; 
        else cout << "! A\n"; 
        return;
    }

    ll first = -1, last = -1;
    for(int i = 0; i < n; i++){
        if(x[i] == 1) first = i + 1;
        if(x[i] == n) last = i + 1;
    }

    if(first == -1 || last == -1){
        cout << "shit went wrong\n";
        return;
    }

    cout << "? " << first << ' ' << last << '\n';
    cout.flush();
    ll in1; cin >> in1;

    cout << "? " << last << ' ' << first << '\n';
    cout.flush();
    ll in2; cin >> in2;


    if(in1 != in2){
        cout << "! A\n";
        return;
    }

    if(in1 < n - 1){
        cout << "! A\n";
        return;
    }

    cout << "! B\n";
    return;

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
