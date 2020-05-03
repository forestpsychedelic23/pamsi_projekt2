#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class List{
	private:
		Node<T> *head;
		Node<T> *tail;
		int length;
	public:
		List();
		~List();
		
		void PushFront(T element);
		void PopFront();
		void PushBack(T element);
		void PopBack();
		void clear();
		void SetHead(Node<T> *nHead);
		void SetTail(Node<T> *nTail);
		void RemoveFromPosition(int pos);
		void remove(Node<T> *v);
		int size();
		bool IsEmpty();
		T front();
		T back();
		Node<T> *GiveHead();
		Node<T> *GiveTail();
		Node<T> *iteration();
		T iter(Node<T> *t);
};

template<class T>
List<T>::List(){
	head = nullptr;
	tail = nullptr;
	length = 0;
}

template<class T>
List<T>::~List(){
	Node<T> *p;
			
	while(head!=nullptr){
		p = head->next;
		delete head;
		head = p;
	}
}
template <class T>
void List<T>::clear(){
	while(length)
		PopFront();
}

template <class T>
bool List<T>::IsEmpty(){
	if(length==0){
		return true;
	}
	else{
		return false;
	}
}

template <class T>
int List<T>::size(){
		return length;
}

template <class T>
void List<T>::PushFront(T element){
	length++;
	Node<T> *added = new Node<T>;
	added->value = element;
	added->next = nullptr;
	if(head==nullptr){
		head = added;
		tail = added;
	}
	else{
		added->next = head;
		head->prev = added;
		head = added;
	}
}

template <class T>
void List<T>::PopFront(){
	if(IsEmpty()){
		cout << "List is empty." << endl;
	}
	else{
		length--;
		Node<T> *temp = new Node<T>;
		temp = head;
		head = head->next;
		if(head!=nullptr)
			head->prev = nullptr;
		delete temp;
	}
}

template<class T>
void List<T>::PushBack(T element){
	length++;
	Node<T> *added = new Node<T>;
	added->value = element;
	
	if(head==nullptr){
		added->next = nullptr;
		added->prev = nullptr;
		head = added;
		tail = added;
	}
	else{
		added->prev = tail;
		tail->next = added;
		added->next = nullptr;
		tail = added;
	}
}

template<class T>
void List<T>::PopBack(){
	if(IsEmpty()){
		cout << "List is empty" << endl;
	}
	else{
		length--;
		Node<T> *temp = new Node<T>;
		temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
	}
}

template<class T>
void List<T>::SetHead(Node<T> *nHead){
	head = nHead;
}

template<class T>
void List<T>::SetTail(Node<T> *nTail){
	head = nTail;
}

template<class T>
T List<T>::front(){
	if(head == nullptr)
		cout << "List is empty" << endl;
	else
		return head->value;
}	

template<class T>
T List<T>::back(){
	return tail->value;
}

template<class T>
inline Node<T> *List<T>::GiveHead(){
	return head;
}

template<class T>
inline Node<T> *List<T>::GiveTail(){
	return tail;
}

template<class T>
inline Node<T> *List<T>::iteration(){
	Node<T> *temp = new Node<T>;
	
	temp = head;
	temp = temp->next;
	return temp;
}

template<class T>
inline void List<T>::RemoveFromPosition(int pos){
	Node<T> *current = new Node<T>;
	Node<T> *previous = new Node<T>;
	current = head;
	for(int i=1;i<pos;i++){
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
}

template<class T>
inline void List<T>::remove(Node<T> *v){
	Node<T> *temp_1 = new Node<T>;
	Node<T> *temp_2 = new Node<T>;
	temp_1 = head;
	
	while(temp_1!=nullptr){
		if(temp_1==v){
			temp_2 = temp_1->prev;
			temp_2->next = temp_1->next;
			delete temp_1;
		}
		else
			temp_1 = temp_1->next;
	}
}

template<class T>
inline T List<T>::iter(Node<T> *t){
	Node<T> *temp = new Node<T>;
	
	temp = head;
	temp = temp->next;
	return temp;
}