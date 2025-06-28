#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s; cin >> s;

    /*
       s consists of 'A' and 'B'

       AB -> BC 
       BA -> CB 
    */


    vector<ll> A, B;



    ll curra = 0, currb = 0;;

    for(int i = 0; i <= s.size(); i++){
        if(i == s.size()){
            if(curra != 0) A.push_back(curra);
            if(currb != 0) B.push_back(currb);
        }
        if(s[i] == 'B'){
            if(curra != 0) A.push_back(curra);
            curra = 0;
            currb++;
        }
        if(s[i] == 'A'){
            if(currb != 0) B.push_back(currb);
            currb = 0;
            curra++;
        }
    }

    ll ans = 0;
    ll mn = LLONG_MAX;

    for(auto e : A){
        mn = min(mn, e);
        ans += e;
    }



    bool found = false;
    for(auto e : B){
        if(e >= 2) found = true;
    }


    if(B.size() == 0){
        cout << 0 << '\n';
        return;
    }

    if(s[0] == 'B'){
        cout << ans << '\n';
        return;
    }

    if(s[s.size() - 1] == 'B'){
        cout << ans << '\n';
        return;
    }

    if(found){
        cout << ans << '\n';
        return;
    }


    cout << ans - mn << '\n';








}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
