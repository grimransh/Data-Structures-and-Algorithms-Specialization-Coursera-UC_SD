// Last Digit of Fibonacci Number Problem Compute the last digit of the n - th Fibonacci number.

#include<bits/stdc++.h>
using namespace std;

int lastDigit(int n){
    n %= 60;
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i=2; i<=n; ++i){
        c = (a + b) % 10; // The last digit of the sum of the last two digits as the last digit of the sum of the last two numbers.
        a = b;
        b = c;
    }
    return c;
}

// int lastDigitSlow(int n) {
//     n %= 60;
//     if (n <= 1)
//         return n;
//     else {
//         int a = (lastDigitSlow(n - 1) + lastDigitSlow(n - 2)) % 10;
//         return a;}
// }

int main(){
////// The sequence of last digits of Fibonacci numbers repeats every 60 terms (Pisano period mod 10)."

    ////////// stress test
    // while(true){
    //     int n = rand() % 100000;
    //     cout << n << endl;
    //     int res1 = lastDigit(n);
    //     int res2 = lastDigitSlow(n);
    //     if (res1 != res2){
    //         cout << "Wrong answer: " << res1 << ' ' << res2 << endl;
    //         break;
    //     }
    //     else cout << "OK" << endl;
    // }

    int n;
    cin >> n;
    cout << lastDigit(n);

    return 0;
}