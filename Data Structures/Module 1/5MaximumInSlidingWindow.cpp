#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;


vector<int> window(vector<int> & a, int n, int m){
    vector<int> ans;
    deque<int> q;

    for (int i = 0; i < n; ++i) {
        while (!q.empty() && q.front() <= i - m)
            q.pop_front();

        while (!q.empty() && a[q.back()] <= a[i])
            q.pop_back();

        q.push_back(i);

        if (i >= m - 1)
            ans.push_back(a[q.front()]);
    }
    return ans;
}
int main(){
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    cin >> m;
    vector<int> ans = window(a, n, m);
    for(int value: ans) cout << value <<' ';
    return 0;
}