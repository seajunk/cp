#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;



    /*
       if 
       10...10 or 01.....01
       exists, can cut cost by two

       else if
       10....1 or 01...0 or 1....01 or 0....10 
       exists, can cut cost by one

       otherwise cost cant be cut
    */

    // 1 0 1




    ll ans = 0;
    bool zero = true;

    for(int i = 0; i < n; i++){
        if(zero){
            if(s[i] == '0') ans++;
            else{
                zero = false;
                ans += 2;
            }
        }
        else{
            if(s[i] == '0'){
                zero = true;
                ans += 2;
            }
            else ans++;
        }
    }

    ll onezero = 0;
    for(int i = 1; i < n; i++){
        if(s[i - 1] == '1' && s[i] == '0') onezero++;
    }

    ll zeroone = 0;
    for(int i = 1; i < n; i++){
        if(s[i - 1] == '0' && s[i] == '1') zeroone++;
    }

    if(onezero >= 2 || zeroone >= 2){
        cout << (ans - 2) << '\n';
        return;
    }


    // there has to be a better way
    ll pfcnt0[n + 1];
    pfcnt0[0] = 0;
    for(int i = 1; i <= n; i++) pfcnt0[i] = pfcnt0[i - 1] + (s[i - 1] == '0');

    ll pfcnt1[n + 1];
    pfcnt1[0] = 0;
    for(int i = 1; i <= n; i++) pfcnt1[i] = pfcnt1[i - 1] + (s[i - 1] == '1');

    ll temp = ans;

    for(int i = 1; i < n; i++){
        if(s[i - 1] == '1' && s[i] == '0'){
            if(pfcnt1[n] - pfcnt1[i + 1] > 0){
                temp = min(temp, ans - 1);
            }
            if(pfcnt0[i] > 0){
                temp = min(temp, ans - 1);
            }
        }
        if(s[i - 1] == '0' && s[i] == '1'){
            if(s[0] == '1'){
                temp = min(temp, ans - 2);
            }
            if(pfcnt0[n] - pfcnt0[i + 1] > 0){
                temp = min(temp, ans - 1);
            }
            if(pfcnt1[i] > 0){
                temp = min(temp, ans - 1);
            }
        }
    }


    if(s[0] == '1' && pfcnt0[n] > 0){
        temp = min(temp, ans - 1);
    } 




    cout << temp << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
