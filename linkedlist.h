#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include "node.h"

template<class T> 
class Linkedlist{
    public:
        node<T>* begin;
        node<T>* end;
        int length;
    public:

        Linkedlist(){
            begin=NULL;
            end=NULL;
            length=0;
        }
        ~Linkedlist(){
            node<T>* temp=this->begin;
            while (temp!=NULL){
                node<T>* temp2=temp;
                temp=temp->next_node;
                delete(temp2);
            }
            delete(this);
        }
        
        template<class S>
        Linkedlist(Linkedlist<S> to_copy) = delete;

        //* curr becomes the value we inserted
        void push_before_index(T insert_value, int index){
            if(index<0 || index>=this->length){
                return;
            }
            node<T>* curr=this->begin;
            int i=0;
            while(i<index){
                curr=curr->next_node;
                i++;
            }
            node<T>* to_insert=new node<T>(insert_value);
            if(this->length==0){
                this->begin=to_insert;
                this->end=to_insert;
                to_insert->prev_node=NULL;
                to_insert->next_node=NULL;
                length++;
                return;
            }
            if (this->length==1){
                this->begin=to_insert;
                to_insert->prev_node=NULL;
                to_insert->next_node=curr;
                curr->prev_node=to_insert;
                length++;
                return;
            }
            if(curr==this->begin){
                this->begin=to_insert;
                to_insert->prev_node=NULL;
                to_insert->next_node=curr;
                curr->prev_node=to_insert;
                length++;
                return;
            }
            to_insert->prev_node=curr->prev_node;
            curr->prev_node->next_node=to_insert;
            curr->prev_node=to_insert;
            to_insert->next_node=curr;
            length++;
        }
        void push_last(T insert_value){
            node<T>* to_insert=new node<T>(insert_value);
            if(this->length==0){
                this->begin=to_insert;
                this->end=to_insert;
                length++;
                return;
            }
            this->end->next_node=to_insert;
            to_insert->prev_node=this->end;
            this->end=to_insert;
            length++;
        }
        //* curr becomes the begining
        void pop_index(int index){
            if(index<0 || index>=this->length){
                return;
            } 
            node<T>* curr=this->begin;
            int i=0;
            while(i<index){
                curr=curr->next_node;
                i++;
            }
            if(curr==this->begin){
                this->begin=curr->next_node;
            }
            if(curr==this->end){
                this->end=curr->prev_node;
            }
            if(curr->prev_node!=NULL){
                curr->prev_node->next_node=curr->next_node;
            }
            if(curr->next_node!=NULL){
                curr->next_node->prev_node=curr->prev_node;
            }
            this->length--;
            delete(curr);
        }

};