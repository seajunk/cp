#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    /*
       have sequence a of length n

       in one operation we can 

       1. reverse, ie a0, a1, a2, ..., an-1 -> an-1, ..., a2, a1, a0
       2. difference, ie a0, a1, a2, ..., an-1 -> a2-a1, a3-a2, ..., an-1 - an-2

       want to maximize sum of sequence after arbitrary operations


       1 <= n <= 50
       -1000 <= a[i] <= 1000


       reverse by itself doesnt change sum
    
       operation 2 looks like this,
       1, 2, 3, 4, 5 -> 2-1, 3-2, 4-3, 5-4 -> 1 1 1 1

       operation 2 is only beneficial if a1 - a0 + a2 - a1 + ... + an-1 - an-2 > a0 + a1 + ... + an-1
       <=> a1 + a2 + ... an-1 > an-1 <=> a1 + a2 + ... an-2 > 0

       if array is profitable from operation 1, reversed array is unprofitable from operation 2


       0, -100, 100 -> -100 200



       1 2 3 4 -> 2-1, 3-2, 4-3 -> 1 1 1 -> 3
       4 3 2 1 -> 4-3, 3-2, 1-2 -> -1 -1 -1 -> -3

       reversing array will negate each element in array after operation 1

       so we can do something like

       if abs(sum after operation) == current sum stop ?


       the idea is that if we do operation 1 then 2, the sum is the negation of the value we would get after doing operation 2 then 1.


       then ... ?





    */

    ll n; cin >> n; 
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];







}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
