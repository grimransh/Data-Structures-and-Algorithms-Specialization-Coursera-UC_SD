#include <bits/stdc++.h>
using namespace std;

struct Item{
    int cost;
    int weight;
    double ratio;
};

bool compare(Item a, Item b){
    return a.ratio > b.ratio;
}

double maximumValue(int n, int W, vector<Item> items){

    sort(items.begin(), items.end(), compare);

    double totalValue = 0;
    for (int i = 0; i < n && W > 0; ++i){
        if (items[i].weight <= W){
            totalValue += items[i].cost;
            W -= items[i].weight;
        }
        else{
            totalValue += items[i].cost * ((double)W / items[i].weight);
            W = 0;
        }
    }

    return totalValue;
}

int main(){
    int n, W;
    cin >> n >> W;

    vector<Item> items(n);

    for (int i = 0; i < n; ++i){
        int ci, wi;
        cin >> ci >> wi;
        items[i].weight = wi;
        items[i].cost = ci;
        items[i].ratio = (double)ci/wi;
    }

    double result = maximumValue(n, W, items);
    cout << fixed << setprecision(4) << result << endl;

    return 0;
}
