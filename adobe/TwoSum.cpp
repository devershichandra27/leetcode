/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].


*/


/*Solution*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>m;
        vector<int>result;
        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(m[diff]!=0){
                result.push_back(m[diff]-1);
                result.push_back(i);
                break;
            }else {
                m[nums[i]] = i+1;
            }
        }
        return result;
    }
};