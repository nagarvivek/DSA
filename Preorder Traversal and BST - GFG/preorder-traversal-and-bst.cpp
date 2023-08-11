//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// A utility function to create a new tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

Node* find(int arr[], int left, int right, int N, int &i) {
    if (i >= N || arr[i] < left || arr[i] > right) {
        return nullptr;
    }
    
    Node* root = newNode(arr[i]);
    i++;
    root->left = find(arr, left, root->data, N, i);
    root->right = find(arr, root->data, right, N, i);
    return root;
}

class Solution {
public:
    bool canRepresentBST(int arr[], int N) {
        int i = 0;
        Node* root = find(arr, INT_MIN, INT_MAX, N, i);
        return i == N;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends