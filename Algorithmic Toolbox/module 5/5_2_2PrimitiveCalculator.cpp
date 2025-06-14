
// #include<iostream>
// #include<vector>
// #include<climits>
// #include<algorithm>
// using namespace std;

// // void primitive(int n){
// //     vector<int> dp(n+1,INT_MAX);
// //     dp[0] = 1;
// //     for(int m=1; m <= n; ++m){
// //         if(m>=1) dp[m] = min(dp[m], dp[m-1]+1);
// //         if(m>=3) dp[m] = min(dp[m], dp[m/3]+1);
// //         if(m>=4) dp[m] = min(dp[m], dp[m/4]+1);
// //     }
// //     cout << dp[n] << endl;
// //     int temp = 1;
// //     cout << temp << ' ';
// //     for(int i=1; i<=n; ++i){
// //         switch (dp[i]){
// //         case 1:
// //             cout << temp+1 << ' ';
// //             break;
// //         case 3:
// //             cout << temp*3 << ' ';
// //             break;        
// //         case 4:
// //             cout << temp*4 << ' ';
// //             break;
// //         }
// //     }
// // }

// vector<int> complete;


// vector<int> primitive2(int n){
//     vector<int> now(3, INT_MAX);
//     if(n>1) now[0] = n-1;
//     if(n>1 && n%2==0) now[1] = n/2;
//     if(n>1 && n%3==0) now[2] = n/3;
//     return now;
// }



// int primitive1(int n){
//     vector<int> pre(3, INT_MAX);
//     vector<int> now1(3, INT_MAX);
//     vector<int> now2(3, INT_MAX);
//     vector<int> now3(3, INT_MAX);   
//     complete.push_back(n);
//     if(n>1) pre[0] = n-1;
//     if(n>1 && n%2==0) pre[1] = n/2;
//     if(n>1 && n%3==0) pre[2] = n/3;
//     now1 = primitive2(pre[0]);
//     now2 = primitive2(pre[1]);
//     now3 = primitive2(pre[2]);   
//     int a = *min_element(now1.begin(), now1.end());
//     int b = *min_element(now2.begin(), now2.end());
//     int c = *min_element(now3.begin(), now3.end());
//     int small = min(a, min(b, c));
//     if (small == now1[0]) {
//         complete.push_back(pre[0]);
//         complete.push_back(now1[0]);
//     }
//     if (small == now1[1]) {
//         complete.push_back(pre[0]);
//         complete.push_back(now1[1]);
//     }
//     if (small == now1[2]) {
//         complete.push_back(pre[0]);
//         complete.push_back(now1[2]);
//     }    
//     if (small == now2[0]) {
//         complete.push_back(pre[1]);
//         complete.push_back(now2[0]);
//     }
//     if (small == now2[1]) {
//         complete.push_back(pre[1]);
//         complete.push_back(now2[1]);
//     }
//     if (small == now2[2]) {
//         complete.push_back(pre[1]);
//         complete.push_back(now2[2]);
//     } 
//     if (small == now3[0]) {
//         complete.push_back(pre[2]);
//         complete.push_back(now3[0]);
//     }
//     if (small == now3[1]) {
//         complete.push_back(pre[2]);
//         complete.push_back(now3[1]);
//     }
//     if (small == now3[2]) {
//         complete.push_back(pre[2]);
//         complete.push_back(now3[2]);
//     }
//     return small;
// }


// void primitive3(int n){
//     int a = primitive1(n);
//     if(a == 1) return;
//     else primitive1(a);
    
// }
// int main(){
//     int n;
//     cin >> n;
//     primitive3(n);
//     int x = complete.size();
//     cout << x << endl;
//     for(int i=x-1; i<=0; --i){
//         cout << complete[i] << ' ';
//     }
//     return 0;
// }







// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<int> getOptimalPath(int n) {
//     vector<int> dp(n + 1);       // dp[i] = min operations to reach i
//     vector<int> prev(n + 1);     // prev[i] = previous number used to reach i
//     dp[1] = 0; // base case
//     for (int i = 2; i <= n; ++i) {
//         dp[i] = dp[i - 1] + 1;
//         prev[i] = i - 1;
//         if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
//             dp[i] = dp[i / 2] + 1;
//             prev[i] = i / 2;
//         }
//         if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
//             dp[i] = dp[i / 3] + 1;
//             prev[i] = i / 3;
//         }
//     }
//     // reconstruct path
//     vector<int> path;
//     for (int curr = n; curr != 0; curr = prev[curr]) {
//         path.push_back(curr);
//     }
//     reverse(path.begin(), path.end());
//     return path;
// }
// int main() {
//     int n;
//     cin >> n;
//     vector<int> complete = getOptimalPath(n);
//     cout << complete.size() - 1 << endl; // number of operations
//     for (int num : complete) cout << num << ' ';
//     cout << endl;
//     return 0;
// }










#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> primitive(int n){

    vector<int> dp(n + 1, INT_MAX);
    vector<int> prev(n + 1, -1);    
    
    dp[1] = 0;
    
    for (int i = 2; i <= n; ++i) {
        if (dp[i - 1] + 1 < dp[i]) {
            dp[i] = dp[i - 1] + 1;
            prev[i] = i - 1;
        }
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            prev[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            prev[i] = i / 3;
        }
    }
    
    cout << dp[n] << endl;
    
    vector<int> sequence;
    for (int i = n; i != -1; i = prev[i])
        sequence.push_back(i);
    
    reverse(sequence.begin(), sequence.end());
    
    return sequence;

}    

int main() {
    int n;
    cin >> n;

    vector<int> sequence = primitive(n);

    for (int x : sequence)
        cout << x << ' ';

    return 0;
}
