#include <cstdio>
#include <iostream>
using namespace std;

template <typename T>
class lklist {
	private:
		struct _node {
			T data;
			_node *last, *next;
			_node(_node *u = NULL, _node *v = NULL, T cont = 0) : last(u), next(v), data(cont) {}
		};
		_node *_newnode() {
			return new _node();
		}
		_node *newnode(_node *u = NULL, _node *v = NULL, T cont = 0) {
			_node *tmp = new _node();
			tmp->last = u, tmp->next = v, tmp->data = cont;
			return tmp;
		}
		void innode(_node *tmp, _node *u = NULL, _node *v = NULL, T cont = 0) {
			tmp->last = u, tmp->next = v, tmp->data = cont;
		}
		_node *HEAD, *TAIL;

	public:
		lklist<T> (_node *nHEAD = NULL, _node *nTAIL = NULL) {
			if (nHEAD == NULL && nTAIL == NULL){
//				this->HEAD = newnode(NULL, TAIL);
//				this->TAIL = newnode(HEAD, NULL);
				this->HEAD = _newnode();
				this->TAIL = newnode(HEAD, NULL);
				HEAD->last = NULL;
				HEAD->next = TAIL;
			}
			else {
				this->HEAD = nHEAD; this->TAIL = nTAIL;
			}
		}
		inline void clear() {
			for (_node *ite = TAIL->last; ite != HEAD; ite = ite->last)
				delete ite;
		}
		inline void insert(T cont, _node *pos) {
			_node *bef = pos->last;
			_node *tmp = _newnode();
			tmp->last = bef;
			tmp->next = pos;
			tmp->data = cont;
			bef->next = pos->last = tmp;
		}
		inline void append(T cont) {insert(cont, TAIL);}
		inline void push_back(T cont) {insert(cont, TAIL);}
		inline void push_front(T cont) {insert(cont, HEAD->next);}
		inline void init(T cont[], int size) {
			clear();
			for (int i = 0; i < size; ++i) append(cont[i]);
		}
		inline void disp_via_cout() {
			for (_node *ite = HEAD->next; ite != TAIL; ite = ite->next)
				cout << ite->data << ' ';
			cout << endl;
		}
		inline void erase(_node *pos) {
			_node *bef = pos->last, *aft = pos->next;
			delete pos;
			bef->next = aft;
			aft->last = bef;
		}
		lklist cut(_node *former, _node *latter) {
			for (_node *ite = latter->next; ite != NULL; ite = ite->next) delete ite;
			for (_node *ite = former->last; ite != NULL; ite = ite->last) delete ite;
			_node *_HEAD = newnode(NULL, former), *_TAIL = newnode(latter, NULL);
			former->last = _HEAD;
			latter->next = _TAIL;
			return lklist<T>(_HEAD, _TAIL);
		}
		lklist clone(_node *former, _node *latter) {
			lklist<T> tmp = lklist<T>();
			for (_node *ite = former; ite != latter->next; ite = ite->next) tmp.append(ite->data);
			return tmp;
		}
		inline _node *begin() {return HEAD->next;}
		inline _node *end() {return TAIL->last;}
		lklist merge(lklist<T> ap) {
			TAIL->last->next = ap.HEAD->next;
			ap.HEAD->next->last = TAIL->last;
			TAIL = ap.TAIL;
			return *this;
		}
};

inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

int main() {
	int n = read();
	lklist<int> b = lklist<int>();
	for (int i = 0; i < n; i++)
		b.push_back(read());
	b.disp_via_cout();
	n = read();
	lklist<int> c = lklist<int>();
	for (int i = 0; i < n; i++)
		c.push_back(read());
	c.disp_via_cout();
	b.merge(c);
	b.disp_via_cout();
	return 0;
}
