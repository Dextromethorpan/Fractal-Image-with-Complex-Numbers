#include <string>
#include <iostream>
#pragma once

using namespace std;

class PGM
{   
    //Declaración de los Atributos de la clase
    private:
    int eje_x; 
    int eje_y; 
    int max;
    string magic_num; 
    string name;

    public:
    
    //Declaración de los Constructores
    
    //Declaración del Constructor por Defecto
    PGM();
    
    //Declaración del Constructor por Pase de Argumentos
    PGM(string, int, int, int, string);
    
    //Declaración del Constructor por Copia
    PGM(const PGM &);
    
    //Declaración del Destructor
    ~PGM();

    //--------------------

    //Declaración del Método para Generar el Archivo PMG
    void generador_imagen(int **);



};

