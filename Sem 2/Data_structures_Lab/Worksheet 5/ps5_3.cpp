#include <iostream>
using namespace std;

int push(int &top1, int &top2, int element, int choice, int *stack, int size)
{
    if (choice == 1)
    {
        if (top1 == size - 1 || top2 - top1 == 1)
            cout << "Stack overflow\n";
        else
        {
            top1 = top1 + 1;
            stack[top1] = element;
            return 1;
        }
        return 0;
    }
    else if (choice == 2)
    {
        if (top2 == 0 || top2 - top1 == 1)
            cout << "Stack overflow\n";
        else
        {
            top2 = top2 - 1;
            stack[top2] = element;
            return 1;
        }
        return 0;
    }
}

int pop(int &top1, int &top2, int choice1, int *stack, int size)
{
    if (choice1 == 1)
    {
        if (top1 == -1)
            cout << "Stack underflow\n";
        else
        {
            top1 = top1 - 1;
            return 1;
        }
        return 0;
    }
    else if (choice1 == 2)
    {
        if (top2 == size)
            cout << "Stack underflow\n";
        else
        {
            top2 = top2 - 1;
            return 1;
        }
        return 0;
    }
}

int viewstack(int &top, int *stack, int choice, int size)
{
    if (choice == 1)
    {
        for (int i = 0; i < top; i++)
            cout << stack[i] << endl;
        return 0;
    }
    else if (choice == 2)
    {
        for (int i = size - 1; i >= top; i--)
            cout << stack[i] << endl;
        return 0;
    }
}

int main()
{
    int size;
    cout << "Enter the size of the stack\n";
    cin >> size;
    int *stack = new int[size];
    int top1 = -1, top2 = size;
    int choice, choice1, element;
label:
    cout << "1)Add an element\n2)Delete an element\n3)View the stack with highest elements\n4)View the stack with lowest elements\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "*stack (1)\n*stack(2)\nEnter the appropriate input\n";
        cin >> choice1;
        cout << "Enter the element\n";
        cin >> element;
        if (choice1 == 1)
        {
            if (!push(top1, top2, element, choice1, stack, size))
                goto label;
        }
        else if (choice1 == 2)
        {
            if (!push(top1, top2, element, choice1, stack, size))
                goto label;
        }
        break;
    case 2:
        cout << "*stack (1)\n*stack(2)\nEnter the appropriate input\n";
        cin >> choice1;
        if (choice1 == 1)
        {
            if (!pop(top1, top2, choice1, stack, size))
                goto label;
        }
        else if (choice1 == 2)
        {
            if (!pop(top1, top2, choice1, stack, size))
                goto label;
        }
        break;
    case 3:
        if (top1 > size - top2)
        {
            choice = 1;
            viewstack(top1, stack, choice, size);
        }
        else
        {
            choice = 2;
            viewstack(top2, stack, choice, size);
        }
        break;
    case 4:
        if (top1 < size - top2)
        {
            choice = 1;
            viewstack(top1, stack, choice, size);
        }
        else
        {
            choice = 2;
            viewstack(top2, stack, choice, size);
        }
        break;
    default:
        cout << "Invalid Input\n";
        goto label;
    }

    return 0;
}