#include<bits/stdc++.h>
using namespace std;

int change(int money){
    int count = 0;
    while(money > 0){
        if(money >= 10){
            money -= 10;
            count++;
        }
        else if(money >= 5){
            money -= 5;
            count++;
        }
        else{
            money -= 1;
            count++;
        }
    }
    return count;
}

int main(){
    int money;
    cin >> money;
    cout << change(money);
    return 0;
}