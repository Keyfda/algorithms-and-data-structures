#include "header.h"

void ConsoleMenu(list*& head, list*& cur, list*& last, list*& head2, list* listss[], int& lists, int ElAmount1[])
{
   
    cout << "    Choose out of this list what do you want to do\n"
        "    Press the number according to the method:\n\n"
        "1).  Add to the end of the list; \n"
        "2).  Add to the beginning of the list;\n"
        "3).  Delete the last element;\n"
        "4).  Delete the first element;\n"
        "5).  Add the element by the index;\n"
        "6).  Get the elemnt by it's index; \n"
        "7).  Delete the elemt by it's index;\n"
        "8).  Get the size of list(Amount of the elements); \n"
        "9).  Delete all the elements(Delete list);\n"
        "10). Replace the elemnt by it index with the new;\n"
        "11). Check if the list is empty;\n"
        "12). Reverse the order of the elements;\n"
        "13). Add another list to the current list by the index;\n" //Подразумевает ввод нового списка как в начале программы(далее также)
        "14). Add another list to the end;\n"
        "15). And another list to the beginning;\n"
        "16). Check if another list is a part of current list\n"
        "17). Find the element index another list starts from in the current list;\n"
        "18). Find the element index another list ends by in the current list;\n"
        "19). Swap two elements by their indices.\n\n"
        "Number of the method:    ";
    Option(head, cur, last, head2, listss, lists, ElAmount1);
}

void end(list*& head)
{
  
    list* cur = head;
           cout << "\n\nChecking the list: ";
        cur = head;
       
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
           
        }
        cout << "\n\n";
  
}

