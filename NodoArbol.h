#ifndef NodoArbol_H
#define NodoArbol_H
#include <vector>
#include "Militar.h"
using std::vector;

class NodoArbol
{
private:
    Militar* militar;
    vector <NodoArbol*> NodosHijos;

public:
    NodoArbol();
    NodoArbol(Militar*);

    Militar* getmilitar();
    void setmilitar(Militar*);

    vector <NodoArbol*> getNodosHijos();
    void setNodosHijos(vector <NodoArbol*>);
    void agregarhijos(NodoArbol*);
    string toString();
};
#endif
