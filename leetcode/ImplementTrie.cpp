#include <iostream>
//#include <map>
//#include <utility>

using namespace std;

// using map to implement, memory limit exceed.
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        next = NULL;
        links = NULL;
    }

    char a;
    TrieNode *links;
    TrieNode *next;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        // Be careful about the pointer when we use it to set the value.
        TrieNode **node = &(root->links);

        for (auto i : word)
        {
            TrieNode *next = *node;

            while (next != NULL)
            {
                if (next->a == i)
                {
                    break;
                }

                node = &(next->next);
                next = next->next;
            }

            // Be very careful about adding new node.
            if (next == NULL)
            {
                *node = new TrieNode();
                (*node)->a = i;
            }

            node = &((*node)->links);
        }

        // adding empty node at the end to recognize the end of a word
        if (*node == NULL)
        {
            *node = new TrieNode();
            (*node)->a = 0;
        }
        else
        {
            TrieNode *next = *node;
            bool end = false;

            while (next != NULL)
            {
                if (next->a == 0)
                {
                    end = true;
                    break;
                }

                node = &(next->next);
                next = next->next;
            }

            if (!end)
            {
                *node = new TrieNode();
                (*node)->a = 0;
            }
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root->links;

        for (auto i : word)
        {
            while (node != NULL)
            {
                if (node->a != i)
                {
                    node = node->next;
                }
                else
                {
                    break;
                }
            }

            if (node == NULL)
            {
                return false;
            }

            node = node->links;
        }

        bool end = false;
        TrieNode *next = node;

        while (next != NULL)
        {
            if (next->a == 0)
            {
                end = true;
                break;
            }

            next = next->next;
        }

        return end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root->links;

        for (auto i : prefix)
        {
            while (node != NULL)
            {
                if (node->a != i)
                {
                    node = node->next;
                }
                else
                {
                    break;
                }
            }

            if (node == NULL)
            {
                return false;
            }

            node = node->links;
        }

        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
int main()
{
    Trie trie;
    //trie.insert("abcde");
    //trie.insert("defghi");
    //trie.insert("jklmno");
    //cout << trie.search("key") << endl;
    //cout << trie.startsWith("defg") << endl;
    //cout << trie.search("defghi") << endl;
    //cout << trie.startsWith("abcde") << endl;
    //trie.insert("abc");
    //cout << trie.search("abc") << endl;
    //cout << trie.search("ab") << endl;
    //trie.insert("ab");
    //cout << trie.search("ab") << endl;
    //trie.insert("ab");
    //cout << trie.search("ab") << endl;
    trie.insert("a");
    cout << trie.search("a") << endl;
    cout << trie.startsWith("a") << endl;
    cout << trie.search("ab") << endl;
    trie.insert("a");
    cout << trie.search("a") << endl;
    trie.insert("b");
    cout << trie.search("b") << endl;
    cout << trie.startsWith("b") << endl;
    cout << trie.search("ba") << endl;
    cout << trie.startsWith("ba") << endl;
    trie.insert("ab");
    cout << trie.search("ab") << endl;
    cout << trie.startsWith("ab") << endl;
    trie.insert("ba");
    cout << trie.search("ba") << endl;
    cout << trie.startsWith("ba") << endl;
    return 0;
}
