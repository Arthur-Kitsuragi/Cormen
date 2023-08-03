#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
struct node {
	vector<int> list;
	int count = 0;
};
class Heap {
private:
	int left(int index) {
		return index * 2 + 1;
	}
	int right(int index) {
		return index * 2 + 2;
	}
	int parent(int index) {
		return int(floor((index - 1) / 2.0));
	}
	void min_heapify(vector<node>& arr, int index) {
		int l = left(index);
		int r = right(index);
		int smallest = index;
		if (l < arr.size() && ((arr[l].list)[arr[l].count] < (arr[index].list)[arr[index].count])) {
			smallest = l;
		}
		if (r < arr.size() && (arr[r].list[arr[r].count] < arr[smallest].list[arr[smallest].count])) {
			smallest = r;
		}
		if (smallest != index) {
			swap(arr[index], arr[smallest]);
			min_heapify(arr, smallest);
		}
		else {
			return;
		}
	}
public:
	node last;
	vector <node> heap;
	Heap(vector<node> &arr) {
		auto buff = arr;
		for (int i = int(floor(buff.size() / 2.0)) - 1; i >= 0; --i) {
			min_heapify(buff, i);
		}
		heap = buff;
	}
	int heap_extract_min() {
		///куча непуста, проверку было делать впадлу
		int min = heap[0].list[heap[0].count];
		last = heap[0];
		last.count += 1;
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		min_heapify(heap, 0);
		return min;
	}
	void min_heap_insert(node t) {
		heap.push_back(t);
		int i = heap.size() - 1;
		while (i > 0 && heap[parent(i)].list[heap[parent(i)].count] > heap[i].list[heap[i].count]) {
			swap(heap[i], heap[parent(i)]);
			i = parent(i);
		}
	}
	void print() {
		for (int i = 0; i < heap.size(); ++i) {
			cout << heap[i].list[0] << " ";
		}
		cout << endl;
	}
};
void main() {
	vector<int> A = { 1, 2, 3, 66, 122, 1222, 1222 }; //7
	vector<int> B = { -1, 2, 3, 11, 12 }; //5
	vector<int> C = { -1, 2, 505}; //3
	node a, b, c;
	a.list = A;
	b.list = B;
	c.list = C;
	vector<node> arr = { a, b ,c };
	Heap heap(arr);
	/// реализую склеивание 3 листов в 1 здесь
	vector<int> ABC;
	for (int i = 0; i < 15; ++i) {
		int min = heap.heap_extract_min();
		ABC.push_back(min);
		if (heap.last.count != heap.last.list.size()) {
			heap.min_heap_insert(heap.last);
		}
	}
	for (int i = 0; i < 15; ++i) {
		cout << ABC[i] << " ";
	}
	cout << endl;
}