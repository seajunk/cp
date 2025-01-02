#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;

    string temp = "";
    for(int i = 0; i < k; i++){
        temp += string('a' + i, 1);
    }

    cout << temp << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
