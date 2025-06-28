#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    /*
       Claim. A valid colouring is possible iff number of left and right parentheses are equal 
       Proof. obviously if left and right not equal, we cant have a proper bracketing so doesnt work. 
       If we do have equal left and right brackets, we can just the ith left bracket with the ith right bracket and give them their own colour. 

       when would we ever need > 2 colours?





    */

    ll lcnt = 0, rcnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') lcnt++;
        else rcnt++;
    }

    if(lcnt != rcnt){
        cout << -1 << '\n';
        return;
    }


    stack<char> stck;
    bool reversed = false;

    vector<ll> ans(n); // not so elegant
    for(int i = 0; i < n; i++){
        if(!reversed){
            if(s[i] == '('){
                ans[i] = reversed + 1; 
                stck.push(s[i]);
            }
            else{
                if(stck.size() == 0){
                    reversed = true;
                    stck.push(s[i]);
                    ans[i] = reversed + 1;
                }
                else{
                    char temp = stck.top();
                    stck.pop();
                    if(temp != '('){
                        cout << "shit went wrong\n";
                        return;
                    }
                    ans[i] = reversed + 1;
                }
            }
        }
        else{
            if(s[i] == ')'){
                ans[i] = reversed + 1; 
                stck.push(s[i]);
            }
            else{
                if(stck.size() == 0){
                    reversed = false;
                    stck.push(s[i]);
                    ans[i] = reversed + 1;
                }
                else{
                    char temp = stck.top();
                    stck.pop();
                    if(temp != ')'){
                        cout << "shit went wrong\n";
                        return;
                    }
                    ans[i] = reversed + 1;
                }
            }
        }
    }


    // def a cleaner way to do this but whatever
    set<ll> cnt;
    for(ll e : ans) cnt.insert(e);

    if(cnt.size() == 1){
        for(int i = 0; i < n; i++) ans[i] = 1;
    }

    cout << cnt.size() << '\n';
    for(ll e : ans) cout << e << ' ';
    cout << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
