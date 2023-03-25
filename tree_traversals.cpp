#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class node{
    int data;
    node *left, *right;

    public:
    node(int data){
        this->data=data;
        left=right=NULL;
    }

    //Traversals

    // 1) RECURSIVE ==>


    // In-Order --> LEFT-ROOT-RIGHT
    void inOrderRecursive(node *root){
        if(root==NULL){
            return;
        }
        inOrderRecursive(root->left);
        cout<<root->data;
        inOrderRecursive(root->right);
    }

    // Pre-Order --> ROOT-LEFT-RIGHT
    void preOrderRecursive(node *root){
        if(root==NULL){
            return;
        }
        cout<<root->data;
        preOrderRecursive(root->left);
        preOrderRecursive(root->right);
    }

    // Post-Order --> LEFT-RIGHT-ROOT
    void postOrderRecursive(node *root){
        if(root==NULL){
            return;
        }
        postOrderRecursive(root->left);
        postOrderRecursive(root->right);
        cout<<root->data;
    }


    // 2) ITERATIVE ==>

    // In-Order 
    void inOrderIterative(node *root){
        if(root==NULL){
            return;
        }
        stack<node *> s;
        node *curr=root;

        while(s.empty()!=true || curr!=NULL){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            cout<<curr->data;
            s.pop();
            curr=curr->right;
        }
    }


    // Pre-Order
    void preOrderIterative(node *root){
        if(root==NULL){
            return;
        }
        stack<node *> s;
        node *curr=root;

        while(s.empty()!=true || curr!=NULL){
            while(curr!=NULL){
                cout<<curr->data;
                if(curr->right!=NULL){
                    s.push(curr->right);
                }
                curr=curr->left;
            }

            if(s.empty()==false){
                curr=s.top();
                s.pop();
            }
        }
    }

    // Post-Order using 2 stacks
    void postOrderIterative_2stacks(node *root){
        if(root==NULL){
            return;
        }
        stack<node *> s1, s2;
        s1.push(root);
        node *curr;

        while(s1.empty()!=true){
            curr=s1.top();
            s1.pop();
            s2.push(curr);

            if(curr->left!=NULL){
                s1.push(curr->left);
            }
            if(curr->right!=NULL){
                s1.push(curr->right);
            }
        }

        while(s2.empty()!=true){              // Printing stack 
            curr=s2.top();
            cout<<curr->data<<" ";
            s2.pop();
        }
    }

    void postOrderIterative_1stack(node *root){
        
    }

    // morris order traversal code has a seperate file '

    void LevelOrderedTraversal(node *root){
        queue<node *> q;
        q.push(root);

        while (q.empty()!=true){
            node *temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }            
        }
    }
};  