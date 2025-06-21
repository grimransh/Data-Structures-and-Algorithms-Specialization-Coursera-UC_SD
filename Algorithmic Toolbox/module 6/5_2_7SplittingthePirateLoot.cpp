#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int total(vector<int> & v, int n){
    int ans = 0;
    for(int i=0; i<n; ++i) ans += v[i];
    return ans;   
}

bool distribute(vector<int> & v, int target, vector<int> & subset, int index){
    if(index == v.size())
        return(subset[0]==target && subset[1]==target &&subset[2]==target);

    for(int i=0; i<3; ++i){
        if(subset[i] + v[index] <= target){
            subset[i] += v[index];
            if(distribute(v,target,subset, index+1)) return true;
            subset[i] -= v[index];
        }
        if(subset[i] == 0) break;
    }
    return false;
}

bool loot(vector<int> & v, int n){
    int sum = total(v, n);
    if(n<3 || sum%3 != 0) return false;
    int target = sum/3;

    sort(v.rbegin(), v.rend());
    vector<int> subset(3,0);

    return distribute(v, target, subset, 0);
}


int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) cin >> v[i];
    cout << loot(v, n);
    return 0;
}