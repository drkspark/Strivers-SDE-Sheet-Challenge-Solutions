#include <bits/stdc++.h> 
class Node {
public: 
    vector<Node *> list;
    bool end;
    Node() {
        end = false;
        list = vector<Node *> (26, NULL);
    }
};

class Trie {
public: 
    Node * root;
    Trie() {
        root = new Node();
    }

    void insert(string & word) {
        Node* node = root;

        for (auto &ch : word) {
            if (node->list[ch -'a'] == NULL) {
                node->list[ch -'a'] = new Node();
            }
            node = node->list[ch -'a'];
        }
        node->end = true;
    }
};

bool checkAllPrefix(string & word, Trie* t) {
    Node* node = t->root;

    for (auto &ch : word) {
        if (node->list[ch -'a'] == NULL) {
            return false;
        }
        node = node->list[ch -'a'];
        if (node->end == false)
            return false;
    }
    
    return true;
}
string completeString(int n, vector<string> &a){
    Trie* t = new Trie();
    
    for (auto word : a) {
        t->insert(word);
    }

    string res = "";

    for (auto word : a) {
        if (checkAllPrefix(word, t)) {
            if (word.size() > res.size()) {
                res = word;
            }
            else if (word.size() == res.size() && word < res) {
                res = word;
            }
        }
    }

    return res == "" ? "None" : res;
}