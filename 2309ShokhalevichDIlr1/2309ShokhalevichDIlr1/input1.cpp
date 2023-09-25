#include "header.h"

void input(list*& head, list*& cur, list*& last)
{
    int ElAmount1;        //количество элементов списка

    head = new list;

    cout << "\n\nType the amount of elements you want to add to the list(only natural numbers):    ";
    cin >> ElAmount1;

    if (ElAmount1 == 0)
    {
        cout << "\n\nInvalid size! Only natural numbers! Try again.";
        input(head, cur, last);
        return;
    }

    int el;
    cout << "\nEnter your list here:  "; 

    cin >> el; // вводить через пробел, после ввода нажать enter(считываются первые %ElAmount% элементов)5
    head->data = el;
    cur = head;
    head->prev = nullptr;

    for (int i = 1; i < ElAmount1; i++)
    {
        std::cin >> el;
        list* tmp = new list;
        
        cur->next = tmp;
        tmp->prev = cur;
        cur = tmp;
        cur->data = el;
    }
    last = cur;
    cur = head;
    

    cout << "\nYour list: ";
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n\n\n";
}