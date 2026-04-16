#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // int longestSubarray_myv1(vector<int> &nums, int k){
    //     int n = nums.size();
    //     // To store the maximum length of the subarray
    //     int maxLen = 0;
    //     int j=0;
    //     int sum = 0;
    //     int length=0;
    //     // Traverse all the elements
    //     for (int i=0; i<n; i++) {
    //         j=i+1;
    //         sum=nums[i];
    //         if (sum==k) {length=1; maxLen = max(maxLen, length);}
    //         // If the sum exceeds K, shrink the window
    //         while(j<n && sum < k) {
    //         sum += nums[j];
    //         // store the maximum length
    //         if(sum == k) {
    //             length = j-i+1;
    //             maxLen = max(maxLen, length);
    //             break;
    //         }
    //         if (sum>k){
    //             sum=0;
    //             break;
    //         }
    //         j++;
    //     }
    //     }
    //     return maxLen;
    // }
    //CLEAN CODE FOR MY VERSION
    int longestSubarray_myv1(vector<int> &nums, int k){
        int n = nums.size();
        int maxLen = 0;
    
        for (int i = 0; i < n; i++) {
            int sum = 0;
    
            for (int j = i; j < n; j++) {
                sum += nums[j];
    
                if (sum == k) {
                    maxLen = max(maxLen, j - i + 1);
                }
    
                if (sum > k) break; // valid because all elements are positive
            }
        }
        return maxLen;
    }
    // Function to find the length of longest subarray having sum k
    int longestSubarray_optimal(vector<int> &nums, int k){
        int n = nums.size();
        // To store the maximum length of the subarray
        int maxLen = 0;
        // Pointers to mark the start and end of window
        int left = 0, right = 0;
        // To store the sum of elements in the window
        int sum = nums[0];
        // Traverse all the elements
        while(right < n) {
            // If the sum exceeds K, shrink the window
            while(left <= right && sum > k) {
                sum -= nums[left];
                left++;
            }
            // store the maximum length
            if(sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
            if(right < n) sum += nums[right];
        }
        return maxLen;
    }
    // MY OPTIMAL VERSION -- WRRONG (right not moving, sum is global etc)
    // int longestSubarray_myoptimalV(vector<int> &nums, int k){
    //     int n = nums.size();
    //     // To store the maximum length of the subarray
    //     int maxLen = 0;
    //     // Pointers to mark the start and end of window
    //     int left = 0, right = 0;
    //     // To store the sum of elements in the window
    //     int sum = 0;
    //     // Traverse all the elements
    //     for (int i=0; i<n; i++) {
    //         left=i; right=i;
    //         sum = sum+nums[i];
            
    //         if (sum<k){
    //             sum = sum + nums[right];
    //             right++;
    //         }
    //         if(sum == k) {
    //             maxLen = max(maxLen, right - left + 1);
    //         }
    //         if (sum>k){
    //             break;
    //         }
    //     }
    // return maxLen;
    // }
};

int main() {
	vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;
    
	// Creating an object of Solution class
	Solution sol;

	/* Function call to find the length
	of longest subarray having sum k */
	int ansv1 = sol.longestSubarray_myv1(nums, k);

	cout << "The length of longest subarray having sum k is: (my version 1) " << ansv1;	
	
	int ans = sol.longestSubarray_optimal(nums, k);

	cout << "\nThe length of longest subarray having sum k is: " << ans;
	
// 	int ans_myopt = sol.longestSubarray_myoptimalV(nums, k);

// 	cout << "\nThe length of longest subarray having sum k is: " << ans_myopt;

	return 0;
}
