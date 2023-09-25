#include "header.h"

void AnotherList(list*& head2)
{
    int ElAmount1;        //количество элементов списка
    list* cur = new list; // выделяем память
    cout  << "\n\nType the amount of elements you want to add to the list(only natural numbers):    ";
    cin >> ElAmount1; 

    if (ElAmount1 == 0) 
    {
        cout << "\n\nInvalid size! Only natural numbers! Try again.";
        AnotherList(head2);
        return;
    }

    int el;
    cout << "\nEnter your list here:  ";

    cin >> el;
    head2->data = el;
    cur = head2;
    head2->prev = nullptr;

    for (int i = 1; i < ElAmount1; i++)
    {
        std::cin >> el;
        list* tmp = new list;
        cur->next = tmp;
        tmp->prev = cur;
        cur = tmp;
        cur->data = el;
    }
   

     cur = head2;
}

//1
void AddEnd(list*& cur, list*& last) 
{
    system("cls");  //очистка консольного меню, встречается во всех функциях

    list* curnew = new list;	//выделение памяти
	curnew = last;              //передаем в новый тело значение хвоста

    if (cur == nullptr)         //проверка на пустоту списка, в случае пустого возвращает в меню выбора действия, встречается почти в каждой функции
    {
        cout << "The list is empty.\n";
        return;                 
    }
    int ElAmount;              
    int el;
    cout << "Type the amount of elements you want to add to the list(only natural numbers):    "; //ввод кол-ва символов для вставки
    cin >> ElAmount;

    cout << "\nEnter your elements here:  ";

    for (int i = 0; i < ElAmount; i++)     
    {
        cin >> el;
        list* tmp = new list;       //выделение памяти под новый элемент списка
        curnew->next = tmp;         //выделение следующему элементу памяти
        curnew = tmp;               //выделяем элементу память
        curnew->data = el;          //присваиваем новому элементу списка передаваемое значение
    }
    cur = curnew;
    last = cur;
	
}

//2
void AddBeg(list*& head, list*& cur, list*& last)
{
    system("cls");

    if (head == nullptr)
    {
        cout << "The list is empty\n";        
        return;
    }

    list* headnew = new list; //выделение памяти для нового элемента
    list* curnew = new list;  //выделение памяти для нового элемента
    curnew->next = head;      //устанавливаем указатель на следующий элемент, то есть на старую голову списка
    cur = head;               //присваиваем значение головы к телу списка
    head = curnew;            //присваиваем голове значение нового эелемента
   

    int ElAmount;
    int el;
    cout << "Type the amount of elements you want to add to the list(only natural numbers):    ";
    cin >> ElAmount;

    cout << "\nEnter your elements here:  "; 

    cin >> el;
    curnew->data = el;        //заполняем новый элемент
    headnew = curnew;         //присваиваем новой голове значение нового элемента
    curnew->next = cur;       //устанавливаем указатель с нового элемента на бывшую голову
   

    for (int i = 1; i < ElAmount; i++)    
    {
        cin >> el;
        list* tmp = new list;
        curnew->next = tmp;
        curnew = tmp;
        curnew->data = el;
    }

    head = headnew;
    curnew->next = cur;
}

//3
void DeleteLast(list*& cur, list*& last) 
{
    system("cls");

    while (cur->next != last)
        cur = cur->next;
    last = cur;
    delete cur->next;
    cur->next = nullptr;
}

//4
void DeleteFirst(list*& head)
{
    system("cls");
    list* cur = head;

    cur = head;    
    head = head->next;   
    delete cur;
}

