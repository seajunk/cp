#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];


    // 8 8
    // 1 1 2 2 3 3 4 4
    ll ans = 1;
    for(ll p = 0, i = 0; p < k; p++){
        ll psize = 0;
        ll mxpsize = (n - i)/(k - p) + (n - i)%(k - p);
        

        while(psize < mxpsize){
            psize += 1;
            if(p%2 == 0){
                if(i == n - 1){
                    i++;
                    break;
                }

                if(a[i + 1] == ans){
                    i += 1;
                    continue;
                }

                if(a[i  + 1] != ans){
                    i += 1;
                    break;
                }
            }
            else{
                if(a[i] != ans){
                    cout << ans << '\n';
                    return;
                }

                ans += 1;

                if(i == n - 1){
                    i++;
                    break;
                }

                if(a[i + 1] == ans){
                    i += 1;
                    break;
                }

                if(a[i + 1]){
                    i += 1;
                }
            }
        }
        cout << psize << '\n';
    }

    cout << ans << '\n';
}

void solve2(){

    /*
       have array a of size n. want to partition a into k nonempty subarrays. array b = concat of all odd indices partition. want first index i of b st b[i] != i - 1 (minus 1 to offset 1 indexing).

       subarray of a which doesnt start with the current size of b OR has non consecutive adjacent elements will fuck up b

       ie [0, 1] or [1, 3]. 


       5 4
       1 1 1 2 2

       [1] [1 1] [2] [2] here b gets killed from non consecutive elements

       3 2
       1 1 1

       [1] [1 1] here b also gets killed from non consec elements 

       3 2
       2 2 2
       [2] [2 2] here b gets killed from incorrect next element


       so we either want to find incorrect next element or non consec adj elements

       kind of hard to work with finding next element since it depends on whats currently inside b
       eg if b rn is [1 2 3] next element = 4

       sidenote, if n = k then b construction is unique

       0 1 2 3 4
       fact; second partition can start from index[1, n - (k - 2))

       if exists an element in that range not equal to 1, take it as the first element of the second subarray

       if every eleent in that range is equal to 1, take  subarray [1 1] which is guaranteed to be in that interval since n > 2 since n != k

    */

    ll n, k; cin >> n >> k;
    ll a[n];

    for(int i = 0; i < n; i++) cin >> a[i];


    vector<ll> b;
    if(n == k){
        for(int i = 0; i < n; i++){
            if(i % 2 == 1) b.push_back(a[i]);
        }

        for(int i = 0; i < b.size(); i++){
            if(b[i] != i + 1){
                cout << i + 1 << '\n';
                return;
            }
        }
        cout << b.size() + 1 << '\n';
        return;
    }


    for(int i = 1; i < n - (k - 2); i++){
        if(a[i] != 1){
            cout << 1 << '\n';
            return;
        }
    }

    cout << 2 << '\n';
    return;







}





int main(){
    ll t; cin >> t;
    while(t--) solve2();
}


/*
takeaway: dont always try to think of nice solutions that "generalize" in some way, in this question the answer depended purely on how we can construct the second subarray but you thought that wasnt "clean" in some way. Not every question is a part of some template of problems.

*/







