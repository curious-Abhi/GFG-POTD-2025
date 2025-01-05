class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(),arr.end());
        int count=0,s=0,e=arr.size()-1;
        while(s<e){
            if(arr[s]+arr[e]<target){
                count+=e-s;
                s++;
            }else e--;
        }
        return count;
    }
};


/*

Problem Statement:
Given an integer array arr[] and a target value, find all pairs in the array whose sum is less than the given target value. The goal is to count how many such pairs exist.

Approach:
We can optimize this problem using a two-pointer approach:

First, sort the array.
Use two pointers (s for the start and e for the end) to traverse the array.
If the sum of the elements at s and e is less than the target, all elements between s and e will form valid pairs with arr[s], so we add to the count and move the left pointer s right.
If the sum is greater than or equal to the target, we move the right pointer e left.
Repeat until the two pointers cross each other.

*/