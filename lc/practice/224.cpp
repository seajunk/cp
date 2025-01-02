#include <bits/stdc++.h>
using namespace std;

string equation;
int i;



int parse_term();

int parse_expression(){
    int t = parse_term();

    if(i < 0 || equation[i] == '('){
        return t;
    }
    else if(equation[i] == '+'){
        i--;
        return parse_expression() + t;
    }
    else if(equation[i] == '-'){
        if(i == 0){
            i--;
            return -1 * t;
        } 
        else if(equation[i - 1] == '('){
            i--;
            return -1 * t;
        }
        else{
            i--;
            return parse_expression() - t;;
        }
    }
    else{
        cerr << "parse_expression error\n";
        exit(-1);
    }
}

int parse_term(){

    if(isdigit(equation[i])){
        string temp = "";
        while((i >= 0) && isdigit(equation[i])){
            //temp = string(1, equation[i]) + temp;
            temp = equation[i] + temp;
            i--;
        }

        return stoi(temp);
    }
    else if(equation[i] == ')'){
        i--;
        int e = parse_expression();
        i--;
        return e;
    }
    else{
        cerr << "parse_term error\n";
        exit(-1);
    }
}




int calculate(string s){
    equation = "";
    for(char c : s){
        if(!iswspace(c)) equation += c;
    }

    i = equation.size() - 1;



    return parse_expression();

}

int main(){
    int t; cin >> t;
    while(t--){
        string thing; cin >> thing;
        cout << calculate(thing) << '\n';
    }
}
