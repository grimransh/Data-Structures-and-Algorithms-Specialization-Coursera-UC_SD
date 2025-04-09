#include<bits/stdc++.h>
using namespace std;

int lastDigitSum(long long n){
    n %= 60;
    if (n == 0) return 0;
    int ans = 0;
    long long a = 0, b = 1, c;
    for(int i=2; i<=n; ++i){
        c = (a+b)%10;
        a = b;
        b = c;
        ans = (ans+b)%10;
    }    
    return (ans+1)%10;
}

// int lastDigitSumSlow(long long n){
//     if(n==0) return 0;
//     vector<long long> fib(n+1);
//     fib[0] = 0;
//     fib[1] = 1;
//     int ans = 0;
//     for(long long i=2; i<=n; ++i){
//         fib[i] = (fib[i-1] + fib[i-2])%10;
//         ans = (ans+fib[i])%10;
//     }
//     return (ans+1)%10;
// }

int main(){
///////////// Stress Test //////////////
    // while(true){
    //     long long n = rand();
    //     cout << n << endl;
    //     int res1 = lastDigitSum(n);
    //     int res2 = lastDigitSumSlow(n);
    //     if(res1 != res2){
    //         cout << "Wrong Answer: " << res1 << " " << res2 << endl;
    //         break;
    //     }
    //     else{
    //         cout << "OK" << endl;
    //     }
    // }

    // code //
    long long n;
    cin >> n;
    cout << lastDigitSum(n) << endl;
    // cout << lastDigitSumSlow(n) << endl;
    return 0;
}