#include<bits/stdc++.h>
using namespace std;

void dfs(vector<set<int>> &links3, vector<int> &visited, int x){
    visited[x] = 1;
    for(auto &p:links3[x]){
        if(visited[p]==0)
            dfs(links3, visited, p);
    }
    return;
    hijl1H
}

int main(){
    int N;
    cin >> N;
    vector<pair<string, string>> links1(N);
    vector<pair<int, int>> links2(N);
    vector<set<int>> links3(N);
    map<string, int> map1;
    vector<int> visited(N, 0);
    for (int i = 0; i < N; i++){
        cin >> links1[i].first >> links1[i].second;
        map1.emplace(links1[i].first, i);
    }
    for (int i = 0; i < N; i++){
        int n1 = map1[links1[i].first];
        int n2 = map1[links1[i].second];
        links2[i].first = n1;
        links2[i].second = n2; 
    }  // string转int转化完成，成员为0~N-1

    // 构建邻接矩阵links3
    for (int i = 0; i < N; i++){
        int n1 = links2[i].first;
        int n2 = links2[i].second;
        links3[n1].insert(n2);
        links3[n2].insert(n1);
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if(visited[i]==0){
            dfs(links3, visited, i);
            sum++;
        }
    }
    cout << sum;
    return 0;
}