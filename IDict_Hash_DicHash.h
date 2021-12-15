template<typename T, typename R>class IDictionary {
public:
	virtual size_t Count() = 0;
	virtual void Add(T, R) = 0;
	virtual void remove(T) = 0;
	virtual R GetVal(T) = 0;
	virtual bool ContainsKey(T) = 0;
};

template <class T> class HashTable {

private:
	int Hashfunction(T elem) {
		/*if (elem % 2==0)
			return 0;
		if (elem % 2 != 0)
			return 1;*/
		return elem + 1;
	}
	
public:
	vector<LinkedList<T>> l;
	HashTable() {
	}
	HashTable(T* a, int length) {
		for (int i = 0; i < length; i++) {
			Append(a[i]);
		}
		
	}
	void Append(T a) {
		int z = Hashfunction(a);
		if (z > l.size()) {
			
			LinkedList<T> n(1);
			n.Set(0, a);
			while (z > l.size()) {
				l.push_back(LinkedList<T>());

			};
			l.push_back(n);
		}
		if (z == l.size()) {
			LinkedList<T> n(1);
			n.Set(0, a);
			l.push_back(n);
		}
		if (z < l.size()) {
			l[z].Append(a);
		}
	}
	void remove(T data) {
		int z = Hashfunction(data);
		l[z].DeleteAt(data);
		
	}
	bool find(T data) {
		int z = Hashfunction(data);
		if (z <= l.size())
			return l[z].Find(data);
		else
			return 0;
	}
};

template <class T, class R> class Dictionary: public IDictionary<T, R>
{
private:
	int Hashfunction(int elem) {
		if (elem % 2==0)
			return 0;
		if (elem % 2 != 0)
			return 1;
		//return elem + 1;
	}
	int Hashfunction(double elem) {
		if (elem > 10)
			return 1;
		else
			return 0;
	}
	int Hashfunction(char elem) {
		if (elem == 'a')
			return 1;
		else
			return 0;
	}

public:
	vector<LinkedList<T>> keys;
	vector<LinkedList<R>> data;
	Dictionary() {}
	Dictionary(Pair<T,R>* a, int length) {
		for (int i = 0; i < length; i++) {
			//cout<<"Construct Append\n"<< a[i] << "\n";
			Append(a[i]);
		}
		
	}
	Dictionary(Dictionary<T,R>& a) {
		for (int i = 0; i < a.data.size(); i++) {
			for (int j = 0; j < a.data[i].GetLength(); j++) {
				Add(a.keys[i].Get(j), a.data[i].Get(j));
			}
		}
	}
	void Append(Pair<T,R> a) {
		int z = Hashfunction(a.key);//или data
		if (z > data.size()) {
			//cout << 1 << "\n";
			//cout << a<<"\n";
			R* temp = new R[1];
			temp[0] = a.value;
			LinkedList<R> n(temp,1);
			T* temp1 = new T[1];
			temp1[0] = a.key;
			LinkedList<T> n1(temp1,1);
			
			while (z > data.size()) {
				data.push_back(LinkedList<R>());
				keys.push_back(LinkedList<T>());
				//cout<<1<<" ";
			};
			data.push_back(n);
			keys.push_back(n1);
			//cout << 1 << "\n";
		}
		else
		if (z == data.size()) {
			//cout << 2 << "\n";
			///cout << a<<"\n";
			R* temp = new R[1];
			temp[0] = a.value;
			LinkedList<R> n(temp, 1);
			T* temp1 = new T[1];
			temp1[0] = a.key;
			LinkedList<T> n1(temp1, 1);
			data.push_back(n);
			keys.push_back(n1);
			//cout << 2 << "\n";
		}
		else
		if (z < data.size()) {
			//cout << 3 << "\n";
			//cout << a<<"\n";
			data[z].Append(a.value);
			keys[z].Append(a.key);
			//cout << 3 << "\n";
		}
	}
	void Add(T key, R value) {
		Pair<T, R> a(key, value);
		Append(a);
	}
	size_t Count() {
		size_t x = 0;
		for (int i = 0; i < data.size(); i++) {
			if (data[i].GetLength() != 0) {
				
				x += data[i].GetLength();
			}
			
		}
		return x;
	}
	void remove(T key) {
		assert(ContainsKey(key) != 0);
		int y = 0;
		int t = 0;
		for (int i = 0; i < keys.size(); i++) {
			//cout << "List " << i << "\n";
			for (int j = 0; j < keys[i].GetLength(); j++) {
				if (key == keys[i].Get(j)) {
					keys[i].DeleteKey(j);
					data[i].DeleteKey(j);
					return;
				}
				
			}
		}
		
	}
	bool ContainsKey(T key) {
		for (int i = 0; i < keys.size(); i++) {
			
			for (int j = 0; j < keys[i].GetLength(); j++) {
				
				if (keys[i].Get(j) == key) return 1;

			}
		}
		return 0;
	}
	R GetVal(T key) {
		assert(ContainsKey(key)!=0);
		for (int i = 0; i < keys.size(); i++) {
			
			for (int j = 0; j < keys[i].GetLength(); j++) {
				
				if (keys[i].Get(j) == key) return data[i].Get(j);

			}
		}
	}
	void Print() {
		for (int i = 0; i < keys.size(); i++) {
			
			for (int j = 0; j < keys[i].GetLength(); j++) {
				cout << keys[i].Get(j) << " ";
				cout << data[i].Get(j) << "\n";
			}
		}

	}
};
