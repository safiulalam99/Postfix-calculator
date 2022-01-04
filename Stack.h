#include "Utility.h"
typedef double Stack_entry;
const int maxstack = 10;   //  small value for testing

class Stack {
public:
	Stack();
	bool empty() const;
	Error_code pop();
	Error_code top(Stack_entry& item) const;
	Error_code push(const Stack_entry& item);
	Error_code pop_top(Stack& s, Stack_entry& t);
	void printall();
	void clear(Stack& s);
	int size(Stack& s);
	void introduction();
	void instructions();
private:
	int count;
	Stack_entry entry[maxstack];
};

Error_code copy_stack(Stack& dest, Stack& source);