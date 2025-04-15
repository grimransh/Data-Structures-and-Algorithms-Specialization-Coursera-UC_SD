#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

long long revenue(int n, vector<int> price,vector<int> click){
    long long ans = 0;
    sort(price.begin(), price.end(), greater<>());
    sort(click.begin(), click.end(), greater<>());
    int pi = price.size();
    for(int i=0; i<n; ++i){
        if(i<pi)
            ans += (long long)price[i]*click[i];
        else
            ans += (long long)price[i - pi] * click[i - pi];
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    vector<int> price;
    vector<int> clicks;

    string p,c;
    getline(cin, p);
    getline(cin, c);

    int temp;
    istringstream pp(p);
    istringstream cc(c);
    while (pp >> temp) price.push_back(temp);
    while (cc >> temp) clicks.push_back(temp);

    cout << revenue(n, price, clicks );

    return 0;
}