#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> k, int key, int n){
    int left = 0, right = n-1;
    int result = -1;

    while(left <= right){
        int mid = left + ((right-left)/2); 
        if(key == k[mid]){
            result = mid;
            right = mid-1;
        }
        else if ( k[mid] < key) left = mid+1;
        else right = mid-1;
    }
    return result;
}

void indexes(int n, int m, vector<int> k, vector<int> q){
    for (int i=0; i<m; ++i){
        int ans = search(k, q[i], n);
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

    indexes(n, m, k, q);

    return 0;
}