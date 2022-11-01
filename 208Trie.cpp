/*
* A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
* There are various applications of this data structure, such as autocomplete and spellchecker.
*/
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    char val;
    TrieNode* next[26];
    bool end;

    TrieNode(char v) 
     :  val(v),
        end(false) {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode('0');
    }
    
    void insert(string word) {
        int idx = 0;
        TrieNode* current = root;
        while (idx < word.size()) {
            if (current->next[word[idx] - 'a'] == nullptr) {
                break;
            }
            current = current->next[word[idx] - 'a'];
            ++idx;
        }
        while (idx < word.size()) {
            current->next[word[idx] - 'a'] = new TrieNode(word[idx]);
            current = current->next[word[idx] - 'a'];
            ++idx;
        }
        current->end = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.size(); i++) {
            if (current->next[word[i]-'a'] == nullptr) {
                return false;
            }
            current = current->next[word[i]-'a'];
        }
        return current->end == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (current->next[prefix[i]-'a'] == nullptr) {
                return false;
            }
            current = current->next[prefix[i]-'a'];
        }
        return true;
    }
private:
    TrieNode* root;
};

int main() {
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;   // return True
    cout << trie->search("app") << endl;     // return False
    cout << trie->startsWith("app") <<endl; // return True
    trie->insert("app");
    cout << trie->search("app") << endl;     // return True
}