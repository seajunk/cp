#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s; cin >> s;

    // s starts with 1
    // want to choose two substrings s1 s2 to maximize s1^s2 

    // conj: we want one of the strings to be s itself? want to utilize the leading 1

    // 111010010 
    //    p 
    // want to make p 1? 

    // conj: s2 nessecarily makes p into 1 -> s2 has len n - p



    ll n = s.size();
    bool haszero = false;
    ll p;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            p = i;
            haszero = true;
            break;
        }
    } 


    if(!haszero){
        cout << 1 << ' ' << n << ' ' << 1 << ' ' << 1 << '\n';
        return;
    }



    bitset<5000> mx = 0;
    ll mxl = -1;
    bitset<5000> s1(s);
    for(ll l = 0; l < p; l++){
        bitset<5000> s2(s.substr(l, n - p));

        bitset<5000> temp = s1^s2;

        if(temp.to_string() >= mx.to_string()){
            mx = temp;
            mxl = l;
        }
    }


    cout << 1 << ' ' << n << ' ' << mxl + 1 << ' ' << mxl + (n - p) << '\n';




















    





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
