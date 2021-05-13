/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.


Input: l1 = [0], l2 = [0]
Output: [0]


Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

*/

/*Solution*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ptr1 = l1;
        ListNode * ptr2 = l2;
        ListNode * resultptr = nullptr;
        ListNode * current;
        int sum=0, n1, n2;
        while(ptr1 || ptr2 || sum){
            if(ptr1)           {
                n1 = ptr1->val;
                ptr1 = ptr1->next;
            }
            else {
                n1 = 0;
            }
            if(ptr2){
                n2 = ptr2->val;
                ptr2 = ptr2->next;
            }
            else {
                n2 = 0;
            }
            sum = sum + n1 + n2;
            if (resultptr==nullptr){
                resultptr = new ListNode(sum%10, nullptr);
                current = resultptr;
            } else {
                current->next = new ListNode(sum%10, nullptr);
                current = current->next;
            }
            sum = sum/10;
        }
        return resultptr;
    }
};