#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    ll tree[n][2];
    for(int i = 0; i < n; i++){
        cin >> tree[i][0] >> tree[i][1];
        tree[i][0]--;
        tree[i][1]--;
    }

    stack<ll> st;
    ll cost[n];
    cost[0] = 0;
    st.push(0);
    while(st.size()){
        ll parent = st.top();
        st.pop();
        ll left = tree[parent][0], right = tree[parent][1];

        if(left != -1){
            if(s[parent] == 'L'){
                cost[left] = cost[parent];
            }
            else{
                cost[left] = cost[parent] + 1;
            }
            st.push(left);
        }
        if(right != -1){
            if(s[parent] == 'R'){
                cost[right] = cost[parent];
            }
            else{
                cost[right] = cost[parent] + 1;
            }
            st.push(right);
        }
    }

    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++){
        if(tree[i][0] == -1 && tree[i][1] == -1) ans = min(ans, cost[i]);
    }

    cout << ans << '\n';




}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
