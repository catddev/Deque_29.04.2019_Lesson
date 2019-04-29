#pragma once
#include<iostream>
#include<string>
using namespace std;

//Реализуйте класс Double queue
// учесть что заполненные ячейки расположены ориентировочно по центру стека


template<typename T>
class Deque {
private:
	T* ptr;
	int begin;
	int end;
	int buf_size;
public:
	Deque();
	Deque(int buf_size);
	Deque(const Deque<T>& obj);
	~Deque();

	void push_front(T el);
	void push_back(T el);
	void pop_front();
	void pop_back();
	int size();
	T& back();
	T& front();
	bool empty();
	void print();
	Deque<T> operator=(const Deque<T>& obj);
};

template<typename T>
inline Deque<T>::Deque()
{
	ptr = 0;
	begin = 0;
	end = 0;
	buf_size = 0;
}

template<typename T>
inline Deque<T>::Deque(int buf_size)
{
	this->buf_size = buf_size;
	begin = 0;
	end = 0;
	ptr = new T[buf_size];
}

template<typename T>
inline Deque<T>::Deque(const Deque<T>& obj)
{
	buf_size = obj.buf_size;
	begin = obj.begin;
	end = obj.end;
	ptr = new T[buf_size];
	for (int i = begin; i <= end; i++)
		ptr[i] = obj.ptr[i];
}

template<typename T>
inline Deque<T>::~Deque()
{
	delete[] ptr;
}

template<typename T>
inline void Deque<T>::push_front(T el)
{
	if (buf_size == 0) {
		buf_size = 10;
		ptr = new T[buf_size];
		begin = buf_size / 2 + 1;
		end = buf_size / 2;
	}
	else if (begin == 0) {
		if (buf_size >= (end - begin) * 2) {
			T* tmp = new T[buf_size];
			begin = (buf_size-(end - begin + 1)) / 2;
			end = (buf_size + (end - begin + 1)) / 2;

			for (int i = begin; i <= end; i++)
				tmp[i] = ptr[i];
			delete[] ptr;
			ptr = tmp;
		}
	}
	else if (buf_size < (end - begin)) {
		buf_size *= 2;
		T* tmp = new T[buf_size];
		begin = (buf_size - (end - begin + 1)) / 2;
		end = (buf_size + (end - begin + 1)) / 2;

		for (int i = begin; i <= end; i++)
			tmp[i] = ptr[i];

		delete[] ptr;
		ptr = tmp;
	}
	ptr[--begin] = el;
}

template<typename T>
inline void Deque<T>::push_back(T el)
{
	if (buf_size == 0) {
		buf_size = 10;
		ptr = new T[buf_size];
		begin = buf_size / 2;
		end = begin-1;
	}
	else if (end == buf_size - 1) {
		if (buf_size >= (end - begin) * 2) {
			T* tmp = new T[buf_size];
			
			begin = (buf_size - (end - begin + 1)) / 2;
			end = (buf_size + (end - begin + 1)) / 2;

			for (int i = begin; i <= end; i++)
				tmp[i] = ptr[i];
			delete[] ptr;
			ptr = tmp;
		}
	}
	else if (buf_size < (end - begin)) {
		buf_size *= 2;
		T* tmp = new T[buf_size];
		begin = (buf_size - (end - begin + 1)) / 2;
		end = (buf_size + (end - begin + 1)) / 2;

		for (int i = begin; i <= end; i++)
			tmp[i] = ptr[i];

		delete[] ptr;
		ptr = tmp;
	}
	ptr[++end] = el;
}

template<typename T>
inline void Deque<T>::pop_front()
{
	begin++;
}

template<typename T>
inline void Deque<T>::pop_back()
{
	end--;
}

template<typename T>
inline int Deque<T>::size()
{
	return (end - begin + 1);
}

template<typename T>
inline T & Deque<T>::back()
{
	return ptr[end];
}

template<typename T>
inline T & Deque<T>::front()
{
	return ptr[begin];
}

template<typename T>
inline bool Deque<T>::empty()
{
	//return (end - begin == 0);//нельзя потому что, если end==begin значит в els[end] есть элемент, он не пустой
	return(size() == 0);
}

template<typename T>
inline void Deque<T>::print()
{
	for (int i = begin; i <= end; i++)
		cout << ptr[i] << endl;
	cout << endl;
}

template<typename T>
inline Deque<T> Deque<T>::operator=(const Deque<T>& obj)
{
	buf_size = obj.buf_size;
	begin = obj.begin;
	end = obj.end;
	ptr = new T[buf_size];
	for (int i = begin; i <= end; i++)
		ptr[i] = obj.ptr[i];

	return *this;
}