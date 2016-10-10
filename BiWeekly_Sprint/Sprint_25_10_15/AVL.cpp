#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
using namespace std;
class AVL{
private:
	struct Node{
		int data;
		Node *left,*right;
		int height;
	};

	typedef struct Node * AVLNODE;
	AVLNODE root;
	
	AVLNODE NewNode(int data){
		Node *node = new Node();
		node->data = data;
		node->left = node->right = NULL;
		node->height = 1;
		return node;
	}
	int GetHeight(AVLNODE head){
		if(head == NULL)
			return 0;
		return max(head->left == NULL ? 0 : head->left->height,head->right==NULL ? 0 : head->right->height)+1;
	}
	int GetBalance(AVLNODE head){
		return GetHeight(head->left)-GetHeight(head->right);
	}

	AVLNODE LeftRotate(AVLNODE head,AVLNODE right){
		AVLNODE rightLeft = right->left;
		right->left = head;
		head->right = rightLeft;
		return right;
	}

	AVLNODE RightRotate(AVLNODE head,AVLNODE left){
		AVLNODE leftRight = left->right;
		left->right = head;
		head->left= leftRight;
		return left;		
	}
	void InsertHelper(AVLNODE &head,int data){
		if(head==NULL)
			head = NewNode(data);
		else if(data<head->data)
			InsertHelper(head->left,data);
		else
			InsertHelper(head->right,data);

		head->height = max(GetHeight(head->left),GetHeight(head->right))+1;

		if(GetBalance(head)> 1 && GetBalance(head->left) > 0)
			head = RightRotate(head,head->left);
		if(GetBalance(head)>1 && GetBalance(head->left) < 0 ){
			head->left = LeftRotate(head->left,head->left->right);
			head = RightRotate(head,head->left);
		}
		if(GetBalance(head) < -1 && GetBalance(head->right) < 0)
			head = LeftRotate(head,head->right);
		if(GetBalance(head) < -1 && GetBalance(head->right) > 0){
			head->right = RightRotate(head->right,head->right->left);
			head = LeftRotate(head,head->right);
		}
	}

	void DeleteHelper(AVLNODE &head,int data){
		if(head==NULL)
			return;
		else if(data<head->data)
			DeleteHelper(head->left,data);
		else if(data>head->data)
			DeleteHelper(head->right,data);
		else{
			if(head->left==NULL && head->right==NULL){
				delete head;
				head = NULL;
			}
			else if(head->left!=NULL && head->right == NULL){
				AVLNODE temp = head;
				head=head->left; delete temp;
			}
			else if(head->left==NULL && head->right!=NULL){
				AVLNODE temp = head;
				head=head->right; delete temp;
			}else{
				AVLNODE temp = head->right;
				while(temp->left!=NULL)
					temp = temp->left;
				swap(temp->data,head->data);
				DeleteHelper(head->right,data);
			}
		}

		if(head == NULL)
			return;

		head->height = max(GetHeight(head->left),GetHeight(head->right))+1;

		if(GetBalance(head)> 1 && GetBalance(head->left) > 0)
			head = RightRotate(head,head->left);
		if(GetBalance(head)>1 && GetBalance(head->left) < 0 ){
			head->left = LeftRotate(head->left,head->left->right);
			head = RightRotate(head,head->left);
		}
		if(GetBalance(head) < -1 && GetBalance(head->right) < 0)
			head = LeftRotate(head,head->right);
		if(GetBalance(head) < -1 && GetBalance(head->right) > 0){
			head->right = RightRotate(head->right,head->right->left);
			head = LeftRotate(head,head->right);
		}
	}
	void Inorder(AVLNODE temp){
		if(temp==NULL)
			return;
		Inorder(temp->left);
		cout<<temp->data<<" ";
		Inorder(temp->right);
	}
public:
	AVL(){
		root = NULL;
	}
	void Insert(int data){
		InsertHelper(root,data);
	}
	void Delete(int data){
		DeleteHelper(root,data);
	}
	void Display(){
		Inorder(root);
	}
};
int main(){
	std::ios_base::sync_with_stdio(false);
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	int a[]={3,6,5,1,8,9,2,4,7,10};
	AVL avl;
	for(int i=0;i<10;i++)
		avl.Insert(a[i]);
	avl.Display();

	for(int i=9;i>=0;i--)
		avl.Delete(a[i]);
	for(int i=0;i<10;i++)
		avl.Insert(a[i]);
	avl.Display();

	for(int i=0;i<10;i++)
		avl.Delete(a[i]);
	avl.Display();
}