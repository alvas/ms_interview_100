/*
 * MiddleOfTheLinkedList.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>

#include "UnitTest.h"
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
    ListNode* middleNode(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *dummyHead = &dummy;

        while (dummyHead != nullptr) {
            dummyHead = dummyHead->next;

            if (!dummyHead) {
                return head;
            }

            dummyHead = dummyHead->next;

            // be careful about this here
            if (!dummyHead) {
                return head;
            }

            head = head->next;
        }
        
        return head;
    }
};

SUITE(TEST_CASES)
{
    class MyFixture
    {
    public:
        Solution sln;
    };

    TEST_FIXTURE(MyFixture, CASE1)
    {
        ListNode *head = nullptr;
        vector<int> a = {1,2,3,4,5};
        initializeLinkList<ListNode>(a, &head);
        ListNode *mid = sln.middleNode(head);
        CHECK_EQUAL(3, mid->val);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        ListNode *head = nullptr;
        vector<int> a = {1,2,3,4,5,6};
        initializeLinkList<ListNode>(a, &head);
        ListNode *mid = sln.middleNode(head);
        CHECK_EQUAL(4, mid->val);
    }
}

