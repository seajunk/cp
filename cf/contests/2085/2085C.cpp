#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x, y; cin >> x >> y;

    // 0010
    // 0101 

    // 10011 10100
    // 01010 01011


    // 0011110
    // 0000010 fixable

    // 0011100 
    // 0001110 fixable

    // 0011100
    // 0100100 not fixable

    // x + y = x ^ y iff no carries happen in x + y ie x and y dont share any common set bits

    // get all blocks of the form 011111.. and compare it to other guy, if other guy is 00001...
    // 0111111...1 
    // 0000011...1
    // then can add lowest set bit of first guy and should work

    // doesnt work if 


    bitset<64> xbs(x), ybs(y);

    vector<vector<ll>> blocks;

    bitset<64> k(0);

    for(int i = 0; i < 64; i++){
        if(xbs[i] == 1 && ybs[i] == 1){
            ll start = i;
            while(xbs[i] == 1 && ybs[i] == 1) i++;
            if(xbs[i] == 0 && ybs[i] == 0){
                if(start != 0){
                    if(xbs[start - 1] == 0 && ybs[start - 1] == 0){
                        cout << -1 << '\n';
                    }
                    else{
                        k[start - 1] = 1;
                    }
                }
                else{
                    cout << -1 << '\n';
                    return;;
                }
            }
            else if(ybs[i] == 0){
                while(xbs[i] == 1) i++;
                if(ybs[i] == 1){
                    cout << -1 << '\n';
                    return;
                }
                else{
                    k[start] = 1;
                }
            } 
            else if(xbs[i] == 0){
                while(ybs[i] == 1) i++;
                if(xbs[i] == 1){
                    cout << -1 << '\n';
                    return;
                }
                else{
                    k[start] = 1;
                }
            }
        }
    }


    cout << xbs << '\n';
    cout << ybs << '\n';
    cout << k << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
