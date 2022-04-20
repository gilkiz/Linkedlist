#include <iostream>
#include <iomanip>
#include <cstdlib>

template <class Q>
class node{
    public:
        Q data;
        node* next_node;
        node* prev_node;

        node()=default;
        node(Q initialize_value, node* previous_node = nullptr, node* next_node = nullptr){
            this->data=initialize_value;
            this->next_node=next_node;
            this->prev_node=previous_node;
        }
        template<class R>
        node(node<R> to_copy) =delete;
        ~node()=default;
        template<class Z> 
        friend std::ostream& operator<<(std::ostream& os, const node<Z>& n);
};


template <class Z>
std::ostream& operator<<(std::ostream& os, const node<Z>& n){
    return os<<n.data;
}
