#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    string s; cin >> s;
    ll n = s.size();
    ll cnt2 = 0;
    ll cnt3 = 0;

    for(int i = 0; i < n; i++){
        if(s[i] - '0' == 2) cnt2++;
        if(s[i] - '0' == 3) cnt3++;
    }


    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += s[i] - '0';
    }

    for(int i = 0; i < min(9ll, cnt2) + 1; i++){
        for(int j = 0; j < min(9ll, cnt3) + 1; j++){
            ll additional = i*2 + j*6;
            if((sum + additional) % 9 == 0){
                cout << "YES\n";
                return;
            }

        }
    }
    cout << "NO\n";
    return;


    // why is using 2/3 more than 9 times redundant?

    // 2 * 9 = 18 = 0
    // 2 * 8 = 16 = 7



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

