// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

unordered_map<int,vi> adj;

void addedge(int source, int dest,vi &parent){
    adj[source].push_back(dest);
    parent[source] = dest;
}
void fill(vi &parent){
    for(int i = 0 ; i < 8 ; i++){
        parent[i] = i;
    }
}
void print(vi ans){
    for (int i : ans)
        cout << i << " ";
    cout << endl;
}

int find(int i, vi parent){
    if(i == parent[i])
        return i;  

    return find(parent[i],parent);
}
void Union(int x, int y, vi &parent){

    int x_parent = find(x,parent);
    int y_parent = find(y,parent);

    if(x_parent != y_parent){
        //not in the same set/part
        parent[y_parent] = x_parent;
    }

}

int main(){
    vector<int> parent(8);
    fill(parent);     //fills the parent array

    addedge(1,0,parent);
    addedge(3,2,parent);
    addedge(5,4,parent);
    addedge(7,6,parent);
    
    // cout << find(5,parent) << endl;
    Union(0,3,parent);
    print(parent);
    


}