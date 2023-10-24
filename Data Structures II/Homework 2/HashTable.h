#pragma once

#include <iostream>
#include <string>
#include <cmath>
using namespace std;



template <typename T, typename K>
class HashTable
{
protected:

	enum state { empty, full, deleted };
	template <typename U, typename V>
	class Item
	{
	public:
		U data;
		V key;
		state flag;
		Item() {}
		Item(U d, V  k, state f) { data = d; key = k; flag = f; }
	};


	int size;
	Item<T, K>* arr;
	//bool prime(int n);
	int hash(K key, int i);
	virtual int h1(K key) = 0;
	virtual int h2(K key) = 0;
public:
	HashTable(int m = 10); // ctor
	~HashTable();
	void add(K& key, T& dat);
	int remove(K key);
	int search(K key);
	bool update(K key, T dat); // should we input an Item<T,K> instead?
	T* entryData(K i)
	{
		int ind = search(i);
		if (ind == -1)
			return NULL;
		else
			return &(arr[ind].data);
	}
	void print();
};

template<typename T, typename K>
inline int HashTable<T, K>::hash(K key, int i)
{
    // this is the hash function
	double hashed = (h1(key) + i * h2(key)) % size;
	return hashed;
}

template<typename T, typename K>
inline HashTable<T, K>::HashTable(int m)
{
    // increase by 1
	int num = m + 1;
	bool flag = false;

	while (true)
	{
		int squareRoot = sqrt(num);
		for (int i = 2; i <= squareRoot; i++)
		{
			if (num % i == 0) {
				flag = true;
				break;
			}
		}
		if (flag == true) break;
		num++;
	}

	arr = new Item<T, K>[num]; // Allocate memory for the array

	for (int i = 0; i < num; i++)
	{
		arr[i].flag = empty; // Initialize the flag member to empty
	}

	size = num;
}


template<typename T, typename K>
inline HashTable<T, K>::~HashTable()
{
	delete[] arr;
    arr = nullptr;
    delete arr;
}

template<typename T, typename K>
inline void HashTable<T, K>::add(K& key, T& dat)
{
	int hashVal;
	for (int i = 0; i < size; i++)
	{
		hashVal = hash(key, i); // perform the hash function with step i
		if (arr[hashVal].flag == empty)
		{
		    // enter the new values for the hash value
			arr[hashVal].key = key;
			arr[hashVal].data = dat;
			arr[hashVal].flag = full;
			return;
		}
	}
	cout << "ERROR" << endl;
}

template<typename T, typename K>
inline int HashTable<T, K>::remove(K key)
{
	int hashVal = search(key);
	if (hashVal != -1)
	{
		arr[hashVal].flag = deleted;
		arr[hashVal].data.clear();
		arr[hashVal].key = "";
	}
	return 0;
}

template<typename T, typename K>
inline int HashTable<T, K>::search(K key)
{
	int hashVal;
	for (int i = 0; i < size; i++)
	{
		hashVal = hash(key, i); // perform the hash function with step i
		if (arr[hashVal].key == key)
		{
			return hashVal;
		}
	}
	return -1;
}

template<typename T, typename K>
inline bool HashTable<T, K>::update(K key, T dat)
{
	int hashVal = search(key);
	if (hashVal == -1)
	{
	    return false;
	}
	if (hashVal != -1)
	{
		arr[hashVal].data = dat;
		return true;
	}
}

template<typename T, typename K>
inline void HashTable<T, K>::print()
{
	for (int i = 0; i < size; i++)
	{
	    // if there is a value in that apot
		if (arr[i].flag == full)
		{
			cout << arr[i].key << ": ";
			for (list<string>:: iterator it = arr[i].data.begin(); it != arr[i].data.end(); it++)
			{
				cout << *it << " ";
			}
			cout << endl;
		}
	}
}
