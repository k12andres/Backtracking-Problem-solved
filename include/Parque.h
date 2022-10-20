#ifndef PARQUE_H
#define PARQUE_H
#include "Solucion.h"
#include <iostream>
#include <limits.h>
#define LIMITE 31

using namespace std;

bool Poda(Solucion & actual, Solucion & mejor)
{
    if (actual.devolver_bono()>mejor.devolver_bono())
    {
        return true;
    } else
    return false;
}


void backParque (int & cantidad_estados, Solucion & actual, Solucion & mejor, list<Familia>::iterator it, const list<Familia> & familias)
{
    cantidad_estados++;

    if (it!= familias.end())
    {
        for (unsigned int i=0; i<it->obtener_cantidad_dias_elegidos(); i++)
        {
            if (((it->obtener_miembros()) + actual.cant_personas(it->obtener_dia_preferido_en(i))) < LIMITE)
            {
                actual.agregar_familia(it->obtener_id(),it->obtener_miembros(), i, it->obtener_dia_preferido_en(i));

                if (!Poda(actual, mejor))
                {
                    list<Familia>::iterator it2=it;
                    backParque(cantidad_estados, actual, mejor, ++it2, familias);
                }
                actual.familia_usada(it->obtener_id(), it->obtener_miembros(), i, it->obtener_dia_preferido_en(i));
            }
        }
    } else
        if (mejor.devolver_bono() != 0)
        {
            if (actual.devolver_bono() < mejor.devolver_bono())
            {
                mejor=actual;

            }
        } else
        {
            mejor=actual;
        }
}

Solucion Resolver_Parque(list<Familia>::iterator it, const list<Familia> & familias)
{
    Solucion mejor(INT_MAX);//Corregido para que no inicialize en 0.
    Solucion actual;
    int cantidad_estados=0;
    backParque(cantidad_estados, actual, mejor, it, familias);
    mejor.imprimir_familias();
    cout<<"Cantidad de estados: "<<cantidad_estados<<endl;
    return mejor;
}
#endif // PARQUE_H
