#include <bits/stdc++.h>
using namespace std;

int fibb(long long n){
    n = n % 60;
    int a = 0, b = 1;
    if (n <= 0) return n;
    for (int i = 2; i <= n; ++i){
        int c = (a + b) % 10;
        a = b;
        b = c;
    }
    return b;
}

int last_digit_sum_squares(long long n){
    int fn = fibb(n);
    int fn1 = fibb(n + 1);
    return (fn * fn1) % 10;
}

int main(){
    long long n;
    cin >> n;
    cout << last_digit_sum_squares(n) << endl;
    return 0;
}
