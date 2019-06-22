#ifndef Militar_H
#define Militar_H
#include <string>
using std::string;
class Militar
{
private:
    string nombre;
    string codigo;
    int edad;
    string rango;

public:
    Militar();
    Militar(string, string, int, string);

    string getnombre();
    void setnombre(string);

    string getcodigo();
    void setcodigo(string);

    int getedad();
    void setedad(int);

    string getrango();
    void setrango(string);

    string toString();
};
#endif
