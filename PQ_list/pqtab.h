#include <iostream>
#include <vector>

using namespace std;

class PQ{
	private:
		vector <int> keys;
	public:
		PQ();
		~PQ();
		
		bool empty();
		void print();
		void insert(int k);
		int get_max();
		int prioritysize();
};
