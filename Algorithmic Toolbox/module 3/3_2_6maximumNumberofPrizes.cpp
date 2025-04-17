#include<iostream>
#include<vector>
using namespace std;

void prizes(int n){
    int sum = 0, i=1;
    vector<int> number_prices;

    while(sum + i <= n){
        number_prices.push_back(i);
        sum += i;
        i++;
    }
    int size = number_prices.size();
    if(sum < n){
        int temp = number_prices[size-1] + n - sum;
        number_prices[size-1] = temp;
    }
    cout << size << endl;
    for (int i = 0; i < size; i++)
        cout << number_prices[i] << ' ';
    
}

int main(){
    int n;
    cin >> n;
    prizes(n);
    return 0;
}