
#include "..//Engine/Engine.hpp"
#include "..//Engine/TextFormatter.hpp"

std::unique_ptr<PromptSingleton> PromptSingleton::instancePtr = nullptr;

template <class T>
class ListElement
{
public:
	ListElement* Next;
	ListElement* Previous;
	T* Data;


	ListElement(T* value, ListElement* previous = nullptr, ListElement* next = nullptr)
		:Data(value), Previous(previous), Next(next) {}
};

template <class T>
class List
{
	ListElement<T>* Head;
	int size = 0;

public:
	List() :Head(nullptr) {}
	~List() { clear(); }

	ListElement<T>* getHead() { return Head; }

	void clear() {
		ListElement<T>* Current = Head;
		while (Current != nullptr)
		{
			ListElement<T>* temp = Current->Next;
			delete Current->Data;
			delete Current;
			Current = temp;
		}

		Head = nullptr;
	}
	void pushBack(T* value) {
		if (Head == nullptr)
		{
			Head = new ListElement<T>(value);
			size++;
		}
		else
		{
			ListElement<T>* Current = Head;
			while (Current->Next != nullptr)
			{
				Current = Current->Next;
			}

			ListElement<T>* Temp = new ListElement<T>(value, Current);
			Current->Next = Temp;
			size++;
		}
	}
	void popBack() {
		if (Head == nullptr)
		{
			throw ("Empty list cannot be poped");
		}

		if (Head->Next == nullptr)
		{
			delete Head;
			Head = nullptr;
			size--;
		}
		else
		{
			ListElement<T>* Current = Head;
			while (Current->Next != nullptr)
			{
				Current = Current->Next;
			}
			Current->Previous->Next = nullptr;
			delete Current;
			size--;
		}
	}
	int Size() { return size; };

};

#include "../Engine/Texts.hpp"

int main()
{
    Engine engine = Engine();

    while(1)
    {
        engine.run();
    }

    return 0;
}
