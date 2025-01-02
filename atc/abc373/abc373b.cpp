#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    unordered_map<char, ll> m;

    string p;
    cin >> p;

    for(int i = 0; i < 26; i++){
        m[p[i]] = i;
    }


    ll curr = m['A'];
    ll ans = 0;

    for(int i = 1; i < 26; i++){
        ll nxt = m['A' + i];

        ans += abs(curr - nxt);

        curr = nxt;


    }

    cout << ans << '\n';


}
