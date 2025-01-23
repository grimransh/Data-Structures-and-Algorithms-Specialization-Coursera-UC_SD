// Problem: Find the maximum product of two distinct numbers in a sequence of non-negative integers.

#include <bits/stdc++.h>
using namespace std;

// long long MaxPairWiseProduct(const vector<int> &numbers) {
//     long long result = 0;
//     int n = numbers.size();
//     for (int i=0; i<n; ++i){
//         for (int j = i + 1; j < n; ++j){
//             if ((long long)numbers[i] * numbers[j] > result)
//                 result = (long long)numbers[i] * numbers[j];
//         }
//     }
//     return result;
// }

long long MaxPairWiseProductFast(const vector<int> &numbers) {
    int n = numbers.size();
    int max_index1 = -1;
    for (int i=0; i<n; ++i){
        if (max_index1 == -1 || numbers[i] > numbers[max_index1])
            max_index1 = i;
    }

    // cout << max_index1 << endl;

    int max_index2 = -1;
    for (int j=0; j<n; ++j){
        if (j != max_index1 && (max_index2 == -1 || numbers[j] > numbers[max_index2]))
            max_index2 = j;
    }

    // cout << max_index2 << endl;

    return (long long)numbers[max_index1] * numbers[max_index2];
}

int main(){
    // // // // //////////Stress Testing

    // while(true){
    //     int n = rand() % 100 + 2;
    //     cout << n << endl;
    //     vector<int> numbers;
    //     for (int i=0; i<n; ++i){
    //         numbers.push_back( rand() % 100000);
    //     }
    //     for (int i=0; i<n; ++i){
    //         cout << numbers[i] << " ";
    //     }
    //     cout << endl;
    //     long long ans1 = MaxPairWiseProductFast(numbers);
    //     long long ans2 = MaxPairWiseProduct(numbers);
    //     if (ans1 != ans2){
    //         cout << "Wrong Answer: " << ans1 << " " << ans2 << endl;
    //         break;       
    //     }
    //     else{
    //         cout << "OK" << endl;
    //     }
    // }



    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i=0; i<n; ++i){
        cin >> numbers[i];
    }
    // for (int i=0; i<n; ++i)
    //     cout << numbers[i] << " ";
    // cout << endl;


    long long result1 = MaxPairWiseProductFast(numbers);
    cout << result1 ;


    // long long result2 = MaxPairWiseProduct(numbers);
    // cout << result2;

    return 0;
}