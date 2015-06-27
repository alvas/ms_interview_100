#include <iostream>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
    }

    // Returns if the word is in the trie.
    bool search(string word) {
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
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
    trie.insert("abcdefghij");
    cout << trie.search("cde") << endl;
    return 0;
}
