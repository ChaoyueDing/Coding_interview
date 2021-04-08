#include <bits/stdc++.h>
using namespace std;

void dfs(vector<pair<int,int>> &vec, vector<int> &visited, int index)
{
    if(visited[index])
    {
        return;
    }
    visited[index] = 1;
    // search directions
    for(int i = 0; i<vec.size(); i++)
    {
        int n1 = vec[index].first;
        int n2 = vec[index].second;            
        if(!visited[i] && (vec[i].first == n1 || vec[i].first == n2
        || vec[i].second == n1 || vec[i].second == n2))
        {
            dfs(vec,visited, i);
        }
    }  
}


int main()
{
    int N;
    cin>>N;
    map<string,int> cmap;
    vector<pair<int,int>> vec;
    int index = 0;
    while(N--)
    {
        string child, friends;
        // note that
        cin>>child>>friends;
        if(cmap.find(child)==cmap.end()){
            cmap[child] = index++;
            
        }
        if(cmap.find(friends)==cmap.end()){
            cmap[friends] = index++;
        }
        vec.push_back({cmap[child],cmap[friends]});
    }
    
    int size =vec.size();
    int count= 0;
    
    // denote the index of number pair
    vector<int> visited(size,0);

    for(int i = 0; i < size; i++)
    {
         if(!visited[i])
         {
            //  第零行
            dfs(vec,visited,i);
            count++;
         }
    }   
    cout<<"Number" <<count<< endl;

    system("pause");

    return 0;
}

/*
6
Jack Tom
Alice John
Jessica Leonie
Tom  Alice
John Jack
Leonie Jessica
*/
