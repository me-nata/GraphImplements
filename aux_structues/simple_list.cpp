#include<iostream>

namespace SList {
    template <class DataType>
    class Cell {
        public:
        DataType object = DataType();
        Cell *next;

        Cell() { next = nullptr; }
        Cell(DataType input_object) {
            object = input_object;
            next = nullptr;
        }

        DataType get() { return object; }

        void set(DataType input_object) { object = input_object; }
    };
    
    template <typename DataType>
    class SList {
        public:
        Cell<DataType> *head;
        Cell<DataType> *tail;
        Cell<DataType> *walk;
        int _walk_pos = 0;
        int size = 0;

        SList() {head = nullptr; tail = nullptr; walk = nullptr;}
        SList(Cell<DataType>* input_head) {
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
                    walk=walk->next;
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
                        _walk_to(0);
                        walk = new Cell<DataType>(object);
                        walk->next = head;
                        head = walk;
                    }
                } else {
                    if(pos == size) {
                        tail->next = new Cell<DataType>(object);
                        tail = tail->next;
                    } else {
                        _walk_to(pos-1);
                        auto *aux = new Cell<DataType>(object);
                        aux->next = walk->next;
                        walk->next = aux;
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
        
        void pop(int pos) {
            if(head != nullptr) {
                if(pos < size and pos >= 0) {
                    if(pos == 0) {
                        _walk_to(0);
                        head = head->next;
                        walk->next = nullptr;
                        walk = head;
                    } else {
                        _walk_to(pos-1);
                        if(pos == size-1) {
                            delete walk->next; walk->next = nullptr;
                            tail = walk;
                            walk = head;
                        } else {
                            auto* del_aux = walk->next;
                            walk->next = walk->next->next;
                            del_aux->next = nullptr;
                            delete del_aux;
                        }
                    }

                    size--;
                }
            }
        }
        void pop(){
            pop(size-1);
        }

        bool empty() {
            return size == 0;
        }

        DataType* ref(int pos) {
            _walk_to(pos);
            return &(walk->object);
        }
    };
}