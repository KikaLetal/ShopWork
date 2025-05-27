#pragma once

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

	bool Remove(int index) {
		if (index < 0 || index >= size) {
			return false;
		}

		for (int i = 0; i < size; ++i) {
			data[i] = data[i + 1];
		}
		--size;
		return true;
	};

	T& Get(int index) {
		if (index < 0 || index >= size) {
			return false;
		}
		return data[index];
	};

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

	List<T>& operator=(const List<T>& other) {
		if (this != &other) {
			delete[] data;
			size = other.size;
			capacity = other.capacity;
			data = new T[capacity];
			for (int i = 0; i < size; ++i) {
				data[i] = other.data[i];
			}
		}
		return *this;
	};

private:
	T* data;
	int size;
	int capacity;

	void Resize() {
		capacity = capacity == 0 ? 4 : capacity * 2;
		T* newData = new T[capacity];
		for (int i = 0; i < size; ++i) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	};
};

