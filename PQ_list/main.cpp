#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "pqtab.h"
#define N 10000

using namespace std;

int main(){
	// *** TESTY POPRAWNOŒCI IMPLEMENTACJI *** //
	PQ keys;
	int liczby[N];
	
	for(int i=0; i<20; i++){ // kolejka dla przyk³adowych 20 liczb //
		liczby[i]=rand();
		keys.insert(liczby[i]);  // sprawdzam poprawnoœæ dzia³ania funkcji insert //
	}
	
	cout<<endl;
	keys.print(); // sprawdzam, czy funkcja print wyœwietla klucze oraz czy funkcja insert poprawnie umieœci³a klucze w kolejce //
	cout<<endl<<"rozmiar kolejki="<<keys.prioritysize()<<endl; // sprawdzam dzia³anie funkcji prioritysize, wynikiem powinien byæ ca³kowity rozmiar kolejki, czyli 20 //
	
	while(!keys.empty()){
		cout<<keys.get_max()<<"\t"; // sprawdzam poprawnoœæ dzia³ania funkcji get_max //
	}
	cout<<endl<<"rozmiar kolejki="<<keys.prioritysize(); // sprawdzam, czy funkcja get_max poprawnie usunê³a wszystkie klucze z kolejki, wynikiem powinno byæ 0 //
	cout<<endl<<"kolejka jest pusta (jezeli wartosc 1), wartosc = "<<keys.empty()<<endl; // sprawdzam poprawnoœæ dzia³ania funkcji empty //
	
	
	// *** CZÊŒÆ OBLICZENIOWA - WYDAJNOŒÆ *** //
	ofstream outcome;
	outcome.open("wyniktablicazwykla.txt", ios_base::app);
	
	for(int i=0; i<N; i++){
		liczby[i]=rand();
	}
	
	unsigned int time_start=clock();
	
	for(int i=0; i<N; i++){
		keys.insert(liczby[i]);
	}
	
	while(!keys.empty()){
		keys.get_max(); 
	}
	
	unsigned int time_end=clock();
	
	outcome<<endl<<"Kolejka na tablicy zwyk³ej obs³uguj¹ca "<<N<<" liczb \tczas obs³u¿enia elementów kolejki:"<<time_end-time_start;
	outcome.close();
	
	return 0;
}
