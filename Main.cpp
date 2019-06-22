#include <iostream>
#include <string>
#include <vector>
#include "ncurses.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
#include "NodoArbol.h"
#include "Militar.h"
#include <fstream>
using std::ofstream;

NodoArbol *PreOrden(NodoArbol *recibo, vector<NodoArbol *> &militarTipoActual, string actual)
{
    if (recibo->getmilitar()->getrango() == actual)
    {
        militarTipoActual.push_back(recibo);
    }
    for (int i = 0; i < recibo->getNodosHijos().size(); i++)
    {
        PreOrden(recibo->getNodosHijos()[i], militarTipoActual, actual);
    }
}
void Visualizar(NodoArbol *nodo, vector<NodoArbol *> &militarTipoActual, string &salida)
{
    if (nodo->getmilitar()->getrango() == "Coronel")
    {
        printw("  ");
        salida += "  ";
    }
    else if (nodo->getmilitar()->getrango() == "Mayor")
    {
        printw("   ");
        salida += "   ";
    }
    else if (nodo->getmilitar()->getrango() == "Capitan")
    {
        printw("    ");
        salida += "    ";
    }
    else if (nodo->getmilitar()->getrango() == "Teniente")
    {
        printw("     ");
        salida += "     ";
    }
    else if (nodo->getmilitar()->getrango() == "Sargento")
    {
        printw("      ");
        salida += "      ";
    }
    else if (nodo->getmilitar()->getrango() == "Cabo")
    {
        printw("       ");
        salida += "       ";
    }
    else if(nodo->getmilitar()->getrango() == "Soldado")
    {
        printw("         ");
        salida += "         ";
    }
    printw("%s\n", nodo->toString().c_str());
    salida += nodo->toString()+"\n";
    for (int i = 0; i < nodo->getNodosHijos().size(); i++)
    {
        Visualizar(nodo->getNodosHijos()[i], militarTipoActual, salida);
    }
}
void GuardarArchivo(string filename, string salida)
{
    ofstream file;
    file.open("Listados/"+filename, std::ios::app);
    file <<salida<<endl;
    file.close();
}
int main()
{

    char resp = 's';
    int opcion = 0, opcion_agregar = 0, edad = 0, cont = 0, posmilitar = 0;
    NodoArbol *raiz;
    string nombre, codigo, actual, salida;
    vector<NodoArbol *> militarTipoActual;
    raiz = new NodoArbol(new Militar("Yagabarish Skrobernov", "M_17", 72, "General"));
    while (resp == 's' || resp == 'S')
    {
        cout << "1. Agregar Militar " << endl
             << "2. Visualizar: " << endl
             <<"3. Guardar en archivo"<<endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            militarTipoActual.clear();
            cout << "1. Agregar Coronel: " << endl
                 << "2. Agregar Mayor: " << endl
                 << "3. Agregar Capitán: " << endl
                 << "4. Agregar Teniente: " << endl
                 << "5. Agregar Sargento: " << endl
                 << "6. Agregar Cabo: " << endl
                 << "7. Agregar Soldado: " << endl;
            cin >> opcion_agregar;
            switch (opcion_agregar)
            {
            case 1:
                cout << "Ingrese nombre: ";
                cin >> nombre;
                cout << "Ingrese codigo: ";
                cin >> codigo;
                cout << "Ingrese edad: ";
                cin >> edad;
                raiz->agregarhijos(new NodoArbol(new Militar(nombre, codigo, edad, "Coronel")));
                break;
            case 2:
            {
                actual = "Coronel";
                PreOrden(raiz, militarTipoActual, actual);
                if (militarTipoActual.size() > 0)
                {
                    for (int i = 0; i < militarTipoActual.size(); i++)
                    {
                        cout << i << ". " << militarTipoActual[i]->getmilitar()->toString() << endl;
                    }
                    cout << "Ingrese posicion a la que desea agregar el Mayor: ";
                    cin >> posmilitar;
                    cout << "Ingrese nombre: ";
                    cin >> nombre;
                    cout << "Ingrese codigo: ";
                    cin >> codigo;
                    cout << "Ingrese edad: ";
                    cin >> edad;
                    Militar *militar = new Militar(nombre, codigo, edad, "Mayor");
                    NodoArbol *newroot = new NodoArbol(militar);
                    militarTipoActual[posmilitar]->agregarhijos(newroot);
                    delete militar;
                    delete newroot;
                }
                else
                {
                    cout << "No existe un Coronel, intente nuevamente: " << endl;
                }
                break;
            }
            case 3:
                actual = "Mayor";
                PreOrden(raiz, militarTipoActual, actual);
                if (militarTipoActual.size() > 0)
                {
                    for (int i = 0; i < militarTipoActual.size(); i++)
                    {
                        cout << i << ". " << militarTipoActual[i]->getmilitar()->toString() << endl;
                    }
                    cout << "Ingrese posicion a la que desea agregar el Capitan: ";
                    cin >> posmilitar;
                    cout << "Ingrese nombre: ";
                    cin >> nombre;
                    cout << "Ingrese codigo: ";
                    cin >> codigo;
                    cout << "Ingrese edad: ";
                    cin >> edad;
                    Militar *militar = new Militar(nombre, codigo, edad, "Capitan");
                    NodoArbol *newroot = new NodoArbol(militar);
                    militarTipoActual[posmilitar]->agregarhijos(newroot);
                    delete militar;
                    delete newroot;
                }
                else
                {
                    cout << "No existe un Capitan, intente nuevamente: " << endl;
                }
                break;
            case 4:
                actual = "Capitan";
                PreOrden(raiz, militarTipoActual, actual);
                if (militarTipoActual.size() > 0)
                {
                    for (int i = 0; i < militarTipoActual.size(); i++)
                    {
                        cout << i << ". " << militarTipoActual[i]->getmilitar()->toString() << endl;
                    }
                    cout << "Ingrese posicion a la que desea agregar el Teniente: ";
                    cin >> posmilitar;
                    cout << "Ingrese nombre: ";
                    cin >> nombre;
                    cout << "Ingrese codigo: ";
                    cin >> codigo;
                    cout << "Ingrese edad: ";
                    cin >> edad;
                    Militar *militar = new Militar(nombre, codigo, edad, "Teniente");
                    NodoArbol *newroot = new NodoArbol(militar);
                    militarTipoActual[posmilitar]->agregarhijos(newroot);
                    delete militar;
                    delete newroot;
                }
                else
                {
                    cout << "No existe un Teniente, intente nuevamente: " << endl;
                }
                break;
            case 5:
                actual = "Teniente";
                PreOrden(raiz, militarTipoActual, actual);
                if (militarTipoActual.size() > 0)
                {
                    for (int i = 0; i < militarTipoActual.size(); i++)
                    {
                        cout << i << ". " << militarTipoActual[i]->getmilitar()->toString() << endl;
                    }
                    cout << "Ingrese posicion a la que desea agregar el Sargento: ";
                    cin >> posmilitar;
                    cout << "Ingrese nombre: ";
                    cin >> nombre;
                    cout << "Ingrese codigo: ";
                    cin >> codigo;
                    cout << "Ingrese edad: ";
                    cin >> edad;
                    Militar *militar = new Militar(nombre, codigo, edad, "Sargento");
                    NodoArbol *newroot = new NodoArbol(militar);
                    militarTipoActual[posmilitar]->agregarhijos(newroot);
                    delete militar;
                    delete newroot;
                }
                else
                {
                    cout << "No existe un Teniente, intente nuevamente: " << endl;
                }
                break;
            case 6:
                actual = "Sargento";
                PreOrden(raiz, militarTipoActual, actual);
                if (militarTipoActual.size() > 0)
                {
                    for (int i = 0; i < militarTipoActual.size(); i++)
                    {
                        cout << i << ". " << militarTipoActual[i]->getmilitar()->toString() << endl;
                    }
                    cout << "Ingrese posicion a la que desea agregar el Cabo: ";
                    cin >> posmilitar;
                    cout << "Ingrese nombre: ";
                    cin >> nombre;
                    cout << "Ingrese codigo: ";
                    cin >> codigo;
                    cout << "Ingrese edad: ";
                    cin >> edad;
                    Militar *militar = new Militar(nombre, codigo, edad, "Cabo");
                    NodoArbol *newroot = new NodoArbol(militar);
                    militarTipoActual[posmilitar]->agregarhijos(newroot);
                    delete militar;
                    delete newroot;
                }
                else
                {
                    cout << "No existe un Sargento, intente nuevamente: " << endl;
                }
                break;
            case 7:
                actual = "Cabo";
                PreOrden(raiz, militarTipoActual, actual);
                if (militarTipoActual.size() > 0)
                {
                    for (int i = 0; i < militarTipoActual.size(); i++)
                    {
                        cout << i << ". " << militarTipoActual[i]->getmilitar()->toString() << endl;
                    }
                    cout << "Ingrese posicion a la que desea agregar el Soldado: ";
                    cin >> posmilitar;
                    cout << "Ingrese nombre: ";
                    cin >> nombre;
                    cout << "Ingrese codigo: ";
                    cin >> codigo;
                    cout << "Ingrese edad: ";
                    cin >> edad;
                    Militar *militar = new Militar(nombre, codigo, edad, "Soldado");
                    NodoArbol *newroot = new NodoArbol(militar);
                    militarTipoActual[posmilitar]->agregarhijos(newroot);
                    delete militar;
                    delete newroot;
                }
                else
                {
                    cout << "No existe un Cabo, intente nuevamente: " << endl;
                }
                break;
            }
            break;
        case 2:
            militarTipoActual.clear();
            PreOrden(raiz, militarTipoActual, "Coronel");
            PreOrden(raiz, militarTipoActual, "Mayor");
            PreOrden(raiz, militarTipoActual, "Capitan");
            PreOrden(raiz, militarTipoActual, "Teniente");
            PreOrden(raiz, militarTipoActual, "Sargento");
            PreOrden(raiz, militarTipoActual, "Cabo");
            PreOrden(raiz, militarTipoActual, "Soldado");
            initscr();
            noecho();
            start_color();
            init_pair(1, COLOR_GREEN, COLOR_WHITE);
            wbkgd(stdscr, COLOR_PAIR(1));
            refresh();
            Visualizar(raiz, militarTipoActual, salida);
            while (getch() != 'x')
            {
                if (has_colors())
                {
                    start_color();
                    if (getch() == 'n')
                    {
                        start_color();
                        init_pair(2, COLOR_GREEN, COLOR_BLACK);
                        wbkgd(stdscr, COLOR_PAIR(2));
                    }
                    else if (getch() == 'i')
                    {

                        start_color();
                        init_pair(3, COLOR_BLACK, COLOR_WHITE);
                        wbkgd(stdscr, COLOR_PAIR(3));
                    }
                    else if (getch() == 'c')
                    {
                        start_color();
                        init_pair(4, COLOR_BLUE, COLOR_RED);
                        wbkgd(stdscr, COLOR_PAIR(4));
                    }
                    else if (getch() == 'l')
                    {
                        start_color();
                        init_pair(5, COLOR_WHITE, COLOR_BLUE);
                        wbkgd(stdscr, COLOR_PAIR(5));
                    }
                }
                getch();
                refresh();
            }
            endwin();
            break;
        case 3:
            {
                cout << salida;
                string filename;
                cout << "Ingrese nombre del archivo: ";
                cin >> filename;
                GuardarArchivo(filename+".txt",salida);
                break;
            }
        }
        cout << "Desea regresar[s/n]: ";
        cin >> resp;
    }
    return 0;
}