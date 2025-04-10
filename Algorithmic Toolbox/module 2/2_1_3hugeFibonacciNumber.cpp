#include<bits/stdc++.h>
using namespace std;

int pisano(int m){
    int a=0, b=1,c;
    for(int i=0; i<m*m; ++i){
        c=(a+b)%m;
        a=b;
        b=c;
        if(a==0 && b==1) return i+1;
    }
    return -1;
}
int hugeFibbNum(long long n, int m){
    int pissa=pisano(m);
    n%=pissa;
    if(n<=1) return n;
    int a = 0, b = 1, c;
    for(long long i=2; i<=n; i++){
        c = (a+b)%m;
        a = b;
        b = c;
    }
    return b;
}
int main(){
    long long n;
    int m;
    cin >> n >> m;
    cout << hugeFibbNum(n, m)<<endl;
    return 0;

}
