// C Program to implement binary search 
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
  
    // Loop will run till left > right. It means that there
      // are no elements to consider in the given subarray
    while (left <= right) {

        // calculating mid point
        int mid = left + (right - left) / 2;

        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // If key greater than arr[mid], ignore left half
        if (arr[mid] < key) {
            left = mid + 1;
        }

        // If key is smaller than or equal to arr[mid],
        // ignore right half
        else {
            right = mid - 1;
        }
    } 


    // If we reach here, then element was not present
    return -1;
} 


int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
  
    // Element to be searched
    int key;
    printf("please enter the number you want to search for: ");
    scanf("%d",&key);
  
    int result = binarySearch(arr, 0, size - 1, key);
    if (result == -1) {
        printf("Element is not present in array\n");
    }
    else {
        printf("Element is present at index %d\n", result);
    }
    return 0;
} 
