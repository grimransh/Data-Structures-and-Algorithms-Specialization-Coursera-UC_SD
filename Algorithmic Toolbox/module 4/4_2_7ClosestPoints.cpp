#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<iomanip>
using namespace std;

bool compareY(pair<int,int> x, pair<int,int> y) {
    return x.second < y.second;
}


double distance(pair<int,int> x, pair<int,int> y){
    long long dx = x.first - y.first;
    long long dy = x.second - y.second;
    return sqrt(dx*dx + dy*dy);
}

double close(vector<pair<int,int>>& px, vector<pair<int,int>>& py){
    int n = px.size();

    if(n<=3){
        double midD = 1e18;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j) midD = min(midD, distance(px[i], px[j]));
        }
        return midD;
    }

    int mid = n/2;

    pair<int,int> midpoint = px[mid];

    vector<pair<int,int>> leftX(px.begin(), px.begin() + mid);
    vector<pair<int,int>> rightX(px.begin() + mid, px.end());

    vector<pair<int,int>> leftY;
    vector<pair<int,int>> rightY;

    for(auto &p : py){
        if(p.first <= midpoint.first) leftY.push_back(p);
        else rightY.push_back(p);
    }

    double dl = close(leftX, leftY);
    double dr = close(rightX,rightY);
    double d = min(dl,dr);

    vector<pair<int,int>> strip;
    for(auto&p : py){
        if(abs(p.first - midpoint.first) < d) strip.push_back(p);
    }


    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < d; ++j)
            d = min(d, distance(strip[i], strip[j]));
    }
    return d;
}

double closepair(vector<pair<int,int>>& points){
    vector<pair<int,int>> px = points;
    vector<pair<int,int>> py = points;

    sort(px.begin(), px.end());
    sort(py.begin(), py.end(), compareY);

    double d = close(px,py);

    return d;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for(int i=0; i<n; ++i){
        cin >> points[i].first;
        cin >> points[i].second;
    }
    double ans = closepair(points);
    cout << fixed << setprecision(4) << ans;
    return 0;
}