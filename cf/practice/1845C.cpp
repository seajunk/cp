#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s; cin >> s;
    ll m; cin >> m;
    string l, r; cin >> l >> r;

    vector<set<char>> record(m);

    for(int i = 0, j = 0; i < s.size() && j < m; i++){
        if(l[j] <= s[i] && s[i] <= r[j]) record[j].insert(s[i]);
        if(record[j].size() == r[j] - l[j] + 1) j++; 
    }

    string ans(m, 'a');
    bool found = false;
    for(int i = 0; i < m; i++){
        ans[i] = l[i];
        for(char d = l[i]; d <= r[i]; d++){
            if(record[i].find(d) == record[i].end()){
                ans[i] = d;
                found = true;
                break;
            }
        }
    }

    if(found) cout << "YES\n";
    else cout << "NO\n";

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
