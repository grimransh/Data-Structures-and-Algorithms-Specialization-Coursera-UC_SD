#include<iostream>
#include<vector>

using namespace std;

int refils(int d, int m, int n, vector<int> stops){
    stops.insert(stops.begin(), 0);
    stops.push_back(d);
    int ans=0,last_stop=0;
    for(int i=1; i<n+2; ++i){
        if (stops[i]-stops[i-1] > m) return -1;
        if (stops[i]-stops[last_stop] > m){
            last_stop = i-1;
            ans ++;
        }
    }

    return ans;
}

int main(){
    int d, m, n, temp;

    cin >> d >> m >> n;
    cin.ignore();

    vector<int> stops(n);
    for(int i=0; i<n; ++i) cin >> stops[i];
    cout << refils(d, m, n, stops);


    return 0;
}