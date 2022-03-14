#include "simple_list.cpp";
#include "queue.cpp";

namespace HashList {
    template <typename DataType> 
    class _Hash {
        public:
        DataType *hash;

        _Hash(int tam) {
            hash = new DataType[tam];    
        }

        DataType get(int pos) {
            return hash[pos];
        }
    };

    template <typename DataType>
    class Cell {
        public:
        _Hash<DataType> hash;
        Cell *next;

        Cell(int tam) {
            hash = _Hash(tam);
            next = nullptr;
        }

        void add(int pos, DataType new_object) {
            
        }
    };

    template <typename DataType>
    class HashList {
        public:
        SList::SList<Cell<DataType>> hash_list;
        Queue::Queue<int> del_queue;
        int current_id;
        int current_bucket;
        int max_per_bucket;

        HashList(int max_length_hash) {
            hash_list = SList::SList<Cell<DataType>>();
            del_queue = Queue::Queue();
            current_id = 0;
            current_bucket = 0;
            max_per_bucket = max_length_hash;
        }

        void Add(DataType new_object) {
            if(del_queue.empty()) {
                if(current_id == max_per_bucket) {

                } else {
                    auto* ref = hash_list.modify(current_bucket);

                }
            } else {

            }
        }
    }
}