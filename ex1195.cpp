#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
Node* Insert(Node* root, int x){
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
void infix(Node* root, vector<int>& res){
    if(root == NULL){
        return;
    }
    infix(root->left, res);
    res.push_back(root->data);
    infix(root->right, res);
}

void prefix(Node* root, vector<int>& res){
    if(root == NULL){
        return;
    }
    res.push_back(root->data);
    prefix(root->left, res);
    prefix(root->right, res);
}

void postorder(Node* root, vector<int>& res){
    if(root == NULL){
        return;
    }
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->data);
}

void printResult(string prefix, vector<int>& res) {
    cout << prefix; 
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
    int n;
    if(!(cin >> n)){ 
        return 0;
    }
    for(int i = 1; i <= n; i++){
        int j;
        cin >> j;
        Node* root = NULL;
        for(int k = 0; k < j; k++){
            int x;
            cin >> x;
            root = Insert(root, x);
        }
        vector<int> in;
        vector<int> post;
        vector<int> pre;
        prefix(root, pre);
        infix(root, in);
        postorder(root, post);
        cout << "Case " << i << ":\n";
        printResult("Pre.: ", pre);
        printResult("In..: ", in);
        printResult("Post: ", post);
        freeTree(root);
        cout << "\n";
    }
    return 0;
}