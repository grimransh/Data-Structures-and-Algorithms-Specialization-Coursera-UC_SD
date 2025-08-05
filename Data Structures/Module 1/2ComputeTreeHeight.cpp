#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int treeHeight(int root, vector<vector<int>>& children){
    // int height = 0;
    // for(int child : children[root]) height = max(height, treeHeight(child, children));
    // return height+1;
    queue<int> q;
    q.push(root);
    int height = 0;
    while (!q.empty()){
        int level = q.size();
        while(level--){
            int node = q.front();
            q.pop();
            for(int child : children[node]) q.push(child); 
        }
        height++;
    }
    return height;
}

void root(int n, vector<int>& parent_nodes){
    int root = -1;
    vector<vector<int>> children(n);
    for(int i=0; i<n; ++i){
        if(parent_nodes[i] == -1) root = i;
        else children[parent_nodes[i]].push_back(i);
    }
    int height = treeHeight(root, children);
    cout << height;
}


int main(){
    int n;
    cin >> n;
    vector<int> parent_nodes(n);
    for(int i=0; i<n; ++i) cin >> parent_nodes[i];
    root(n, parent_nodes);

    return 0;
}