//PROBLEM:
// Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 5 islands

// Example: 

// Input : mat[][] = {{1, 1, 0, 0, 0},
//                    {0, 1, 0, 0, 1},
//                    {1, 0, 0, 1, 1},
//                    {0, 0, 0, 0, 0},
//                    {1, 0, 1, 0, 1} 
// Output : 5
// This is a variation of the standard problem: “Counting the number of connected components in an undirected graph”.

#include <bits/stdc++.h>
using namespace std;

int DFS(vector<vector<int>> &mat, int i, int j )
{
    if ((i < 0 )|| (i >= mat.size()) || (j < 0) || (j >= mat[i].size()) || (mat[i][j] == 0))
    {
        return 0;
    }
    mat[i][j] = 0;
    DFS(mat, i+1, j);
    DFS(mat, i-1, j);
    DFS(mat, i, j+1);
    DFS(mat, i, j-1);
    return 1;
}

int number_of_island(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    int count = 0;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if (mat[i][j] == 1)
            {
                count += DFS(mat, i, j);
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> mat = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};

    cout << "number of isalnd is: " << number_of_island(mat) << endl;
    return 0;
}