/*Author : drkspark */
/*Problem Url : https://www.codingninjas.com/codestudio/problems/number-of-distinct-substring_1465938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1 */

#include <bits/stdc++.h>
using namespace std;


//  N ^ 2 With a lot of Space, we have to use Trie to reduce space
int distinctSubstring(string &word) {
    set<string> st;
    int n = word.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string s = word.substr(i, j - i + 1);
            st.insert(s);
        }
    }

    // for (auto s : st) {
    //     cout << s << " ";
    // }

    return static_cast<int>(st.size());
}


// Using Trie

class Node {
public: 
    vector<Node *> list;
    Node() {
        list = vector<Node *>(26, NULL);
    }
};

class Trie {
    Node * root;
    int cnt;
    public:
    Trie() {
        root = new Node();
        cnt = 0;
    }

    void insert(string word) {
        Node * node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->list[word[i] - 'a'] == NULL) {
                cnt++;
                node->list[word[i] - 'a'] = new Node();
            }
            node = node->list[word[i] - 'a'];
        }
    }
    int getResult() {
        return this->cnt;
    }

};

int distinctSubstring(string &word) {
    Trie* t = new Trie();
    int n = word.size();
    for (int i = 0; i < n; i++) {
        t -> insert(word.substr(i));
    }
    return t->getResult();
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while(t--) {

		


	}
	return 0;
}
