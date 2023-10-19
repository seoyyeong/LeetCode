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
    void reorderList(ListNode* head) {

        int size = 0;
        vector<ListNode*> NodeArr;
        ListNode* pNode = head;

        while (pNode != nullptr)
        {
            NodeArr.push_back(pNode);
            pNode = pNode->next;
            size++;
        }

        pNode = head;
        size--;
        for (int i = size; i > size / 2; i--)
        {
            NodeArr[i - 1]->next = NodeArr[i]->next;
            NodeArr[i]->next = pNode->next;
            pNode->next = NodeArr[i];
            pNode = pNode->next->next;
        }
    }
};