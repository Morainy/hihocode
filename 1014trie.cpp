/*
 * =====================================================================================
 *
 *       Filename:  1014trie.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年08月02日 14时11分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class trieNode{
public:
	int count;						//统计单词前缀出现的次数
	struct trieNode* next[26];
	bool exist;
	trieNode():count(0) , exist(false){
		memset(next , 0 , sizeof(next));
	}
};

trieNode* createTrieNode()
{
	trieNode* node = new trieNode;
	return node;
}

void trieInsert(trieNode * root , char* word)
{
	trieNode* node = root;
	char* p = word;
	int id;
	while(*p){
		id = *p - 'a';
		if(node->next[id] == NULL){
			node->next[id] = createTrieNode();
		}
		node = node->next[id];
		++p;
		node->count += 1;
	}
	node->exist = true;
}

int trieSearch(trieNode* root , char* word)
{
	trieNode* node = root;
	char* p = word;
	int id;
	while(*p){
		id = *p -'a';
		node = node->next[id];
		++p;
		if(node == NULL){
			return 0;
		}
	}
	return node->count;
}

int main(int argc , char* argv[])
{
	int m , n;
	cin>>m;
	string * dict = new string[m];
	for(int i = 0 ; i < m ; i++){
		cin>>dict[i];
	}
	cin>>n;
	string* search = new string[n];
	for(int i = 0 ; i < n; i++){
		cin>>search[i];
	}
	trieNode* root = createTrieNode();

	for(int i = 0 ; i < m ; i++){
		trieInsert(root , (char*)dict[i].c_str());
	}

	for(int i = 0 ; i < n ; i++){
		int res = trieSearch(root , (char*)search[i].c_str());
		cout<<res<<endl;
	}
}
