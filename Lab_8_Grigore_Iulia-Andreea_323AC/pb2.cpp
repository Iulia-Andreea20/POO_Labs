#include <iostream>
#include <string>
#define size 5

using namespace std;

template <class Type> class Stack
{
    private:
        int top;
        Type stack1[size];
    public:
        Stack();
        void push(Type x);
        Type pop();
        bool isFull();
        bool isEmpty();
        void show();
};

template <class Type> Stack<Type>::Stack() 
{ 
    top = -1; 
}
template <class Type> void Stack<Type>::push(Type x)
{

	if (isFull()) 
    {
		cout << "Stiva este plina\n";
	}

	cout << "Se insereaza elementul: " << x << endl;
	top++;

	stack1[top] = x;
}

template <class Type> bool Stack<Type>::isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

template <class Type> bool Stack<Type>::isFull()
{
	if (top == (size - 1))
		return 1;
	else

	return 0;
}
template <class Type> Type Stack<Type>::pop()
{
	Type popped_element = stack1[top];
	top--;

	return popped_element;
}

template <class Type> void Stack<Type>::show()
{
    int i;
    for(i = 0; i <= top; i++)
    {
        cout << stack1[i] << " ";
    }
    cout << "\n";
}
int main()
{
    Stack<int> integer_stack;
	Stack<string> string_stack;

    integer_stack.push(1);
	integer_stack.push(2);
	integer_stack.push(3);
    integer_stack.push(5);

    string_stack.push("Ana");
	string_stack.push("are");
	string_stack.push("mere");

    cout << "\n\nPentru int array:\nStiva initiala este: "; 
    integer_stack.show();
    cout << "\n";

    cout << "Se elimina elementul: " <<integer_stack.pop() << endl;
    cout << "Noua stiva este: "; 
    integer_stack.show();
    cout << "\n\n";

    cout << "Pentru string array:\nStiva initiala este: "; 
    string_stack.show();
    cout << "\n";

    cout << "Se elimina elementul: " <<string_stack.pop() << endl;
    cout << "Noua stiva este: "; 
    string_stack.show();
    return 0;
}