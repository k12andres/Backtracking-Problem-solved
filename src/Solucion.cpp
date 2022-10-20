#include "Solucion.h"

Solucion::Solucion()
{
    bono_obtenido=0;
}

Solucion::~Solucion()
{
    //dtor
}

void Solucion::agregar_familia(int id_familia, int integrantes, int pos_preferencia, int dia)
{
    familias[dia-1].push_back(id_familia);
    if (posicion > 0)
    {
        bono_obtenido+= (25+ (10*integrantes) + (5*pos_preferencia)
    }
}
