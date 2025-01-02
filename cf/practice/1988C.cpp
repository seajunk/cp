#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void solve(){
    ll n;
    cin >> n;

    // n = 1111 
    // a = 0111 1011 1101 1110 1111
    // n = 1001
    // a = 0001 1000 1001

    vector<ll> ans;
    for(int i = 63; i >= 0; i--){
        if(n & (1ULL << i)){
            if((n & ~(1ULL << i)) != 0){
                ans.push_back((n & ~(1ULL << i)));
                
            }
        }
    }
    ans.push_back(n);

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}
