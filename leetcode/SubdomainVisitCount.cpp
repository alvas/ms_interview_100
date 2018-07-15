/*
 * SubdomainVisitCount.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "NormalData.h"
#include "UnitTest.h"

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        map<string, int> domainCount;
        
        for (auto &cpDomain: cpdomains) {
            //istringstream iss(cpDomain);
            //vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
            //int count = stoi(tokens[0]);

            auto itr = cpDomain.find_first_of(" ");
            int count = stoi(cpDomain.substr(0, itr - 0));

            //stringstream ss(tokens[1]);
            //string item;

            //while (getline(ss, item, '.')) {
                //cout << item << endl;
            //}

            for (int i = itr; i < cpDomain.size(); ++i) {
                if (cpDomain[i] == ' ' || cpDomain[i] == '.') {
                    string domain = cpDomain.substr(i + 1, cpDomain.size() - i - 1);
                    domainCount[domain] += count;
                }
            }
        }

        for (auto &m: domainCount) {
            res.emplace_back(to_string(m.second) + " " + m.first); 
        }

        return res;
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
        vector<string> cpdomains = {"9001 discuss.leetcode.com"};
        vector<string> output = {"9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"};
        vector<string> res = sln.subdomainVisits(cpdomains);
        //printVector<string>(res);
        CHECK_EQUAL(res == output, true);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
        vector<string> output = {"901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"};
        vector<string> res = sln.subdomainVisits(cpdomains);
        //printVector<string>(res);
        CHECK_EQUAL(res == output, true);
    }
}

