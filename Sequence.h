#pragma once
using namespace std;
template <class T> class Sequence {
public:
    Sequence() {};
    Sequence(T* data, int length);
    Sequence(const Sequence& a);
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual int GetLength() = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;
    virtual void Resize(int newl) = 0;
    virtual void Set(int index, T value) = 0;
    virtual Sequence <T>* Concat(Sequence <T>* list) = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    ~Sequence() {};
    void ShakerSort() {
        //cout << 1;
        int i = 0;
        int j = GetLength() - 1;
        bool flag = 1;
        while (i < j&& flag != 0) {
            flag = 0;
            for (int a = i; a < j; a++) {
                if (Get(a) > Get(a + 1)) {
                    T temp = Get(a);
                    Set(a, Get(a + 1));
                    Set(a + 1, temp);
                    flag = 1;
                }

            }
            j--;
            for (int a = j; a > i; a--) {
                if (Get(a - 1) > Get(a)) {
                    T temp = Get(a);
                    Set(a, Get(a - 1));
                    Set(a - 1, temp);
                    flag = 1;
                }
            }
            i++;
            //cout << 2;
        }
    }
    void InsertionSort() {
        for (int i = 0; i < GetLength(); i++) {
            T min = Get(i);
            int jmin = i;
            for (int j = i; j < GetLength(); j++) {
                if (Get(j) < min) {
                    jmin = j;
                    min = Get(j);
                }
            }
            Set(jmin, Get(i));
            Set(i, min);
        }
    }
    void SelectionSort() {
        for (int i = 0; i < GetLength(); i++) {
            T a = Get(i);
            int mini = i;
            for (int j = i; j < GetLength(); j++) {
                if (a > Get(j)) {
                    a = Get(j);
                    mini = j;
                }
            }

            Set(mini, Get(i));
            Set(i, a);
        }

    }
    void ShakerSort(bool (*cmp)(T, T)) {
        //cout << 1;
        int i = 0;
        int j = GetLength() - 1;
        bool flag = 1;
        while (i < j&& flag != 0) {
            flag = 0;
            for (int a = i; a < j; a++) {
                if (cmp(Get(a), Get(a + 1))) {
                    T temp = Get(a);
                    Set(a, Get(a + 1));
                    Set(a + 1, temp);
                    flag = 1;
                }

            }
            j--;
            for (int a = j; a > i; a--) {
                if (cmp(Get(a - 1), Get(a))) {
                    T temp = Get(a);
                    Set(a, Get(a - 1));
                    Set(a - 1, temp);
                    flag = 1;
                }
            }
            i++;
            //cout << 2;
        }
    }
    void InsertionSort(bool (*cmp)(T, T)) {
        for (int i = 1; i < GetLength(); i++) {
            T min = Get(i);
            int jmin = i - 1;
            while (jmin >= 0 && cmp(min,Get(jmin))) {
                
                Set(jmin + 1, Get(jmin));
                Set(jmin, min);
                jmin--;
            }
        }
        
    }
    void SelectionSort(bool (*cmp)(T, T)) {
        for (int i = 0; i < GetLength(); i++) {
            T a = Get(i);
            int mini = i;
            for (int j = i; j < GetLength(); j++) {
                if (cmp(a, Get(j))) {
                    a = Get(j);
                    mini = j;
                }
            }

            Set(mini, Get(i));
            Set(i, a);
        }

    }
};
