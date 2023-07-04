

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<int> largestValues(Node* root)
    {
        vector<int>res;
        int ans = 0;
        queue<Node*>q;
        q.push(root);
        while(q.size())
        {
            int size = q.size();
            while(size--)
            {
                Node* temp = q.front();
                q.pop();
                ans = max(ans,temp->data);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            res.push_back(ans);
            ans = 0;
        }
        return res;
    }
};

