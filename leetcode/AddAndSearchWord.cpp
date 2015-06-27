#include <iostream>
#include <string>

using namespace std;

class WordDictionary {
public:
    // Adds a word into the data structure.
    void addWord(string word) {
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
int main()
{
    string word;
    WordDictionary wordDictionary;
    wordDictionary.addWord("word");
    cout << wordDictionary.search("pattern") << endl;
    return 0;
}
