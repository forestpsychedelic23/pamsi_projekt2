#include "Vertex.h"
#include <iostream>

template<class T>
class Graph{
	private:
		int inf;		//nieskonczonosc
		int size;
		int **matrix;
		Vertex<T> *Vertexes;
	public:
		Graph();
		Graph(int n);
		~Graph();
		void InsertEdge(int v1, int v2, int w);
		void InsertEdgeFullMatrix();
		void InsertEdgeInList(int v1, int v2, int w);
		void BelmanFordList(int v);
		void BelmanFordMatrix(int v);
		void SetGraph(int n);
		void reset();
};

template<class T>
Graph<T>::Graph(){
}

template<class T>
Graph<T>::Graph(int n){
	inf = 10000;
	size = n;
	matrix = new int*[n];
	for(int i=0;i<n;i++){
		matrix[i] = new int[n];
	}
	Vertexes = new Vertex<T>[n];
	for(int i=0;i<n;i++){
		Vertexes[i].SetIndex(i);
	}
	for(int j=0;j<n;j++){
		for(int k=0;k<n;k++)
			matrix[j][k] = inf;
	}
}

template<class T>
inline Graph<T>::~Graph(){
	delete[] Vertexes;
	for(int i=0;i<size;i++)
		delete[] matrix[i];
	delete[] matrix;
}

template<class T>
inline void Graph<T>::InsertEdge(int v1, int v2, int w){
	int pom;
	Vertexes[v1].AddToList(v2, w);
	
	if(matrix[v1][v2] == inf)
		matrix[v1][v2] = w;
	else{
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if(matrix[i][j] == inf){
					matrix[i][j] = w;
					break;
				}
			}
		}
	}
}	

template<class T>
inline void Graph<T>::InsertEdgeFullMatrix(){
	int pom;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(i==j) continue;
			pom = rand() % 10 + 1;
			matrix[i][j] = pom;
		}
	}
}

template<class T>
inline void Graph<T>::InsertEdgeInList(int v1, int v2, int w){
	Vertexes[v1].AddToList(v2, w);
}

template<class T>
inline void Graph<T>::BelmanFordList(int v){
	int *d = new int[size];
	int *p = new int[size];
	int pom_1, pom_2, wg;
	Node<Vertex<int>> *temp;
	
	for(int i=0;i<size;i++)
		d[i] = inf;
	
	for(int i=0;i<size;i++)
		p[i] = -1;
	
	d[v] = 0;
	
	for(int j=1;j<size;j++) //relax
	for(int i=0;i<size;i++){
		pom_1 = Vertexes[i].GetIndex(); //wierzcholki z listy
		for(temp = Vertexes[i].GiveHead(); temp != nullptr; temp = temp->next){
			pom_2 = temp->GiveValue()->GetIndex();
			wg = temp->GiveValue()->GetWage();
			if(d[pom_2]>d[pom_1]+wg){
				d[pom_2] = d[pom_1] + wg;
				p[pom_2] = pom_1;
			}
		}
	}
	//sprawdzenei czy zachodzi cykl ujemny
	for(int i=0;i<size;i++){
		pom_1 = Vertexes[i].GetIndex();
		for(temp = Vertexes[i].GiveHead(); temp!=nullptr; temp = temp->next){
			pom_2 = temp->GiveValue()->GetIndex();
			wg = temp->GiveValue()->GetWage();
			if(d[pom_2]>d[pom_1] +wg){
				std::cout << "Cykl jest ujemny." << std::endl;
				exit(0);
			}
		}
	}
	delete[] d;
	delete[] p;
}

template<class T>
inline void Graph<T>::BelmanFordMatrix(int v){
	int *d = new int[size];
	int *p = new int[size];
	int wg;
	for(int i=0;i<size;i++)
		d[i] = inf;
	for(int i=0;i<size;i++)
		p[i]=-1;
	
	d[v] = 0;
	for(int a=1;a<size;a++)	// relax
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++){
			wg = matrix[i][j];
			if(wg<inf){
				if(d[j]>d[i] + wg){
					d[j] = d[i] + wg;
					p[j] = i;
				}
			}
		}
	
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++){
			wg = matrix[i][j];
			if(wg<inf){
				if(d[j]>d[i] + wg){
					cout<< "Cykl jest ujemny." << endl;
					exit(0);
				}
			}
		}
		
	delete[] d;
	delete[] p;
}

template<class T>
inline void Graph<T>::SetGraph(int n){
	inf = 10000;
	size = n;
	matrix = new int*[n];
	
	for(int i=0;i<n;i++)
		matrix[i] = new int[n];
	
	Vertexes = new Vertex<T>[n];
	for(int i=0;i<n;i++)
		Vertexes[i].SetIndex(i);
	for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
			matrix[j][k] = inf;
}

template<class T>
inline void Graph<T>::reset(){
	delete[] Vertexes;
	for(int i;i<size;i++)
		delete[] matrix[i];
	delete[] matrix;
}
