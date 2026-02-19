/*A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/
/*
class Solution {
    public:
     int MaxRowIndex(vector<vector<int>>& mat,int m,int n,int col) {
       // int m=mat.size();
       // int n=mat[0].size();
    
        int maxValue=-1;
        int index=-1;
    
        for(int i=0;i<m;i++){
    
            if(mat[i][col]>maxValue){
                maxValue=mat[i][col];
                index=i;
            }
        }
        return index;
            
        }
    
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int m=mat.size();
             int n=mat[0].size();
            int low=0;
            int high=n-1;
    
            while(low<=high){
    
                int mid=(low+high)/2;
    
                int row=MaxRowIndex(mat,m,n,mid);
    
                int left=(mid-1>0) ? mat[row][mid-1] : -1;
                int right=(mid+1<n) ? mat[row][mid+1] : -1;
    
                if ( mat[row][mid] > left &&  mat[row][mid]>right) return {row,mid};
                else if( mat[row][mid]<left){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return {-1,-1};
    
            
            
        }
    };

    */