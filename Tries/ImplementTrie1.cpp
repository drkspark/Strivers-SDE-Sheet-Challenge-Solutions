/*Author : drkspark */
/*Problem Url : https://www.codingninjas.com/codestudio/problems/implement-trie_631356?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	vector<Node *> list;
	bool end;
	Node() {
		list = vector<Node *>(26, NULL);
		end = false;
	}
};

class Trie {
	Node * root;
public:
	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node * node = root;
		for (int i = 0; i < word.size(); i++) {
			if (node->list[word[i] - 'a'] == NULL) {
				node->list[word[i] - 'a'] = new Node();
			}
			node = node->list[word[i] - 'a'];
		}
		node->end = true;
	}

	bool check(string word) {
		Node * node = root;
		for (int i = 0; i < word.size(); i++) {
			if (node->list[word[i] - 'a'] == NULL) {
				return false;
			}
			node = node->list[word[i] - 'a'];
		}

		return node->end;
	}

	bool startsWith(string word) {
		Node * node = root;
		for (int i = 0; i < word.size(); i++) {
			if (node->list[word[i] - 'a'] == NULL) {
				return false;
			}
			node = node->list[word[i] - 'a'];
		}

		return true;
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Trie t1;
	string word = "hello";
	t1.insert(word);
	cout << t1.startsWith("a");
	return 0;
}
