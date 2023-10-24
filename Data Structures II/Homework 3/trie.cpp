
#include "trie.h"

TrieNode* getNode()
{
	// this function creates an empty node
	TrieNode* node = new TrieNode;
	// it's not the end of a word
	node->isWordEnd = false;
	// all its children are set to null
	for (int i = 0; i < 26; i++)
		node->children[i] = nullptr;
	// return the empty node
	return node;
}

bool isLastNode(TrieNode* root)
{
	// traverse all the letters of the alphabet
	for (int i = 0; i < 26; i++)
	{
		// if the node has children return false
		if (root->children[i] != nullptr)
			return false;
	}
	return true;
}

bool insertT(TrieNode* root, string key)
{	
	//// case 1: the string already exists in the database
	//if (searchT(root, key) == true) return;

	//// case 2: it is a prefix of an existing string
	//for (int i = 0; i < ALPHABET_SIZE; i++)
	//{
	//	if (root->children[i] ==)
	//}
	// our current node initially points to the root
	TrieNode* current = root; // used to say struct in front of this

	// we loop through the length of the key given
	for (int i = 0; i < key.length(); i++)
	{
		// convert into a lowercase letter
		int index = key[i] - 'a';
		// if the current node we are at does not have a corresponding child for that letter
		if (!current->children[index])
		{
			if (i == 0)
			{
				current->children[index] = getNode();
				current->children[index]->hasParent = false;
				current->children[index]->parent = nullptr;
				current->children[index]->c = index;
				/*current = getNode();
				current->hasParent = false;
				current->parent = nullptr;
				current->c = index;*/
			}
			// create a corresponding child
			else
			{
				current->children[index] = getNode();
				current->children[index]->hasParent = true;
				current->children[index]->parent = current;
				current->children[index]->c = index;
			}
			//current->children[index]->hasParent = false;
		}
		// continue to go through the loop
		current = current->children[index];
	}

	// mark last node as leaf
	current->isWordEnd = true;
	return true;
}

bool delT(TrieNode* root, string key)
{
	if (root == nullptr)
	{
		return false;
	}

	// case 1: the word does not exist in the trie
	if (searchT(root, key) == false)
		return false;
	
	// cases 2-4:
	delR(root, key, 0);
	return true;
}

//TrieNode* delR(TrieNode* current, string key, int depth)
//{
//	TrieNode* p = nullptr;
//	// if the word is not a prefix of any other word
//	int length = key.length();
//	if (depth == length) 
//	{
//		if (current->isWordEnd == true)
//			current->isWordEnd = false;
//		
//		bool flag = true;
//		int countChildren = 0;
//
//		for (int i = 0; i < 26; i++)
//		{
//			if (current->children[i] != nullptr)
//			{
//				flag = false;
//			}
//		}
//		/*if (current->hasParent)
//		{
//			p = current->parent;
//		}
//		if (p)
//		{
//			for (int i = 0; i < 26; i++)
//			{
//				if (p->children[i] != nullptr)
//				{
//					countChildren++;
//				}
//			}
//		}*/
//
//		// if the node has no children of its own and it has  "siblings" (its parent has other children)
//		//if (flag  && countChildren > 1) 		// if (current->children == nullptr) 
//		//{
//		//	delete current;
//		//	current = nullptr;
//		//}
//
//		// if the node has no children of its own and it has no "siblings"
//		/*else*/ if (flag && countChildren <= 1) 		// if (current->children == nullptr) 
//		{
//			TrieNode* copy = current;
//			if(current->hasParent)
//				p = current->parent;
//			delete current;
//			current = nullptr;
//			for (int i = 0; i < 26; i++)
//			{
//				if (p->children[i] != nullptr)
//					countChildren++;
//			}
//			//if (countChildren == 1)
//			//{
//				for (int i = 0; i < 26; i++)
//				{
//					if (p->children[i] == copy) // != nullptr
//						p->children[i] = nullptr;
//				}
//				countChildren = 0;
//			for (int i = 0; i < 26; i++)
//			{
//				if (p->children[i] != nullptr) // != nullptr
//					return nullptr;
//			}
//			//cout << countChildren; // for us
//			
//			//}
//			//deleteParent(p);
//			key.pop_back();
//			delR(p, key, depth - 1); // do we need to change the key?
//		}
//		return current;
//	}
//
//	// case 4: the word shares a prefix with another node.
//
//	int ind = CHAR_TO_INDEX(key[depth]); // maybe +1?
//	// delete all the nodes until the first node of the longest common prefix
//	current->children[ind] = delR(current->children[ind], key, depth + 1);
//	
//	// if we deleted the last child of a node
//	if ((current->children == nullptr) && (current->isWordEnd == false))
//	{
//		delete current;
//		current = nullptr;
//	}
//	return current;
//}