//5
void AddByIndex(list*& head)
{

    system("cls");
    list* cur = head;
    if (cur == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    int index;
    cin >> index;

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
    

    int el;
    cin >> el; 

    tmpprev = cur->prev;
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
 }

//6
void GetByIndex(list*& head)
{
   
    system("cls");
    list* cur = head;

    if (head == nullptr)
    {
        cout << "The list is empty";
            return;
    }

    int index;
    cin >> index;
    
    

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
}

//7
void DeleteByIndex(list*& head)
{
    system("cls");
    list* cur = head;

    if (cur == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    int index;
    cin >> index;

    for (int i = 1; i < index-1; i++)
    {
        cur = cur->next;
        if (cur == nullptr)
        {
            cout << "There's no element with this index";
            return;
        }
    }
 
    list* tmp = new list;
    tmp = cur->next;           
    cur->next = tmp->next;   
    delete tmp;
}

//8
void GetSize(list*& head)
{

    system("cls");
    list* cur = head;


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

    cout << "Size of this list is " << size;
}

//9
void DeleteList(list*& head, list*& cur, list*& last)
{

    system("cls");

    cur = head;

    list* prv = new list;

    cout << "\n\n";
   
    cout << "List before deleting: ";
    while (cur != nullptr)
    {       
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

    cout << "List after deleting:  ";

    cur = head;

    while (cur != nullptr)
    {
        prv = cur;
        cur = cur->next;
        delete prv;
        prv = nullptr;
        head = prv;

        cout << prv << " ";
    }
    cout << "\n";
}

//10
void ReplaceByIndex(list*& head)
{
    system("cls");
    list* cur = head;

    if (cur == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    int index;
    cin >> index;

    for (int i = 1; i < index; i++)
    {
        cur = cur->next;
        if (cur == nullptr)
        {
            cout << "There's no element with this index";
            return;
        }
    }
    int newel;
    cin >> newel;
    cur->data = newel;
    cout << cur->data;
}

//11
void IsEmpty(list*& head)
{
    system("cls");

    if (head == nullptr)
        cout << "The list is empty.";
    else cout << "The list is not empty.";
}

//12
void Reverse(list*& head, list*& last)
{
    system("cls");

    list* cur, *next, *prev = nullptr;
    cur = head;

    if (cur == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }
 
    list* lastt = head;

    while (lastt)             // ищем последний элемент
        lastt = lastt->next;
    list* tmpLast = head;   // этот узел станет предпоследним в преобразованном списке

    while (cur != lastt)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    tmpLast = lastt;          // за предпоследним узлом следует последний
   
    head = prev;
}

//13
void AddListByIndex(list*& head, list*& head2)
{
    system("cls");

    AnotherList(head2);

    list* tmp = new list;
    list* cur = head;
    list* cur2 = head2;

    if (cur == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    int index;
    cin >> index;

    for (int i = 0; i < index - 1; i++)
    {
        cur = cur->next;
        if (cur == nullptr)
        {
            cout << "There's no element with this index";
            return;
        }
    }

    list* tmpprev = new list;
    list* tmpnext = new list;
    list* tmpprev2 = new list;
   

    tmpprev = cur->prev;
    tmpnext = cur;
  
    if (tmpprev == nullptr)
    {
        head = tmp;
        tmp = cur2;
        cur->prev = tmp;
        tmpprev = head;
    }
    else
    {

        //указатель с предыдущего элемента основного списка на следующий, уже из второго списка, элемент
    //указатель на следующий элемент
        tmp = cur2;              //присваиваем новому элементу значение головы второго списка
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


}

//14
void AddListEnd(list*& head, list*& head2)
{
    system("cls");

    AnotherList(head2);

    list* tmp, * tmp1 = new list;
    list* cur = head;

    if (cur == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }
    cout << head2->data;

    while (cur->next != nullptr) {
        cur = cur->next;
    }

    tmp = cur;
    cur->next = head2;

}

//15
void AddListBeg(list*& head, list*& head2)
{
    system("cls");

    AnotherList(head2);
    
    list* check = head;
 
    list* newtail = new list;
    list* tmp = new list;
    list* cur = head2;

    if (check == nullptr)
    {
        cout << "The first list is empty.\n";
        return;
    }
   
    newtail = head;

    while (cur->next != nullptr) {
        cur = cur->next;
        head = tmp;
        cur->prev = tmp;
        tmp->next = cur;
    }

    tmp = cur;
    cur->next = newtail;
    head = head2;
      
}

//16
void CheckIsIn(list*& head, list*& head2)
{
    system("cls");

    AnotherList(head2);

    list* cur1 = head;
    list* cur2 = head2;
    
    if (cur1 == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    int i = 0;
    while (cur2 != nullptr)
    {
        i++;
        cur2 = cur2->next;
    }

    int check = 0;
    cur1 = head;
    cur2 = head2;


    while (cur1 != nullptr && cur2 != nullptr)
    {
       
        if (cur1->data == cur2->data)
        {
            check++;
            cur2 = cur2->next;
        }
        else 
            cur2 = head2;

        cur1 = cur1->next;       
    }

    if (i == check)
        cout << "YES";
    else
        cout << "NO";
}

//17
void FindIndexStart(list*& head, list*& head2)
{
    system("cls");

    AnotherList(head2);

    list* cur1 = head;
    list* cur2 = head2;

    if (cur1 == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    int i = 0;
    while (cur2 != nullptr)
    {
        i++;
        cur2 = cur2->next;
    }

    int check = 0;
    cur1 = head;
    cur2 = head2;

    int c = 0;
    int first;
    while (cur1 != nullptr && cur2 != nullptr)
    {
        c++;
       
        if (cur1->data == cur2->data)
        {  
            first = c;
           
            check++;
            cur2 = cur2->next;
        }
        else 
            cur2 = head2;
  
        cur1 = cur1->next;
        
    }

    if (i == check)
        cout << "Index of the first entry is   " << first - i + 1;
    else
        cout << "there's no other lists in current";
}

//18
void FindIndexEnd(list*& head,list*& head2)
{
    system("cls");

    AnotherList(head2);

    list* cur1 = head;
    list* cur2 = head2;

    if (cur1 == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    int i = 0;
    while (cur2 != nullptr)
    {
        i++;
        cur2 = cur2->next;
    }

    int check = 0;
    cur1 = head;
    cur2 = head2;
 
    int c = 0;
    int first;
    while (cur1 != nullptr && cur2 != nullptr)
    {
        c++;
       
        if (cur1->data == cur2->data)
        {
            first = c;

            check++;
            if (c >=  i)
            {
               
                cur2 = head2;
            } else
            cur2 = cur2->next;
        }
        else {
           
          
            cur2 = head2;
         
            
        }
        cur1 = cur1->next;
       
    }
    

    if (i < check)
    {
        cout << "Index of the last entry:   " << first;
    }else
    if (i == check)
    {
        cout << "Index of the last entry:   " << first - i + 1;
    }
    else
    {
        cout << "There's no other list in current.";
    }
}


//19                    //не сделана
void Swap(list*& head)
{
    system("cls");

    list* tmp1 = head;
    list* tmp2 = head;
    list* c = new list;

    list* cur = new list;
    cur = head;

    list* newhead = new list;
    
    int index1;
    int index2;
    cout << "Enter first index:    ";
    cin >> index1;

    cout << "Enter second index:    ";
    cin >> index2;
    
    
    for (int i = 0; i < index1-1; i++)
    {
        tmp1 = tmp1->next;
    }
   // tmp1 = cur;

  //  cur = head;
    for (int i = 0; i < index2-1; i++)
    {
        tmp2 = tmp2->next;
    }
  //  tmp2 = cur;


    c = tmp1;
    tmp1 = tmp2;
    tmp2 = c;

    cout << tmp1->data << " " << tmp2->data;
   // cur = head;

    for (int i = 0; i < index1-1; i++)
    {
        cur = cur->next;
    }

    list* t = new list;
    t = cur->next;
     cur->prev->next = tmp1;
    // t = t->next;
     cur = t;

     cout << cur->data;

    cur = head;
    for (int i = 0; i < index2-1; i++)
    {
        cur = cur->next;
    }
    t = cur->next;
    cur->prev->next = tmp2;
    cur->next = t;
  //  cur->next = tmp2;
   // cur = cur->next;
    

   // cur = head;
    



    //tmp1 = head;
    //tmp2 = last;

    //list* c = new list;
    //list* order1 = new list;
    //list* order2 = new list;

    //order1 = tmp1;
    //order2 = tmp2; 
    //int b = 1;
    //while (b < 4)
    //{
    //    c = order1;
    //    order1 = order2;
    //    order2 = c;
    //    cout << order2->data;
    //    tmp1 = tmp1->next;
    //   // tmp2 = tmp2->prev;
    //    b++;
    //    c

    //}
}


