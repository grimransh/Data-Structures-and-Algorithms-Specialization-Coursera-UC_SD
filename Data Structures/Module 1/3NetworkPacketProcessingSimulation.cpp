#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;



vector<int> time(int buffer, int n, vector<pair<int, int>> ArrPro) {
    vector<int> ans(n, -1);
    queue<long long> q; 

    for (int i = 0; i < n; ++i) {
        int arrival = ArrPro[i].first;
        int duration = ArrPro[i].second;

        while (!q.empty() && q.front() <= arrival)
            q.pop();

        if (q.size() < buffer) {
            long long startTime = q.empty() ? arrival : q.back(); 
            ans[i] = startTime;
            q.push(startTime + duration);  
        }
    }

    return ans;
}

int main(){
    int buffer, n;
    cin >> buffer >> n;
    vector<pair<int, int>> ArrPro(n);
    for(int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        ArrPro[i] = make_pair(a, b);
    }
    vector<int> ans = time(buffer, n, ArrPro);
    for(int i=0; i<n; ++i) cout << ans[i] << endl;
    // cout << endl;
    return 0;
}