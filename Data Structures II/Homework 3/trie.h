// C++ program to demonstrate auto-complete feature 
// using Trie data ure. 
#include <iostream>
#include <string>
using namespace std;

// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 

// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

// trie node 
struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE]; // array of pointers to children of the node

	// isWordEnd is true if the node represents 
	// end of a word 
	bool isWordEnd = false;
	bool hasParent = true;
	TrieNode* parent = nullptr;
	char c = ' ';
	// a null parent can be used to indicate root of tree
};


TrieNode* getNode(void);
//int getIndex(char c);
bool isLastNode(TrieNode* root);
bool insertT(TrieNode* root, string key);
bool delT(TrieNode* root, string key);
void delR(TrieNode* current, string key, int depth); // used to return TrieNode*
bool searchT(TrieNode* root, string key);
void suggestionsRec(TrieNode* root, string currPrefix);
int printAutoSuggestionsT(TrieNode* root, string query);
void printT(TrieNode* t, int level=0);
void deleteParent(TrieNode* parent);


class Trie
{
	TrieNode* root;

public:
	Trie() { root = getNode(); }
	bool insert(string wrd) { return insertT(root, wrd); } // adds a new word to the repository
	bool delW(string wrd) { return delT(root, wrd); } // deleting an exitsing string from the repository
	int printAutoSuggestions(string wrd) { return printAutoSuggestionsT(root, wrd); } // printing auto-completion of a string
	bool search(string key) { return searchT(root, key); } // searching whether a string exists in the database
	void printTrie() { printT(root, 0); } // print indented represented of trie
};
