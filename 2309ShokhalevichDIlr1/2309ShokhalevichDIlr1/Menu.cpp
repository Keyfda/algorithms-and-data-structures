#include "header.h"

void ConsoleMenu(list*& head, list*& cur, list*& last, list*& head2)
{
   
    cout << "    Choose out of this list what you want to do\n"
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
    Option(head, cur, last, head2);
}

void Option(list*& head, list*& cur, list*& last, list*& head2)
{
    cur = head;
    
    int NumbOfMethod;     //номер используемого метода
    cin >> NumbOfMethod;
    switch (NumbOfMethod)
    {
    case(1):
        AddEnd(cur, last);
        break;
    case(2):
        AddBeg(head, cur, last);
        break;
    case(3):
        DeleteLast(cur, last);
        break;
    case(4):
        DeleteFirst(head);
        break;
    case(5):
        AddByIndex(head);
        break;
    case(6):
        GetByIndex(head);
        break;
    case(7):
        DeleteByIndex(head);
        break;
    case(8):
        GetSize(head);
        break;
    case(9):
        DeleteList(head, cur, last);
        break;
    case(10):
        ReplaceByIndex(head);
        break;
    case(11):
        IsEmpty(head);
        break;
    case(12):
        Reverse(head, last);
        break;
    case(13):
        AddListByIndex(head, head2);
        break;
    case(14):
        AddListEnd(head, head2);
        break;
    case(15):
        AddListBeg(head, head2);
        break;
    case(16):
        CheckIsIn(head, head2);
        break;
    case(17):
        FindIndexStart(head, head2);
        break;
    case(18):
        FindIndexEnd(head, head2);
        break;
    case(19):
        Swap(head);
        break;
    default:
        cout << "There's no such option, Try again!    ";
        Option(head, cur, last, head2);
    }

  //  int key;
    if (NumbOfMethod != 9)
    {
        cout << "\n\nNew List: ";
        cur = head;

        //cout << "\nYour list: ";
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }
    cout << "\n\n  1). Back to menu; "
        "\n  2). Exit;"
        "\n\n  0). Create new list;"
        "\n\n\n Enter:  ";
    OptionMenu(head, cur, last, head2);
  

}

void OptionMenu(list*& head, list*& cur, list*& last, list*& head2)
{
    

    int key;
    cin >> key;

    system("cls");
    switch (key)
    {
    case(1):
        ConsoleMenu(head, cur, last, head2);
        break;
    case(2):
        cout <<"\n\n\n*************  Have a nice day!  *************\n\n\n";
        exit(0);
        break;
    case(0):
        input(head, cur, last);
        ConsoleMenu(head, cur, last, head2);
        break;
    default:
        cout << "There's no such option, Try again!    ";
        OptionMenu(head, cur, last, head2);
    }
}