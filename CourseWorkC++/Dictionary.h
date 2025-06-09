#pragma once

#include <utility>
#include "List.h"

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
			entries[i] = other.entries[i];
		}
	};

	~Dictionary() {
		delete[] entries;
	};

	List<V> DictToList() {
		List<V> result;
		for (int i = 0; i < size; i++) {
			result.Add(entries[i].value);
		}
		return result;
	};

	List<V> DictToList() const{
		List<V> result;
		for (int i = 0; i < size; i++) {
			result.Add(entries[i].value);
		}
		return result;
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
	void Replace(const K& key, const V& value) {
		int index = FindIndex(key);
		if (index == -1) {
			return;
		}
		entries[index].value = value;

	};
	V& Get(const K& key) {
		int index = FindIndex(key);
		if (index == -1) {
			throw std::out_of_range("Index out of range");
		}
		return entries[index].value;
	};
	bool ContainsKey(const K& key) {
		return FindIndex(key) != -1;
	};
	bool ContainsValue(const V& value) {
		for (int i = 0; i < size; i++) {
			if (entries[i].value == value) {
				return true;
			}
		}
		return false;
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
		int limit = (size <= capacity) ? size : newCapacity;
		for (int i = 0; i < limit; ++i) {
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
