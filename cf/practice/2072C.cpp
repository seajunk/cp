#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, x;  cin >> n >> x;

    // need array a[n] such that or of all elements is x and mex is maximized
    // get least significant 0 bit in x. then mex can be at most 01111...11 where 0 is the least sig 0 bit.

    bitset<64> xbs(x);

    ll zero = -1;
    for(int i = 0; i < 64; i++){
        if(xbs[i] == 0){
            zero = i;
            break;
        }
    }
    cout << '\n';

    ll mex = 1;

    for(int i = 0; i < zero; i++){
        mex *= 2;
    }


    vector<ll> ans;
    ll curr = 0;


    for(int i = 0; i < n; i++){
        ans.push_back(curr);
        if(curr < mex - 1)  curr++;
    }

    ll temp = 0;
    for(int i = 0; i < n; i++) temp |= ans[i];
    if(temp != x) ans[n - 1] = x;

    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';





}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
