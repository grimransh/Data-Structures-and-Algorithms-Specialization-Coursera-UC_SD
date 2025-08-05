#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool match(char open, char close){
    return (open == '[' && close == ']') ||
           (open == '{' && close == '}') ||
           (open == '(' && close == ')');
}

string brackets(string & s){
    stack<pair<char,int>> stack;
    int n = s.length();
    for(int i=0; i<n; ++i){
        char ch = s[i];
        if(ch == '[' || ch == '{' || ch == '(') stack.push(make_pair(ch,i+1));
        else if(ch == ']' || ch == '}' || ch == ')') {
            if (stack.empty()) return to_string(i+1);
            char topC = stack.top().first;
            if(match(topC, ch)){
                stack.pop();
            }
            else return to_string(i+1);   
        }
    }
    if(!stack.empty()) return to_string(stack.top().second);
    return "Success";
}


int main(){
    string s;
    getline(cin, s);
    cout << brackets(s);
    return 0;
}

