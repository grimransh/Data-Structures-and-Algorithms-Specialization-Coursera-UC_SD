#include <bits/stdc++.h>
using namespace std;

long long fibFast(int n) {
    if (n <= 1)
        return n;
    else
        return (long long)(fibFast(n - 1) + fibFast(n - 2));
}

// long long fib(int n){
//     if (n <= 1)
//         return n;
//     long long a1 = 0, a2 = 1, a3;
//     for (int i = 2; i <= n; ++i)
//     {
//         a3 = a1 + a2;
//         a1 = a2;
//         a2 = a3;
//     }
//     return a3;
// }

int main(){

    //////// stress test
    // while (true)
    // {
    //     int n = rand() % 46; //// rand()%(max−min+1)+min
    //     // cout << n << endl;
    //     long long res1 = fibFast(n);
    //     long long res2 = fib(n);
    //     if (res1 != res2)
    //     {
    //         cout << "Wrong answer: " << res1 << " " << res2 << endl;
    //         break;
    //     }
    //     else
    //         cout << "OK" << endl;
    // }

    int n;
    cin >> n;
    cout << fibFast(n) << endl;

    return 0;
}