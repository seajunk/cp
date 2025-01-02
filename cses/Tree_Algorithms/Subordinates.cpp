#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n; cin >> n;
    vector<vector<ll>> children(n);


    for(int i = 1; i < n; i++){
        ll boss; cin >> boss; boss--;
        children[boss].push_back(i);
    }

    vector<bool> visited(n, false);
    vector<ll> subordinate(n, 0);
    stack<ll> dfs;
    dfs.push(0);

    while(dfs.size()){
        ll top = dfs.top();

        
        bool seen = true;
        for(int i = 0; i < children[top].size(); i++){
            if(!visited[children[top][i]]) seen = false;
        }


        if(seen){
            subordinate[top] = 0;
            for(int i = 0; i < children[top].size(); i++){
                subordinate[top] += subordinate[children[top][i]] + 1;
            }
            visited[top] = true;
            dfs.pop();
        }
        else{
            for(int i = 0; i < children[top].size(); i++){
                if(!visited[children[top][i]]) dfs.push(children[top][i]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << subordinate[i] << ' ';
    }
    cout << '\n';


}

