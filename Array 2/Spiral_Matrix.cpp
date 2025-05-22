// Spiral traversal of matrix


/*
🧠 Spiral Matrix – Intuition and Approach

🔍 Intuition:
Imagine you're peeling an onion layer by layer.

In a spiral traversal of a matrix, you start from the top-left and go:

Right → along the top row

Down ↓ along the right column

Left ← along the bottom row

Up ↑ along the left column

Then move inward to the next layer, and repeat until all elements are visited.

🧭 Approach (Boundaries Method):
We use 4 pointers to keep track of boundaries:

top – starting row

bottom – ending row

left – starting column

right – ending column


Then, repeat the following steps while (top <= bottom && left <= right):

👉 Traverse left to right on top row → for (int i = left; i <= right; i++)

top++

👇 Traverse top to bottom on right column → for (int i = top; i <= bottom; i++)

right--

👈 Traverse right to left on bottom row (only if top <= bottom) → for (int i = right; i >= left; i--)

bottom--

☝ Traverse bottom to top on left column (only if left <= right) → for (int i = bottom; i >= top; i--)

left++

Repeat until all layers are traversed.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> printSpiral(vector<vector<int>> mat) {
 
  // Define ans array to store the result.
  vector<int> ans;
 
  int n = mat.size(); // no. of nows
  int m = mat[0].size(); // no. of columns
  
  // Initialize the pointers reqd for traversal.
  int top = 0, left = 0, bottom = n - 1, right = m - 1;

  // Loop until all elements are not traversed.
  while (top <= bottom && left <= right) {
      
    // For moving left to right
    for (int i = left; i <= right; i++)
      ans.push_back(mat[top][i]);

    top++;

    // For moving top to bottom.
    for (int i = top; i <= bottom; i++)
      ans.push_back(mat[i][right]);

    right--;
    
    // For moving right to left.
    if (top <= bottom) {
      for (int i = right; i >= left; i--)
       ans.push_back(mat[bottom][i]);

      bottom--;
    }

    // For moving bottom to top.
    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        ans.push_back(mat[i][left]);

      left++;
    }
  }
  return ans;
}

int main() {
    
  //Matrix initialization.
  vector<vector<int>> mat   {{1, 2, 3, 4},
                             {5, 6, 7, 8},
	                         {9, 10, 11, 12},
		                     {13, 14, 15, 16}};
		                     
  vector<int> ans = printSpiral(mat);

  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  
  return 0;
}

/*
✅ Time and Space Complexity:
Time: O(n * m) (every element visited once)

Space: O(1) (if we print directly) or O(n*m) (if storing in a list)
*/