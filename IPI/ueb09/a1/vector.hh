#ifndef VECTOR
#define VECTOR

#include <initializer_list>
#include <iostream>

template <class T> class Vector {
public:
	typedef T MemberType;
	typedef T* Iterator;


	Iterator begin () const {
        return p[0];
    }

	Iterator end () const {
        return p[n];
    }


	Vector(int c) : c(c), n(0) {
        p = new T[c];
    }

	Vector() : c(0), n(0) {
        p = new T[0];
    }

	Vector(std::initializer_list<T> init) {
        for (int i = 0; i < init.size(); ++i) {
            push_back(init);
        }
    }

	Vector (const Vector<T>&);

	Vector<T>& operator= (const Vector<T>& v) {
        empty();

        for (int* it = v.begin(); it != v.end(); ++it) {
            push_back(it);
        }

        return *this;
    };

	~Vector();

	int size () const {
        return n;
    }

	int capacity () const {
        return c;
    }

	bool empty() const {
        return n == 0;
    }

	T& operator[](int i);
	T& front() {
        if (n < 1)
            return nullptr;

        return p[0];
    }

	T& back() {
        if (n < 1)
            return nullptr;

        return p[n - 1];
    }

	Iterator insert(Iterator it, const T& t);
	Iterator erase(Iterator it);

	void push_back(const T& t) {
        if (c == n) {
            c *= 2;
        }

        p[n++] = t;
    }

	void pop_back() {
        p[n - 1] = nullptr;

        --n;
    }

private:
	int c;
	int n;
	T *p;
};

template <class T>
std::ostream& operator<< (std::ostream& s, Vector<T>& a) {
}

#endif
