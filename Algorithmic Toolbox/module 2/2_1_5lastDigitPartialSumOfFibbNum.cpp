#include<bits/stdc++.h>
using namespace std;

int lastDigtPrtSumFibbNum(long long m, long long n){
    m %=60;
    n %=60;
    if(n < m) n += 60;
    int a = 0, b = 1;
    int ans = 0;
    for(long long i = 0; i <= n; ++i){
        if(i >= m){
            ans = (ans + a) % 10;
        }
        int temp = (a + b) % 10;
        a = b;
        b = temp;
    }
    return ans;
}

int lastDigitSumFibbNum(long long n){
    n %= 60; // Pisano period for mod 10 is 60
    int a = 0, b = 1, sum = 1;
    if (n == 0) return 0;
    for (int i = 2; i <= n; ++i){
        int temp = (a + b) % 10;
        a = b;
        b = temp;
        sum = (sum + b) % 10;
    }
    return sum;
}
int lastPart(long long m, long long n){
    int sum_n = lastDigitSumFibbNum(n);     // Sum of Fibonacci numbers up to n
    int sum_m = lastDigitSumFibbNum(m - 1); // Sum of Fibonacci numbers up to m-1 for where m=n
    return (sum_n + 10 - sum_m) % 10;       // Ensures non-negative result
}

int main(){
        ///////////TEST CASES///////////
    // while (true) {
    //     srand(time(0)); // Seed for random number generation
    //     long long m = rand() % (long long)1e14;
    //     cout << m << endl;
    //     long long n = m + (rand() % (long long)(1e14 - m)); // Ensure n > m
    //     cout << n << endl;
    //     int res1 = lastDigtPrtSumFibbNum(m, n);
    //     int res2 = lastPart(m, n);
    //     if (res1 != res2){
    //         cout << "Wrong Answer: " << res1 << " " << res2 << endl;
    //         break;
    //     }
    //     else
    //     cout << "OK" << endl;
    // }

    ///////CODE /////////////
    long long n,m;
    cin >> m >> n;
    cout << lastDigtPrtSumFibbNum(m, n) << endl;
    // cout << lastPart(m,n) << endl;
    return 0;
}