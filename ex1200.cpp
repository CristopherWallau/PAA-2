#include <bits/stdc++.h>
using namespace std;
struct Node{
    char data;
    Node* left;
    Node* right;
    Node(char x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
bool search(Node* root, char x){
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    if(x < root->data){
        return search(root->left, x);
    }
    else{
        return search(root->right, x);
    }
}
Node* Insert(Node* root, char x){
    if(root == NULL){
        return new Node(x);
    }
    if(x < root->data){
        root->left = Insert(root->left, x);
    }
    else{
        root->right = Insert(root->right, x);
    }
    return root;
}
void infix(Node* root, vector<char>& res){
    if(root == NULL){
        return;
    }
    infix(root->left, res);
    res.push_back(root->data);
    infix(root->right, res);
}

void prefix(Node* root, vector<char>& res){
    if(root == NULL){
        return;
    }
    res.push_back(root->data);
    prefix(root->left, res);
    prefix(root->right, res);
}

void postorder(Node* root, vector<char>& res){
    if(root == NULL){
        return;
    }
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->data);
}

void printResult(vector<char>& res) {
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i + 1 == res.size() ? "" : " ");
    }
    cout << "\n";
}
void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
int main(void){
    // Otimização de I/O em C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x;
    Node* root = NULL;
    while(cin >> x){
    if(x == "I"){
        char c;
        cin >> c;
        root = Insert(root, c);
    }
    else if(x == "INFIXA"){
        vector<char> in;
        infix(root, in);
        printResult(in);
    }
    else if(x == "PREFIXA"){
        vector<char> pre;
        prefix(root, pre);
        printResult(pre);
    }
    else if(x == "POSFIXA"){
        vector<char> post;
        postorder(root, post);
        printResult(post);
    }
    else if(x == "P"){
        char elem;
        cin >> elem;
        search(root, elem) ? cout << elem << " existe\n" : cout << elem << " nao existe\n";
    }
    }
    return 0;
}