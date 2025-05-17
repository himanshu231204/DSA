/*
A palindrome is a number that reads the same backward as forward. 
For example, 121, 1331, and 4554 are palindromes because they remain the same 
when their digits are reversed.

Optimal Approach
Algorithm / Intuition
To check if a number is a palindrome, we can use the algorithm created in Extract Digits as now we extract the digits of the number to create a reversed number.

We then compare the reversed number with the original number. If they are equal, the original number is a palindrome. If they are not equal the original number is not a palindrome.

Algorithm
Step 1:Initialise an integer revNum to 0. This variable will store the reverse of the number.

Step 2: Make a duplicate of the original number and store it in an integer dup for later comparison.

Step 3: Run a while loop with the condition n>0 to reverse the number and at each iteration:

Get the last digit of n by using the modulus operator % with 10 and store it in a temporary variable ld.
Update the revNum by multiplying it by 10 and adding the last digit ld.
Update n by integer division with 10 effectively removing the last digit.
Step 4: After the loop, check if the original number dup is equal to the reversed number revNum.

If they are equal, return true indicating the number is a palindrome.
If they are not equal, return false indicating that the number is not a palindrome.

Complexity Analysis

Time Complexity: O(log10N + 1) where N is the input number. The time complexity is determined by the number of digits in the input integer N. In the worst case when N is a multiple of 10 the number of digits in N is log10 N + 1.

In the while loop we divide N by 10 until it becomes 0 which takes log10N iterations.
In each iteration of the while loop we perform constant time operations like modulus and division and pushing elements into the vector.
Space Complexity: O(1) as only a constant amount of additional memory for the reversed number regardless of size of the input number.


*/
                            
#include <iostream>
using namespace std;

// Function to check if a
// given integer is a palindrome
bool palindrome(int n)
{
    // Initialize a variable to
    // store the reverse of the number
    int revNum = 0;
    // Create a duplicate variable to
    // store the original number
    int dup = n;
    // Iterate through each digit of
    // the number until it becomes 0
    while (n > 0) {
        // Extract the last
        // digit of the number
        int ld = n % 10;
        // Build the reverse number
        // by appending the last digit
        revNum = (revNum * 10) + ld;
        // Remove the last digit
        // from the original number
        n = n / 10;
    }
    // Check if the original number
    // is equal to its reverse
    if (dup == revNum) {
        // If equal, return true
        // indicating it's a palindrome
        return true;
    } else {
        // If not equal, return false
        // indicating it's not a palindrome
        return false;
    }
}


int main() {
    int number = 4554;

    if (palindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}
                            
                        
