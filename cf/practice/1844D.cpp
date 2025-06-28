#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;

    // (n, n + d) is an edge for any d that divides n
    // then if c is first number which does not divide n, c, c - 1, c - 2, ..., 1 all share edges. since 1, 2, ..., c all divide n

    // then this forms a clique of size c
    // chromatic number >= size of any clique so we have a lower bound of answer
    // c is tight lowerbound since we can do something like

    ll c = -1;
    for(int d = 1; d <= n; d++){
        if(n % d != 0){
            c = d;
            break;
        }
    }

    if(c == -1){
        // this only happens with 1 and 2 i think ? maybe ? just a guess lol
        // n is divisible by all x st 1 <= x <= n 

        if(n == 1){
            cout << "a\n";
            return;
        }
        else{
            cout << "ab\n";
            return;
        }
    }

    // c needs to be <= 26 to work (?)

    string ans(n, 'a');

    for(int i = 0, j = 0; i < n; i++){
        ans[i] = 'a' + j;
        j = (j + 1) % c;
    }

    cout << ans << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
