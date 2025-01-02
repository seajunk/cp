#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p){
    // construct state machine from p?


    vector<string> tokens;


    int i = 0;
    while(i < p.size()){
        // four cases
        // char | char* | . | .*



        // char
        if(isalpha(p[i]) && (i == p.size() - 1 || p[i + 1] != '*')){

        }
        // char*
        if(isalpha(p[i]) && i < (p.size() - 1) && p[i + 1] == '*'){

        }
        // .
        if(p[i] == '.' && (i == p.size() - 1 || p[i + 1] != '*')){

        }
        // .*
        if(p[i] == '.' && i < (p.size() - 1) && p[i + 1] == '*'){

        }

    }




}
