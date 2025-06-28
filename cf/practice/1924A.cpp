#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k, m; cin >> n >> k >> m;
    string s; cin >> s;



    /*
       s consists of first k letters, does there exist string of len n consiting of first k letters which is not a sub sequence of s ?



       possible iff we can find a partition of s of size n such that each string in the partition has all k of the first letters
    */



    vector<char> lastseen;

    set<char> curr;
    ll cnt = 0;

    for(int i = 0; i < m; i++){
        curr.insert(s[i]);

        if(curr.size() == k){
            cnt++;
            lastseen.push_back(s[i]);
            curr.clear();
        }
    }

    if(cnt >= n){
        cout << "YES\n";
        return;
    }


    cout << "NO\n";

    char missing;

    for(int i = 0; i < k; i++){
        if(curr.find('a' + i) == curr.end()){
            missing = 'a' + i;
        }
    }




    for(auto c : lastseen) cout << c;

    for(int i = 0; i < n - cnt; i++) cout << missing;

    cout << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
