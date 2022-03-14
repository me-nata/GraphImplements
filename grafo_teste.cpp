#include <iostream>
#include "grafo/aux_structues/simple_list.cpp"

typedef unsigned short ushort;
using namespace std;

template <typename T>
class Vertice {
    public:
    T data;
    ushort degree;
    ushort painted;
    SList::SList<Vertice<T>*> adjacents;

    Vertice(T input_data) {
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

    T get() {return data;}
    void set(T input_data) {data = input_data;}

    void altern_color() {
        painted = 1-painted;
    }

    void reset_color() {
        painted = 0;
    }

    void add_edge(Vertice<T> &adjacent) {
        adjacents.add(adjacent);
    }

    void show(int index, bool data_is_class) {
        string out = "(v";
        out+=to_string(index);
        out+=": ";

        if(!data_is_class) {
            out+=to_string(data);
        } 

        out+=", painted="+to_string((bool)painted);
        out+=", degree="+to_string(degree);
        out+=")";
        cout << out << endl;
    }
};

template <typename T>
class Graph {
    public:
    SList::SList<Vertice<T>> vertices;

    Graph() {
        vertices = SList::SList<Vertice<T>>();
    }

    void add(T data) {
        vertices.add(Vertice<T>(data));
    }

    void conect(ushort a, ushort b) {
        auto* v = vertices.ref(a);
        v->add_edge(vertices.ref(b));
    }

    void show() {
        for(int pos=0; pos < vertices.size; pos++) {
            Vertice<T> *current_v = vertices.ref(pos);
            current_v->show(pos, false);

        }
    }
};

int main() {
    // SList::SList<int> g = SList::SList<int>();
    Graph<int> g = Graph<int>();
    g.add(5);
    g.add(8);
    g.add(90);
    g.show();

    return 0;
}