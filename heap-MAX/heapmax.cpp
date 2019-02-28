#include "heapmax.h"
#include <cmath>

using namespace std;

PQ_heap::PQ_heap(){ 
	vector <int> keys;
	cout<<"konstruktor zostal wywolany"; // informuje o wywo³aniu konstruktora (oznacza to, ¿e konstruktor zosta³ poprawnie wywo³any) //
}

PQ_heap::~PQ_heap(){
	keys.clear();
	cout<<"destruktor zostal wywolany"; // informuje o wywo³aniu destruktora (oznacza to, ¿e destruktor zosta³ poprawnie wywo³any) //
}

void PQ_heap::fixUP(int ksize){
	int i=ksize;
	while(i>0 && keys[parent(i)]<keys[i]){
		swap(keys[parent(i)], keys[i]);
		i=parent(i);
	}
}

void PQ_heap::fixDOWN(int i){
	while(left(i)<keys.size()){
		int j=i;

		if(left(i)<keys.size() && keys[left(i)]>keys[j]){
			j=left(i);
		}
		if(right(i)<keys.size() && keys[right(i)]>keys[j]){
			j=right(i);
		}
		if(j!=i) {
			swap(keys[j], keys[i]);
			i=j;
		}
		else break;
	}
}

bool PQ_heap::empty(){
	if(keys.size()==0){
		return true;
	}
	else{
		return false;
	}
}

void PQ_heap::insert(int k){
	keys.push_back(k);
	fixUP(keys.size()-1);
}

int PQ_heap::get_max(){
	int maxkey;
	maxkey=keys[0];
	swap(keys[keys.size()-1], keys[0]);
	keys.pop_back();
	fixDOWN(0);
	return maxkey;
}

void PQ_heap::printpriority(){
	int i;
	cout<<endl;
	if(!keys.empty()){
		for(i=0; i<(keys.size()); i++){
			cout<<"nr "<<i<<"="<<keys[i]<<"\t";
		}
		cout<<endl;
	}
	else{
		cout<<"kolejka jest pusta (jezeli wartosc 1), wartosc = "<<keys.empty();
	}
}

void PQ_heap::printheap(){
	if(!keys.empty()){
		cout<<"poziomy kopca:"<<endl;
		int i=0;
		while(i<keys.size()){
			cout<<(int)log2(i+1)<<":"<<"\t";
			int j=i;
			while(j<keys.size() && j<left(i)){
				cout<<keys[j]<<"  ";
				j++;
			}
			i=left(i);
			cout<<endl;
		}
	}
	else{
		cout<<"kopiec jest pusty (jezeli wartosc 1), wartosc = "<<keys.empty()<<endl;
	}
}
