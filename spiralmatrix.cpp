
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int i=0, j=c, a=0, b=r;
        int g;
        while(i<j && a<b){
            for (g=i; g<j-1; g++){
                // cout<< matrix [a][g];
            }
            a++;
            for (g=a; g<b-1; g++){
                // cout<< matrix[g][j];
            }
            j--;
            
            if (j>i){
            for (g=j; g>=i; --g){
                // cout<< matrix [b][g];
            }
            b--;
            
            if (a<b){
            for (g=b; g>=a; --g){
                // cout<< matrix[g][i];
            }
            i++;
            }
            }
        }
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}