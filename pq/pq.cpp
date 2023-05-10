#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    int priority;
    int data;
    struct node *next;
};

class PriorityQueue
{
private:
    node *head;

public:
    PriorityQueue()
    {
        head = NULL;
    }
    void enqueue(int data, int priority)
    {
        node *temp, *p;
        temp = new node;
        temp->data = data;
        temp->priority = priority;
        if (head == NULL || head->priority > priority)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL && p->next->priority <= priority)
            {
                p = p->next;
            }
            temp->next = p->next;
            p->next = temp;
        }
    }

    void dequeue()
    {
        node *temp;
        if (head == NULL)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        temp = head;
        head = head->next;
        delete temp;
    }

    void show()
    {
        node *p = head;
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue is :\n";
        cout << "Priority\tData\n";
        while (p != NULL)
        {
            cout << p->priority << "\t\t" << p->data << endl;
            p = p->next;
        }
    }

    int top()
    {
        return (head->data);
    }
};

int main()
{
    int choice, data, priority;
    PriorityQueue pq;
    do
    {
        cout << "--------------------";
        cout << "1.Enqueue\n";
        cout << "2.Dequeue\n";
        cout << "3.Show Top\n";
        cout << "4.Show Queue\n";
        cout << "5.Exit\n";
        cout << "--------------------";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to be enqueueed : ";
            cin >> data;
            cout << "Enter priority : ";
            cin >> priority;
            pq.enqueue(data, priority);
            break;
        case 2:
            pq.dequeue();
            break;
        case 3:
            cout << "Top Element : " << pq.top() << endl;
            break;
        case 4:
            pq.show();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Wrong Choice\n";
        }
    } while (choice != 5);
    return 0;
}
