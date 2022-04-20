#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
    Linkedlist<int> temp;
    temp.push_last(7);
    temp.push_last(3);
    temp.push_last(12);
    temp.push_last(-4);
    temp.push_last(90);
    temp.push_last(-51);
    temp.push_last(19);
    //temp.push_before_index(7000, 2);
    temp.pop_index(2);
    temp.pop_index(2);
    node<int>* temp2=temp.begin;
    while(temp2!=nullptr){
        std::cout << *temp2 << std::endl;
        temp2=temp2->next_node;
    }
}