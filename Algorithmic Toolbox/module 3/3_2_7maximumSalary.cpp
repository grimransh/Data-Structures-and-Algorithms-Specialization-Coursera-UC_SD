#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool compare( const string &a, const string &b){
    return a+b > b+a;
}

void maximun(int n, vector<string> numbers){

    sort(numbers.begin(), numbers.end(), compare);
    if (numbers[0] == "0"){   
        cout << 0;
        return;
    }
    
    for (int i = 0; i < n; i++){
        cout << numbers[i];
    }
    
    

}

int main(){
    int n;
    cin >> n;
    vector<string> numbers(n);
    for(int i=0; i<n; ++i) cin >> numbers[i];
    maximun(n, numbers);

    return 0;
}