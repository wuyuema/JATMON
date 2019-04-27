#include <cstdio>
#include <iostream>
using namespace std;

template<typename T> class lklist {
	private:
		struct _node {
			T data;
			_node *last, *next;
			_node(_node *u = NULL, _node *v = NULL, T cont = 0) : last(u), next(v), data(cont) {}
		};
		_node *newnode() {return new _node();}
		_node HEAD = _node(NULL, newnode());
		_node TAIL = _node(&HEAD, NULL);
	public:
		inline void clear() {
			for (_node *ite = TAIL.last; ite != &HEAD; ite = ite->last) 
				delete ite;
		}
		inline void insert(T cont, _node *pos) {
			_node *bef = pos->last;
			_node *tmp = newnode();
			tmp->last = bef;
			tmp->next = pos;
			tmp->data = cont;
			bef->next = pos->last = tmp;
		}
		inline void append(T cont) {insert(cont, &TAIL);}
		inline void push_back(T cont) {insert(cont, &TAIL);}
		inline void push_front(T cont) {insert(cont, HEAD.next);}
		inline void init(T cont[], int size) {
			clear();
//			int size = sizeof(cont) / sizeof(cont[0]);
			for (int i = 0; i < size; ++i) append(cont[i]);
		}
		inline disp_via_cout() {
			for (_node *ite = HEAD.next; ite != &TAIL; ite = ite->next) cout << ite->data << ' ';
		}
};

int main() {
	int a[] = {1, 2, 3, 4};
	lklist<int> b;
	b.init(a, sizeof(a) / sizeof(a[0]));
	b.disp_via_cout();
	return 0;
}
