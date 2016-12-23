/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ln = NULL;
        ListNode* baseLn = NULL;
        ListNode* ln1 = l1;
        ListNode* ln2 = l2;
        int baseVal = 0;
        while(true)
        {
            ListNode* tempLn = NULL;
            int val = baseVal;

            if(ln1)
            {
                 val = ln1->val + val;
            }
            if(ln2)
            {
                 val = ln2->val + val;
            }

            if (val >=10)
            {
                baseVal = 1;
                val = val - 10;
            }
            else
            {
                baseVal = 0;
            }
            tempLn = new ListNode(val);
                
            if (baseLn)
            {
              ln->next = tempLn;
              ln = tempLn;
            }
            else
            {
                baseLn = tempLn;
                ln = tempLn;
            }
            if (ln1)
            ln1 = ln1->next;
            if (ln2)
            ln2 = ln2->next;
            
            if (!ln2&&!ln1&&baseVal==0)
            break;
        }
        return baseLn;
    }
};
