#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// int maxximum(int n, vector<int> a){
//     unordered_map<int, int> frequency;
//     int maxFrequency = 0;
//     int minElemMaxFreq = a[0];

//     for(int elements : a){
//         frequency[elements]++;
//         if(frequency[elements] > maxFrequency || (frequency[elements] == maxFrequency && elements < minElemMaxFreq)){
//             maxFrequency = frequency[elements];
//             minElemMaxFreq = elements;
//         }
//     }
//     for (int i = 0; i < n; i++){
//         if (minElemMaxFreq == a[i]){
//             return i;
//             break;
//         }
        
//     }
//     return -1;

// }

int majority(int n, vector<int> a){
    unordered_map<int, int> frequncy;
    for(int elements : a){
        frequncy[elements]++;
    }
    for(const auto& count : frequncy){
        if(count.second > n/2) return 1;
    }
    return 0;


}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    // cout << maxximum(n,a);
    cout << majority(n,a);
    return 0;

}