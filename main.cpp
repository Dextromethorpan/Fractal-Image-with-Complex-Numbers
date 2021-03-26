//Bibliotecas incluidas

//Biblioteca para operación de flujo de entrada/salida de datos
#include <iostream>

//Biblioteca para Operaciones Matemáticas
#include <cmath>

//Bibliotecas de clase complejos
#include "complejos_def.h"
#include "complejos_dec.h"

//Biblioteca para cadena de caracteres
#include <string>

//Biblioteca para clase pmg
#include "pgm_dec.h"
#include "pgm_def.h"


//Declaración de Constantes
#define FILE "out.pgm"
#define OPCION_O "-o"
#define OPCION_R "-r"
#define OPCION_C "-c"
#define OPCION_W "-w"
#define OPCION_H "-h"
#define RESOLUCION_X 640
#define RESOLUCION_Y 480
#define WIDTH 4.0
#define HEIGHT 4.0
#define EJE_X 0.0
#define EJE_Y 0.0
#define PGM_MAGIC_NUMBER "P2"
#define PGM_MAX_GREY_VAL 75

using namespace std;

//Declaración de las Funciones
    
    //Función Menu
    int menu (void);
    
    //Función Ayuda
    void ayuda(void);
    
    //Función Salir
    int salir(void);

    //Funcion Invalido
    void invalido(void);

    //Función Algoritmo
    //Esta función representa el algoritmo de Mandelbrot
    int algoritmo(double,double,int);


    //Funciones para la modificación del archivo PMG
    double modificar_ancho(double);
    double modificar_alto(double);
    int modificar_resolucion_x(int);
    int modificar_resolucion_y(int);
    int modificar_corte(int);
    string modificar_nombre(string);
    complejos modificar_eje(complejos eje);
    void mostrar_configuracion(complejos,int,int, double, double ,string, int);
    void mandelbrot(complejos,double , double , int , int , int , string, string);
    

//-----------------------------------------

//Función Main

int main(int arg, char *argv[])
{
    int eje_x=RESOLUCION_X, eje_y=RESOLUCION_Y;
    int corte=PGM_MAX_GREY_VAL;
    double width= WIDTH, height=HEIGHT;
    complejos c(EJE_X,EJE_Y);
    string name=FILE, magic_num=PGM_MAGIC_NUMBER;

    if(arg>1)
    {
        for(int i=1;i<arg;i++)
        {
            if(string(argv[i])==OPCION_O)
            {
                name==string(argv[i+1]);
            }
            else if(string(argv[i])==OPCION_R)
            {
                int pos=string(argv[i+1]).find("x");
                int s_length=string(argv[i+1]).length();
                eje_x=stoi(string(argv[i+1]).substr(0,pos));
                eje_y=stoi(string(argv[i+1]).substr(pos+1,s_length));
            }
            else if(string(argv[i])==OPCION_C)
            {
                int s_length= string(argv[i+3]).length();
                if(string(argv[i+2])=="-")
                    c="("+string(argv[i+1])+",-"+string(argv[i+3]).substr(0,s_length-1)+")";
                else
                    c="("+string(argv[i+1])+","+string(argv[i+3]).substr(0,s_length-1)+")";
            }
            else if(string(argv[i])==OPCION_W)
            {
                width=stod(string(argv[i+1]));
            }
            else if (string(argv[i])==OPCION_H)
            {
                height=stod(string(argv[i+1]));

            }
        
        }

    }


   

    int eleccion;

    do 
    {   
        eleccion=menu();
        switch(eleccion)
        {
            case 1:
            width=modificar_ancho(width);
            break;

            case 2:
            height=modificar_alto(height);
            break;

            case 3:
            eje_x=modificar_resolucion_x(eje_x);
            eje_y=modificar_resolucion_y(eje_y);
            break;

            case 4:
            c=modificar_eje(c);
            break;

            case 5:
            name=modificar_nombre(name);
            break;

            case 6:
            corte=modificar_corte(corte);
            break;

            case 7:
            mandelbrot(c,width,height,eje_x,eje_y,corte,name,magic_num);
            break;

            case 8:
            mostrar_configuracion(c,eje_x,eje_y,width,height,name,corte);
            break;

            case 9:
            ayuda();
            break;

            case 10:
            eleccion=salir();
            break;

            default:
            invalido();
            break;
        }

        system("pause");
        cout<<endl;

    }while (eleccion);

    return 0;
}
//--------------------------------------------

//Definición de las Funciones

//Función Menu
int menu(void)
{
    int a;

    cout<<"-------Manual--------------------"<<endl
        <<"Genere el Conjunto de Mandelbrot"<<endl
        <<"Debe ingresar por teclado cada uno de los siguientes paraámetros"
        <<endl
        <<endl
        <<"1-ANCHO"
        <<endl
        <<"2-ALTO"
        <<endl
        <<"3-RESOLUCIÓN"
        <<endl
        <<"4-EJE"
        <<endl
        <<"5-NOMBRE DEL ARCHIVO"
        <<endl
        <<"6-CORTE"
        <<endl
        <<"7-EJECUTAR MANDELBROT"
        <<endl
        <<"8-MOSTRAR CONFIGURACIÓN"
        <<endl
        <<"9-AYUDA"
        <<endl
        <<"10-SALIR"
        <<endl;

    cin>>a;

    return a;
}


