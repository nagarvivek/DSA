//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    bool ancestors(Node* root,int target,stack<pair<Node*,Node*>> &st)
    {
        if(root==NULL)
        {
            return  false;
        }
        if(root->data==target)
        {
            st.push({root,NULL});
            return true;
        }
        if(ancestors(root->left,target,st)){
            st.push({root,root->right});
            return true;
        }
        if(ancestors(root->right,target,st)){
            st.push({root,root->left});
             return true;
        }
        return false;
        
    }
    int timerequired(Node* root){
        if(root==NULL){
            return 0;
        }
        int left=timerequired(root->left);
        int right=timerequired(root->right);
        return 1+max(left,right);
    }
    int minTime(Node* root, int target) 
    {   
        stack<pair<Node*,Node*>> st;
        ancestors(root,target,st);
        int i=st.size();
        int ans=-1;
        while(i>1)
        {
            ans=max(ans,i-1+timerequired(st.top().second));
            st.pop();
            i--;
        }
        ans=max(ans,timerequired(st.top().first->left));
        ans=max(ans,timerequired(st.top().first->right));
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends