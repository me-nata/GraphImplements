#include <iostream>
#include "aux_structues/simple_list.cpp"

typedef unsigned short ushort;
using namespace std;

namespace Unweighted {
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

    namespace Directional {
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

    namespace Undirectional {
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
                auto* va = vertices.ref_object(a);
                auto* vb = vertices.ref_object(b);
                va->add_edge(vb);
                if(va != vb) {
                    vb->add_edge(va);
                }
            }

            void show() {
                for(int pos=0; pos < vertices.size; pos++) {
                    Vertice<int> *current_v = vertices.ref_object(pos);
                    current_v->show(false);
                }
            }
        };
    }
}

namespace Weighted
{
    template <typename T> 
    struct Connection { 
        T* to; 
        float weight;

        Connection(){}
        Connection(float w, T* v) {
            weight = w;
            to = v;
        }
    }; 

    template <typename T>
    class Vertice {
        public:
        string label;
        T data;
        ushort degree;
        ushort painted;
        SList::SList<Connection<Vertice<T>>> adjacents;

        Vertice(int index, T input_data) {
            label = "v"+to_string(index);
            degree = 0;
            painted = 0;
            data = input_data;
            adjacents = SList::SList<Connection<Vertice<T>>>();
        }

        Vertice() {
            degree = 0;
            painted = 0;
            adjacents = SList::SList<Connection<Vertice<T>>>();
        }

        void altern_color() {
            painted = 1-painted;
        }

        void reset_color() {
            painted = 0;
        }

        void add_edge(float weight, Vertice<T> *adjacent) {
            adjacents.add({weight, adjacent});
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
                out += ((aux->object).to)->label;
                out += ":w=" + to_string((aux->object).weight);
                out += " ";
            }
            out+="]";
            cout << out << endl;
        }
    };

    namespace Directional {
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

            void conect(ushort a, ushort b, float weight) {
                auto* v = vertices.ref_object(a);
                v->add_edge(weight, vertices.ref_object(b));
            }

            void show() {
                for(int pos=0; pos < vertices.size; pos++) {
                    Vertice<int> *current_v = vertices.ref_object(pos);
                    current_v->show(false);
                }
            }
        };
    }

    namespace Undirectional {
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

            void conect(ushort a, ushort b, float weight) {
                auto* va = vertices.ref_object(a);
                auto* vb = vertices.ref_object(b);
                va->add_edge(weight, vb);
                if(va != vb) {
                    vb->add_edge(weight, va);
                }
            }

            void show() {
                for(int pos=0; pos < vertices.size; pos++) {
                    Vertice<int> *current_v = vertices.ref_object(pos);
                    current_v->show(false);
                }
            }
        };
    }
}

int main() {
    Unweighted::Directional::Graph<int>   g1 = Unweighted::Directional::Graph<int>();
    Unweighted::Undirectional::Graph<int> g2 = Unweighted::Undirectional::Graph<int>();
    Weighted::Directional::Graph<int>     g3 = Weighted::Directional::Graph<int>();
    Weighted::Undirectional::Graph<int>   g4 = Weighted::Undirectional::Graph<int>();
    
    cout << "Unweighted Directional" << endl;
    g1.add(4);
    g1.add(8);
    g1.add(90);
    g1.conect(0, 1);
    g1.conect(2, 2);
    g1.conect(0, 2);
    g1.conect(2, 1);
    g1.show();

    cout << "\nUnweighted Undirectional"<< endl;
    g2.add(4);
    g2.add(8);
    g2.add(90);
    g2.conect(0, 1);
    g2.conect(2, 2);
    g2.conect(0, 2);
    g2.conect(2, 1);
    g2.show();

    cout << "\nWeighted Directional"<< endl;
    g3.add(4);
    g3.add(8);
    g3.add(90);
    g3.conect(0, 1, 5.2);
    g3.conect(2, 2, 3.2);
    g3.conect(0, 2, 1.25);
    g3.conect(2, 1, 8);
    g3.show();

    cout << "\nWeighted Undirectional"<< endl;
    g4.add(4);
    g4.add(8);
    g4.add(90);
    g4.conect(0, 1, 5.2);
    g4.conect(2, 2, 3.2);
    g4.conect(0, 2, 1.25);
    g4.conect(2, 1, 8);
    g4.show();

    return 0;
}