//Función Ayuda
void ayuda(void)
{
    cout<<"Para generar el Conjunto de Mandelbrot, debe ingresar por teclado"
    <<endl
    <<"cada uno de los parámetros presentados en el Manual"<<endl
    <<endl
    <<endl
    <<"Para ingresar un nuevo eje, debe ser de la forma: (a,b) "
    <<endl
    <<"con a y b son escalares"<<endl<<endl;

}

//Función Salir
int salir(void)
{
    cout<<"Adios"<<endl<<endl;
    return 0;
}

//Función invalido
void invalido(void)
{
    cout<<"Por favor, reingrese."<<endl<<endl;
}



//Función Algoritmo
int algoritmo(double re, double im, int corte)
{
    int i=0;

    complejos c(re,im);
    
    complejos c0(c);

    for (i=0; i<corte; i++)
    {
        if (c.modulo()>2)
            break;
        c=c*c+c0;
    }

    return i;
}


//Funcion Modificar Ancho
double modificar_ancho(double width)
{
    cout<<"El ancho actual es: "
    <<width
    <<endl
    <<"Ingrese el nuevo ancho: "<<endl;
    cin>>width;
    cout<<endl;

    return width;
}

//Función Midificar Altura
double modificar_alto(double height)
{
    cout<<"El alto actual es: "
    <<height
    <<endl
    <<"Ingrese el nuevo alto: "<<endl;
    cin>>height;
    cout<<endl;

    return height;
}

//Función Modificar la Resolución Horizontal
int modificar_resolucion_x(int eje_x)
{
    cout<<"La resolución horizontal actual es: "
    <<eje_x
    <<endl
    <<"Ingrese la nueva resolución: "<<endl;
    cin>>eje_x;
    cout<<endl;

    return eje_x;
}

//Función Modificar la Resolución Vertical
int modificar_resolucion_y(int eje_y)
{
    cout<<"La resolución vertical actual es: "
    <<eje_y
    <<endl
    <<"Ingrese la nueva resolución: "<<endl;
    cin>>eje_y;
    cout<<endl;

    return eje_y;
}

//Función Modificar Corte
int modificar_corte(int corte)
{
    cout<<"El corte actual es: "
    <<corte
    <<endl
    <<"Ingrese el nuevo corte: "<<endl;
    cin>>corte;
    cout<<endl;

    return corte;
}

//Función Modificar Nombre
string modificar_nombre(string name)
{   cout << "Nombre actual: "
	<< name
	<< endl
	<< "Ingrese el nuevo nombre del archivo: ";
	cin >> name;
	cout << endl;
	return name;
}

//Función Mostrar Configuración
void mostrar_configuracion(complejos c,int eje_x,int eje_y,double width, double height, string name, int corte)
{
    cout<<"La configuración es :"
    <<endl
    <<endl
    <<"Centro de la Imagen: "
    <<c
    <<endl
    <<"Resolución Horizontal: "
    <<eje_x
    <<endl
    <<"Resolución Vertical: "
    <<eje_y
    <<endl
    <<"Ancho: "
    <<width
    <<endl
    <<"Alto: "
    <<height
    <<endl
    <<"Nombre del Archivo: "
    <<name
    <<endl;
}

//Funcion Modificar Complejo
complejos modificar_eje(complejos c)
{
    cout<<"El eje actual es: "
    <<c
    <<endl
    <<"Ingrese el nuevo eje, respetando el formato (a,b): ";
    cin>>c;
    cout<<endl;
    return c;
}




//Función Mandelbrot
void mandelbrot(complejos c,double width, double height, int eje_x, int eje_y, int corte, string name, string magic_num)
{
    //Declaro el Objeto PGM
    PGM out(magic_num,eje_x,eje_y,corte,name);
    

    //Informo comienzo del procesamiento
    cout<<"Algoritmo ejecutandose";

    //Declaro Matriz
    int **matriz= new int *[eje_x];
    for (int i =0; i<eje_x; i++)
    {
        matriz[i]=new int[eje_y];
    }

    //Calculo los bordes del rectangulo del plano complejo a graficar
    double x0= c.get_re()- (width/2);
    double y0= c.get_im()- (height/2);

    //Calculo incremento basado en el tamaño del rectangulo del plano
    //complejo a graficar
    double aumentox= width/ eje_x;
    double aumentoy=height/eje_y;

    //Genero Conjunto de Mandelbrot
    for(int i=0;i<eje_x;i++)
    {
        for(int j=0;j<eje_y;j++)
        {
            matriz[i][j] =algoritmo(x0+(i*aumentox),y0+(j*aumentoy),corte);  
        }
    }

    //Informe Fin del Procesamiento
    cout<<"Listo. Exportando resultados a archivo: "
    <<name<<endl;

    //Genero Archivo PGM
    out.generador_imagen(matriz);

    //Informo Fin de Exportación
    cout<<"Listo"
    <<endl
    <<endl;
}


