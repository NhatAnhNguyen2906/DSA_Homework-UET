#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct Node
{
    int data;
    vector<Node*> children; 
};
Node *newNode(int data)
{
    Node *tmp = new Node;
    tmp->data = data;
    return tmp;
}
bool binaryTree_check(unordered_map<int, Node*> tree)
{
    for(auto node : tree)
    {
        if((node.second->children).size() > 2)
        {
            return false;
        }
    }
    return true;
}
void preorderTraversal(Node *node)
{
    if(node != NULL)
    {
        cout << node->data << " ";
        for(auto child : node->children)
        {
            preorderTraversal(child);
        }
    }
}
void postorderTraversal(Node *node)
{
    if(node != NULL)
    {
        for(auto child : node->children)
        {
            postorderTraversal(child);
        }
        cout << node->data << " ";
    }
}
void inorderTraversal(Node *node)
{
    if(node != NULL)
    {
        int n = (node->children).size();
        if(n >= 1)
        {
            inorderTraversal(node->children[0]);
        }
        cout << node->data << " ";
        if(n == 2)
        {
            inorderTraversal(node->children[1]);
        }
    }
}
int main()
{
    int n; cin >> n;
    unordered_map<int, Node*> tree;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        if(tree.find(u) == tree.end())
        {
            tree[u] = newNode(u);
        }
        if(tree.find(v) == tree.end())
        {
            tree[v] = newNode(v);
        }
        tree[u]->children.push_back(tree[v]);
    }
    if(binaryTree_check(tree) == 1)
    {
        cout << "Yes\n";
    }
    else cout << "No\n";
    Node* root = tree[0];
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    return 0;
}







