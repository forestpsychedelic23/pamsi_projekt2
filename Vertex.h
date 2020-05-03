#include "List.h"

template<class T>
class Vertex{
		T element;			
		int wage, index;	
		List<Vertex> AdjacencyList;
	public:
		static int number;
		
		Vertex();
		~Vertex();
		void SetElement(T e);
		void SetIndex(int i);
		int GetIndex();
		void SetWage(int w);
		int GetWage();
		void AddToList(int i, int w);
		Node<Vertex<T>> *GiveHead();
		Node<Vertex<T>> *GiveTail();
};

template<class T>
int Vertex<T>::number = 0;

template<class T>
Vertex<T>::Vertex(){
	wage = 0;
	element = 0;
	number++;
}

template<class T>
Vertex<T>::~Vertex(){
	AdjacencyList.clear();
	number--;
}

template<class T>
void Vertex<T>::SetElement(T e){
	element = e;
}

template<class T>
void Vertex<T>::SetIndex(int i){
	index = i;
}

template<class T>
inline int Vertex<T>::GetIndex(){
	return index;
}

template<class T>
void Vertex<T>::SetWage(int w){
	wage = w;
}

template<class T>
inline int Vertex<T>::GetWage(){
	return wage;
}

template<class T>
void Vertex<T>::AddToList(int i, int w){
	Vertex<T> v;
	v.SetIndex(i);
	v.SetWage(w);
	AdjacencyList.PushBack(v);
}

template<class T>
inline Node<Vertex<T>> *Vertex<T>::GiveHead(){
	return AdjacencyList.GiveHead();
}

template<class T>
inline Node<Vertex<T>> *Vertex<T>::GiveTail(){
	return AdjacencyList.GiveTail();
}