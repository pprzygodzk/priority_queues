#include "pqtab.h"

using namespace std;

PQ::PQ(){
	vector <int> keys;
	cout<<"konstruktor zostal wywolany"; // informuje o wywo³aniu konstruktora (oznacza to, ¿e konstruktor wywo³uje siê poprawnie) //
}

PQ::~PQ(){
	keys.clear();
	cout<<"destruktor zostal wywolany"; // informuje o wywo³aniu destruktora (oznacza to, ¿e destruktor wywo³uje siê poprawnie) //
}

bool PQ::empty(){
	if(keys.size()==0){
		return true;
	}
	else{
		return false;
	}
}

void PQ::print(){
	int i=0, ksize=keys.size();
	while(i<ksize){
		cout<<"nr "<<i<<"="<<keys[i]<<"\t";
		i++;
	}
}

void PQ::insert(int k){
	keys.push_back(k);
}

int PQ::get_max(){
	int i, indexmax=0, ksize=keys.size(), a;
	
	for(i=1; i<ksize; i++){
		if(keys[i]>keys[indexmax]){
			indexmax=i;
		}
	}
	a=keys[ksize-1];
	keys[ksize-1]=keys[indexmax];
	keys[indexmax]=a;
	keys.pop_back();
	return keys[ksize-1];
}

int PQ::prioritysize(){
	return keys.size();
}
