/*
2 5
-1.739623 -4.587115 -4.286510 4.015947 -2.671629
2.323935 3.158164 -3.211263 2.444232 -0.413941

3 0.995180
1 0.511840
*/

// #include<bits/stdc++.h>
// using namespace std;

// void softmax(vector<float> &x, int row, int column){
//     for(int j=0; j<row; j++){
//         float max = 0.0;
//         float sum = 0.0;
//         for(int k=0; k<column; k++)
//             if(max < x[k + j*column])
//                 max = x[k + j*column];
//         for(int k=0; k<column; k++){
//             x[k + j*column] = exp(x[k + j*column] - max);
//             sum += x[k + j*column];
//         }
//         for(int k=0; k<column; k++)
//             x[k + j*column] /= sum;
//     }
// }

// int main(){
//     int N, K;
//     cin>>N>>K;
//     vector<vector<float>> logits(N, vector<float>(K));

//     // vector<vector<float>> logits = {
//     //     {-1.739623, -4.587115, -4.286510, 4.015947, -2.671629},
//     //     {2.323935, 3.158164, -3.211263, 2.444232, -0.413941}
//     // };
//     int row = logits.size();
//     int column = logits[0].size();
//     for(int i=0; i<row; i++){
//         for(int j=0; j<column; j++){
//             cin>>logits[i][j];
//         }
//     }
//     vector<float> x;
//     for(int i=0; i<row; i++){
//         for(int j=0; j<column; j++){
//             x.push_back(logits[i][j]);
//         }
//     }
//     softmax(x, row, column);
//     for(int i=0; i<row; i++){
//         for(int j=0; j<column; j++){
//             logits[i][j] = x[j + i*column];
//         }
//     }
//     for(int i=0; i<row; i++){
//         printf("%d %.6lf\n", i, *max_element(logits[i].begin(), logits[i].end()));
//     }
//     return 0;
// }







#include<bits/stdc++.h>
using namespace std;
vector<vector<double>> x;
void softmax(int row, int column){
    for(int j=0; j<row; j++){
        double max = 0.0;
        double sum = 0.0;
        for(int k=0; k<column; k++){
            if(max<x[j][k]) max=x[j][k];
        }
        for(int k=0; k<column; k++){
            x[j][k] = exp(x[j][k] - max);
            sum += x[j][k];
        }
        for(int k=0; k<column; k++){
            x[j][k]/=sum;
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    x.resize(n, vector<double>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>x[i][j];
        }
    }
    softmax(n, m);
    for(int i=0; i<n; i++){
        int max_idx = 0;
        double max_val = x[i][0];
        for(int j=1; j<m; j++){
            if(x[i][j] > max_val){
                max_idx = j;
                max_val = x[i][j];
            }
        }
        printf("%d %.6lf\n", max_idx, max_val);
    }
    return 0;
}