// level order traversal using bfs

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//You are required to complete this method
vector<int> levelOrder(Node *node)
{
    queue<Node *> q;
    q.push(node);
    vector<int> v;
    while (!q.empty())
    {
        if (q.front() != NULL)
        {
            v.push_back(q.front()->data);
            q.push(q.front()->left);
            q.push(q.front()->right);
        }
        q.pop();
    }
    return v;
}