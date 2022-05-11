/*
118. Pascal's Triangle
To print the complete pascal tree:

Approach:
First element and the last element of any row remains 1.
And every nth row contains n columns.
Implementation: Add the above two elements in a matrix to obtain the below.

Time=O(NxN)

*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        for(int i=0;i<numRows;i++)
        {
            v[i].resize(i+1);
            v[i][0]=v[i][i]=1;
            for(int j=1;j<i;j++)
            {
                v[i][j]=v[i-1][j-1]+v[i-1][j];
            }
        }return v;

    }
};
