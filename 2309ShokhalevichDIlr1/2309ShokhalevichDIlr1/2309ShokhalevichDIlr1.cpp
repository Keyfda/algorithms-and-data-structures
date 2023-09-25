#include "header.h"

int main()
{
      
    list* head = new list, * cur = nullptr, * last = nullptr;
    list* head2 = new list;

    cout << "Hello!\n";
    input(head, cur, last);
    ConsoleMenu(head, cur, last, head2); 
}
