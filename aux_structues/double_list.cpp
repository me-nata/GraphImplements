#include <iostream>
using namespace std;

template <class T>
class CelulaDupla {
    public:
        // Atributos
        T value;
        CelulaDupla *prox;
        CelulaDupla *ant;

        // Metodos especiais
        CelulaDupla() {
            this->prox = nullptr;
            this->ant = nullptr;
        }

        CelulaDupla(T value) {
            this->value = value;
            this->prox = nullptr;
            this->ant = nullptr;
        }

        CelulaDupla(T value, CelulaDupla prox, CelulaDupla ant) {
            this->value = value;
            this->prox = prox;
            this->ant = ant;
        }
};

template <class T>
class Lista {
    public:
        // Atributos
        int size;
        CelulaDupla<T> *primeiro;
        CelulaDupla<T> *ultimo;

        // Metodos especiais
        Lista() {
            this->primeiro = new CelulaDupla<T>();
            this->ultimo = this->primeiro;
        }

        int getSize() {
            return this->size;
        }

        // Funcoes e metodos
        void inserirInicio(T value) {
            CelulaDupla<T> *tmp = new CelulaDupla<T>(value);

            tmp->ant = this->primeiro;
            tmp->prox = this->primeiro->prox;
            this->primeiro->prox = tmp;

            if (this->primeiro == this->ultimo) {
                this->ultimo = tmp;
            } else {
                tmp->prox->ant = tmp;
            }

            this->size++;
            tmp = nullptr;
        }

        void inserir(T value) {
            this->ultimo->prox = new CelulaDupla<T>(value);
            this->ultimo->prox->ant = this->ultimo;
            this->ultimo = this->ultimo->prox;

            this->size++;
        }

        void inserirPosition(T value, int position) {
            int length = this->size;

            if (position < 0 || position > length) {
                cout << "Erro: nao e possivel inserir na posicao { " << position << " }" << endl;
            } else if (position == 0) {
                inserirInicio(value);
            } else if (position == length) {
                inserir(value);
            } else {
                CelulaDupla<T> *i = this->primeiro;

                for (int j = 0; j < position; i++, i = i->prox);

                CelulaDupla<T> *tmp = new CelulaDupla<T>(value);
                tmp->ant = i;
                tmp->prox = i->prox;
                tmp->ant->prox = tmp;
                tmp->prox->ant = tmp;

                tmp = nullptr;
                i = nullptr;

                this->size++;
            }
        }

        T removerInicio() {
            if (this->primeiro == this->ultimo) {
                cout << "Erro: a lista esta vazia" << endl;
            }
            CelulaDupla<T> *tmp = this->primeiro;
            this->primeiro = this->primeiro->prox;
            T result = this->primeiro->value;

            tmp->prox = nullptr;
            this->primeiro->ant = nullptr;
            tmp = nullptr;

            this->size--;
            return result;
        }

        T removerFim() {
            if (this->primeiro == this->ultimo) {
                cout << "Erro: a lista esta vazia" << endl;
            }

            T result = this->ultimo->value;
            this->ultimo = this->ultimo->ant;

            this->ultimo->prox->ant = nullptr;
            this->ultimo->prox = nullptr;

            this->size--;
            return result;
        }

        T removerPosition(int position) {
            T result;
            int length = this->size;

            if (this->primeiro == this->ultimo) {
                cout << "Erro: a lista esta vazia" << endl;
            } else if (position < 0 || position >= length) {
                cout << "Erro: nao e possivel remover na posicao { " << position << " }" << endl;
            } else if (position == 0) {
                result = removerInicio();
            } else if (position == length - 1) {
                result = removerFim();
            } else {
                CelulaDupla<T> *i = this->primeiro->prox;

                for (int j = 0; j < position; j++, i = i->prox);

                i->ant->prox = i->prox;
                i->prox->ant = i->ant;
                result = i->value;

                i->prox = nullptr;
                i->ant = nullptr;
                i = nullptr;

                this->size--;
            }

            return result;
        }

        bool remover(T value) {
            bool result = false;
            int j = 0;
            int length = this->size;

            if (this->primeiro == this->ultimo) {
                cout << "Erro: a lista esta vazia" << endl;
            } else {
                for (CelulaDupla<T> *i = this->primeiro->prox; i != nullptr; i = i->prox, j++) {
                    if (i->value == value) {
                        if (j == 0) {
                            result = removerInicio();
                        } else if (j == length - 1) {
                            result = removerFim();
                        } else {
                            i->ant->prox = i->prox;
                            i->prox->ant = i->ant;
                            result = i->value;

                            i->prox = nullptr;
                            i->ant = nullptr;
                            i = nullptr;

                            this->size--;
                        }
                        break;
                    }
                }
            }

            return result;
        }

        void print() {
            for (CelulaDupla<T> *i = this->primeiro->prox; i != nullptr; i = i->prox) {
                cout << i->value << endl;
            }
            cout << endl;
        }

        bool contains(T value) {
            bool result = false;

            for (CelulaDupla<T> *i = this->primeiro->prox; i != nullptr; i = i->prox) {
                if (i->value == value) {
                    result = true;
                    i = this->ultimo;
                }
            }

            return result;
        }

        T get(int position) {
            T result;
            int length = this->size;

            if (this->primeiro == this->ultimo) {
                cout << "Erro: a lista esta vazia" << endl;
            } else if (position < 0 || position >= length) {
                cout << "Erro: nao e possivel pegar na posicao { " << position << " }" << endl;
            } else {
                CelulaDupla<T> *i = this->primeiro->prox;
                for (int j = 0; j < position; j++, i = i->prox);

                result = i->value;

                i = nullptr;
            }

            return result;
        }

        int indexOf(T value) {
            int result = -1;
            int j = 0;

            for (CelulaDupla<T> *i = this->primeiro->prox; i != nullptr; i = i->prox, j++) {
                if (i->value == value) {
                    result = j;
                    i = this->ultimo;
                }
            }

            return result;
        }
};