#ifndef LIST_HPP
#define LIST_HPP

#include <memory>

template <typename T>
struct ListElement {
    T data; 
    std::shared_ptr<ListElement<T>> next; 
	std::shared_ptr<ListElement<T>> previous; 

    ListElement(T value, std::shared_ptr<ListElement> _previous = nullptr, 
				std::shared_ptr<ListElement> _next = nullptr) : data(value),  previous(_previous), next(_next) {}
};

template <class T>
class List
{
	std::shared_ptr<ListElement<T>> _head;
	int _size = 0;

public:
	List() :_head(nullptr) {}

	std::shared_ptr<ListElement<T>> getHead() { return _head; }

    int Size() { return _size; };

	void pushBack(T value) {
		if (_head == nullptr)
		{
			auto list_element = std::make_shared<ListElement<T>>(value);
			_head = list_element;
			_size++;
		}
		else
		{
			auto current = _head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			auto list_element = std::make_shared<ListElement<T>>(value,current);
			current->next = list_element;
			_size++;
		}
	}
	void popBack() {
		if (_head == nullptr)
		{
			throw ("Empty list cannot be poped");
		}

		if (_head->next == nullptr)
		{
			_head.reset();
			_size--;
		}
		else
		{
			auto current = _head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->previous->next = nullptr;
			current.reset();
			_size--;
		}
	}


};

#endif