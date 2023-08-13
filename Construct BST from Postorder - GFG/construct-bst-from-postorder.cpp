//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/
Node* create(int post[], int left, int right, int& i) {
    if (i < 0 || post[i] > right || post[i] < left) {
        return nullptr;
    }

    Node* root = new Node(post[i]);
    i--;

    root->right = create(post, root->data , right, i);
    root->left = create(post, left, root->data , i);

    return root;
}

Node* constructTree(int post[], int size) {
    int i = size - 1;

    return create(post, INT_MIN, INT_MAX, i);
}