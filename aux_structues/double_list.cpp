#include <iostream>

namespace DList {
    template <typename DataType>
    class Cell {
        public:
        DataType object = DataType();
        Cell *next;
        Cell *previous;

        Cell() { next = nullptr; previous = nullptr; }
        Cell(DataType input_object) {
            object = input_object;
            next = nullptr;
            previous = nullptr;
        }
    };

    template <typename DataType>
    class DList {
        public:
        Cell<DataType> *head;
        Cell<DataType> *tail;
        Cell<DataType> *walk;
        int size = 0;
        int _walk_pos = 0;
         
        void Dlist() { walk = head = tail = nullptr; }
        void Dlist(Cell<DataType> *input_head) { 
            walk = head = input_head;
            while(walk++ +1 != nullptr);
            tail = walk;
            walk = head;
            _walk_pos = 0; 
        }
        
        void _walk_to(int pos) {
            if(pos == 0) {
                walk = head;
                _walk_pos=0;
            } else {
                if(_walk_pos >= pos) {
                    walk = head;
                    _walk_pos=0;
                }
                while(_walk_pos < pos) {
                    walk = walk->next;
                    _walk_pos++;
                }
            }
        }
        void _add_in(int pos, DataType object) {
            if(pos >= 0 and pos <= size) {
                if(pos == 0) {
                    if(size == 0) {
                        walk = head = tail = new Cell<DataType>(object);
                    } else {
                        walk = new Cell<DataType>(object);
                        walk->next = head;
                        head->previous = walk;
                        _walk_to(0);
                    }
                } else {
                    if(pos == size) {
                        tail->next = new Cell<DataType>(object);
                        tail->next->previous = tail;
                        tail = tail->next;
                    } else {
                        _walk_to(pos-1);
                        walk->next->previous = new Cell<DataType>(object);
                        walk->next->previous->next = walk->next;
                        walk->next->previous->previous = walk;
                        walk->next = walk->next->previous;
                    }
                }

                size++;
            }
        }
        void add(DataType object) {
            _add_in(size, object);
        }
        void insert(int pos, DataType object) {
            _add_in(pos, object);
        }

        DataType get(int pos) {
            _walk_to(pos);
            return walk->object;
        }
        DataType get() {
            return get(size-1);
        }

        bool empty() {
            return size == 0;
        }

        Cell<DataType>* ref(int pos) {
            _walk_to(pos);
            return walk;
        }
    };
}