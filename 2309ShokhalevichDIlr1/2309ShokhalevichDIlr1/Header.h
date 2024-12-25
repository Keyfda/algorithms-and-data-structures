#ifndef header
#define header
#include <stdlib.h>
#include <iostream>
#include <chrono>
 
using namespace std;

struct list
{
    int data;    
    list* next = nullptr;    
    list* prev = nullptr;       
};

void amlists(list*& head, list*& cur, list*& last, list* listss[], int& lists, list*& head2, int ElAmount1[]);
void input(list*& head, list*& cur, list*& last, int ElAmount1[], int& j);
void AnotherList(list*& head2);



void ConsoleMenu(list*& head, list*& cur, list*& last, list*& head2, list* listss[], int& lists, int ElAmount1[]);
void Option(list*& head, list*& cur, list*& last, list*& head2, list* listss[], int& lists, int ElAmount1[]);
void OptionMenu(list*& head, list*& cur, list*& last, list*& head2, list* listss[], int& lists, int ElAmount1[]);
void end( list*& head);


void AddEnd(list*& head, list*& last, int el);                       //1
void AddBeg(list*& head, list*& cur, list*& last, int el);           //2
void DeleteLast(list*& cur, list*& last);                    //3
void DeleteFirst(list*& head);                               //4
void AddByIndex(list*& head, int index, int el);                                //5
void GetByIndex(list*& head, int index);                                //6
void DeleteByIndex(list*& head, int index);                             //7
void GetSize(list*& head);                                   //8
void DeleteList(list*& head, list*& cur, list*& last);       //9
void ReplaceByIndex(list*& head, int index, int newel);                            //10
void IsEmpty(list*& head);                                   //11
void Reverse(list*& head, list*& last);                      //12
void AddListByIndex(list*& head, list*& head2, int& index);  //13
void AddListEnd(list*& head, list*& head2);                  //14
void AddListBeg(list*& head, list*& head2, list*& last);     //15
void CheckIsIn(list*& head, list*& head2);                   //16
void FindIndexStart(list*& head, list*& head2);              //17
void FindIndexEnd(list*& head, list*& head2);                //18
void Swap(list*& head, int x, int y);                                      //19


#endif