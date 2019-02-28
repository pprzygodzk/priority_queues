#include <iostream>
#include <vector>

using namespace std;

class PQ_heap{
	private:
		vector <int> keys;
		
		int parent(int i) { return (i-1)/2; }
		int left(int i) { return 2*i+1; }
		int right(int i) { return 2*i+2; }

		void fixUP(int ksize);
		void fixDOWN(int i);
	public:
		PQ_heap();
		~PQ_heap();
		
		bool empty();
		void insert(int k);
		int get_max();
		void printpriority();
		void printheap();
};
