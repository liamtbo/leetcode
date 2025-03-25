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
        ListNode *answer = new ListNode(0); // null
        ListNode *first_node = answer;
        ListNode *curr1 = list1;
        ListNode *curr2 = list2;
        ListNode *new_node;

        // while neither is at end of linked list
        while (curr1 || curr2) {
            // case 1: both have numbers, take smallest
            if (curr1 && curr2) {
                if (curr1->val <= curr2->val) {
                    new_node = new ListNode(curr1->val);
                    curr1 = curr1->next;
                }
                else {
                    new_node = new ListNode(curr2->val);
                    curr2 = curr2->next;
                }
            }
            // case 2: only one has numbers, take that one
            else if (curr1 && !curr2) {
                new_node = new ListNode(curr1->val);
                curr1 = curr1->next;
            }
            else if (!curr1 && curr2) {
                new_node = new ListNode(curr2->val);
                curr2 = curr2->next;
            }
            // case 3: none have any numbers left, finished - handles by while loop

            // update pointers
            answer->next = new_node;
            answer = new_node;
        }
        answer = first_node->next;
        delete first_node;
        return answer;
    }
};