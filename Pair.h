#pragma once
template <class T, class R> class Pair {
public:
	T key;
	R value;
	Pair() {};
	Pair(T key, R value) {
		this->key = key;
		this->value = value;
	}
	bool operator==(Pair pair) {
		return key == pair.key && value == pair.value;
	}
	bool operator!=(Pair pair) {
		return key != pair.key || value != pair.value;
	}
	bool operator>(Pair pair) {
		return key > pair.key;
	}
	bool operator<(Pair pair) {
		return key < pair.key;
	}
	bool operator>=(Pair pair) {
		return key >= pair.key;
	}
	bool operator<=(Pair pair) {
		return key <= pair.key;
	}
	friend ostream& operator<<(ostream& out, const Pair& pair) {
		out << "key: ";
		out << pair.key;
		out << "; ";
		out << "value: ";
		out << pair.value;
		return out;
	}
};
