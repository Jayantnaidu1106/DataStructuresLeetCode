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
      ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* l3 = nullptr;   
        ListNode* tail = nullptr; 

        while (t1 != nullptr && t2 != nullptr) {
            ListNode* temp;
            if (t1->val <= t2->val) {
                temp = t1;
                t1 = t1->next;
            } else {
                temp = t2;
                t2 = t2->next;
            }

            if (l3 == nullptr) {
                l3 = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = tail->next;
            }
        }

       
        if (t1)
            tail ? tail->next = t1 : l3 = t1;
        if (t2)
            tail ? tail->next = t2 : l3 = t2;

        return l3;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
         if (n == 0) return nullptr;
        if (n == 1) return lists[0];
        for(int i = n-1;i>0;i--){
            ListNode* t = mergeTwoLists(lists[i],lists[i-1]);
            lists[i-1]=t;
            lists.pop_back();
        }

        return lists[0];
    }
};