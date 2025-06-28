#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    /*
       want smallest substring k such that we can make a string t by concating k to itself any number of times where t is at most 1 away from s

       when does substring k of s work with lenght m work?

       note that m must divide n.

       m works iff 


       for each i = 0; i < divisor; i++, 



       ababababaa

       guys[i] = {s[i], s[i + m], s[i + 2m], ... (n - m + i)} 








    */


    vector<ll> divisors;

    for(int i = 1; i <= n; i++){
        if(n % i == 0) divisors.push_back(i);
    }

    for(ll divisor : divisors){
        string pf(s, 0, divisor);
        string sf(s, n - divisor, divisor);
        string potential1 = "";
        string potential2 = "";
        for(int i = 0; i < n/divisor; i++) potential1 += pf;
        for(int i = 0; i < n/divisor; i++) potential2 += sf;

        ll pferror = 0;
        for(int i = 0; i < n; i++){
            if(potential1[i] != s[i]) pferror++;
        }
        ll sferror = 0;
        for(int i = 0; i < n; i++){
            if(potential2[i] != s[i]) sferror++;
        }

        if(min(pferror, sferror) <= 1){
            cout << divisor << '\n';
            return;
        }

    }

    cout << "shit went wrong\n";
    return;

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

