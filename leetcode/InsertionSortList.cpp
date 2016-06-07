#include <iostream>
#include <map>
#include <vector>

#include "LinkList.h"

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newHead = new ListNode(INT_MIN);

        while (head)
        {
            ListNode *cur = head;
            ListNode *p = newHead;
            head = head->next;

            while (p->next && p->next->val <= cur->val)
            {
                p = p->next;
            }

            cur->next = p->next;
            p->next = cur;
        }

        head = newHead->next;
        delete newHead;
        return head;
    }

    ListNode* insertionSortList_not_insertion(ListNode* head) {
        if (head == NULL)
        {
            return head;
        }

        vector<int> v;
        multimap<int, ListNode *> m;
        ListNode *node = head;

        while (node != NULL)
        {
            v.push_back(node->val);
            m.insert(make_pair(node->val, node));
            node = node->next;
        }

        sort(v.begin(), v.end());
        int size = v.size();
        ListNode *newHead = NULL, *prev = NULL;

        for (int i = 0; i < size; ++i)
        {
            map<int, ListNode *>::iterator itr = m.find(v[i]);
            ListNode *t = itr->second;
            m.erase(itr);

            if (i == 0)
            {
                newHead = t;
            }

            if (prev != NULL)
            {
                prev->next = t;
            }

            prev = t;
            t->next = NULL;
        }

        return newHead;
    }

    // This implementation exceeds time limit.
    ListNode* insertionSortList2(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *newHead = head, *cur = head->next, *prevCur = head;

        while (cur != NULL)
        {
            ListNode *node = newHead, *prev = NULL;

            while (node->val < cur->val)
            {
                prev = node;
                node = node->next;
            }

            // Be careful when two node val equals. We need to insert the the later node to the right position also.
            if (node != cur && node->val >= cur->val)
            {
                prevCur->next = cur->next;

                // Be careful about the modification of pointer here. prev == null means the cur node is inserted at the head.
                if (prev == NULL)
                {
                    cur->next = newHead;
                    newHead = cur;
                }
                else
                {
                    cur->next = node;
                    prev->next = cur;
                }

                cur = prevCur->next;
            }
            else
            {
                prevCur = cur;
                cur = cur->next;
            }
        }

        return newHead;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 500;
    //int a[LOCAL_LENGTH] = {1};
    //int a[LOCAL_LENGTH] = {1, 2};
    //int a[LOCAL_LENGTH] = {2, 1};
    //int a[LOCAL_LENGTH] = {1, 2, 3};
    //int a[LOCAL_LENGTH] = {1, 3, 2};
    //int a[LOCAL_LENGTH] = {2, 1, 3};
    //int a[LOCAL_LENGTH] = {2, 3, 1};
    //int a[LOCAL_LENGTH] = {3, 1, 2};
    //int a[LOCAL_LENGTH] = {3, 2, 1};
    //int a[LOCAL_LENGTH] = {1, 2, 3, 4};
    //int a[LOCAL_LENGTH] = {1, 2, 4, 3};
    //int a[LOCAL_LENGTH] = {1, 3, 2, 4};
    //int a[LOCAL_LENGTH] = {1, 3, 4, 2};
    //int a[LOCAL_LENGTH] = {1, 4, 2, 3};
    //int a[LOCAL_LENGTH] = {1, 4, 3, 2};
    //int a[LOCAL_LENGTH] = {2, 1, 3, 4};
    //int a[LOCAL_LENGTH] = {2, 1, 4, 3};
    //int a[LOCAL_LENGTH] = {2, 3, 1, 4};
    //int a[LOCAL_LENGTH] = {2, 3, 4, 1};
    //int a[LOCAL_LENGTH] = {2, 4, 1, 3};
    //int a[LOCAL_LENGTH] = {2, 4, 3, 1};
    //int a[LOCAL_LENGTH] = {3, 1, 2, 4};
    //int a[LOCAL_LENGTH] = {3, 1, 4, 2};
    //int a[LOCAL_LENGTH] = {3, 2, 1, 4};
    //int a[LOCAL_LENGTH] = {3, 2, 4, 1};
    //int a[LOCAL_LENGTH] = {3, 4, 1, 2};
    //int a[LOCAL_LENGTH] = {3, 4, 2, 1};
    //int a[LOCAL_LENGTH] = {4, 1, 2, 3};
    //int a[LOCAL_LENGTH] = {4, 1, 3, 2};
    //int a[LOCAL_LENGTH] = {4, 2, 1, 3};
    //int a[LOCAL_LENGTH] = {4, 2, 3, 1};
    //int a[LOCAL_LENGTH] = {4, 3, 1, 2};
    //int a[LOCAL_LENGTH] = {4, 3, 2, 1};
    //int a[LOCAL_LENGTH] = {9, 8, 6, 7, 5, 3, 4, 1, 2};
    //int a[LOCAL_LENGTH] = {4, 19, 14, 5, -3, 1, 8, 5, 11, 15};
    int a[LOCAL_LENGTH] = {-470,-346,602,625,819,861,439,722,706,800,894,855,-385,597,-101,-84,558,-16,-236,284,349,24,-268,100,-96,-432,514,10,152,502,-29,-475,-436,571,278,632,959,397,-322,-409,712,125,-181,779,361,514,882,139,54,314,272,-42,787,329,731,312,-333,-46,-152,798,-362,819,952,791,251,-232,977,-183,-140,-229,-256,-203,-230,170,-153,-360,938,-123,-83,447,898,710,-101,64,830,-403,217,-320,531,-471,727,-408,-368,218,842,891,-205,-37,-428,-93,374,330,-189,-445,814,240,290,254,-131,-344,895,36,-240,497,378,67,927,115,193,-256,-497,-82,406,637,-417,-452,518,-205,600,26,-373,-489,476,-287,-100,-361,783,101,147,-233,703,613,931,572,21,498,379,-168,-350,166,139,-62,-285,313,901,-432,858,172,-39,-354,117,-278,367,224,455,-198,559,403,2,690,-321,831,820,-146,424,-7,618,90,-377,70,705,770,-96,953,210,331,220,-275,146,949,-345,193,38,154,915,-241,-402,-128,-88,496,-234,811,690,960,-334,665,-405,-475,579,-134,515,-185,395,304,318,-246,-386,541,191,59,-138,-161,-317,-207,-134,202,925,-140,416,57,665,568,189,148,228,747,565,-124,510,-282,-41,400,790,783,-79,453,415,-334,784,376,-203,831,-311,460,54,583,688,330,267,14,-27,752,-344,-100,-373,545,937,944,465,-289,193,735,-170,403,-153,-482,41,335,301,-350,845,634,-213,-486,-406,-10,71,986,-107,418,211,-17,951,98,934,701,-362,-153,843,819,78,576,158,-477,-71,454,200,570,420,-176,716,488,-269,617,413,357,681,178,796,951,983,710,844,661,464,-386,942,-483,-240,955,-203,966,292,39,-270,924,527,984,810,-425,-479,404,724,-83,162,520,-334,-348,189,949,-99,-443,136,-475,216,415,80,530,127,635,831,794,778,335,-101,577,853,-118,976,-354,537,9,575,-430,685,51,707,-26,584,-482,968,-194,-91,832,-84,-330,188,171,712,66,-263,-376,741,55,410,990,688,-437,-430,-121,-207,426,186,552,528,136,-470,-222,436,465,994,-266,-404,353,117,454,-95,826,254,917,426,-29,63,-348,303,869,-167,270,-426,816,971,-282,83,809,906,93,-378,114,410,-354,104,-188,381,933,919,391,-99,570,274,717,11,637,-185,914,918,277,397,561,-262,-451,752,55,-68,134,401,257,591,489,465,-115,-444,-177,8,-204,519,517,-305,292,207,943,453,392,-339,400,57,-445,-11,542,25,-256,510,0,543,-422,696,732,307,443,-297,321};
    vector<int> v(a, a + LOCAL_LENGTH);
    ListNode *head = NULL;
    initializeLinkList<ListNode>(v, &head);
    printLinkList<ListNode>(head);
    head = sln.insertionSortList(head);
    //head = sln.insertionSortList_not_insertion(head);
    printLinkList<ListNode>(head);
    destroyLinkList<ListNode>(head);
    return 0;
}
