#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s; cin >> s;
    ll n = s.size();
    // sum of digits divisible by 9 <=> number is divisible by 9
    // all 0s 9s can be ignored

    // 3 3 = 6
    // 2 3 = 5
    
    // 6 need 3
    // 5 need 4

    // 62254522632
    // 39 need 6
    // have 5 2s 1 3s

    // 16






    ll sum = 0;

    for(int i = 0; i < n; i++){
        sum += (s[i] - '0');
    }

    if(sum % 9 == 0){
        cout << "YES\n";
        return;
    }

    ll need = ((sum + 9 - 1) / 9) * 9 - sum;

    ll two = 0;
    ll three = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '2') two++;
        else if(s[i] == '3') three++;
    }






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
