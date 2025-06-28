#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n; 
    vector<ll> original(n);
    vector<vector<ll>> a(n, vector<ll>(2));
    for(int i = 0; i < n; i++){
        a[i][0] = i;
        cin >> a[i][1];
        original[i] = a[i][1];
    }

    /*
       first coordinate compress a[i]

       say 1 2 3 4 ... m

       all i must be pressed before any j < i gets pressed


       we start with an empty graph

       add all m as nodes and do dfs/bfs where two buttons have an edge between them if they have the same order and are adjacent.

       the # of connected components is the number of clones we need to press all order m buttons

       then connect each of these connected components and designate this cc as curr
       which represents the buttons which our clones can reach currently

       then for the remaing order i < m buttons, do dfs from buttons of order i where buttons are connected if they have smae order and are adjacent. now count the number of connected components of the order i elements which arent curr. add this count to the number of clones we need. then connect every cc into one cc and designate it as curr.

       continue this process for every order i < m



       eg
       a = 1 7 9 7 1 10 2 10 10 7

       x = not seen
       n = new node
       c = node is part of curr 

       x x x x x x x x x x, 0
       x x x x x n x n n x, 2
       x x n x x c x c c x, 1
       x n c n x c x c c n, 0
       x c c c x c n c c c, 0
       n c c c n c c c c c, 0

    */

    sort(a.begin(), a.end(), [](auto l, auto r){
            return l[1] < r[1];
            });

    vector<vector<ll>> orders;
    set<ll> temp;

    for(int i = n - 1; i >= 0; i--){
        if(temp.find(a[i][1]) == temp.end()) orders.push_back({a[i][0]}); 
        else orders[orders.size() - 1].push_back(a[i][0]);
        temp.insert(a[i][1]);
    }



    vector<ll> leader(n, -1);
    vector<ll> size(n, -1);

    function<void(ll)> make_set = [&](ll a){
        leader[a] = a;
        size[a] = 1;
    };

    function<ll(ll)> get_leader = [&](ll a){
        if(leader[a] == a) return a;
        leader[a] = get_leader(leader[a]);
        return leader[a];
    };

    function<void(ll, ll)> union_set = [&](ll a, ll b){
        if(get_leader(a) == get_leader(b)) return;
        if(size[get_leader(a)] < size[get_leader(b)]) swap(a, b);
        size[get_leader(a)] += size[get_leader(b)];
        leader[get_leader(b)] = get_leader(a);
    };

    ll curr = -1;
    ll ans = 0;
    vector<ll> seen(n, false);

    for(auto order : orders){

        for(auto node : order){
            if(seen[node]) continue;


            make_set(node);
            seen[node] = true;
            stack<ll> dfs;
            dfs.push(node);

            while(dfs.size()){
                ll top = dfs.top();
                dfs.pop();

                ll left = top - 1, right = top + 1;

                if(0 <= left && left < n){
                    if(seen[left]){
                        union_set(left, top);
                    }
                    else{
                        if(original[left] == original[top]){
                            seen[left] = true;
                            make_set(left);
                            union_set(top, left);
                            dfs.push(left);
                        }
                    }
                }

                if(0 <= right && right < n){
                    if(seen[right]){
                        union_set(right, top);
                    }
                    else{
                        if(original[right] == original[top]){
                            seen[right] = true;
                            make_set(right);
                            union_set(top, right);
                            dfs.push(right);
                        }
                    }
                }

            }
        }
        // dfs finished, dsu set up





        if(curr == -1){
            set<ll> count;
            for(auto node : order) count.insert(get_leader(node));
            ans += count.size();
            curr = get_leader(order[0]);
            for(auto node : order){
                union_set(node, curr);
            }
        }
        else{
            set<ll> count;

            for(auto node : order){
                if(get_leader(curr) != get_leader(node)) count.insert(get_leader(node));
            }
            ans += count.size();

            for(auto node : order) union_set(node, curr);
        }


    }

    cout << ans << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
