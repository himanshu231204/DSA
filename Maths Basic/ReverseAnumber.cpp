/*
Optimal Approach
Algorithm / Intuition
To reverse the digits of a number, we can use the algorithm created 
in Extract Digits as now instead of extracting 
digits we are simply appending them to the reversed number.

Algorithm
Step 1:Initialise an integer revNum to 0. This variable will store the reversed number.

Step 2: Using a while loop we iterate while n is greater than 0 and at each iteration:

Calculate the last digit of the number using the modulus operator (N%10) and store it in a variable last digit.
Update the reversed number by multiplying it with 10 and adding the last digit. This effectively appends the last digit to the end of the reversed number.
Remove the last digit of the number by dividing it by 10.
Step 3: After exiting the while loop, return the reversed number.


Time Complexity: O(log10N + 1) where N is the input number. The time complexity is determined by the number of digits in the input integer N. In the worst case when N is a multiple of 10 the number of digits in N is log10 N + 1.

In the while loop we divide N by 10 until it becomes 0 which takes log10N iterations.
In each iteration of the while loop we perform constant time operations like modulus and division and pushing elements into the vector.
Space Complexity: O(1) as only a constant amount of additional memory for the reversed number regardless of size of the input number.



*/

                            
#include <iostream>
using namespace std;

int main() {
	// Declare a variable 'n' to
	// store the input integer.
	int n;
	// Prompt the user to enter an
	// integer and store it in 'n'.
	cin >> n;
	// Initialize a variable 'revNum' to
	// store the reverse of the input integer.
	int revNum = 0;
	// Start a while loop to reverse the
	// digits of the input integer.
	while(n > 0){
		// Extract the last digit of
		// 'n' and store it in 'ld'.
		int ld = n % 10;
		// Multiply the current reverse number
		// by 10 and add the last digit.
		revNum = (revNum * 10) + ld;
		// Remove the last digit from 'n'.
		n = n / 10;
	}
	// Print the reversed number.
	cout << revNum;
}
                            
                        