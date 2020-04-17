#include <bits/stdc++.h>
using namespace std;

template <class temp>
class Stack
{
    int size_, top_;
    temp *stack;

public:
    Stack();
    Stack(temp[], int, int);
    int push(temp);
    temp pop();
    int length;
    int get_max();
    void allocate_size(int);
    void displayFromTop();
    void displayFromBottom();
    ~Stack();
};

template <class temp>
Stack<temp>::Stack()
{
    size_ = 0;
    top_ = -1;
    length = 0;
    stack = new temp[0];
}

template <class temp>
Stack<temp>::Stack(temp arr[], int size, int max)
{
    if (max == 0)
        size_ = max;
    size_ = max;
    stack = new temp[size_];
    top_ = -1;
    length = size;
    for (int i = 0; i < size; i++)
        push(arr[i]);
}

template <class temp>
int Stack<temp>::push(temp data)
{
    if (top_ + 1 == size_)
    {
        cout << "Stack Overflow !!\n";
        return 0;
    }
    else
    {
        length += 1;
        top_ += 1;
        stack[top_] = data;
        return 1;
    }
}

template <class temp>
Stack<temp>::~Stack()
{
    delete[] stack;
}

template <class temp>
temp Stack<temp>::pop()
{
    if (top_ == -1)
    {
        cout << "Stack Underflow !!\n";
        return -1;
    }
    else
    {
        length- = 1;
        top_ -= 1;
        return stack[top_ + 1];
    }
}

template <class temp>
int Stack<temp>::get_max()
{
    return size_;
}

template <class temp>
void Stack<temp>::allocate_size(int size)
{
    delete[] stack;
    size_ = size;
    length = 0;
    stack = new temp[size_];
    top_ = -1;
}

template <class temp>
void Stack<temp>::displayFromBottom()
{
    if (top_ == -1)
    {
        cout << "No data\n";
        return;
    }
    Stack<temp> temp_stack;
    temp_stack.allocate_size(size_);
    while (top_ != -1)
    {
        temp_stack.push(pop());
    }
    while (temp_stack.top_ != -1)
    {
        temp element = temp_stack.pop();
        cout << element << endl;
        push(element);
    }
}

template <class temp>
void Stack<temp>::displayFromTop()
{
    if (top_ == -1)
    {
        cout << "No data/n";
        return;
    }
    Stack<temp> temp_stack;
    temp_stack.allocate_size(size_);
    while (top_ != -1)
    {
        int element = pop();
        cout << element << endl;
        temp_stack.push(element);
    }
    while (temp_stack.top_ != -1)
    {
        push(temp_stack.pop());
    }
}

int main()
{
    //for integer type stack
    Stack<int> s;
    int size, choice, data;
    cout << "Enter the max size of Stack : ";
    cin >> size;
    s.allocate_size(size);
    while (size > 0)
    {
        cout << "\nStack Operations\n"
             << "1.Push" << endl
             << "2.Pop" << endl
             << "3.Count" << endl
             << "4.Display from bottom" << endl
             << "5.Display from top" << endl
             << "Exit" << endl
             << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element : ";
            cin >> data;
            s.push(data);
            break;
        case 2:
            try
            {
                cout << "The element is " << s.pop();
            }
            catch (const std::exception &e)
            {
                cout << e.what() << '\n';
            }
            break;
        case 3:
            cout << "The count is " << s.length;
            break;
        case 4:
            s.displayFromBottom();
            break;
        case 5:
            s.displayFromTop();
            break;
        default:
            size = -1;
        }
    }
    return 0;
}