/*
     Brute Force Approach
Algorithm / Intuition
To count the number of digits in a number, we can use the algorithm created in Extract Digits as now instead of extracting digits we are simply creating a counter to count the number of digits in the number..

Algorithm:

Step 1:Initialise a counter to store the number of digits.

Step 2:While N is greater than 0, execute the following:

Increment the counter by 1
Update N by removing its last digit by performing a modulo 10 (%10) operation on it.
Step 3:After exiting the while loop, we return the counter as the number of digits.



Time Complexity: O(log10N + 1) where N is the input number. The time complexity is determined by the number of digits in the input integer N. In the worst case when N is a multiple of 10 the number of digits in N is log10N + 1.

In the while loop we divide N by 10 until it becomes 0 which takes log10N iterations.
In each iteration of the while loop we perform constant time operations like division and increment the counter.
Space Complexity : O(1) as only a constant amount of additional memory for the counter regardless of size of the input number.



                                
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Function to count the number
// of digits in an integer 'n'.
int countDigits(int n){
    // Initialize a counter variable
    // 'cnt' to store the count of digits.
    int cnt = 0;
    // While loop iterates until 'n'
    // becomes 0 (no more digits left).
    while(n > 0){
        // Increment the counter
        // for each digit encountered.
        cnt = cnt + 1;
        // Divide 'n' by 10 to
        // remove the last digit.
        n = n / 10;
    }
    // Return the
    // count of digits.
    return cnt;
}



int main() {
    int N = 329823;
    cout << "N: "<< N << endl;
    int digits = countDigits(N);
    cout << "Number of Digits in N: "<< digits << endl;
    return 0;
}

                                
                            
*/


/*  Optimal Approach
Algorithm / Intuition
The logarithmic base 10 of a positive integers gives the number of digits in n. We add 1 to the result to ensure that the count is correct even for numbers that are powers of 10.

We cast the result to an integer to ensure that any fractional part is discarded giving the exact count of digits.

Algorithm

Step 1: Initialise a variable to store the count of digits of the number.

Step 2: The count of digits can be calculated using log10 N + 1.

log10 N operation gives the logarithmic base 10 of which returns the power to which 10 must be raised to, to be equal to N.
We add 1 to the result which accounts for the possibility that N itself is a power of 10.
Financially cast the result to an integer to ensure that it is rounded down to the nearest whole number.
Step 3: Return the value of count which represents the count of digits in the input integer N


Time Complexity: O(1)as simple arithmetic operations in constant time are computed on integers.

Space Complexity : O(1)as only a constant amount of additional memory for the count variable regardless of size of the input number.
*/

                                
#include <bits/stdc++.h>
using namespace std;



// Calculate the count of digits in 'n'
// using logarithmic operation log10(n) + 1.
int countDigits(int n){
    // Initialize a variable 'cnt' to
    // store the count of digits.
    if(n==0) return 1;
    return (int)(log10(n)+1);

    // The expression (int)(log10(n)+1)
    // calculates the number of digits in 'n'
    // and casts it to an integer.
    
    // Adding 1 to the result accounts
    // for the case when 'n' is a power of 10,
    // ensuring that the count is correct.
   
    // Finally, the result is cast
    // to an integer to ensure it is rounded
    // down to the nearest whole number.
    
    // Return the count of digits in 'n'.
    
}




int main() {
    int N = 329823;
    cout << "N: "<< N << endl;
    int digits = countDigits(N);
    cout << "Number of Digits in N: "<< digits << endl;
    return 0;
}
                                
                            




                                


                                
                            