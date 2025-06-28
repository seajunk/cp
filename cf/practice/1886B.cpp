#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ld d(ld x1, ld y1, ld x2, ld y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

void solve(){
    /*
       if home is (0, 0) then ans = 0

       o.w. we need,
       1. home is inside circle
       2. guy is inside circle


       then if guy and home inside same circle then good

       o.w. need
       3. circle are touching
    */


    ld px, py; cin >> px >> py;
    ld ax, ay; cin >> ax >> ay;
    ld bx, by; cin >> bx >> by;

    if(px == 0 && py == 0){
        cout << 0 << '\n';
        return;
    }

    if((d(0, 0, ax, ay) <= d(0, 0, bx, by)) && (d(px, py, ax, ay) <= d(px, py, bx, by))){
        cout << setprecision(15) << max(d(0, 0, ax, ay), d(px, py, ax, ay)) << '\n';
        return;
    }


    if((d(0, 0, ax, ay) >= d(0, 0, bx, by)) && (d(px, py, ax, ay) >= d(px, py, bx, by))){
        cout << setprecision(15) << max(d(0, 0, bx, by), d(px, py, bx, by)) << '\n';
        return;
    }



    ld house = min(d(px, py, ax, ay), d(px, py, bx, by));
    ld guy = min(d(0, 0, ax, ay), d(0, 0, bx, by));
    ld touching = d(ax, ay, bx, by)/2;

    cout << setprecision(15) << max(max(house, guy), touching) << '\n';
    return;













}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}
