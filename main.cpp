#include <iostream>
#include <fstream>
#include <list>
#include "Familia.h"
#include "Parque.h"
#include "Solucion.h"

using namespace std;

void procesar_dataset(string origen, list<Familia> & familias);
//DEBUG.
void mostrar_familias(const list<Familia> & familias);


int main()
{
    list<Familia> familias;
    procesar_dataset("data\\familias-2.csv", familias);
    mostrar_familias(familias);
    list<Familia>::iterator it=familias.begin();
    Solucion S=Resolver_Parque(it,familias);
    cout<<"Bono total: "<<S.devolver_bono();
    return 0;
}


void procesar_dataset(string origen, list<Familia> & familias)
{
    ifstream archivo(origen.c_str());
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        //cabecera del csv
        getline(archivo, linea);
        //contamos cuantas columnas "dia" hay para determinar la cantidad de días de preferencia.
        unsigned int cantidad_dias = 0;
        string nombre_columna = "dia_";
        size_t pos = linea.find(nombre_columna);
        while (pos != string::npos) {
            cantidad_dias++;
            pos = linea.find("dia_", pos + nombre_columna.size());
        }

        //Leemos de una linea completa por vez (getline).
        while (getline(archivo, linea)){
            size_t pos_inicial = linea.find(',');
            string id = linea.substr(0, pos_inicial);

            pos_inicial++;
            size_t pos_final = linea.find(',', pos_inicial);
            int miembros = atoi(linea.substr(pos_inicial, pos_final).c_str());

            Familia f(id, miembros, cantidad_dias);

            for (unsigned int dia = 0; dia < cantidad_dias; dia++) {
                pos_inicial = pos_final + 1;
                pos_final = linea.find(',', pos_inicial);
                int preferencia = atoi(linea.substr(pos_inicial, pos_final).c_str());
                f.agregar_preferencia(preferencia);
            }
            familias.push_back(f);
        }
    }
}

void mostrar_familias(const list<Familia> & familias) {
    list<Familia>::const_iterator it = familias.begin();
    while (it != familias.end()) {
        cout << *it;
        it++;
    }

}
