#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll l, r; cin >> l >> r;

    bitset<30> curra = r, currb = l, currc = 0;



    ll msb = 30;

    for(int i = 29; i >= 0; i--){
        if(curra[i] == 1){
            msb = i;
            break;
        }
    }

    bool toggle = true;
    for(int i = msb; i >= 0; i--){
        if(curra[i] == 1 && currb[i] == 1) currc[i] = 0;
        if(curra[i] == 0 && currb[i] == 0) currc[i] = 1;

        if(toggle){
            if(curra[i] == 1 && currb[i] == 0) currc[i] = 0;
            if(curra[i] == 0 && currb[i] == 1) currc[i] = 0;
            toggle = !toggle;
        }
        else{
            if(curra[i] == 1 && currb[i] == 0) currc[i] = 1;
            if(curra[i] == 0 && currb[i] == 1) currc[i] = 1;
            toggle = !toggle;
        }

        if(currc.to_ullong() < currb.to_ullong()){
            currc[i] = 1;
            break;
        }
    }

    /*
    cout << curra.to_string() << '\n';
    cout << currb.to_string() << '\n';
    cout << currc.to_string() << '\n';
    */
    cout << curra.to_ullong() << ' ';
    cout << currb.to_ullong() << ' ';
    cout << currc.to_ullong() << '\n';


    ll a = curra.to_ullong();
    ll b = currb.to_ullong();
    ll c = currc.to_ullong();
    //cout << (curra^currb).to_ullong() + (currb^currc).to_ullong() + (currc^curra).to_ullong() << '\n';























}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
