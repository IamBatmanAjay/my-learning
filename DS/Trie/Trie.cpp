/*
Trie is an efficient information reTrieval data structure. Using Trie, search complexities can be brought 
to optimal limit (key length). If we store keys in binary search tree, a well balanced BST will need time 
proportional to M * log N, where M is maximum string length and N is number of keys in tree. Using Trie, 
we can search the key in O(M) time. However the penalty is on Trie storage requirements (Please refer Applications of Trie for more details)

Every node of Trie consists of multiple branches. Each branch represents a possible character of keys. 
We need to mark the last node of every key as end of word node. A Trie node field isEndOfWord is used 
to distinguish the node as end of word node. A simple structure to represent nodes of the English alphabet 
can be as following, 

// Trie node 
struct TrieNode 
{ 
     struct TrieNode *children[ALPHABET_SIZE];
     // isEndOfWord is true if the node 
     // represents end of a word 
     bool isEndOfWord; 
}; 
Inserting a key into Trie is a simple approach. Every character of the input key is inserted as an individual 
Trie node. Note that the children is an array of pointers (or references) to next level trie nodes. The key 
character acts as an index into the array children. If the input key is new or an extension of the existing key, 
we need to construct non-existing nodes of the key, and mark end of the word for the last node. If the input key 
is a prefix of the existing key in Trie, we simply mark the last node of the key as the end of a word. The key 
length determines Trie depth. 
 

 
Searching for a key is similar to insert operation, however, we only compare the characters and move down. 
The search can terminate due to the end of a string or lack of key in the trie. In the former case, if the 
isEndofWord field of the last node is true, then the key exists in the trie. In the second case, the search 
terminates without examining all the characters of the key, since the key is not present in the trie.
The following picture explains construction of trie using keys given in the example below, 
 
Insert and search costs O(key_length), however the memory requirements of Trie is O(ALPHABET_SIZE * key_length * N) 
where N is number of keys in Trie. There are efficient representation of trie nodes (e.g. compressed trie, ternary 
search tree, etc.) to minimize memory requirements of trie.

*/


#include<iostream>

using namespace std;
const int length = 26;

struct trieNode {
struct trieNode* children[length];
bool isWordComplete = false;
};

struct trieNode* getNode()
{
    struct trieNode * node = (trieNode*)malloc(sizeof(trieNode));
    for (int i = 0; i < length; i++)
    {
        node->children[i] = NULL;
    }
    node->isWordComplete = false;

    return node;
}

void insert(struct trieNode* root, string key)
{
    struct trieNode *pCrawl = root;
    for (int i=0; i < key.length(); i++)
    {
        int idx = key[i] - 'a';
        if (!pCrawl->children[idx])
            pCrawl->children[idx] = getNode();

        pCrawl = pCrawl->children[idx];
    }
    pCrawl->isWordComplete = true;
}

bool search(struct trieNode* root, string key)
{
    struct trieNode *pCrawl = root;
    for(int i = 0; i < key.length(); i++)
    {
        int idx = key[i] - 'a';
        if (!pCrawl->children[idx])
        return false;

        pCrawl = pCrawl->children[idx];
    }
    return pCrawl->isWordComplete;
}

int main()
{
    string keys[] = {"hello", "i", "am", "ajay"};
    struct trieNode* root = getNode();
    for (int i =0 ; i < sizeof(keys)/sizeof(keys[0]); i++)
    {
        cout << keys[i] << endl;
        insert(root, keys[i]);
    }

    cout <<  search(root, "hello") << endl;
    cout <<  search(root, "this");
        cout <<  search(root, "i");


    return 0;
}