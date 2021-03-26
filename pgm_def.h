#include <iostream>
#include <string>
#include "pgm_dec.h"
#include <fstream>

using namespace std;


//Declaración del Constructor por Defecto
//Se establecen por Defecto los parámetros establecidos en el Archivo
PGM::PGM():magic_num("P2"), eje_x(640),eje_y(480),max(255), name("out.pmg")
{};


//Declaración del Constructor por Pase de Argumentos
PGM::PGM(string nombre, int x, int y, int m, string f)
:magic_num(nombre),
eje_x(x),
eje_y(y),
max(m),
name(f){};

//Declaración del Constructor por Copia
PGM::PGM(const PGM &p)
:magic_num(p.magic_num),
 eje_x(p.eje_x),
 eje_y(p.eje_y),
 max(p.max),
 name(p.name){};

//Declaración del Destructor
PGM::~PGM(){};



//Declaración del Método para generar Imágenes
void PGM::generador_imagen(int **matriz)
{
    ofstream fout(name.c_str(), ios::out);

    //Escribo los Formatos de PGM
    fout<<magic_num<<endl<<eje_x<<" "<<eje_y<<endl<<max<<endl;

    //Imprimo matriz
    for(int j=0;j<eje_y;j++)
    {
        for(int i=0;i<eje_x;i++)
        {
            fout<<matriz[i][j]<<" ";
        }
        fout<<endl;
    }


}

