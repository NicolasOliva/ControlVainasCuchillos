#include <stdio.h>

typedef struct{

    char nombre[40];
    int medida;
    float precio;
    float precioCosto;
    int porcentaje;
    int stock;

}estructura;


void CargaPrincipal (char vainas []);

void Muestra (char vaina []);

void CargaProducto (char vainas[]);

void Ordena (char vainas[]);

int PasarArreglo (char vainas [], estructura Arreglo[]);

void OrdenaArreglo (estructura A [], int cant);

void IntercambiaArreglo (estructura A[], int menor, int i);

int PosicionMenor (estructura A[], int cant, int pos);

void PasarArchivo (char vainas [], estructura Arreglo[], int cant);

void MuestraArreglo (estructura A[], int cant);

int Busca (char vaina[], char palabra[]);

void Modifica (char vainas[]);

int BuscaCelda (estructura A[],char Palabra[],int cant);

void CambiaValor (estructura A[],int pos);

void MuestraUnoArreglo (estructura Arreglo[], int i);

void EliminarProducto (char vainas[]);

void Eliminar (estructura A[],estructura aux[], int cant, int pos);

void Vender (char vainas []);

int  BuscaCelda2 (estructura A[], char Palabra[], int cant);


void CrearContrasena (char contra []);

void ComprobacionPass(char contra []);

int ControlPass (char contra []);

void leercontrasenia (char contra[]);









