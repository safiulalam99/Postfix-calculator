#include "stack.h"
#include <iostream>



Error_code Stack::pop_top(Stack& s, Stack_entry& t)
{

    if (!s.empty()) {

        std::cout << s.top(t);
        s.pop();
        
    }
    return success;
}
void Stack::clear(Stack& s) {
    double k;
    while (!s.empty()) {
        s.pop();
    }
    std::cout << s.top(k);
}


int Stack::size(Stack& s) {

    while (!s.empty()) {
        
        count++;
          
    }
    std::cout << "size is: " << count;
    return count;
}

Error_code copy_stack(Stack& dest, Stack& source) {
    dest = source;
    Stack st1;
    while (!source.empty()) {
        double k;
        source.top(k);
        st1.push(k);
        source.pop();
    }
    while (!st1.empty()) {
        double k;
        st1.top(k);
        source.push(k);
        dest.push(k);
        st1.pop();
    }
    return success;
}

Error_code Stack::push(const Stack_entry& item)
/*
Pre:  None.
Post: If the Stack is not full, item is added to the top
      of the Stack.  If the Stack is full,
      an Error_code of overflow is returned and the Stack is left unchanged.
*/

{
    Error_code outcome = success;
    if (count >= maxstack)
        outcome = overflow;
    else
        entry[count++] = item;
    return outcome;
}


Error_code Stack::pop()
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is removed.  If the Stack
      is empty, an Error_code of underflow is returned.
*/

{
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else --count;
    return outcome;
}


Error_code Stack::top(Stack_entry& item) const
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is returned in item.  If the Stack
      is empty an Error_code of underflow is returned.
*/

{
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else
        item = entry[count - 1];
    return outcome;
}


bool Stack::empty() const
/*
Pre:  None.
Post: If the Stack is empty, true is returned.
      Otherwise false is returned.
*/

{
    bool outcome = true;
    if (count > 0) outcome = false;
    return outcome;
}


Stack::Stack()
/*
Pre:  None.
Post: The stack is initialized to be empty.
*/
{
    count = 0;
}

void Stack::printall() {

    for (int i = 0; i < count; i++) {
        std::cout << entry[i] << " " << std::endl;
    }
    std::cout << std::endl;
}