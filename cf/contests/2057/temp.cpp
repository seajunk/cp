#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c; cin >> a >> b >> c;


    bitset<30> A(a), B(b), C(c);


    cout << (A^B).to_ullong() + (B^C).to_ullong() + (C^A).to_ullong() << '\n';



}
