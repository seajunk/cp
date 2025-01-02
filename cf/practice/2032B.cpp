#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;

    // [1, 2, 3, 4, 5, ..., n]

    // n is odd
    // partition into some m sub arrays st each sub array is odd length and median of median is k

    // >> 3 2
    // 1 2 3 -> [1] [2] [3]
    // 1 no 2 yes 3 no



    // 1 2 3 4 5 -> [1] [2] [3, 4, 5] / [1, 2, 3] [4] [5] / [1] [2, 3, 4] [5]
    // 

    // fact: med of med will be median of middle array 
    // so m is possible iff we can make m the median of the middle array
    // 1 2 3 4 5 6 7
    // [1] [2 3 4] [5 6 7]
    // 1 2 3 4 5 6 7



    // fact: # of guys left parity == # of guys right parity
    // eg 1 2 3 4 5 -> 3 has 2 guys left and 2 guys right, 1 has 0 guys left 4 guys right etc


    // conjecture: # of guys left of k = odd  => k works
    // 1 2 3 4 5




    // fact n > 1 and k == 1 or k == n => k cant work
    // cus k cant be a part of the middle array, will always be a part of the left/right most array




    // >> 5 2
    // >> 1 2 3
    // [1, 2, 3, 4, 5, 6, 7] [8] [9 10 11 12 13 14 15] -> 4 8 12 -> 8

    if(n == 1){
        cout << 1 << '\n' << 1 << '\n';
        return;
    }
    if(k == 1 || k == n){
        cout << -1 << '\n';
        return;
    }
    if((k - 1) % 2 == 1){
        cout << 3 << '\n';
        cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
    }
    else{
        cout << 3 << '\n';
        cout << 1 << ' ' << k - 1 << ' ' << k + 2 << '\n';
    }
    
    // [1, 2, 3, 4, 5, 6, 7, 8, 9] k = 4
    // 1 2 3 4 5 6 7












}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

