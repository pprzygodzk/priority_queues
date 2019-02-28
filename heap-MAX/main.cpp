#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include "heapmax.h"
#define N 10000

using namespace std;


int main(){
	// *** TESTY POPRAWNO�CI IMPLEMENTACJI *** //
	PQ_heap keys;
	int liczby[N];
	int rozmiar=20;
	
	for(int i=0; i<rozmiar; i++){ // przyk�adowa kolejka dla 20 losowych liczb //
		liczby[i]=rand();
		keys.insert(liczby[i]); // sprawdzam poprawno�� dzia�ania funkcji insert //
	}
	cout<<endl;
	keys.printheap(); //sprawdzam poprawno�� wy�wietlania kopca i czy funkcja insert poprawnie umie�ci�a klucze na kopcu //
	cout<<endl<<"wysokosc kopca="<<(int)log2(rozmiar-1)<<endl;
	
	while(!keys.empty()){
		cout<<keys.get_max()<<"\t"; // sprawdzam poprawno�� dzia�ania funkcji get_max, wynikiem s� klucze od najwi�kszego do najmniejszego //
	}
	cout<<endl;
	keys.printheap(); // sprawdzam, czy funkcja get_max usun�a wszystkie klucze z kopca oraz poprawno�� dzia�ania u�ytej w niej funkcji empty //
	
	
	// *** CZʌ� OBLICZENIOWA - WYDAJNO�� *** //
	ofstream outcome;
	outcome.open("wynikkopiecMAX.txt", ios_base::app);
	
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
	
	outcome<<endl<<"Kolejka kopiec MAX obs�uguj�ca "<<N<<" liczb \t czas obs�u�enia element�w kolejki:"<<time_end-time_start;
	outcome.close();
	
	return 0;
}
