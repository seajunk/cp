#include <iostream>
#include <string>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
    ll n;
    string s;
    cin >> n >> s;;

    if(s[0] == s[n - 1]){
        cout << "NO" << '\n';
    }
    else{
        cout << "YES" << '\n';
    }


}

int main(){
    ll t; 
    cin >> t;
    while(t--) solve();
}

