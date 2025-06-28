#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    ll q; cin >> q;


    vector<vector<ll>> next(n + 1, vector<ll>(k, -1)); // next[i][c] = index of next occurence of character c in s[i, n), -1 if c doesnt occur in s[i, n)

    for(int i = n - 1; i >= 0; i--){
        for(char c = 0; c < k; c++){
            if(s[i] == c + 'a') next[i][c] = i;
            else next[i][c] = next[i + 1][c];
        }
    }

    vector<ll> mn(n + 1);
    mn[n] = 1;
    set<char> curr;
    ll cnt = 0;

    for(int i = n - 1; i >= 0; i--){
        curr.insert(s[i]);

        if(curr.size() == k){
            cnt += 1;
            curr.clear();
        }

        mn[i] = cnt + 1;
    }







    for(int i = 0; i < q; i++){
        string t; cin >> t;

        /*
           want to calculate minimum number of characters to append to t to make t not a subseq of s


           if t isnt a ss of s, output 0

           if t is a ss of s,
           let j = min(idx : s[idx] is the last character of a ss of s whose elements are t)
           we can obtain j with next array using greedy approach


           now we need to append some substring to t such that the substring is not a ss in s[j + 1, n)

           as a precomputation we need to calculate for each l, mn[l] = minimum length of substring which does not appear as ss in s[l, n)

           then output for each query is mn[j, n)

           how to calculate mn array ?




           set<char> = curr
           count

           from right to left, 

           append char to curr

           if curr size == k{
           count++
           curr.clear(:
           }

        */


        bool is_ss = true;
        int l = 0;
        for(int j = 0; l <= n && j < t.size(); j++){
            if(next[l][t[j] - 'a'] == -1){
                is_ss = false;
                break;
            }
            l = next[l][t[j] - 'a'] + 1;
        }


        if(!is_ss){
            cout << 0 << '\n';
            continue;
        }



        cout << mn[l] << '\n';


    }






}

int main(){
    solve();
}
