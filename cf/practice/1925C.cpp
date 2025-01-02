#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k, m; cin >> n >> k >> m; // length of subword, first k letters, length of superword
    string s; cin >> s; // superword

    // conj: works <=> there exists n consecutivev permutations of the first k letters as a subsequence in s
    // eg <abc><abc><abc> does not appear in aabbcccccabab so doesnt work

    // <abc> <cab> <ab>
    // <aabbc> <ccccab> <ab>
    // <a:2 b:2 c:1> <a:1 b:1 c:4> <a:1 b:1 c:0>

    // <abc><cab><ab>cbc

    set<char> curr;
    vector<char> lastseen;
    ll cnt = 0;

    for(int i = 0; i < m ; i++){
        curr.insert(s[i]);


        if(curr.size() == k){
            cnt++;
            lastseen.push_back(s[i]);
            curr.clear();
        }

        if(cnt == n) break;


    }


    if(cnt < n){
        char missing;
        for(int i = 0; i < k; i++){
            if(curr.find(i + 'a') == curr.end()){
                missing = i + 'a';
                break;
            }
        }

        cout << "NO\n";
        for(char c : lastseen) cout << c;
        cout << missing << '\n';
        return;
    }

    cout << "YES\n";

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