bool searchT(TrieNode* root, string key)
{
	if (root == nullptr) return false;
	TrieNode* current = root;
	int index = 0;
	// traverse through the length of the key
	for (int i = 0; i < key.length(); i++)
	{
		// make the index equal to the number corresponding to the letter of the key
		index = CHAR_TO_INDEX(key[i]);
		if (current->children[index] == nullptr)
		{
			return false;
		}
		current = current->children[index];
	}
	if (current->isWordEnd == true)
	{
		return true;
	}
	return false;
}

// the recursive function
void suggestionsRec(TrieNode* root, string word)
{
	// if the root of the string inputted is the end of a word
	if (root->isWordEnd)
	{
		cout << word << endl;
	}
	for (int i = 0; i < 26; i++)
	{
		//int index = CHAR_TO_INDEX(currPrefix[i]);
		if (root->children[i])
		{
			char c = i + 'a';
			// word + c so you can keep suggesting more words
			suggestionsRec(root->children[i], word + c);
			/*for (int j = 0; j < 26; j++)
			{
				if (root->children[index] != nullptr && root->children[index]->isWordEnd == false)
				{
					char c = i + 'a';
					cout << c << ": " << endl;
					printT(root->children[index], 0);

				}
			}*/
		}
	}
}
//Printing auto-completion of a string (the function receives a pointer to a node in the 
//tree).The function prints all the strings stored in the sub - tree of the node(i.e., all the
//strings for which the node is a prefix) in lexicographic order.

// the inner function
int printAutoSuggestionsT(TrieNode* current, string word)
{
	TrieNode* myCurrent = current;
	for (char c : word)
	{
		int index = CHAR_TO_INDEX(c);
		// if none of the node's children have any more children that match with word
		if (myCurrent->children[index] == nullptr)
		{
			return 0;
		}
		// continue with the node's children
		myCurrent = myCurrent->children[index];
	}

	// if the word is found to truly be an existing word
	if (myCurrent->isWordEnd == true)
	{
		cout << word << endl;
		return 1;
	}
	/*if (current->children == nullptr)
	{
		return 0;
	}*/
	suggestionsRec(myCurrent, word);
	return 1;

}

void printT(TrieNode* t, int level)
{
	if (t != nullptr)
	{
		// traverse through the length of the alphabet
		for (int i = 0; i < 26; i++)
		{
			// if the letter has children
			if (t->children[i] != nullptr)
			{
				// if first generation
				if (t->children[i]->hasParent == false)
				{
					level = 0;
				}
				// second generation
				else if (t->children[i]->hasParent)
				{
					if (t->children[i]->parent->hasParent == false)
					{
						level = 1;
					}
				}
				// print as many tabs for the corresponding level
				for (int j = 0; j < level; j++) // this was i
				{
					cout << "   ";
				}
				char c = i + 'a';
				cout << c << ": " << endl;
				level++;
				printT(t->children[i], level);
			}
		}
	}
}

