#include<iostream>

namespace Queue{
    template <typename DataType>
    class Cell {
        public:
        DataType object;
        Cell *next;
        Cell *previous;

        Cell() { next = nullptr; previous = nullptr;}
        Cell(DataType input_object) {
            object = input_object;
            next = nullptr;
            previous = nullptr;
        }

        DataType get() { return object; }

        void set(DataType input_object) { object = input_object; }
    };

    template <typename DataType>
    class Queue {
        public:
        Cell<DataType> *head;
        Cell<DataType> *tail;
        int size = 0;

        Queue() { head = nullptr; tail = nullptr;}

        void push(DataType object) {
            if(head == nullptr) {
                tail = head = new Cell<DataType>(object);
            } else {
                tail->previous = new Cell<DataType>(object);  
                tail->previous->next = tail;
                tail = tail->previous;
            }
            size++;
        }
        
        void pop() {
            if(head != nullptr) {
                if(size == 1) {
                    tail = head = nullptr;
                } else {
                    head = head->previous;
                    head->next->previous = nullptr;
                    head->next = nullptr;
                }

                size--;
            }
        }

        bool empty() {
            return size==0;
        }

        DataType front() {
            return head->get();
        }

        DataType back() {
            return tail->get();
        }
    };
}