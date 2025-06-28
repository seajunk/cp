#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s; cin >> s;

    /*
       s is well fromed bracketing
       identify if possible to remove one ( and one ) such that s becomes ill formed









    */



    ll n = s.size();


    ll pfs1[n + 1], pfs2[n + 1];

    pfs1[0] = 0, pfs2[0] = 0;


    for(int i = 1; i <= n; i++){
        if(s[i - 1] == '('){
            pfs1[i] = pfs1[i - 1] + 1;
            pfs2[i] = pfs2[i - 1];
        }
        else{
            pfs1[i] = pfs1[i - 1];
            pfs2[i] = pfs2[i - 1] + 1;
        }
    }




    for(int i = 0; i < n; i++){
        if(s[i] == '('){
        }
        else{

        }
    }










}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
