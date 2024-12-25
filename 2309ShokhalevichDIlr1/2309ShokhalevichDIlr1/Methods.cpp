#include "header.h"

void AnotherList(list*& head2)
{
    int ElAmount2;   
    list* cur = new list; 
    cout  << "\n\nType the amount of elements you want to add to the list(only natural numbers):    ";
    cin >> ElAmount2; 

    if (ElAmount2 == 0) 
    {
        cout << "\n\nInvalid size! Only natural numbers! Try again.";
        AnotherList(head2);
        return;
    }

    int el;
    cout << "\nEnter your list here:  ";

    if (ElAmount2 > 10)
        el = 1 + rand() % 9;
    else
        cin >> el; 
    head2->data = el;
    cur = head2;
    head2->prev = nullptr;

    for (int i = 1; i < ElAmount2; i++)
    {
        if (ElAmount2 > 10)

            el = 1 + rand() % 9;
        else
            cin >> el;

        list* tmp = new list;

        cur->next = tmp;
        tmp->prev = cur;
        cur = tmp;
        cur->data = el;

    }

     cur = head2;
}

//1
void AddEnd(list*& head, list*& last, int el) 
{
    int ElAmount;
  
    auto start = chrono::high_resolution_clock::now();

    list* curnew = new list;  
   
    list*  cur = head;
    if (cur == nullptr)       
    {
        cout << "The list is empty.\n";
        return;
    }
    
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }

    last = cur;
    curnew = last;
   
  
        
    list* tmp = new list;       
    curnew->next = tmp;         
    curnew = tmp;               
    curnew->data = el;          
    
    last = curnew;
    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
  
	
}

//2
void AddBeg(list*& head, list*& cur, list*& last, int el)
{
    int ElAmount;
  
    auto start = chrono::high_resolution_clock::now();
    list* lastcur = new list;
    

    if (head == nullptr)
    {
        cout << "The list is empty\n";        
        return;
    }

    list* headnew = new list; 
    list* curnew = new list;  
 
   list* curr = head;             
 
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    last = curr;
  
    curr = head;
    


   
 
    headnew->data = el;
    headnew->next = curr;     

    head = headnew;       
    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
}

//3
void DeleteLast(list*& head, list*& last) 
{
    list* cur = head;
    auto start = chrono::high_resolution_clock::now();
    while (cur->next != nullptr)
    {    
        cur = cur->next;
    }

   cur = cur->prev;
 
  list* tmp = cur->next;
    delete tmp;             
    cur->next = nullptr;
    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
    
}

//4
void DeleteFirst(list*& head)
{
    list* cur = head;              
    auto start = chrono::high_resolution_clock::now();

    cur = head;                   
    head = head->next;            
    delete cur;    

    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
}

//5
void AddByIndex(list*& head, int index, int el)
{

    list* cur = head;           

    if (cur == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

   

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < index-1; i++)                      
    {
        cur = cur->next;
        if (cur == nullptr)                                 
        {
            cout << "There's no element with this index";
            return;
        }
    }

    list* tmpprev = new list;              
    list* tmp = new list;                  
    list* tmpnext = new list;               
    


    tmpprev = cur->prev;                    
    tmpnext = cur;                         
    tmpnext = cur;
    


    if (tmpprev == nullptr)
    {
        head = tmp;
        cur->prev = tmp;
        tmp->next = cur;
        tmp->data = el;
    }
    else                                   
    {
         tmpprev->next = tmp;              
         tmp->data = el;                    
         tmp->next = tmpnext;              
    }

    if (tmpnext == nullptr) cur = tmp;     

    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
 }

//6
void GetByIndex(list*& head, int index)
{
    list* cur = head;                  

    if (head == nullptr)
    {
        cout << "The list is empty";
            return;
    }

    

    auto start = chrono::high_resolution_clock::now();

    for (int i = 1; i < index; i++)           
    {
        cur = cur->next;
        if (cur == nullptr)                    
        {
            cout << "There's no element with this index";
            return;
        }
    }
    cout << cur->data;              

    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
}

