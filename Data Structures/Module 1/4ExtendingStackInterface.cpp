#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> maxStack;

void maxx(vector<int>& stack){
    if (!maxStack.empty()) {
        cout << maxStack.back() << endl;
    }
}

void push(vector<int>& stack, int value){
    stack.push_back(value);
    if (maxStack.empty() || value >= maxStack.back()) {
        maxStack.push_back(value);
    } else {
        maxStack.push_back(maxStack.back());
    }
}

void pop(vector<int>& stack){
    stack.pop_back();
    maxStack.pop_back();
}

void function(vector<string> & queries){
    vector<int> stack; 
    for(string query : queries){
        if(query == "pop") pop(stack);
        else if(query == "max") maxx(stack);
        else push(stack, stoi(query.substr(5)));
    }
}

int main(){
    int n;
    cin >> n;
    cin.ignore(); 
    vector<string> queries(n);
    for(int i=0; i<n; ++i) getline(cin, queries[i]);

    function(queries);

    return 0;
}