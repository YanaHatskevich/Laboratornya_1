#include "Header.cpp"
#include <iostream>


int main() {
	setlocale(LC_ALL, "RUS");
	// третий пункт
	{
		std::cout << "Задача про 3 целых числа\n";
		My_List<int> list;
		My_Ochered<int> queue;
		My_stack<int> stack;
		int a;
		int b;
		int c;
		std::cout << "Введите 3 целых числа: ";
		std::cin >> a >> b >> c;
		list.insert_new(a); //вставляет элемент в список в порядке возрастания
		list.insert_new(b);
		list.insert_new(c);
		std::cout << "Список| ";
		list.ShowList();
		queue.ListToQueue(list);
		stack.ListToStack(list);
		std::cout << "Очередь| ";
		queue.Show();
		std::cout << "Стек| ";
		stack.Show();
	}
	// четвертый пункт
	{
		std::cout << "Задача про 3 символа\n";
		My_List<char> list;
		My_Ochered<char> queue;
		My_stack<char> stack;
		char a;
		char b;
		char c;
		std::cout << "Введите 3 символа: ";
		std::cin >> a >> b >> c;
		list.insert_new(a);
		list.insert_new(b);
		list.insert_new(c);
		std::cout << "Список| ";
		list.ShowList();
		queue.ListToQueue(list);
		stack.ListToStack(list);
		std::cout << "Очередь| ";
		queue.Show();
		std::cout << "Стек| ";
		stack.Show();
	}
	// шестой пункт
	{
		My_List<int> list;
		My_Ochered<int> queue;
		My_stack<int> stack;
		std::string str;
		std::cout << "Введите последовательность целых чисел, которая заканчивается числом 0: ";
		std::cin >> str;
		list.insert_row(str);
		std::cout << "Список| ";
		list.ShowList();
		queue.ListToQueue(list);
		stack.ListToStack(list);
		std::cout << "Очередь| ";
		queue.Show();
		std::cout << "Стек| ";
		stack.Show();
		std::cout << "Список в обратном порядке| ";
		list.ShowListReverse();
		std::cout << "Очреедь в обратном порядке| ";
		queue.ShowReverse();
		std::cout << "Стек в обратном порядке| ";
		stack.ShowReverse();
	}
	// седьмой пункт 
	{
		My_List<int> list;
		std::string str;
		std::cout << "Введите последовательность целых чисел, которая заканчивается числами 00: ";
		std::cin >> str;
		list.insert_row_custom(str);
		std::cout << "Список| ";
		list.ShowList();
	}
}