//7
void DeleteByIndex(list*& head, int index)
{
 
    list* cur = head;                              

    if (cur == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < index-1; i++)      
    {
        
        cur = cur->next;
        if (cur == nullptr )               
        {
            cout << "There's no element with this index";
            return;
        }
    }
 
    list* tmp = new list;          
    if (index == 1)
    {
        cur = head;
        head = head->next;           
        delete cur;

    }
    else
    {
       
        tmp = cur;
        cur->prev->next = cur->next;
        delete tmp;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
}

//8
void GetSize(list*& head)
{
    list* cur = head;                                     
    auto start = chrono::high_resolution_clock::now();

    if (cur == nullptr)                 
    {
        cout << "The list is empty.\n";
        return;
    }

    int size = 1;
    while (cur->next != nullptr)         
    {
        size++;
        cur = cur->next;
    }

   /* cout << "Size of this list is " << size;   */

    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
}

//9
void DeleteList(list*& head, list*& cur, list*& last)
{
    cur = head;      
    list* prv = new list; 
    int count = 0;

    while (cur != nullptr)
    {
        count++;
        cur = cur->next;
    }
    
    cur = head;

    cout << "\n\n";
   
    cout << "List before deleting: ";
    if (count <= 10)
    {
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }
    else
        for (int i = 0; i < 10; i++)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }

    cout << endl;
    if( count >10)
    cout << "Only 10 first elements were printed because the list is too big!";
    cout << endl;

    auto start = chrono::high_resolution_clock::now();

    cout << "List after deleting:  ";

    cur = head;
    int ccount = 0;
 
        while (cur != nullptr)
        {
            prv = cur;
            cur = cur->next;
            delete prv;
            prv = nullptr;
            head = prv;
            ccount++;
            if(ccount <=10)
            cout << prv <<  " ";
        }
        cout << endl;
        if(ccount >10)
           
        cout << "Only 10 first elements were printed because the list is too big!";
   
    cout << "\n";

    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
}

