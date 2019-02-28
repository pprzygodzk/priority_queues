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
	// *** TESTY POPRAWNOŒCI IMPLEMENTACJI *** //
	PQ_heap keys;
	int liczby[N];
	int rozmiar=20;
	
	for(int i=0; i<rozmiar; i++){ // przyk³adowa kolejka dla 20 losowych liczb //
		liczby[i]=rand();
		keys.insert(liczby[i]); // sprawdzam poprawnoœæ dzia³ania funkcji insert //
	}
	cout<<endl;
	keys.printheap(); //sprawdzam poprawnoœæ wyœwietlania kopca i czy funkcja insert poprawnie umieœci³a klucze na kopcu //
	cout<<endl<<"wysokosc kopca="<<(int)log2(rozmiar-1)<<endl;
	
	while(!keys.empty()){
		cout<<keys.get_max()<<"\t"; // sprawdzam poprawnoœæ dzia³ania funkcji get_max, wynikiem s¹ klucze od najwiêkszego do najmniejszego //
	}
	cout<<endl;
	keys.printheap(); // sprawdzam, czy funkcja get_max usunê³a wszystkie klucze z kopca oraz poprawnoœæ dzia³ania u¿ytej w niej funkcji empty //
	
	
	// *** CZÊŒÆ OBLICZENIOWA - WYDAJNOŒÆ *** //
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
	
	outcome<<endl<<"Kolejka kopiec MAX obs³uguj¹ca "<<N<<" liczb \t czas obs³u¿enia elementów kolejki:"<<time_end-time_start;
	outcome.close();
	
	return 0;
}
