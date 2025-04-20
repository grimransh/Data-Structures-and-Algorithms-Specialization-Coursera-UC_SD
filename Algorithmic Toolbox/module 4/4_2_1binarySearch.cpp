#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> k, int n, int key){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = left + ((right-left)/2);
        if(key == k[mid]) return mid;
        else if(k[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}


void search(int n, int m, vector<int> k, vector<int> q){
    for(int i=0; i<m; ++i){
        int ans;
        ans = binary_search(k, n, q[i]);
        cout << ans << ' ';

    }
}

int main(){
    int n, m;
    cin >> n;
    vector<int> k(n);
    for(int i=0; i<n; ++i) cin >> k[i];
    
    cin >> m;
    vector<int> q(m);  
    for(int i=0; i<m; ++i) cin >> q[i];
    search(n, m, k, q);
    return 0;
}