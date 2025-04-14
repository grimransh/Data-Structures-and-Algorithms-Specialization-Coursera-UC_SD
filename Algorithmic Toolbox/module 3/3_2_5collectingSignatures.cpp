#include<bits/stdc++.h>
using namespace std;

struct Length{
    int start;
    int end;
};

bool compare(Length a, Length b){
    return a.end < b.end;
}
void collecting(int n, vector<Length> length ){
    vector<int> points;
    int lastpoint = -1;
    sort(length.begin(), length.end(), compare);
    
    for(int i=0; i<n; ++i){
        if(lastpoint < length[i].start){
            lastpoint = length[i].end;
            points.push_back(lastpoint);
        }
    }
    cout << points.size() << endl;
    for(int i=0; i<points.size(); ++i)
        cout << points[i] << ' ';
}


int main(){
    int n;
    cin >> n;
    vector<Length> lenght(n);
    for(int i=0; i<n; ++i){
        int li, ri;
        cin >> li >> ri;
        lenght[i].start = li;
        lenght[i].end = ri;
    }
    
     collecting(n,lenght);

    return 0;
}