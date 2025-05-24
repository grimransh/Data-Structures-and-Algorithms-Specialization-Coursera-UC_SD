#include<iostream>
#include<vector>
#include <ctime>
using namespace std;

int partition(vector<int>& a,int m, int n){
    int x=a[m];
    int start = m;
    for(int i=m+1; i<=n; i++){
        if(a[i] <= x){
            start++;
            swap(a[start], a[i]);
        }
    }
    swap(a[m], a[start]);
    return start;
}

void RandomQuick(vector<int>& a, int m, int n){
    if (m >= n ) return;
    
    int k = m + rand() % (n - m + 1);
    
    swap(a[m], a[k]);
    
    int mid = partition(a,m,n);
    RandomQuick(a,m,mid-1);
    RandomQuick(a,mid+1,n);
    
}

int main(){
    srand(time(0)); 
    int n, m = 0;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    RandomQuick(a,m,n-1);

    for(int i=0; i<n; ++i) cout << a[i] << ' ';

    return 0;
}