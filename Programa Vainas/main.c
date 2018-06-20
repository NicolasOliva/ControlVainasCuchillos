#include <stdio.h>
#include <stdlib.h>
#include "Vainas.h"


int main()
{

estructura A;

char vainas [] = "vainas.dat";

char contra [] = "Contraseña.dat";

int opcion;

int control;


// _________________________

control = ControlPass(contra);

printf("CONTROL : %d ", control);

if (control == 0){                       // SI NO SE CREO CONTRASEÑA

    printf("\n \n Debe crear una nueva contrasenia para utilizar el programa ");

    printf("\n\n (Enter para continuar) \n ");

    getch();

    CrearContrasena(contra);

}

leercontrasenia(contra);
//ComprobacionPass(contra);


while (opcion != 6){

system("cls");

printf("\n \t MENU \n");

printf("\n \n 1.Muestra listado de vainas ");
printf("\n \n 2.Venta de un producto");
printf("\n \n 3.Cargar un producto nuevo");
printf("\n \n 4.Modificar un producto");
printf("\n \n 5.Eliminar un producto");
printf("\n \n 6.Salir del programa");
printf("\n\n \n 9.Borrar lista y crear una nueva");

printf("\n\n \n  Ingrese la opcion : ");
scanf("%d", &opcion);

switch(opcion){

case 1 :

        system("cls");

        Muestra(vainas);

        getch();

        break;

case 2 :

        system("cls");

        Muestra(vainas);

        Vender(vainas);

        break;

case 3 :

        system("cls");

        CargaProducto(vainas);

        Muestra(vainas);

        getch();

        break;

case 4 :

        system("cls");

        Muestra(vainas);

        Modifica(vainas);

        break;

case 5 :

        system("cls");

        Muestra(vainas);

        EliminarProducto(vainas);

        break;

case 6 :

        break;

case 9 :

        CrearContrasena(contra);

        system("cls");

   //   CargaPrincipal(vainas);

        break;

}   // <-- SWITCH

}   // <-- WHILE

return 0;

}