void delR(TrieNode* current, string key, int depth)
{
	while (depth != key.length())
	{
		depth++;
		int ind = CHAR_TO_INDEX(key[depth]);
		current = current->children[ind];
	}
	TrieNode* p = nullptr;
	// if the word is not a prefix of any other word
	int length = key.length();
	if (depth == length)
	{
		if (current->isWordEnd == true)
			current->isWordEnd = false;

		bool flag = true;
		int countChildren = 0;

		for (int i = 0; i < 26; i++)
		{
			if (current->children[i] != nullptr)
			{
				flag = false;
			}
		}
	
		// if the node has no children of its own and it has no "siblings"
		/*else*/ if (flag && countChildren <= 1) 		// if (current->children == nullptr) 
		{
			TrieNode* copy = current;
			if (current->hasParent)
				p = current->parent;
			delete current;
			current = nullptr;
			for (int i = 0; i < 26; i++)
			{
				if (p->children[i] != nullptr)
					countChildren++;
			}
			//if (countChildren == 1)
			//{
			for (int i = 0; i < 26; i++)
			{
				if (p->children[i] == copy) // != nullptr
					p->children[i] = nullptr;
			}
			countChildren = 0;
			for (int i = 0; i < 26; i++)
			{
				if (p->children[i] != nullptr) // != nullptr
					return; // don't want to do anything else
			}
			//cout << countChildren; // for us

			//}
			//deleteParent(p);
			key.pop_back();
			delR(p, key, depth - 1); // do we need to change the key?
		}
		//return current; ?
	}

	 //case 4: the word shares a prefix with another node.

	//int ind = CHAR_TO_INDEX(key[depth]); // maybe +1?
	//// delete all the nodes until the first node of the longest common prefix
	//current->children[ind] = delR(current->children[ind], key, depth + 1);

	 //if we deleted the last child of a node
	if ((current->children == nullptr) && (current->isWordEnd == false))
	{
		delete current;
		current = nullptr;
	}
	return;
}

//void deleteParent(TrieNode* p)
//{
//	TrieNode* grandparent = nullptr;
//	TrieNode* parent = nullptr;
//	//TrieNode* copy = p;
//	if (p->parent != nullptr)
//	{
//		parent = p->parent;
//	}
//	for (int i = 0; i < 26; i++)
//	{
//		p->children[i] = nullptr;
//	}
//
//	//p2->children[p->c] = nullptr;
//	// we need to have the parent point to the specific child to null here
//	delete p;
//	p = nullptr;
//
//	int countChildren = 0;
//	for (int i = 0; i < 26; i++)
//	{
//		if (parent->children[i] != nullptr)
//			countChildren++;
//	}
//	if (countChildren == 1)
//	{
//		for (int i = 0; i < 26; i++)
//			parent->children[i] = nullptr;
//	}
//
//	bool flag = true;
//
//	if (!parent)
//	{
//		return;
//	}
//	// this whole if statement is "for the future," meaning do we send the parent into the deleteParent function
//	// if parent has a parent
//	if (parent->parent != nullptr)
//	{
//		grandparent = parent->parent;
//		// this loop checks to see if p2 has any other siblings
//		for (int i = 0; i < 26; i++)
//		{
//			if (grandparent->children[i] != nullptr)
//			{
//				countChildren++;
//			}
//		}
//	}
//
//	/*bool flag2 = true;
//
//	if (countChildren == 1)
//	{
//		flag2 = true;
//	}*/
//	// loop to see if parent has any other children
//
//	for (int i = 0; i < 26; i++)
//	{
//		if (parent->children[i] != nullptr)
//		{
//			flag = false;
//		}
//	}
//
//	
//	// send the parent into the deleteParent function if: parent exists and countChildren<=1
//	
//	// if parent has a parent (grandparent) and the grandparent has no other children then you want to delete the grandparent.
//
//	// do not delete the node if it has other children
//	if (flag && countChildren > 1)
//	{
//		return;
//	}
//
//	// if the current node does not have any other children and it has no "siblings" deleteParent
//	if (flag)
//	{
//		deleteParent(parent); // used to say p2 instead of parent
//	}
//}
