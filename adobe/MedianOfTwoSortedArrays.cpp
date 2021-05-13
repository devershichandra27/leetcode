/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000

 

Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106

*/


//SOLuTION


/*
1. First find the smaller of the two arrays.
2. Now, we will divide both the arrays into two parititions each such that the greatest element in both the left paritions is smaller than the 
lowest element in the right parition and also number of elements in both the partitions are equal.
3. Let the first index of partition in smaller array be i1. then corresponding partition index in array2 will be (m+n+1)/2 - i1;
4. Now check if the greater than condition is true. if Not shift the begin1 to i1+1 or end1 to i1-1
5. Perfect explaination on https://www.youtube.com/watch?v=ws98ud9uxl4
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty()){
            int len = nums2.size()/2;
            if(nums2.size()%2==0){
                // cout << "here" <<endl;
                // cout << nums2[len] <<" " << nums2[len-1] << endl;
                return (double)(nums2[len]+nums2[len-1])/2;
            }
            return (double)nums2[len];
        }
        if(nums2.empty()){
            int len = nums1.size()/2;
            if(nums1.size()%2==0){
                return (double)(nums1[len]+nums1[len-1])/2;
            }
            return (double)nums1[len];
        }
        
        if(nums1.size()>nums2.size()){
            vector<int>temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        
        //initialize begin1 and end1
        int begin1 = 0;
        int end1 = nums1.size();
        
        while(begin1 <= end1){
            int index1 = (begin1 + end1)/2;
            int index2 = ((nums1.size() + nums2.size() +1))/2 - index1;
            
            int min1 = index1==nums1.size() ? INT_MAX : nums1[index1];
            int max1 = index1==0 ? INT_MIN : nums1[index1-1];
            
            int min2 = index2==nums2.size() ? INT_MAX : nums2[index2];
            int max2 = index2==0 ? INT_MIN : nums2[index2-1];
            
            if(max1 > min2){
                end1 = index1-1;
            } 
            else if (max2 > min1){
                begin1 = index1 + 1;
            }
            
            else {
                int total_len = nums1.size() + nums2.size();
                int M = max(max1, max2);
                if((total_len%2)==0){
                    int m = min(min1, min2);
                    // cout << "M " << M << " m " << m << endl;
                    return (double)(M+m)/2;
                }
                return M;
            }
                    
        }
     return 0;   
    }
};