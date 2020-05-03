#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Graph.h"

using namespace std;

int main(){
	
	srand(time(NULL));
	
	fstream plik_1, plik_2, plik_3;
	int e, v, s = 0;	// ilosc krawedzi, ilosc wierzchlkow
	int v1, v2, w, n; 		// krawedzie, waga
	int exp = 100;
	double g;

	plik_1.open("dane.txt", ios::out);
	
	int tab_1[5] = {10, 30, 50, 150, 250};	//liczba wierzcholkow
	double tab_2[4] = {0.25, 0.5, 0.75, 1};
	

	
	for(int i=0;i<5;i++){
		n = tab_1[i];
		for(int k=0;k<4;k++){
			g = tab_2[k];
			e = g * n * (n-1);
			plik_1 << e << " " << n << " " << s << endl;
			for(int a=0;a<exp;a++)
				for(int j=0; j<e; j++){
					v1 = rand() % n;
					v2 = rand() % n;
					w = rand() % 100+1;
					plik_1 << v1 << " " << v2 << " " << w << endl;
				}
		}
	}
		plik_1.close();
		cout << "Saved" << endl;
		// zapisywanie wynikow
		// wczytywanie
		plik_1.open("dane.txt", ios::in);
		plik_2.open("wyniki_list.txt", ios::out);
		plik_3.open("wyniki_matrix.txt", ios::out);
		Graph<int> *graf = new Graph<int>;
		for(int i=0;i<5;i++){
			cout << "Wielkosc: " << i << endl;
			for(int k=0;k<4;k++){
				cout << "Gestosc: " << k << endl;
				plik_1 >> e >> v >> s;
				for(int j=0;j<exp;j++){
					graf->SetGraph(v);
					if(k==3){
						graf->InsertEdgeFullMatrix();
						for(int h=0;h<e;h++){
							plik_1 >> v1 >> v2 >> w;
							graf->InsertEdgeInList(v1, v2, w);
						}
					}
					else{
						for(int h=0;h<e;h++){
							plik_1 >> v1 >> v2 >> w;
							graf->InsertEdge(v1, v2, w);
						}
					}	
					//LIST
					auto start = std::chrono::system_clock::now();  // liczymy czas
					graf->BelmanFordList(s);
					auto end = std::chrono::system_clock::now();
					std::chrono::duration<double> diff = end - start;
					double DurationTime = diff.count();
					
					plik_2 << "List " << i << " " << k << " " << DurationTime << endl; //zapisanie do pliku
					//MATRIX
					start = std::chrono::system_clock::now();
					graf->BelmanFordMatrix(s);
					end = std::chrono::system_clock::now();
					diff = end - start;
					DurationTime = diff.count();
					plik_3 << "Matrix " << i << " " << k << " " << DurationTime << endl;
					graf->reset();
				}
			}
		}	
		plik_1.close();
		plik_2.close();
		plik_3.close();
	}
	
	
	
	
