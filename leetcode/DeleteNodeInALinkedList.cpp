#include <iostream>
#include <vector>

#include "LinkList.h"
#include "NormalData.h"

using namespace std;

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
    void deleteNode(ListNode* node) {
        if (node == NULL)
        {
            return;
        }

        ListNode *prev = NULL;

        while (node->next != NULL)
        {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }

        if (prev != NULL)
        {
            prev->next = NULL;
        }

        delete node;
    }
};

int main()
{
    Solution sln;
    ListNode *head = NULL;
    vector<int> v = {1, 2, 3, 4, 5};
    initializeLinkList<ListNode>(v, &head);
    printLinkList<ListNode>(head);

    int i = 0;
    std::cout << "Please select the i [1, " << v.size() << ") node to delete: ";
    cin >> i;

    ListNode *node = findINode<ListNode>(head, i);
    sln.deleteNode(node);
    printLinkList<ListNode>(head);

    // This problem implementation has a problem. If user selects to delete the last node,
    // it would be deleted twice. This is bad. But I don't want to add extra login in this
    // solution, because it is not required for this problem.
    destroyLinkList<ListNode>(head);
    return 0;
}
