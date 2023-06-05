/*Author : drkspark */
/*Problem Url : https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public: 
    vector<Node *> list;
    int endsWith = 0; // To keep track of the number of words that end at that node
    int countPrefix = 0; // To keep track of the number of words that have common prefix
    
    Node () {
        list = vector<Node *>(26, NULL);
        endsWith = countPrefix = 0;
    }
    
    bool notPresent(char ch) {
        return this->list[ch - 'a'] == NULL;
    }

};

class Trie{
    Node * root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->notPresent(word[i])) {
                node->list[word[i] - 'a'] = new Node();
            }
            node = node->list[word[i] - 'a'];
            node->countPrefix += 1;
        }
        node->endsWith += 1;
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->notPresent(word[i])) {
                return 0;
            }
            node = node->list[word[i] - 'a'];
            
        }
        return node->endsWith;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->notPresent(word[i])) {
                return 0;
            }
            node = node->list[word[i] - 'a'];
            
        }
        return node->countPrefix;
    }

    void erase(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            node = node->list[word[i] - 'a'];
            node->countPrefix -= 1;
        }
        node->endsWith -= 1;
    }
};


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
