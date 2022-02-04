#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> vec;

void dfs(int val)
{
    cout << val << " ";
    for (auto iter : vec[val])
    {
        dfs(iter);
    }
}

void leftView(int val, int &maxLevel, int currentLevel)
{
    if (maxLevel < currentLevel){ cout << val; maxLevel = currentLevel;}
    for (const int & node : vec[val])
    {
        leftView(node , maxLevel, currentLevel+1);
    }
}

int main()
{
    int N, E, u , v;
    cin >> N >> E;
    vec.resize(N+1);

    while(E--)
    {
        cin >> u >> v;
        vec[u].push_back(v);
    }

    //dfs(1);
    int maxLevel = INT_MIN;
    int currentLevel = 0;
    leftView(1, maxLevel, currentLevel);

    return 0;
}