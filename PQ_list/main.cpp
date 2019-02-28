#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "pqtab.h"
#define N 10000

using namespace std;

int main(){
	// *** TESTY POPRAWNO�CI IMPLEMENTACJI *** //
	PQ keys;
	int liczby[N];
	
	for(int i=0; i<20; i++){ // kolejka dla przyk�adowych 20 liczb //
		liczby[i]=rand();
		keys.insert(liczby[i]);  // sprawdzam poprawno�� dzia�ania funkcji insert //
	}
	
	cout<<endl;
	keys.print(); // sprawdzam, czy funkcja print wy�wietla klucze oraz czy funkcja insert poprawnie umie�ci�a klucze w kolejce //
	cout<<endl<<"rozmiar kolejki="<<keys.prioritysize()<<endl; // sprawdzam dzia�anie funkcji prioritysize, wynikiem powinien by� ca�kowity rozmiar kolejki, czyli 20 //
	
	while(!keys.empty()){
		cout<<keys.get_max()<<"\t"; // sprawdzam poprawno�� dzia�ania funkcji get_max //
	}
	cout<<endl<<"rozmiar kolejki="<<keys.prioritysize(); // sprawdzam, czy funkcja get_max poprawnie usun�a wszystkie klucze z kolejki, wynikiem powinno by� 0 //
	cout<<endl<<"kolejka jest pusta (jezeli wartosc 1), wartosc = "<<keys.empty()<<endl; // sprawdzam poprawno�� dzia�ania funkcji empty //
	
	
	// *** CZʌ� OBLICZENIOWA - WYDAJNO�� *** //
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
	
	outcome<<endl<<"Kolejka na tablicy zwyk�ej obs�uguj�ca "<<N<<" liczb \tczas obs�u�enia element�w kolejki:"<<time_end-time_start;
	outcome.close();
	
	return 0;
}
