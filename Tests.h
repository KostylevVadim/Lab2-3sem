#include "ta vsa yeres"
void Hash_DictionaryTest() {
	int* m = new int[6];
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = 1;
	int* n = new int[6];
	n[5] = 1;
	n[4] = 0;
	n[3] = 1;
	n[2] = 0;
	n[1] = 0;
	n[0] = 1;
	Vector<int> a(m,6);
	
	Vector<int> b(n, 6);
	
	
	
	Dictionary<int, int> L;
	L = a.Get();
	Dictionary<int, int> N;
	
	Vector<int> c;
	c = a - b;
	N = c.Get();
	int x = a * b;
	cout << x;
}
void Cache_Test() {
	ListSequence<int>* a = new ListSequence<int>;
	for (int i = 0; i < 10; i++) {
		a->Append(i * 10 + rand() % 10);
		cout << a->Get(i) << " ";
	}
	cout << "\n";
	Cache<int> Cach((ListSequence<int>*)a,5);

	Dictionary<int, int> t;
	t = Cach.ReturnCache();
	cout << "\n========================================\n";
	t.Print();
}
int indexer(int x) {
	return x + 1;
}
bool indexer_cmp(int x) {
	if (x > 45)
		return 1;
	else
		return 0;
}
void Indexes_Test() {
	ListSequence<int>* a = new ListSequence<int>;
	for (int i = 0; i < 10; i++) {
		a->Append(i * 10 + rand() % 10);
		cout << a->Get(i) << " ";
	}
	Dictionary<int, int> t;
	Indexes<int, int> g((ListSequence<int>*)a,indexer_cmp);
	t = g.ReturnIndexed();
	t.Print();
}
