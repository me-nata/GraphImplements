#include <iostream>
#include "aux_structues/simple_list.cpp"

typedef unsigned short ushort;
using namespace std;


namespace Directional {
    template <typename T>
    class Vertice {
        public:
        string label;
        T data;
        ushort degree;
        ushort painted;
        SList::SList<Vertice<T>*> adjacents;

        Vertice(int index, T input_data) {
            label = "v"+to_string(index);
            degree = 0;
            painted = 0;
            data = input_data;
            adjacents = SList::SList<Vertice<T>*>();
        }

        Vertice() {
            degree = 0;
            painted = 0;
            adjacents = SList::SList<Vertice<T>*>();
        }

        void altern_color() {
            painted = 1-painted;
        }

        void reset_color() {
            painted = 0;
        }

        void add_edge(Vertice<T> *adjacent) {
            adjacents.add(adjacent);
        }

        void show(bool data_is_class) {
            string out = label;
            out+=": ";

            if(!data_is_class) {
                out+=to_string(data);
            } 

            out+=", painted="+to_string((bool)painted);
            out+=", degree="+to_string(degree);
            out+=") [ ";

            for(auto *aux = adjacents.ref(0); aux != nullptr; aux=aux->next) {
                out += (aux->object)->label;
                out += " ";
            }
            out+="]";
            cout << out << endl;
        }
    };

    template <typename T>
    class Graph {
        public:
        SList::SList<Vertice<T>> vertices;
        int index = 0;

        Graph() {
            vertices = SList::SList<Vertice<T>>();
        }

        void add(T data) {
            vertices.add(Vertice<T>(index, data));
            index++;
        }

        void conect(ushort a, ushort b) {
            auto* v = vertices.ref_object(a);
            v->add_edge(vertices.ref_object(b));
        }

        void show() {
            for(int pos=0; pos < vertices.size; pos++) {
                Vertice<int> *current_v = vertices.ref_object(pos);
                current_v->show(false);
            }
        }
    };
}

namespace Undirectional {}

namespace Weighted
{
    namespace Directional {}
    namespace Undirectional {}
}



int main() {
    Directional::Graph<int> g1 = Directional::Graph<int>();
    g1.add(4);
    g1.add(8);
    g1.add(90);
    g1.conect(0, 1);
    g1.conect(1, 2);
    g1.conect(0, 2);
    g1.conect(2, 1);

    g1.show();

    return 0;
}