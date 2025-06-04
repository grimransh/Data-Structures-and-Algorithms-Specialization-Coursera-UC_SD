#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct segments{
    int l, r;
};

void points(vector<segments> a, int n, vector<int> p, int m){
    vector<int> start(n);
    vector<int> end(n);

    for(int i=0; i<n; ++i){
        start[i]=a[i].l;
        end[i]=a[i].r;
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    for(int i=0; i<m; ++i){

        int start_count = upper_bound(start.begin(), start.end(), p[i]) - start.begin();
        int end_count = lower_bound(end.begin(), end.end(), p[i]) - end.begin();

        int ans =start_count-end_count;
        cout << ans << ' ';
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<segments> a(n);
    vector<int> p(m);

    for (int i = 0; i < n; i++) cin >> a[i].l >> a[i].r;

    for (int i = 0; i < m; i++) cin >> p[i];
    
    points(a, n, p, m);

    return 0;
}