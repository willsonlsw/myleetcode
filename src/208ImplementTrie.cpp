#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* next[26];
    bool isWord;
    
    TrieNode() {
    	for (int i = 0; i < 26; ++i) next[i] = NULL;
      isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
				TrieNode *trie = root;
        int x;
        for (int i = 0; i < word.length(); ++i){
        	x = word[i] - 'a';
        	if (trie->next[x] == NULL){
        		TrieNode *node = new TrieNode();
        		trie->next[x] = node;
        	}
        	trie = trie->next[x];
        	if (i == word.length() - 1) trie->isWord = true; 
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *trie = find(word);
        if (trie == NULL) return false;
        return trie->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *trie = find(prefix);
        if (trie == NULL) return false;
        if (trie->isWord) return true;
        for (int i = 0; i < 26; ++i){
        	if (trie->next[i] != NULL) return true;
        }
        return false;
    } 

private:
    TrieNode* root;
    
    TrieNode* find(string word) {
    	TrieNode *trie = root;
    	int x; 
    	for (int i = 0; i < word.length(); ++i){
    		x = word[i] - 'a';
    		if (trie->next[x] == NULL) return NULL;
    		trie = trie->next[x];
    	}
    	return trie;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(){
	int t;
	string str;
	Trie trieTree;
	while (cin >> t) {
		cin >> str;
		if (t == 0) trieTree.insert(str);
		if (t == 1) {
			if (trieTree.search(str)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
		if (t == 2) {
			if (trieTree.startsWith(str)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
	return 0;
}