#include "Header.h"
#include <iostream>
#include <set>

using namespace std;

template <typename T>
void List<T>::push_head(T data)
{
	Node* temp = new Node;
	temp->data = data;
	if (isEmpty() == false) {
		temp->next = head;
		head = temp;
	}
	else {
		temp->next = NULL;
		head = temp;
	}
}

template <typename T>
void List<T>::push_back(T data)
{
	Node* temp = new Node;
	if (head == NULL) {
		head = new Node();
		head->next = NULL;
		head->data = data;
	}
	else {
		Node* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = new Node;
		temp->next->next = NULL;
		temp->next->data = data;
	}
}

template <typename T>
void List<T>::ShowList()
{
	Node* temp = head;
	if (isEmpty()) cout << "out: <пусто>" << endl;
	else {
		cout << "out: [";
		cout << temp->data;
		while (temp->next != NULL) {
			temp = temp->next;
			cout << ", " << temp->data;
		}
		cout << "]";
		cout << endl;
	}
}

template <typename T>
void List<T>::ShowListReverse() {
	std::cout << "[ ";
	while (!this->isEmpty()) {
		T data = this->getlast();
		this->DeleteElement(data);
		std::cout << data << " ";
	}
	std::cout << "]" << std::endl;
}


template <typename T>
bool List<T>::isEmpty()
{
	if (head == NULL) {
		return true;
	}
	return false;
}

template <typename T>
void List<T>::ChangeElement(Node* temp, T data)
{
	temp->data = data;
}

template <typename T>
typename List<T>::Node* List<T>::FindValueByData(T data)
{
	Node* temp = head;
	while (temp != NULL) {
		if (temp->data == data) {
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

template <typename T>
void List<T>::ShowLikeString()
{
	Node* temp = head;
	if (head == nullptr) {
		cout << "out: <пусто>" << endl;
	}
	else {
		cout << temp->data;
		while (temp->next != NULL) {
			temp = temp->next;
			cout << temp->data;
		}
	}
}

template <typename T>
void List<T>::DeleteElement(T data)
{
	Node* temp = FindValueByData(data);
	Node* save = head;
	if (!isEmpty() && temp != NULL) {
		if (temp == head) {
			Node* temp = head;
			temp = temp->next;
			delete head;
			head = temp;
		}
		else {
			while (save->next != temp) {
				save = save->next;
			}
			save->next = temp->next;
			delete temp;
		}
	}
}

template <typename T>
bool List<T>::FindValueByPtr(Node* temp)
{
	if (temp == NULL) {
		return false;
	}
	return true;
}

template <typename T>
T List<T>::getfirst()
{
	if (!isEmpty()) {
		return head->data;
	}
}

template <typename T>
T List<T>::getlast()
{
	if (!isEmpty()) {
		Node* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		return temp->data;
	}
}



template<class T>
My_List<T>::My_List(const My_List<T>& other)
{
	typename List<T>::Node* temp = other.head;
	while (temp != nullptr) {
		this->push_back(temp->data);
		temp = temp->next;
	}
}

template <typename T>
void My_List<T>::insert_new(T data) {
	typename List<T>::Node* new_node = new typename List<T>::Node;
	new_node->data = data;
	new_node->next = nullptr;
	if (this->head == nullptr) {
		// Если список пустой, просто добавляем новый элемент в начало
		this->head = new_node;
	}
	else if (data < this->head->data) {
		// Если новый элемент меньше текущего head, делаем его новым head
		new_node->next = this->head;
		this->head = new_node;
	}
	else {
		// Иначе ищем место для вставки
		typename List<T>::Node* temp = this->head;
		while (temp->next != nullptr && temp->next->data < data) {
			temp = temp->next;
		}
		new_node->next = temp->next;
		temp->next = new_node;
	}
}

template <typename T>
void My_List<T>::insert_row(std::string str) {
	std::string type = typeid(T).name();
	if (type == "int") {
		while (!str.empty()) {
			if (str[0] == '0') {
				break;
			}
			insert_new(str[0] - 48);
			str.erase(str.begin());
		}
	}
	else {
		while (!str.empty()) {
			if (str[0] == '#') {
				break;
			}
			insert_new(str[0]);
			str.erase(str.begin());
		}
	}
}

template<class T>
void My_List<T>::insert_row_custom(std::string str)
{
	str = str.substr(0, str.find("00"));
	std::set<char> charSet(str.begin(), str.end());
	std::string temp(charSet.begin(), charSet.end());
	temp += "0";
	insert_row(temp);
}




template <typename T>
bool My_Ochered<T>::isEmpty() {
	if (this->head == NULL) {
		return true;
	}
	return false;
}

template<class T>
void My_Ochered<T>::ShowLikeString()
{
	typename List<T>::Node* temp = this->head;
	if (this->head == nullptr) {
		cout << "out: <пусто>" << endl;
	}
	else {
		cout << temp->data;
		while (temp->next != NULL) {
			temp = temp->next;
			cout << temp->data;
		}
	}
}

template<class T>
void My_Ochered<T>::push(T data)
{
	this->push_back(data);
}

template<class T>
void My_Ochered<T>::pop()
{
	if (!isEmpty()) {
		typename List<T>::Node* temp = this->head;
		temp = temp->next;
		delete this->head;
		this->head = temp;
	}
}

template<class T>
void My_Ochered<T>::Show()
{
	this->ShowList();
}

template<class T>
void My_Ochered<T>::ShowReverse()
{
	this->ShowListReverse();
}

template<class T>
T My_Ochered<T>::get()
{
	if (!isEmpty()) {
		return this->head->data;
	}
}

template <class T>
void My_Ochered<T>::ListToQueue(My_List<T> list) {
	while (!list.isEmpty()) {
		T data = list.getfirst();
		list.DeleteElement(data);
		this->push(data);
	}
}




template<class T>
bool My_stack<T>::isEmpty()
{
	if (this->head == NULL) {
		return true;
	}
	return false;
}

template<class T>
void My_stack<T>::ShowLikeString()
{
	typename List<T>::Node* temp = this->head;
	if (this->head == nullptr) {
		cout << "out: <пусто>" << endl;
	}
	else {
		cout << temp->data;
		while (temp->next != NULL) {
			temp = temp->next;
			cout << temp->data;
		}
	}
}

template<class T>
void My_stack<T>::push(T data)
{
	this->push_head(data);
}

template<class T>
void My_stack<T>::pop()
{
	if (!isEmpty()) {
		typename List<T>::Node* temp = this->head;
		if (this->head->next == NULL) {
			if (!isEmpty()) {
				typename List<T>::Node* temp = this->head;
				temp = temp->next;
				delete this->head;
				this->head = temp;
			}
		}
		else {
			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			temp->next = NULL;
		}
	}
}

template<class T>
void My_stack<T>::Show()
{
	this->ShowList();
}

template<class T>
void My_stack<T>::ShowReverse()
{
	this->ShowListReverse();
}

template<class T>
T My_stack<T>::get()
{
	if (!isEmpty()) {
		typename List<T>::Node* temp = this->head;
		while (temp->next) {
			temp = temp->next;
		}
		return temp->data;
	}
}

template<class T>
void My_stack<T>::ListToStack(My_List<T> list)
{
	while (!list.isEmpty()) {
		T data = list.getfirst();
		list.DeleteElement(data);
		this->push(data);
	}
}