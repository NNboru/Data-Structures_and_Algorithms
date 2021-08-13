# include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>

#define fr(i,n) for(int i=0;i<n;++i)
#define pr cout<<
#define sp <<' '
#define en <<'\n'

using namespace std;
typedef long long ll;


// Doubly circular non-header link list (where header is a pointer, not a node)
class Doubly_list{
	int _size;
	public:
	struct node{
		node *next=NULL;
		node *prev=NULL;
		int value;
		node(int v = 0){value=v;}
	};
	node *HEAD;
	Doubly_list() : _size(0), HEAD(NULL) {}
	
	int size(){
		return this->_size;
	}
	
	node* insert(node* ptr, int value){
		// returns pointer to newly inserted node.
		node *tmp = new node(value);
		
		tmp->next = ptr->next;
		ptr->next = tmp;
		tmp->prev = ptr;
		tmp->next->prev = tmp;
		
		this->_size++;
		return tmp;
	}
	
	node* insert(int value){
		// insert at HEAD, returns pointer to newly inserted node.
		node *tmp = new node(value);
		if(HEAD == NULL){ // when _size=0
			tmp->prev = tmp->next = tmp;
		}
		else{
			tmp->next = HEAD;
			HEAD->prev->next = tmp;
			tmp->prev = HEAD->prev;
			HEAD->prev = tmp;
		}
		
		HEAD = tmp;
		this->_size++;
		return tmp;
	}
	
	node* remove(node *ptr){
		// remove ptr, returns pointer next to removed node or NULL if size=0.
		this->_size--;
		if(this->_size == 0){
			delete ptr;
			return (HEAD = NULL);
		}
		
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		
		node *tmp = ptr->next;
		if(HEAD == ptr)
			HEAD = tmp;
		delete ptr;
		return tmp;
	}
	
	node* find(int value){
		// returns pointer to node with value=value if exists else NULL.
		if(HEAD==NULL) return NULL;
		node* tmp = HEAD;
		do{
			if(tmp->value==value)
				return tmp;
			tmp = tmp->next;
		} while(tmp != HEAD);
		
		return NULL;
	}
	
	void show(){
		if(this->_size==0){
			cout<<"empty list\n";
			return;
		}
		node *tmp = HEAD;
		do{
			cout<< tmp->value <<' ';
			tmp = tmp->next;
		} while(tmp != HEAD);
		cout<<endl;
	}
	
};



main(){
	int t=1,n;
	
	auto my = Doubly_list();
	my.insert(1);
	my.insert(2);
	auto p = my.insert(4);
	my.insert(p,3);
	my.insert(5);
	my.remove(my.find(4)); // removes 4.
	
	my.show();
	pr "size = "<< my.size();
	
}