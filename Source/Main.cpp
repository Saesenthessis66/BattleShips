
#include "..//Engine/Engine.hpp"
#include "..//Engine/TextFormatter.hpp"

std::unique_ptr<PromptSingleton> PromptSingleton::instancePtr = nullptr;

#include"List.hpp"

#include "../Engine/Texts.hpp"

int main()
{

	List<int> l;
	int x,y;
	x=2;y=3;

	l.pushBack(x);l.pushBack(x);
		l.popBack();
	std::cin>>x;
	// std::shared_ptr<int> x,y;
	// *x= 2;
	// *y= 2;

	// l.pushBack(x);
	// l.pushBack(y);

	// std::shared_ptr<ListElement<int>> e = l.getHead();
	// auto current = l.getHead();	
	// int s = l.Size();
	// for(int i =0;i<s;i++)
	// {
	// 	std::cout<<current->data<<std::endl;
	// 	if(current->next != nullptr)current = current->next;
	// }
	// for(int i = s; i>0;i--)
	// {
	// 	std::cout<<current->data<<std::endl;
	// 	current = current->previous;
	// }

    // Engine engine = Engine();

    // while(1)
    // {
    //     engine.run();
    // }

    return 0;
}
