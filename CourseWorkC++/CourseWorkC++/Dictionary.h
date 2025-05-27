#pragma once

#include <utility>

template <typename K, typename V>
struct Entry {
	K key;
	V value;
};

template <typename K, typename V>
class Dictionary {
public:
	Dictionary() : entries(nullptr), size(0), capacity(0) {};

	Dictionary(const Dictionary<K, V>& other)
		: entries(new Entry<K, V>[other.capacity]),
		size(other.size),
		capacity(other.capacity) {
		for (int i = 0; i < size; i++) {
			entries[i] = other.entries[i]
		}
	};

	~Dictionary() {
		delete[] entries;
	};

	void Add(const K& key, const V& value) {
		if (ContainsKey(key)) {
			Get(key) = value;
			return;
		}
		if (size >= capacity) {
			Resize();
		}
		entries[size].key = key;
		entries[size].value = value;
		++size;
	};
	bool Remove(const K& key) {
		int index = FindIndex(key);
		if (index == -1) {
			return false;
		}
		for (int i = index; i < size - 1; ++i) {
			entries[i] = entries[i + 1];
		}
		--size;
		return true;
	};
	V& Get(const K& key) {
		int index = FindIndex(key);
		if (index == -1) {
			return false;
		}
		return entries[index].value;
	};

	bool ContainsKey(const K& key) {
		return FindIndex(key) != -1;
	};
	int GetSize() {
		return size;
	};
	void Clear() {
		delete[] entries;
		entries = nullptr;
		size = 0;
		capacity = 0;
	};

	Dictionary<K, V>& operator=(const Dictionary<K, V>& other) {
		if (this != &other) {
			Clear();
			entries = new Entry<K, V>[other.capacity];
			size = other.size;
			capacity = other.capacity;

			for (int i = 0; i < size; ++i) {
				entries[i] = other.entries[i];
			}
		}
		return *this;
	};
private:
	Entry<K, V>* entries;
	int size;
	int capacity;
	void Resize() {
		int newCapacity = capacity == 0 ? 4 : capacity * 2;
		Entry<K, V>* newEntries = new Entry<K, V>[newCapacity];
		for (int i = 0; i < size; ++i) {
			newEntries[i] = entries[i];
		}
		delete[] entries;
		entries = newEntries;
		capacity = newCapacity;
	};
	int FindIndex(const K& key) {
		for (int i = 0; i < size; ++i) {
			if (entries[i].key == key) {
				return i;
			}

		}
		return -1;
	};
};
