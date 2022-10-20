#ifndef SOLUCION_H
#define SOLUCION_H
#include "vector"
#define CONST 10

using namespace std;

class Solucion
{
    public:
        Solucion();//Constructores
        Solucion(int bono);

        virtual ~Solucion();//Destructor

        //Metodos modificadores.
        void agregar_familia (string id_familia, int integrantes, int pos_preferencia, int dia); //Es para sumar la familia y ademas para no repetirla
        void familia_usada(string id_familia, int integrantes, int pos_preferencia, int dia);//En caso de retroceso vuelvo a tener en cuenta esa familia y resto al bono si se sumo algo.

        //Operador =
        Solucion &operator = (Solucion &otraSolucion);

        //Metodos observadores.
        void imprimir_familias () const;//Imprime las familias en sus posiciones.
        int devolver_bono() const; //Devuelve el monto del bono
        int cant_personas(int dia) const; //Devuelve la cantidad de personas en un dia

    private:
        int bono_obtenido;
        int personas[CONST];
        vector<string> familias[CONST];
};


Solucion::Solucion()
{
    bono_obtenido=0;
    for(int i=0; i<CONST; i++)
    {
        personas[i]=0;
    }
}

Solucion::Solucion(int bono)
{
    bono_obtenido=bono;
    for(int i=0; i<CONST; i++)
    {
        personas[i]=0;
    }
}

Solucion::~Solucion()
{
    //dtor
}


void Solucion::imprimir_familias() const
{
    for (int dia=0; dia<CONST; dia++)
    {
        cout<<"Para el dia "<<dia+1<<":";
        for (vector<string>::const_iterator it3=familias[dia].begin(); it3!=familias[dia].end(); it3++)
        {
            cout<<"  "<< *it3;
        }
        cout<<endl<<endl;
    }
}


Solucion & Solucion::operator=(Solucion &otraSolucion)
{
    bono_obtenido=otraSolucion.bono_obtenido;
    for (int i=0; i<CONST; i++)
    {
        familias[i]=otraSolucion.familias[i];
        personas[i]=otraSolucion.personas[i];

    }
    return *this;
}


void Solucion::familia_usada(string id_familia, int integrantes, int pos_preferencia, int dia)
{
    familias[dia-1].pop_back();
    if (pos_preferencia > 0)
    {
        bono_obtenido-= 25+ (10*integrantes) + (5*pos_preferencia);
    }
    personas[dia-1]= personas[dia-1]-integrantes;
}


void Solucion::agregar_familia(string id_familia, int integrantes, int pos_preferencia, int dia)
{
    familias[dia-1].push_back(id_familia);
    if (pos_preferencia > 0)
    {
        bono_obtenido+= 25+ (10*integrantes) + (5*pos_preferencia);
    }
    personas[dia-1]= personas[dia-1]+integrantes;
}


int Solucion::cant_personas(int dia) const
{
    return personas[dia-1];
}


int Solucion::devolver_bono() const
{
    return bono_obtenido;
}
#endif // SOLUCION_H
