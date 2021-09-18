#include<bits/stdc++.h>
#define ll long long
using namespace std;

// vector<int> solve(int n, int m, float a, vector<int>& reward, vector<int>& x_list, vector<int>& y_list) {
//     vector<int> ans;
//     for(int i=0; i<m; i++){
//         float ans = 0.0, mul = 1.0;
//         for(int j=x_list[i]; j<=y_list[i]; j++){
//             ans += reward[j] * mul;
//             mul *= a;
//         }
//         ans.push_back((int)ans);
//     }
//     return ans;
// }

vector<int> solve(int n, int m, float a, vector<int>& reward, vector<int>& x_list, vector<int>& y_list) {
    vector<int> ans;
    vector<int> pre(n, 0.0);
    float mul = 1.0;
    // pre[0] = reward[0];
    for(int i=1; i<=n; i++){
        pre[i] = pre[i-1] + reward[i-1] * mul;
        mul *= a;
    }
    for(int i=0; i<m; i++){
        float tmp = 0.0, mul = 1.0;
        float ppp = pow(a, x_list[i]);
        tmp = (pre[y_list[i]+1] - pre[x_list[i]]) / ppp;
        ans.push_back(tmp);
    }
    return ans;
}

int main(){
    int n, m;
    // int x_list[1000], y_list[1000], reward[1000];
    vector<int> x_list(1000), y_list(1000), reward(1000);
    vector<int> ans;
    float a;
    char c;
    char c1;
    scanf("%d %c %d %c %lf %c %c", &n, &c, &m, &c, &a, &c, &c);
    for(int i=0; i<n; i++) scanf("%d %c", &reward[i], &c);
    cin>>c>>c1;
    for(int i=0; i<m; i++) scanf("%d %c", &x_list[i], &c);
    cin>>c>>c1;
    for(int i=0; i<m; i++) scanf("%d %c", &y_list[i], &c);
    solve(n, m, a, reward, x_list, y_list);
    return 0;
}