//10
void ReplaceByIndex(list*& head, int index, int newel)
{   
    list* cur = head;                                 

    if (cur == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

  
    auto start = chrono::high_resolution_clock::now();

    for (int i = 1; i < index; i++)
    {
        cur = cur->next;
        if (cur == nullptr)
        {
            cout << "There's no element with this index";
            return;
        }
    }
    
    cur->data = newel;
    cout << cur->data;

    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
}

//11
void IsEmpty(list*& head)
{
    auto start = chrono::high_resolution_clock::now();

    //if (head == nullptr)
    //    cout << "The list is empty.";
    //else cout << "The list is not empty.";

    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
}

//12
void Reverse(list*& head, list*& last)
{
    list* cur, *next, *prev = nullptr;
    cur = head;

    if (cur == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }
    auto start = chrono::high_resolution_clock::now();
 
    list* lastt = head;

    while (lastt)           
        lastt = lastt->next;
    list* tmpLast = head;   

    while (cur != lastt)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    tmpLast = lastt;         
   
    head = prev;

    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
}

//13
void AddListByIndex(list*& head, list*& head2 , int& index)
{
    list* tmp = new list;
    list* cur = head;                           

    if (cur == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

  

    for (int i = 0; i < index - 1; i++)
    {
        cur = cur->next;
        if (cur == nullptr)
        {
            cout << "There's no element with this index";
            return;
        }
    }
    AnotherList(head2);
    list* cur2 = head2;

    list* tmpprev = new list;
    list* tmpnext = new list;
    list* tmpprev2 = new list;
    auto start = chrono::high_resolution_clock::now();

    tmpprev = cur->prev;
    tmpnext = cur;
  
    if (tmpprev == nullptr)
    {
       
        tmp = cur2;
        head = tmp;
        tmp = tmp->next;
  
        tmpprev = head;
        cout << tmpprev->data;
    }
    else
    {
        tmp = cur2;              
        tmp->next = cur2->next;
        
        cout << cur2->data << " ";
    }

    cur2 = cur2->next;
    tmpprev->next = tmp;
    
    while (cur2 != nullptr)
    {
        tmp = cur2;
        tmp->next = cur2->next;
        cur2 = cur2->next;
    }

    if (cur2 == nullptr)
        tmp->next = tmpnext;

    cur = tmp;
    if (tmpnext == nullptr) cur = tmp;
 
    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
}

//14
void AddListEnd(list*& head, list*& head2)
{
    list* tmp, * tmp1 = new list;
    list* cur = head;                            

   
    if (cur == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    auto start = chrono::high_resolution_clock::now();
    while (cur->next != nullptr) {
        cur = cur->next;
    }

    tmp = cur;
    
    cur->next = head2;
    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";


}

//15
void AddListBeg(list*& head, list*& head2, list*& last)
{
     AnotherList(head2);
 
     auto start = chrono::high_resolution_clock::now();
    list* newtail = new list;
    list* tmp = new list;
    list* cur = head2;                         
    list* cur1 = head;

    while (cur1->next != nullptr)
    {
        cur1 = cur1->next;
    }
    last = cur1;

    if (head == nullptr)
    {
        cout << "The first list is empty.\n";
        return;
    }
   
    newtail = head;

    while (cur->next != nullptr)
    {
        cur = cur->next;
        cur->prev = tmp;
        tmp->next = cur;
    }

    tmp = cur;
    cur->next = newtail;
    head = head2;
    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
      
}

//16
void CheckIsIn(list*& head, list*& head2)
{
    list* cur1 = head;                       
    list* cur2 = head2;                           
     
    if (cur1 == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }
    auto start = chrono::high_resolution_clock::now();
    int i = 0;
    while (cur2 != nullptr)
    {
        i++;
        cur2 = cur2->next;
    }

    int check = 0;
    cur1 = head;
    cur2 = head2;

    bool k = false;
    int c = 0;
    int first;
    while (cur1 != nullptr && cur2 != nullptr)
    {
        c++;

        if (cur1->data == cur2->data)
        {
            check++;
            cur2 = cur2->next;
        }
        else
        {
            check = 0;
            cur2 = head2;
        }

        cur1 = cur1->next;
        if (check == i)
        {
            k = true;
            break;
        }

    }

    if (k)
        cout << "YES";
    else
        cout << "NO";
    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
}

//17
void FindIndexStart(list*& head, list*& head2)
{
    list* cur1 = head;                               
    list* cur2 = head2;                            

    if (cur1 == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }
    auto start = chrono::high_resolution_clock::now();
    int i = 0;
    while (cur2 != nullptr)
    {
        i++;
        cur2 = cur2->next;
    }

    int check = 0;
    cur1 = head;
    cur2 = head2;
    bool k = false;
    int c = 0;
    int first;
    while (cur1 != nullptr && cur2 != nullptr)
    {
        c++;
       
        if (cur1->data == cur2->data)
        {  
                    
            check++;
            cur2 = cur2->next;
        }
        else
        {
            check = 0;
            cur2 = head2;
        }
  
        cur1 = cur1->next;
        if (check == i)
        {
            k = true;
            first = c;
            break;
        }
        
    }

   if (k)
        cout << "Index of the first entry is   " << first - i + 1;
    else
       cout << "there's no other lists in current";
   auto end = chrono::high_resolution_clock::now();
   chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
   cout.precision(10);
   cout << fixed << duration.count() << ", ";
}

//18
void FindIndexEnd(list*& head,list*& head2)
{
  
    AnotherList(head2);
  
    list* cur1 = head;              
    list* cur2 = head2;               

    if (cur1 == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    auto start = chrono::high_resolution_clock::now();
    int i = 0;
    while (cur2 != nullptr)
    {
        
        i++;
        cur2 = cur2->next;
    }
 
    int check = 0;
    cur1 = head;
    cur2 = head2;
    int p = 0;
    int c = 0;
    int first = 0;
    int k = 0;

    while (cur1 != nullptr && cur2 != nullptr)
    {
        c++;
        check = 0;
      
        if (cur1->data == cur2->data)
        {
            check++;

            while ((cur1->data == cur2->data) && (cur1->next != nullptr) && (cur2->next != nullptr))
            {
                check++;
                cout << check;

                k++;
                cur1 = cur1->next;
                cur2 = cur2->next;

                c++;

                if (cur1->data != cur2->data)
                {
                    cur2 = head2;
                    check = 1;
                }
            }
            if (check == i)
                first = c - i + 1;

            k = 0;

            cur2 = head2;
            cur1 = cur1->next;
        }

    }

    cur1 = head;

    if (first!=0)
    {
        cout << "Index of the last entry:   " << first;
    }
    else
        if (first != 0)
        {
            cout << "Index of the last entry:   " << first;
        }
        else
        {
            cout << "There's no other list in current.";
        }  

    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";
}


void Swap(list*& head, int x, int y)
{
    list* prevX = NULL;
    list* curX = head;
    list* prevY = NULL;
    list* curY = head;

    auto start = chrono::high_resolution_clock::now();

    for (int i = 1; i < x; i++)
    {
        curX = curX->next;
        if (curX == nullptr)
        {
            cout << "There's no element with this index";

            return;
        }
    }

    for (int i = 1; i < y; i++)
    {
        curY = curY->next;
        if (curY == nullptr)
        {
            cout << "There's no element with this index";
            return;
        }
    }

    curX = head;
    curY = head;
    if (x == y)
    {
        cout << "\nYou entered same indeces! ";
        return;
    }

    int i = 1;

    while (i != x) 
    {
        i++;
        prevX = curX;
        curX = curX->next;
    }

    int j = 1;

    while (j != y) 
    {
        j++;
        prevY = curY;
        curY = curY->next;
    }

 
    if (curX == NULL || curY == NULL)
        return;

   
    if (prevX != NULL)
        prevX->next = curY;
    else 
        head = curY;

   
    if (prevY != NULL)
        prevY->next = curX;
    else 
        head = curX;

  
    list* tmp = curY->next;
    curY->next = curX->next;
    curX->next = tmp;

    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << ", ";


}

void Swap1(list*& head)
{
    system("cls");

    list* tmp1 = head;              
    list* tmp2 = head;
    list* c = new list;

    list* cur = new list;
    cur = head;
    list* cur1 = head;
   list*  cur2 = head;

    list* newnext1 = new list;
    list* newnext2 = new list;

   
    list* newhead = new list;

    int index1;
    int index2;
    cout << "Enter first index:    ";
    cin >> index1;

    cout << "Enter second index:    ";
    cin >> index2;
    
   

   list*  newnextnext1 = new list;
    list* newnextnext2 = new list;
    
    for (int i = 0; i < index1-1; i++)
    {
        cur1 = cur1->next;
        cur = cur->next;
    }

    newnextnext2 = cur1->next;
    tmp1 = cur1;
    cur->prev->next = tmp1;
    newnext1 = cur->prev->next;
    
    cur = head;

    for (int i = 0; i < index2 - 1; i++)
    {
        cur2 = cur2->next;
        cur = cur->next;
    }
    newnextnext1 = cur2->next;
    cur->prev->next = tmp2;
    tmp2 = cur2;
   
    newnext2 = cur->prev->next;


    cur = head;

    for (int i = 0; i < index1 - 1; i++)
    {
        cur = cur->next;
    }
    cout << 0000 << cur->prev->data << 0000;

    cur->prev->next = newnext2;
    cur = tmp2;
    cur->next = newnextnext1;

    cur = head;

    for (int i = 0; i < index2 - 1; i++)
    {
        cur = cur->next;
    }

    cur->prev->next = newnext1;
    cur = tmp1; 
    cur->next = newnextnext1;
  
}


