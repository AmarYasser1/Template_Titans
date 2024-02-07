#pragma once
#include<iostream>
#include<assert.h>
#include<algorithm>
#include<iterator>
using namespace std;

template<typename T>
class DynamicContainer {
	T* arr{ nullptr };
	size_t size{ };
	size_t capacity{ };
public:
	DynamicContainer(size_t capacity = 0);
	DynamicContainer(const DynamicContainer& other);
	~DynamicContainer();

	bool isFull();
	bool isEmpty();

	void resize();
	void resize(size_t newCapacity);
	void Shrink();

	int maxSize();
	int getSize();

	void insertEnd(const T& value);
	void insertFront(const T& value);
	void insertAt(size_t idx, const T& value);

	void remove(const T& value);
	void removeAt(int idx);

	T& findElement(size_t idx);
	int findIdx(const T& value);

	void sort();
	void sortDecreasing();

	void reverse();
	void print();
	void clear();

	struct Iterator {
		T* ptr;

		Iterator(T* ptr) : ptr(ptr) {}
		Iterator() : ptr(nullptr) {}

		T& operator*() const { return *ptr; }
		T* operator->() const { return ptr; }

		Iterator& operator ++ () { ptr++; return *this; }
		Iterator& operator -- () { ptr--; return *this; }
		Iterator& operator ++ (int) {
			Iterator temp = *this;
			++(*this);
			return temp;
		}
		Iterator& operator -- (int) {
			Iterator temp = *this;
			--(*this);
			return temp;
		}

		Iterator& operator += (int n) { ptr += n; return *this; }
		Iterator& operator -= (int n) { ptr -= n; return *this; }
		Iterator& operator + (int n) { ptr += n; return *this; }
		Iterator& operator - (int n) { ptr -= n; return *this; }

		friend bool operator == (const Iterator& it1, const Iterator& it2) { return it1.ptr == it2.ptr; }
		friend bool operator != (const Iterator& it1, const Iterator& it2) { return it1.ptr != it2.ptr; }
		friend bool operator < (const Iterator& it1, const Iterator& it2) { return it1.ptr < it2.ptr; }
		friend bool operator > (const Iterator& it1, const Iterator& it2) { return it1.ptr > it2.ptr; }
		friend bool operator <= (const Iterator& it1, const Iterator& it2) { return it1.ptr <= it2.ptr; }
		friend bool operator >= (const Iterator& it1, const Iterator& it2) { return it1.ptr >= it2.ptr; }
	};
	Iterator begin() { return Iterator(&arr[0]); }
	Iterator end() { return Iterator(&arr[size]); } // reference to invalid memory address
};

// To the linker find compelete template definition in the linking phase .
template<typename T>
DynamicContainer<T>::DynamicContainer(size_t capacity) : capacity(capacity), size(0), arr(new T[capacity]) {}
template<typename T>
DynamicContainer<T>::DynamicContainer(const DynamicContainer& other) : arr(new T[other.capacity]), capacity(other.capacity), size(other.size) {
	copy(other.arr, other.arr + other.size, arr);
}
template<typename T>
DynamicContainer<T>::~DynamicContainer() {
	delete[]arr;
	arr = nullptr;
}

template<typename T>
bool DynamicContainer<T>::isFull() { return size >= capacity; }
template<typename T>
bool DynamicContainer<T>::isEmpty() { return size <= 0; }

template<typename T>
void DynamicContainer<T>::resize() {
	int expand = 2 * capacity;
	capacity = max(2, expand);

	T* temp = new T[capacity];
	copy(arr, arr + size, temp);

	delete[]arr;
	arr = temp;
}
template<typename T>
void DynamicContainer<T>::resize(size_t newCapacity) {
	T* temp = new T[newCapacity];
	size = 0;
	for (auto i = 0; i < min(capacity, newCapacity); ++i)
		temp[i] = arr[i], ++size;

	delete[]arr;
	arr = temp;
	capacity = newCapacity;
}
template<typename T>
void DynamicContainer<T>::Shrink() {
	capacity /= 2;

	T* temp = new T[capacity];
	copy(arr, arr + size, temp);

	delete[] arr;
	arr = temp;
}

template<typename T>
int DynamicContainer<T>::maxSize() { return capacity; }
template<typename T>
int DynamicContainer<T>::getSize() { return size; }

template<typename T>
void DynamicContainer<T>::insertEnd(const T& value) {
	if (isFull())
		resize();

	arr[size++] = value;
}
template<typename T>
void DynamicContainer<T>::insertFront(const T& value) {
	if (isFull())
		resize();

	copy(arr, arr + size, arr + 1);

	arr[0] = value;
	++size;
}
template<typename T>
void DynamicContainer<T>::insertAt(size_t idx, const T& value) {
	assert(idx >= 0 && idx <= size);

	if (isFull())
		resize();

	copy(arr + idx, arr + size, arr + idx + 1);

	arr[idx] = value;
	++size;
}

template<typename T>
void DynamicContainer<T>::remove(const T& value) {
	assert(!isEmpty());

	int idx = -1;
	for (auto i = 0; i < size; ++i) {
		if (arr[i] == value) {
			idx = i;
			break;
		}
	}

	if (idx != -1) {
		copy(arr + idx + 1, arr + size, arr + idx);
		arr[size - 1] = 0, --size;
	}

	if (capacity > 2 * size)
		Shrink();
}
template<typename T>
void DynamicContainer<T>::removeAt(int idx) {
	assert(idx >= 0 && idx < size);
	assert(!isEmpty());

	copy(arr + idx + 1, arr + size, arr + idx);

	arr[size - 1] = 0;
	--size;

	if (capacity > 2 * size)
		Shrink();
}

template<typename T>
T& DynamicContainer<T>::findElement(size_t idx) {
	assert(idx >= 0 && idx < size);
	assert(!isEmpty());

	return arr[idx];
}
template<typename T>
int DynamicContainer<T>::findIdx(const T& value) {
	assert(!isEmpty());

	for (auto i = 0; i < size; ++i)
		if (value == arr[i])
			return i;

	return -1;
}

template<typename T>
void DynamicContainer<T>::sort() {
	// Selection sort
	for (auto i = 0; i < size; ++i) {
		T temp = arr[i];
		int idx = -1;

		for (auto j = i + 1; j < size; ++j)
			if (temp > arr[j])
				temp = arr[j], idx = j;

		if (idx != -1)
			swap(arr[i], arr[idx]);
	}
}
template<typename T>
void DynamicContainer<T>::sortDecreasing() {
	for (auto i = 0; i < size; ++i) {
		T temp = arr[i];
		int idx = -1;

		for (auto j = i + 1; j < size; ++j)
			if (temp < arr[j])
				temp = arr[j], idx = j;

		if (idx != -1)
			swap(arr[i], arr[idx]);
	}
}

template<typename T>
void DynamicContainer<T>::reverse() {
	for (size_t i = 0, sz = size - 1; i < sz; ++i, --sz)
		swap(arr[i], arr[sz]);
}

template<typename T>
void DynamicContainer<T>::print() {
	for (auto it = begin(); it != end(); ++it)
		cout << *it << ' ';
}

template<typename T>
void DynamicContainer<T>::clear() { size = capacity = 0; }