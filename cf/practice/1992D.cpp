#include <iostream>
#include <string>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
    ll n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    
    ll i = -1;

    while(i < n){
        if(i == -1 || s[i] == 'L'){
            if(i + m >= n){
                cout << "YES" << '\n';
                return;
            }
            ll last_water = -1, last_log = -1;
            for(ll j = i + 1; j <= i + m; j++){
                if(s[j] == 'L') last_log = j;
                if(s[j] == 'W') last_water = j;
            }
            if(last_log != -1) i = last_log;
            else if(last_water != -1) i = last_water;
            else{ cout << "NO" << '\n'; return; } 
        }
        else if(s[i] == 'W'){
            if(k == 0){
                cout << "NO" << '\n';
                return;
            }
            i++;
            k--;
        }
        else{
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}


int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}
