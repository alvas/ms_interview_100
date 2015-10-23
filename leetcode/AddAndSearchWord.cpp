#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Have to improve
class WordDictionary {
public:
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

    // Have to initialize root in the constructor. Otherwise, if we try to 
    // initialize root in addWord by checking whether root is null or not, 
    // the behavior is random, because root would be a random value.
    WordDictionary()
    {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        // Be careful about the pointer when we use it to set the value.
        // because we need to change node's value, we can't use reference.
        // and we need to change the value that node points to, we have to use pointer to pointer
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int sz = word.size();
        queue<TrieNode *> q;
        q.push(root);

        for (int i = 0; i < sz; ++i)
        {
            char c = word[i];

            if (c == '.')
            {
                queue<TrieNode *> q2;

                while (!q.empty())
                {
                    TrieNode *t = q.front();
                    q.pop();
                    t = t->links;

                    // We can't skip adding the empty node(t->a = 0) here, because we use q.empty() to check
                    // the matching after processing each character.
                    while (t != NULL)
                    {
                        q2.push(t);
                        t = t->next;
                    }
                }

                bool allEmpty = true;

                // check whether all node in queue are empty node.
                while (!q2.empty())
                {
                    TrieNode *t = q2.front();
                    q2.pop();
                    q.push(t);

                    if (t->a != 0)
                    {
                        allEmpty = false;
                    }
                }

                if (allEmpty)
                {
                    return false;
                }
            }
            else
            {
                queue<TrieNode *> q2;

                while (!q.empty())
                {
                    TrieNode *t = q.front();
                    q.pop();
                    t = t->links;

                    while (t != NULL)
                    {
                        if (t->a == c)
                        {
                            q2.push(t);
                        }

                        t = t->next;
                    }
                }

                q2.swap(q);
            }

            if (q.empty())
            {
                return false;
            }
        }

        // Because the Trie tree use empty node(t->a = 0) to indicate the end of a word, we have to check
        // the empty node to see whether it really contains of word.
        while (!q.empty())
        {
            TrieNode *t = q.front();
            q.pop();
            t = t->links;

            while (t != NULL)
            {
                if (t->a == 0)
                {
                    return true;
                }

                t = t->next;
            }
        }

        return false;
    }

private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
int main()
{
    string word;
    WordDictionary wordDictionary;

    wordDictionary.addWord("a");
    wordDictionary.addWord("a");
    std::cout << wordDictionary.search(".") << endl;
    std::cout << wordDictionary.search("a") << endl;
    std::cout << wordDictionary.search("aa") << endl;
    std::cout << wordDictionary.search("a") << endl;
    std::cout << wordDictionary.search(".a") << endl;
    std::cout << wordDictionary.search("a.") << endl;

    //wordDictionary.addWord("word");
    //wordDictionary.addWord("bad");
    //wordDictionary.addWord("dad");
    //wordDictionary.addWord("mad");
    //std::cout << wordDictionary.search("pad") << endl;
    //std::cout << wordDictionary.search("bad") << endl;
    //std::cout << wordDictionary.search(".ad") << endl;
    //std::cout << wordDictionary.search("b..") << endl;
    
    //wordDictionary.addWord("a");
    //wordDictionary.addWord("ab");
    //std::cout << wordDictionary.search("a") << endl;
    //std::cout << wordDictionary.search("a.") << endl;
    //std::cout << wordDictionary.search("ab") << endl;
    //std::cout << wordDictionary.search(".a") << endl;
    //std::cout << wordDictionary.search(".b") << endl;
    //std::cout << wordDictionary.search("ab.") << endl;
    //std::cout << wordDictionary.search(".") << endl;
    //std::cout << wordDictionary.search("..") << endl;

    //wordDictionary.addWord("at");
    //wordDictionary.addWord("and");
    //wordDictionary.addWord("an");
    //wordDictionary.addWord("add");
    //std::cout << wordDictionary.search("a") << endl;
    //std::cout << wordDictionary.search(".at") << endl;
    //wordDictionary.addWord("bat");
    //std::cout << wordDictionary.search(".at") << endl;
    //std::cout << wordDictionary.search("an.") << endl;
    //std::cout << wordDictionary.search("a.d.") << endl;
    //std::cout << wordDictionary.search("b.") << endl;
    //std::cout << wordDictionary.search("a.d") << endl;
    //std::cout << wordDictionary.search(".") << endl;

    return 0;
}
