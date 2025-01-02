#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    // 1023 -> 1103 | 1022
    // value for swapping a[i] is gain - lose
    // lose =  a[i] * 10^(n-i - 1) +  a[i - 1] * 10^(n - i)
    // gain = (a[i] - 1) * 10^(n - i) + a[i - 1] * 10^(n - i - 1)



    // obs: advantageous to swap a[i-1] a[i] when a[i] - 1 > a[i-1]


    //1709 -> 6109 -> 6180 -> 6710


    // 11555 -> 311555 -> 

    // conj: from left to right, keep swapping a[i] with left until no longr advatnageuous -> optimal answer
    // at most 9*n iterations

    string s; cin >> s;
    ll n = s.size();
    for(ll i = 1; i < n; i++){
        ll j = i;
        while(s[j] > 0 && j > 0 && (s[j] - 1) > s[j - 1]){
            s[j]--;
            swap(s[j], s[j - 1]);
            j--;
        }
    }

    cout << s << '\n';









}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
