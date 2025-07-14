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
    int getDecimalValue(ListNode* head) {
        int ans = 0 ;
         ListNode*dummy = head;
          while(dummy !=NULL){
              ans*= 2;
              ans+=(dummy->val);
              dummy = dummy->next;
          }
          return ans ;
    }
};