/*
 * Node.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <algorithm>
#include <cctype>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// json string {v:1, c:[{v:3, c:[{v:5}, {v:6}]}, {v:2}, {v:4}]}
// v: value, c: children

Node* parse(string &json) {
    stack<Node *> stk;
    int i = 0, num = json.size();
    Node *root = nullptr, *node = nullptr, *preNode = nullptr;

    while (i < num) {
        if (json[i] == ']') {
            stk.pop();
        }
        else if (json[i] == '[') {
            stk.push(preNode);
        }

        if (json[i] == 'v') {
            while (!isdigit(json[i])) {
                i++;
            }

            int v = 0;
            while (isdigit(json[i])) {
                v = v * 10 + (json[i] - '0');
                i++;
            }

            node = new Node; 
            node->val = v;

            if (!root) {
                root = node;
            }

            if (!stk.empty()) {
                vector<Node*> &children = (stk.top())->children;
                children.push_back(node);
            }

            preNode = node;
        }

        i++;
    }

    return root;
}

void traverse(Node *root) {
    if (!root) {
        return;
    }

    cout << root->val << "\t";

    for (auto n: root->children) {
        traverse(n);
    }
}

Node* constructNaryTree(string &json) {
    json.erase(remove_if(json.begin(), json.end(), [](char c) {
                return isspace(static_cast<unsigned char>(c)); // need to explicitly specify which overload isspace is used
                }), json.end());
    json.erase(remove(json.begin(), json.end(), '\n'), json.end());
    Node* root = parse(json);
    traverse(root);
    cout << endl;
    return root;
}

