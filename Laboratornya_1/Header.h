#pragma once
#include <string>

template <class T>
class List {
protected:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head = NULL;

public:
	virtual bool isEmpty(); // эта запись означает что дикларируется функция, у функций нет никаких параметров , возвращаемое значение типа bool 
	void ChangeElement(Node*, T); // изменить значение элемента
	void DeleteElement(T); // удалить элемент списка
	Node* FindValueByData(T); // найти элемент по информационной части
	bool FindValueByPtr(Node*);
	virtual void ShowLikeString();
	void push_head(T);
	void push_back(T);
	void ShowList();
	void ShowListReverse();
	T getfirst();
	T getlast();
};



template <class T>
class My_List : public List<T> {
public:
	My_List() : List<T>() {};
	My_List(const My_List<T>& other);
	void insert_new(T data);
	void insert_row(std::string str);
	void insert_row_custom(std::string str);
};



template <class T>
class My_Ochered : public List<T> {
public:
	bool isEmpty() override;
	void ShowLikeString() override;
	void push(T data);
	void pop();
	void Show();
	void ShowReverse();
	T get();
	void ListToQueue(My_List<T> list);
};



template<class T>
class My_stack : public List<T> {
public:
	bool isEmpty() override;
	void ShowLikeString() override;
	void push(T data);
	void pop();
	void Show();
	void ShowReverse();
	T get();
	void ListToStack(My_List<T> list);
};
