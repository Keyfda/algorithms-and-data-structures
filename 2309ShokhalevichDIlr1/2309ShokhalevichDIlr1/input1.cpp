#include "header.h"

void amlists(list*& head, list*& cur, list*& last, list* listss[], int& lists, list*& head2, int ElAmount1[])
{

    cout << "\n Type the amount of lists you want to test:    ";
    cin >> lists;
    int j = 1;
    int k = 1;
    list* c = new list;
    for (int i = 0; i < lists; i++)
    {
        input(head, cur, last, ElAmount1, j);

        listss[j] = head;
        j++;

    }
  
}




void input(list*& head, list*& cur, list*& last, int ElAmount1[], int& j)
{
    head = new list;

    cout << "\n\nType the amount of elements you want to add to the list(only natural numbers):    ";
    cin >> ElAmount1[j];
   
    if (ElAmount1[j] == 0 )
    {
        cout << "\n\nInvalid size! Only natural numbers! Try again.";
        input(head, cur, last, ElAmount1, j);
        return;
    }

    int el;

    if (ElAmount1[j] > 10)
        el = 1 + rand() % 9;
    else
      cin >> el;
    head->data = el;
    cur = head;
    head->prev = nullptr;

    for (int i = 1; i < ElAmount1[j]; i++)
    {
        if (ElAmount1[j] > 10)
           
            el = 1 + rand() % 9;
        else
            cin >> el;

            list* tmp = new list;

            cur->next = tmp;
            tmp->prev = cur;
            cur = tmp;
            cur->data = el;
        
    }
    last = cur;
    cur = head;
    
    cout << "\n\n\n";
}