#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){




    /*
    possible if every guy has a valid pair
    if guy is suit:
        can pair with antoher suit or a trump
        values of the pairs dont matter since nessecarily one is < than other so can swap as needed

        makes sense to always pair suit with suit if possible 


    if guy is trump:
        can pair with only with another trump
        again, value of pairs dont matter.

    conj: optimal to do trumps first

    VVV WRONG
    conj: optimal to pair suits with other suits before trumps
    3
    C
    2C 9C 8C 9H 3H 4C


*/



    unordered_map<char, set<ll>> m;

    m['C'];
    m['D'];
    m['H'];
    m['S'];

    ll n; cin >> n;
    char trump; cin >> trump;

    vector<string> ans;


    for(int i = 0; i < 2*n; i++){
        string in; cin >> in;
        m[in[1]].insert(in[0] - '0');
    }

    char suits[4] = {'C', 'D', 'H', 'S'};

    for(auto suit : suits){
        if(suit == trump) continue;


        while(m[suit].size() > 0){
            if(m[suit].size() > 1){
                string curr = "";

                curr += (char) *prev(prev(m[suit].end())) + '0';
                curr += suit;
                curr += ' ';

                curr += (char) *prev(m[suit].end()) + '0';
                curr += suit;

                m[suit].erase(prev(m[suit].end()));
                m[suit].erase(prev(m[suit].end()));
                ans.push_back(curr);
            }
            else{ // one of this suit left
                if(m[trump].size() == 0){
                    cout << "IMPOSSIBLE\n";
                    return;
                }
                else{
                    string curr = "";

                    curr += (char) *prev(m[suit].end()) + '0';
                    curr += suit;
                    curr += ' ';
                    curr += (char) *prev(m[trump].end()) + '0';
                    curr += trump;
                    ans.push_back(curr);

                    m[suit].erase(prev(m[suit].end()));
                    m[trump].erase(prev(m[trump].end()));
                }
            }
        }
    }

    while(m[trump].size() > 0){
        if(m[trump].size() == 1){
            cout << "IMPOSSIBLE\n";
            return;
        }

        string curr = "";

        curr += (char) *prev(prev(m[trump].end())) + '0';
        curr += trump;
        curr += ' ';
        curr += (char) *prev(m[trump].end()) + '0';
        curr += trump;
        ans.push_back(curr);

        m[trump].erase(prev(m[trump].end()));
        m[trump].erase(prev(m[trump].end()));
    }

    for(auto s : ans) cout << s << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


