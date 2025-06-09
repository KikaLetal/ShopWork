#pragma once
#include <stdexcept>

template <typename T>
class List {
public:
	List() : data(nullptr), size(0), capacity(0) {};

	List(const List<T>& other) : data(new T[other.capacity]), size(other.size), capacity(other.capacity) {
		for (int i = 0; i < size; ++i) {
			data[i] = other.data[i];
		}
	};

	~List() {
		delete[] data;
	};

	void Add(const T& element) {
		if (size >= capacity) {
			Resize();
		}
		data[size++] = element;
	};

	void Replace(int index, const T& element) {
		data[index] = element;
	};

	bool Remove(int index) {
		if (index < 0 || index >= size) {
			return false;
		}

		for (int i = 0; i < size - 1; ++i) {
			data[i] = data[i + 1];
		}
		--size;
		return true;
	};

	T& Get(int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	};

	const T& Get(int index) const {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}

	int GetSize() const {
		return size;
	};

	void Clear() {
		delete[] data;
		data = nullptr;
		size = 0;
		capacity = 0;
	};

	int FindIndex(const T& element) {
		for (int i = 0; i < size; ++i) {
			if (data[i] == element) {
				return i;
			}
		}
		return -1;
	};

	bool ContainsValue(const T& element) {
		for (int i = 0; i < size; ++i) {
			if (data[i] == element) {
				return true;
			}
		}
		return false;
	};

	void swap(List<T>& other) noexcept {
		std::swap(data, other.data);
		std::swap(size, other.size);
		std::swap(capacity, other.capacity);
	}

	List<T>& operator=(List<T> other) { // передача по значению Ч копи€
		swap(other);
		return *this;
	}

private:
	T* data;
	int size;
	int capacity;

	void Resize() {
		capacity = capacity == 0 ? 4 : capacity * 2;
		T* newData = new T[capacity];
		if (data != nullptr) {
			for (int i = 0; i < size; ++i) {
				newData[i] = data[i];
			}
		}
		delete[] data;
		data = newData;
	};
};

