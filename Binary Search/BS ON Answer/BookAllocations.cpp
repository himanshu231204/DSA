// Allocate Minimum Number of Pages
/*
Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1
*/

/*
📚 Problem: Book Allocation Problem

Given an array of books (each with page count), and a number of students,
allocate books such that:
👉 Each student gets at least one book
👉 Books are allocated in contiguous manner
👉 The goal is to minimize the maximum number of pages assigned to any student
*/

// 🔍 Observation:
// Minimum pages a student can get: max(arr[]) — one book with max pages
// Maximum pages a student can get: sum(arr[]) — one student gets all books
// So, search space for answer = [max(arr), sum(arr)]

/*
📘 When allocation is not possible:
If number of students > number of books, return -1.
*/

// ✅ Function: Count number of students needed for a given 'maxPages'
/*
int countStudents(vector<int>& arr, int maxPages) {
    int students = 1;
    int pagesStudent = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > maxPages) return INT_MAX; // can't allocate
        if (pagesStudent + arr[i] <= maxPages) {
            pagesStudent += arr[i];
        } else {
            students++;              // move to next student
            pagesStudent = arr[i];   // start new allocation
        }
    }
    return students;
}

/*
💡 Binary Search Logic:
Try all values in range [max(arr), sum(arr)].
Use countStudents() to validate if a 'mid' value works.
*/




#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}


