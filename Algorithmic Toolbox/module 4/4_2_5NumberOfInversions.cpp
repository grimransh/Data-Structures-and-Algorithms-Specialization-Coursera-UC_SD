#include<iostream>
#include<vector>
using namespace std;

long long count = 0;

vector<int> merge(vector<int> b, vector<int> c){
    vector<int> ans;
    int i=0,j=0;
    while(i<b.size() && j<c.size()){
        if(b[i] <= c[j]) ans.push_back(b[i++]);
        else {
            ans.push_back(c[j++]);
            count += b.size() - i;
        }
    }
    while(i<b.size()) ans.push_back(b[i++]);
    while(j<c.size()) ans.push_back(c[j++]);
    return ans;
}
vector<int> mergesort(vector<int> a){
    int n = a.size();
    if(n<=1) return a;

    int mid = n/2;

    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());

    vector<int> b = mergesort(left);
    vector<int> c = mergesort(right);

    return merge(b,c);
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    mergesort(a);
    cout << count;
    
    return 0;
}