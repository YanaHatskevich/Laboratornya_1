#include "Header.cpp"
#include <iostream>


int main() {
	setlocale(LC_ALL, "RUS");
	// ������ �����
	{
		std::cout << "������ ��� 3 ����� �����\n";
		My_List<int> list;
		My_Ochered<int> queue;
		My_stack<int> stack;
		int a;
		int b;
		int c;
		std::cout << "������� 3 ����� �����: ";
		std::cin >> a >> b >> c;
		list.insert_new(a); //��������� ������� � ������ � ������� �����������
		list.insert_new(b);
		list.insert_new(c);
		std::cout << "������| ";
		list.ShowList();
		queue.ListToQueue(list);
		stack.ListToStack(list);
		std::cout << "�������| ";
		queue.Show();
		std::cout << "����| ";
		stack.Show();
	}
	// ��������� �����
	{
		std::cout << "������ ��� 3 �������\n";
		My_List<char> list;
		My_Ochered<char> queue;
		My_stack<char> stack;
		char a;
		char b;
		char c;
		std::cout << "������� 3 �������: ";
		std::cin >> a >> b >> c;
		list.insert_new(a);
		list.insert_new(b);
		list.insert_new(c);
		std::cout << "������| ";
		list.ShowList();
		queue.ListToQueue(list);
		stack.ListToStack(list);
		std::cout << "�������| ";
		queue.Show();
		std::cout << "����| ";
		stack.Show();
	}
	// ������ �����
	{
		My_List<int> list;
		My_Ochered<int> queue;
		My_stack<int> stack;
		std::string str;
		std::cout << "������� ������������������ ����� �����, ������� ������������� ������ 0: ";
		std::cin >> str;
		list.insert_row(str);
		std::cout << "������| ";
		list.ShowList();
		queue.ListToQueue(list);
		stack.ListToStack(list);
		std::cout << "�������| ";
		queue.Show();
		std::cout << "����| ";
		stack.Show();
		std::cout << "������ � �������� �������| ";
		list.ShowListReverse();
		std::cout << "������� � �������� �������| ";
		queue.ShowReverse();
		std::cout << "���� � �������� �������| ";
		stack.ShowReverse();
	}
	// ������� ����� 
	{
		My_List<int> list;
		std::string str;
		std::cout << "������� ������������������ ����� �����, ������� ������������� ������� 00: ";
		std::cin >> str;
		list.insert_row_custom(str);
		std::cout << "������| ";
		list.ShowList();
	}
}