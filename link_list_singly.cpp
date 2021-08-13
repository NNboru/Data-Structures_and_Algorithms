// # include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>

#define fr(i,n) for(int i=0;i<n;++i)
#define pr cout<<
#define sp <<' '
#define en <<'\n'

using namespace std;
typedef long long ll;


// Singly header link list (where header is a node)
class Singly_list{
	public:
	struct node{
		node *next=NULL;
		int value;
		node(int v = 0){value=v;}
	};
	node *HEAD;
	Singly_list(){
		HEAD = new node(0); // no of elements=0
	}
	
	int size(){
		return this->HEAD->value;
	}
	
	node* insert(node* ptr, int value){
		// returns pointer to newly inserted node.
		node *tmp = new node(value);
		tmp->next = ptr->next;
		ptr->next = tmp;
		this->HEAD->value++;
		return tmp;
	}
	node* insert(int value){
		// insert at HEAD, returns pointer to newly inserted node.
		node *tmp = new node(value);
		tmp->next = this->HEAD->next;
		this->HEAD->next = tmp;
		this->HEAD->value++;
		return tmp;
	}
	
	node* remove(node *ptr){
		// remove next of ptr, returns pointer to removed node.
		if(ptr->next!=NULL){
			node* tmp = ptr->next;
			ptr->next = ptr->next->next;
			--this->HEAD->value; // decrease count.
			return tmp;
		}
		return NULL;
	}
	
	node* find(int value){
		// returns pointer to node with value=value if exists else NULL.
		node* tmp = HEAD;
		while(tmp->next!=NULL){
			tmp = tmp->next;
			if(tmp->value==value)
				return tmp;
		}
		return NULL;
	}
	
	node* show(){
		// returns pointer to last node.
		node *tmp = HEAD;
		while(tmp->next!=NULL){
			pr tmp->next->value sp;
			tmp = tmp->next;
		}
		pr endl;
		return tmp;
	}
	
};



main(){
	int t=1,n;
	
	auto my = Singly_list();
	my.insert(1);
	my.insert(2);
	auto p = my.insert(4);
	my.insert(p,3);
	my.insert(5);
	my.remove(my.find(4)); // removes next of 4 = 3.
	my.show();
	pr "size = "<< my.size();
	
}