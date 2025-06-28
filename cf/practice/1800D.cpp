#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    ll ans = 1;


    char first = s[0], second = s[1];
    for(int i = 2; i < n;){
        if(s[i] == first){
            first = second;
            second = s[i];
            i++;
        }
        else{
            first = second;
            second = s[i];
            i++;
            ans++;
        }
    }

    cout << ans << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
