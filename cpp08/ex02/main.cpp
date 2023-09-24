#include "MutantStack.hpp"

// int main()
// {
// 	MutantStack<int> mstack;

// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(42);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Stack elements using my iterator:" << std::endl;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\ndoes it equals ite : " << ((it == ite) ? "true" : "false") << std::endl;

    std::cout << "this is the top element of the stack: " << mstack.top() << std::endl;

    // Pop the top element
    mstack.pop();

    // Check the size of the stack
    std::cout << "and this is the ize of the stack after popping: " << mstack.size() << std::endl;

    return 0;
}


