#include <iostream>
using namespace std;

int pop(int &top)
{
    if (top == -1)
        cout << "Stack Underflow\n";
    else
        top = top - 1;
    return top;
}

int push(char *output, int size, int &top, char c)
{
    if (top = size - 1)
        cout << "Stack overflow\n";
    else
    {
        top++;
        output[top] = c;
    }
    return top;
}

int read(char *input, char *output)
{
    int l=0;
    while(input[l]!='\0')
    l++;
    int top = -1;
    for (int i = 0; i < l; i++)
    {
        if (input[i] == '#' && top > 0)
            top = pop(top);
        else if (top >= 0 && input[i] > 'A' && input[i] < 'Z')
            top = push(output, 50, top, input[i]);
        else
            cout << "Invalid number of #(erase functions)\n";
    }
    cout << "The elements in the stack are : ";
    for (int i = 0; i <= top; i++)
        cout << output[i];
    return 0;
}

int main()
{
    char *input = new char[50];
    char *output = new char[50];
    cout << "Enter a string with only # as a special character to erase the previous letter\n";
    cin >> input;
    read(input, output);
    return 0;
}