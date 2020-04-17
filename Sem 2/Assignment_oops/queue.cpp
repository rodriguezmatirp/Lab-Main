#include <bits/stdc++.h>
using namespace std;

template <class temp>
class Queue
{
    int front_, rear_, size_;
    temp *queue_;

public:
    Queue();
    Queue(temp[], int, int);
    ~Queue();
    void allocate_size(int);
    int length_;
    void display();
    temp dequeue();
    int enqueue(temp);
    int get_max();
};

template <class temp>
Queue<temp>::Queue()
{
    size_ = 0;
    front_ = 0;
    rear_ = 0;
    length_ = 0;
    queue_ = new temp[0];
}

template <class temp>
Queue<temp>::Queue(temp arr[], int size, int max)
{
    if (max == 0)
        size_ = max;
    queue_ = new temp[max];
    size_ = max;
    front_ = -1;
    rear_ = -1;
    length_ = size;
    for (int i = 0; i < size; i++)
        enqueue(arr[i]);
}

template <class temp>
Queue<temp>::~Queue()
{
    delete[] queue_;
}

template <class temp>
void Queue<temp>::allocate_size(int size)
{
    delete[] queue_;
    size_ = size;
    length_ = 0;
    queue_ = new temp[size_];
    front_ = -1;
    rear_ = -1;
}

template <class temp>
temp Queue<temp>::dequeue()
{
    if (front_ == rear_)
    {
        cout << "Data underflow!!\n";
        return -1;
    }
    length_ -= 1;
    front_ += 1;
    return queue_[front_];
}

template <class temp>
int Queue<temp>::enqueue(temp data)
{
    if (rear_ + 1 == size_)
    {
        cout << "Data overflow!\n";
        return 0;
    }
    length_ += 1;
    rear_ += 1;
    queue_[rear_] = data;
    return 1;
}

template <class temp>
void Queue<temp>::display()
{
    for (int i = front_ + 1; i <= rear_; i++)
        cout << queue_[i] << "\n";
}

template <class temp>
int Queue<temp>::get_max()
{
    return size_;
}

int main()
{
    //for a integer type Queue
    Queue<int> q;
    int size, choice, data;
    cout << "Enter the max size of Stack : ";
    cin >> size;
    q.allocate_size(size);
    while (size > 0)
    {
        cout << "/nQueue Operations\n"
             << "1.Push\n"
             << "2.Pop\n"
             << "3.Count\n"
             << "4.Display\n"
             << "Exit\n"
             << "Enter your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element : ";
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            try
            {
                cout << "The element is " << q.dequeue();
            }
            catch (const std::exception &e)
            {
                cout << e.what() << '\n';
            }
            break;
        case 3:
            cout << "The count is " << q.length_;
            break;
        case 4:
            q.display();
            break;
        default:
            size = -1;
        }
    }
    return 0;
}