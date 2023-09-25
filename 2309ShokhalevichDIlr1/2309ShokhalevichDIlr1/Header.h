#ifndef header
#define header
#include <stdlib.h>
#include <iostream>

using namespace std;

struct list
{
    int data;        // поле данных
    list* next = nullptr;       // указатель на следующий элемент
    list* prev = nullptr;       // указатель на предыдущий элемент
};

void input(list*& head, list*& cur, list*& last);
void AnotherList(list*& head2);


void ConsoleMenu(list*& head, list*& cur, list*& last, list*& head2);
void Option(list*& head, list*& cur, list*& last, list*& head2);
void OptionMenu(list*& head, list*& cur, list*& last, list*& head2);


void AddEnd(list*& cur, list*& last);                        //1
void AddBeg(list*& head, list*& cur, list*& last);           //2
void DeleteLast(list*& cur, list*& last);                    //3
void DeleteFirst(list*& head);                               //4
void AddByIndex(list*& head);                                //5
void GetByIndex(list*& head);                                //6
void DeleteByIndex(list*& head);                             //7
void GetSize(list*& head);                                   //8
void DeleteList(list*& head, list*& cur, list*& last);       //9
void ReplaceByIndex(list*& head);                            //10
void IsEmpty(list*& head);                                   //11
void Reverse(list*& head, list*& last);                      //12
void AddListByIndex(list*& head, list*& head2);              //13
void AddListEnd(list*& head, list*& head2);                  //14
void AddListBeg(list*& head, list*& head2);                  //15
void CheckIsIn(list*& head, list*& head2);                   //16
void FindIndexStart(list*& head, list*& head2);              //17
void FindIndexEnd(list*& head, list*& head2);                //18
void Swap(list*& head);                                      //19


#endif