void Option(list*& head, list*& cur, list*& last, list*& head2, list* listss[], int& lists, int ElAmount1[])
{

    //auto start = chrono::high_resolution_clock::now();
   
    cur = head;
    int j;
    int NumbOfMethod;    

    int index;
    int newel;
    int el;

    int sizeofl;

    cin >> NumbOfMethod;
    switch (NumbOfMethod)
    {
    case(1):
        system("cls");
        j = 1;
        cout << "\nEnter your element here:  ";
        cin >> el;
        for (int i= 0; i < lists; i++)
        {
            head = listss[j];
           
            AddEnd(head, last, el);

            if (ElAmount1[j] <= 10)
                end(head);
           

            listss[j] = head;
            j++;
         
           
        }
     
        break;
    case(2):
        system("cls");
         j = 1;
         cout << "\nEnter your element here:  ";
         cin >> el;
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
         
            AddBeg(head, cur, last, el);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
           
        }
       
        break;
    case(3):
        system("cls");
        j = 1;
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
          
            DeleteLast(head, last);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
           
        }
        break;
    case(4):
        system("cls");
        j = 1;
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            DeleteFirst(head);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
            
        }
      
        break;
    case(5):
        system("cls");
        j = 1;
       // int index;
        cout << "\nEntere the index of elemnt:  ";
        cin >> index;

        while (index < 1)
        {
            cout << "\n\nThe index cannot be less than 1!\n";
            cout << "\nTry again.\n\n";
            cout << "Enter index:   ";
            cin >> index;
           
        }

       // int el
        cout << "\nEnter the element:   ";
        cin >> el;
        for (int i = 0; i < lists; i++)
        {
            

            head = listss[j];
            AddByIndex(head, index, el);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
           
        }
       
        break;
    case(6):
        system("cls");
        j = 1;
        cout << "Enter the index:   ";
        cin >> index;
        while (index < 1)
        {
            cout << "\n\nThe index cannot be less than 1!\n";
            cout << "\nTry again.\n\n";
            cout << "Enter index:   ";
            cin >> index;

        }
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            GetByIndex(head, index);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
         
        }
       
        break;
    case(7):
        system("cls");
        j = 1;
        cout << "Enter the index";
        cin >> index;
        while (index < 1)
        {
            cout << "\n\nThe index cannot be less than 1!\n";
            cout << "\nTry again.\n\n";
            cout << "Enter index:   ";
            cin >> index;

        }
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            DeleteByIndex(head, index);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
           
        }
       
        break;
    case(8):
        system("cls");
        j = 1;
      
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            GetSize(head);
       
            if (ElAmount1[j] <= 10)
          //  end(head);
            listss[j] = head;
            j++;
           
          
        }
       
        break;
    case(9):
        system("cls");
        j = 1;
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            DeleteList(head, cur, last);
            listss[j] = head;
            j++;
          
        }
       
        break;
    case(10):
        system("cls");
        j = 1;
        cin >> index >> newel;
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            ReplaceByIndex(head, index, newel);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
           
        }
       
        break;
    case(11):
        system("cls");
        j = 1;
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            IsEmpty(head);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
       
        }
       
        break;
    case(12):
        system("cls");
        j = 1;
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            Reverse(head, last);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
           
        }
     
        break;
    case(13):
        system("cls");

       
        cout << "\nEnter the index:    ";
        cin >> index;
        while (index < 1)
        {
            cout << "\n\nThe index cannot be less than 1!\n";
            cout << "\nTry again.\n\n";
            cout << "Enter index:   ";
            cin >> index;

        }
        j = 1;

     
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            AddListByIndex(head, head2, index);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
           
        }       
        break;
    case(14):
       
        system("cls");
        AnotherList(head2);

        j = 1;
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
     
            AddListEnd(head, head2);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
           
        }
        break;
    case(15):
   
        system("cls");
      

        j = 1;
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            cout << "      " << head->data;
            cout << "      " << last->data;
            AddListBeg(head, head2, last);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
           
        }
               break;
    case(16):
        system("cls");
        AnotherList(head2);
        j = 1;
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            CheckIsIn(head, head2); 
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
           
        }       
        break;
    case(17):
        system("cls");
        AnotherList(head2);
        j = 1;
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            FindIndexStart(head, head2);
            if (ElAmount1[j] <= 10)
                  end(head);
            listss[j] = head;
            j++;
          
        }       
        break;
    case(18):
        system("cls");
       
        j = 1;
        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            FindIndexEnd(head, head2);
            if (ElAmount1[j] <= 10)
            end(head);
            listss[j] = head;
            j++;
           
        }        
        break;
    case(19):
        system("cls");
        int x, y;
        j = 1;
        cout << "Enter first index:   ";
        cin >> x;
        cout << "Enter second index:  ";
        cin >> y;
        while(x< 1 || y <1)
        {
           cout << "\n\nThe index cannot be less than 1!\n";
           cout << "\nTry again.\n\n";
           cout << "Enter first index:   ";
           cin >> x;
           cout << "Enter second index:  ";
           cin >> y;  
        }

        for (int i = 0; i < lists; i++)
        {
            head = listss[j];
            Swap(head, x, y);
            if (ElAmount1[j] <= 10)
            end(head);
           listss[j] = head;
            j++;
           
        }
        break;
    default:
        cout << "There's no such option, Try again!    ";
        Option(head, cur, last, head2, listss, lists, ElAmount1);
    }

  //  int key;
      cout << "\n\n  1). Create new list and back to menu; "
        "\n  2). Exit;"
        "\n\n\n Enter:  ";
   
    OptionMenu(head, cur, last, head2, listss, lists, ElAmount1);
  

}

void OptionMenu(list*& head, list*& cur, list*& last, list*& head2, list* listss[], int& lists, int ElAmount1[])
{
    

    int key;
    cin >> key;

    system("cls");
    switch (key)
    {
    case(2):
        cout <<"\n\n\n*************  Have a nice day!  *************\n\n\n";
        exit(0);
        break;
    case(1):
        amlists(head, cur, last, listss, lists, head2, ElAmount1);
        ConsoleMenu(head, cur, last, head2, listss, lists, ElAmount1);
        break;
    default:
        cout << "There's no such option, Try again!    ";
        OptionMenu(head, cur, last, head2, listss, lists, ElAmount1);
    }
}