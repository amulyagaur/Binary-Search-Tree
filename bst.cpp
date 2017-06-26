#include <bits/stdc++.h>
using namespace std;
struct bstnode
{
	int data;
	bstnode* left;
	bstnode* right;
};

//function to get a new dynamically allocated node in heap
bstnode* newnode(int x)
{
	bstnode* temp = new bstnode();
	temp->data = x;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

//function to insert a new node in the Binary Search Tree
bstnode* insert(bstnode* root,int x)
{
	if(root==NULL)
	{
		root = newnode(x);
		return root;
	}
	else
		if(x<=root->data)
			root->left = insert(root->left,x);
		else
			root->right = insert(root->right,x);
	return root;
}

//function to search for a value in Binary Search Tree
bool search(bstnode* root,int x)
{
	if(root==NULL)
		return false;
	else
		if(root->data == x)
			return true;
		else
			if(x<=root->data)
				return search(root->left,x);
			else
				return search(root->right,x);
}

//function to find the minimum element in a BST
int min_e(bstnode* root)
{
	while(root->left != NULL)
		root=root->left;
	return root->data;
}

int min_rec(bstnode* root)
{
	if(root->left==NULL)
		return root->data;
	return min_rec(root->left);
}

//function to find the maximum element in a BST
int max_e(bstnode* root)
{
	while(root->right != NULL)
		root=root->right;
	return root->data;
}

int max_rec(bstnode* root)
{
	if(root->right==NULL)
		return root->data;
	return max_rec(root->right);
}

//function to calculate the height of binary tree
int height(bstnode* root)
{
	if(root==NULL)
		return -1;
	else
		return 1+ max(height(root->left),height(root->right));
}

//function for level order traversal of a binary tree
void LevelOrder(bstnode* root)
{
	if(root==NULL)
		return ;
	queue<bstnode*> q;
	q.push(root);
	while(!q.empty())
	{
		bstnode *temp = q.front();
		cout<<temp->data<<" ";
		if(temp->left !=NULL)
			q.push(temp->left);
		if(temp->right !=NULL)
			q.push(temp->right);
		q.pop();
	}
}

//function for PreOrder traversal of a binary tree
void PreOrder(bstnode* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

//function for InOrder traversal of a binary tree
void InOrder(bstnode* root)
{
	if(root==NULL)
		return;
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

//function for PostOrder traversal of a binary tree
void PostOrder(bstnode* root)
{
	if(root==NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}

//function to check if a given tree is a BST
bool isBST(bstnode* root,int min_v,int max_v)
{
	if(root==NULL)
		return true;
	if(root->data >=min_v && root->data<=max_v && isBST(root->left,min_v,root->data) && isBST(root->right,root->data,max_v))
		return true;
		else
		return false;	
}
bool checkBST(bstnode* root)
{
	if(isBST(root,INT_MIN,INT_MAX))
		return true;
	else
		return false;
}

//function to find the Lowest Common Ancestor of two given node values
bstnode * lca(bstnode * root, int v1,int v2)
{
 bstnode* temp1 =root;
    bstnode* temp2=root;
vector<bstnode*> vec1,vec2;
    
    while(1)
    {
        if(temp1->data == v1)
        {
            vec1.push_back(temp1);
            break;
        }
        else
            if(v1<temp1->data)
            {
                vec1.push_back(temp1);
                temp1 = temp1->left;
            }
        else
            if(v1>temp1->data)
            {
                vec1.push_back(temp1);
                temp1 = temp1->right;
            }
    }
   while(1)
    {
        if(temp2->data == v2)
        {
            vec2.push_back(temp2);
            break;
        }
        else
            if(v2<temp2->data)
            {
                vec2.push_back(temp2);
                temp2 = temp2->left;
            }
        else
            if(v2>temp2->data)
            {
                vec2.push_back(temp2);
                temp2 = temp2->right;
            }
    }
    bstnode* req ;
    for(int i=0;;i++)
    {
        if(vec1[i]!=vec2[i])
        {
            req = vec1[i-1];
            break;
        }
    }
    return req;
}

int main()
{
    bstnode* root = NULL;              //enpty BST

    root = insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,17);
    root=insert(root,25);
    //root= insert(root,100);
    if(search(root,8))
    	cout<<"Found"<<endl;
    else
    	cout<<"Not Found"<<endl;
    cout<<"The min element is"<<" "<<min_rec(root)<<endl;
    cout<<"The max element is"<<" "<<max_rec(root)<<endl;
    cout<<"Height of tree is "<<" "<<height(root)<<endl;
    LevelOrder(root);
    cout<<endl;
    PreOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PostOrder(root);
    cout<<endl;
    if(checkBST(root))
    	cout<<"YES it is BST"<<endl;
    else
    	cout<<"No its not a BST"<<endl;
    cout<<"LCA of 8 and 20 is"<<" "<<lca(root,8,20)->data<<endl;
    cout<<"LCA of 8 and 12 is"<<" "<<lca(root,8,12)->data<<endl;
    return 0;
}
