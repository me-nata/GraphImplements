#include<iostream>

namespace Stack{
    template <typename DataType>
    class Cell {
        public:
        DataType object;
        Cell *down;

        Cell() { down = nullptr; }
        Cell(DataType input_object) {
            object = input_object;
            down = nullptr;
        }

        DataType get() { return object; }

        void set(DataType input_object) { object = input_object; }
    };

    template <typename DataType>
    class Stack {
        public:
        Cell<DataType> *head;
        int size = 0;

        Stack() { head = nullptr; }
        Stack(Cell<DataType> *input_head) { head = input_head; }

        void push(DataType object) {
            if(head == nullptr) {
                head = new Cell<DataType>(object);
            } else {
                auto *aux = new Cell<DataType>(object);
                aux->down = head;
                head = aux;
            }
            size++;
        }
        
        void pop() {
            if(head != nullptr) {
                auto* aux = head->down;
                head->down = nullptr;
                head = aux;

                size--;
            }
        }

        bool empty() {
            return size==0;
        }

        DataType get() {
            return head->get();
        }
    };
}