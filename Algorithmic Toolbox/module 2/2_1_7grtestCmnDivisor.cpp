#include<bits/stdc++.h>
using namespace std;

int GDC(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int a, b, ans; 
    cin >> a >> b;
    cout << GDC(a,b);

}