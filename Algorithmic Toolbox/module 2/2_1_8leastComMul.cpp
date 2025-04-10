#include<bits/stdc++.h>
using namespace std;

int gcd(long long a, long long b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    long long lcm, a, b;
    cin >> a >> b;
    lcm = (a * b) / gcd(a, b);
    cout << lcm << endl;

    return 0;
}
