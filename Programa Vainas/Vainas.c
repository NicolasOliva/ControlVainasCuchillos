#include "Vainas.h"

void CargaPrincipal (char vainas [])                      /// PRINCIPAL
{

char pregunta;
printf("\n Desea eliminar la lista y cargarlo nuevamente? s/n : ");
fflush(stdin);
scanf("%c", &pregunta);

if (pregunta == 's'){

FILE * archi;

archi = fopen(vainas,"wb");

if (archi != NULL){

// ___________________________________

estructura A;

char resp = 's';

char precio = 's';


    while (resp == 's'){

    printf("\n Ingrese el nombre del producto : Vaina ");
    fflush(stdin);
    gets(&A.nombre);

    printf("\n Ingrese la medida de la vaina : ");
    scanf("%d", &A.medida);

    printf("\n Ingrese el precio de costo de la vaina : ");
    scanf("%f", &A.precioCosto);

    printf("\n Que porcentaje quiere agregarle al costo? : ");
    scanf("%d", &A.porcentaje);

    A.precio = ((A.precioCosto * A.porcentaje) / 100) + A.precioCosto ;

    printf("\n Precio : $%.2f ", A.precio);

    printf("\n Quiere dejar ese precio? s/n : ");
    fflush(stdin);
    scanf("%c", &precio);

    if (precio == 'n'){

    printf("\n Ingrese el precio de la vaina manualmente : ");
    scanf("%f", &A.precio);

    A.porcentaje = NULL;

    }

    printf("\n Ingrese el stock de vainas : ");
    scanf("%d", &A.stock);

    fwrite(&A, sizeof(estructura),1,archi);

    // ___________________________

    printf(" \n Desea cargar una nueva vaina? s/n : ");
    fflush(stdin);
    scanf("%c", &resp);

    }

fclose(archi);

Ordena(vainas);

}else{

    printf("/n Ocurrio un problema en el archivo ");

}

}

}

void Muestra (char vaina [])                              /// PRINCIPAL
{

FILE * archi;

archi = fopen(vaina, "rb");

if (archi!=NULL){

// _________________________

estructura A;

printf("\n  LA LISTA DE PRODUCTOS ES : \n ");

while (fread(&A,sizeof(estructura),1,archi)>0){

    printf("\n   _________________________ \n\n ");

    printf("   TIPO : Vaina %s \n",A.nombre);
    printf("    MEDIDA : %d cm \n", A.medida);
    printf("    PRECIO : $%.2f ($%.2f) [%%%d] \n", A.precio, A.precioCosto, A.porcentaje);
    printf("    STOCK : %d \n", A.stock);

}

    printf("\n   _________________________ \n\n ");

fclose(archi);

}else{

    printf("\n El archivo en ´mostrar´ no se abrio correctamente");

}

}

void CargaProducto (char vainas[])                        /// PRINCIPAL
{

FILE * archi;

archi = fopen(vainas,"ab");

if (archi != NULL){

// ___________________________________

estructura A;

char resp = 's';
char precio = 's';

    while (resp == 's'){

    printf("\n Ingrese el nombre del producto : Vaina ");
    fflush(stdin);
    gets(&A.nombre);

    printf("\n Ingrese la medida de la vaina : ");
    scanf("%d", &A.medida);

    printf("\n Ingrese el precio de costo de la vaina : ");
    scanf("%f", &A.precioCosto);

    printf("\n Que porcentaje quiere agregarle al costo? : ");
    scanf("%d", &A.porcentaje);

    A.precio = ((A.precioCosto * A.porcentaje) / 100) + A.precioCosto ;

    printf("\n Precio : $%.2f ", A.precio);

    printf("\n Quiere dejar ese precio? s/n : ");
    fflush(stdin);
    scanf("%c", &precio);

    if (precio == 'n'){

    printf("\n Ingrese el precio de la vaina manualmente : ");
    scanf("%f", &A.precio);

    A.porcentaje = NULL;

    }

    printf("\n Ingrese el stock de vainas : ");
    scanf("%d", &A.stock);

    fwrite(&A, sizeof(estructura),1,archi);

    // ___________________________

    printf(" \n Desea cargar una nueva vaina? s/n : ");
    fflush(stdin);
    scanf("%c", &resp);

    printf(" \n ");

    }

fclose(archi);

Ordena(vainas);


}else{

    printf("/n Ocurrio un problema en el archivo en `CargaProducto'");

}

}

void Ordena (char vainas[])                                // AUX
{

int cant = 0;

estructura Arreglo [100];

cant = PasarArreglo(vainas, Arreglo);

OrdenaArreglo (Arreglo, cant);

PasarArchivo(vainas,Arreglo,cant);

}

int PasarArreglo (char vainas [], estructura Arreglo[])                   // AUX   (CargaProducto)
{

int i = 0;

FILE * archi;

archi = fopen(vainas, "rb");

if (archi!=NULL){

// _________________________

estructura A;

while (fread(&A,sizeof(estructura),1,archi)>0 && i<100){

      Arreglo[i] = A;

      i++;

}

if (i>=100){

    printf("\n Problema en el arreglo, se necesitan mas celdas \n");
}

return i;

fclose(archi);

}

}

void OrdenaArreglo (estructura A [], int cant)                            // AUX   (CargaProducto)
{

int i = 0;

int PosMenor = 0;

estructura aux;

while (i<cant-1){

    PosMenor = PosicionMenor(A,cant,i);

    IntercambiaArreglo(A,PosMenor,i);

    i++;
}


}

void IntercambiaArreglo (estructura A[], int menor, int i)                // AUX   (CargaProducto)(OrdenaArreglo)
{

    estructura aux;

    aux = A[menor];

    A[menor] = A[i];

    A[i] = aux;


}

int PosicionMenor (estructura A[], int cant, int pos)                     // AUX   (CargaProducto) (OrdenaArreglo)
{

    int i = pos;

    int menor = i;

    estructura aux;

    aux = A[i];


    while(i<cant)
    {
        if(strcmpi(aux.nombre,A[i].nombre)>0)
        {
            aux = A[i];
            menor = i;

        }else{

            if(strcmpi(aux.nombre,A[i].nombre)==0 && aux.medida > A[i].medida){

            aux = A[i];
            menor = i;

            }

        }

        i++;
    }

    return menor;
}

void PasarArchivo (char vainas [], estructura Arreglo[], int cant)                   // AUX   (CargaProducto)
{

FILE * archi;

archi = fopen(vainas, "wb");

if (archi!=NULL){

// _________________________

estructura A;

int i = 0;

while (i<cant){

      fwrite(&Arreglo[i], sizeof(estructura),1,archi);

      i++;

}

fclose(archi);

}

}

void MuestraArreglo (estructura A[], int cant)                            // AUX
{
    int i=0;

    printf (" \t ARREGLO : \n \n");

    while(i<cant)
    {

    printf("   \t TIPO : Vaina %s \n",A[i].nombre);
    printf("   \t MEDIDA : %d cm \n", A[i].medida);
    printf("   \t PRECIO : $%.2f ($%.2f)\n", A[i].precio, A[i].precioCosto);
    printf("   \t STOCK : %d \n", A[i].stock);

    printf(" \n --------------------- \n\n ");

    i++;
}


}

int Busca (char vaina[], char palabra[])                                      // AUX (Modificar)
{

    FILE * archi;

    archi = fopen(vaina,"rb");

    int flag = 0 ;

    if (archi!=NULL){

// _____________________________

    estructura A;

    while (fread(&A,sizeof(estructura),1,archi)>0 && flag == 0){

        if (strcmpi(A.nombre,palabra)==0){

            flag = 1;

        }

    }

    fclose(archi);

    // _________________________

    }
    else {

        printf("\n El archivo NO se abrio correctamente, en 'busca' ! ");
    }

return flag;

}

void Modifica (char vainas[])                                                 /// PRINCIPAL
{

estructura A;
char palabra [30];
int flag = 0;
char resp = 's';

while (flag == 0 && resp == 's'){

printf("\n Ingrese producto que desea modificar : ");
fflush(stdin);
scanf("%s", &palabra);

flag = Busca(vainas,palabra);

if (flag == 0){

    printf("\n El producto NO existe \n");

    printf("\n Desea cargarlo de nuevo? s/n : ");
    fflush(stdin);
    scanf("%c", &resp);

}else{

    int cant = 0;

    int pos = 0;

    estructura Arreglo [100];

    cant = PasarArreglo(vainas,Arreglo);

    pos = BuscaCelda (Arreglo,palabra,cant);

    CambiaValor(Arreglo,pos);

    PasarArchivo(vainas,Arreglo,cant);

}

}

}

int BuscaCelda (estructura A[],char Palabra[],int cant)                       // AUX (Modificar)
{
    int i = 0;

    int j = 0;

    int flag = 0;

    int e = 0;

    int medida = 0;

    int pos = -1;

    char resp = 's';


    while (resp == 's'){ // por si la palabra es incorrecta

         i = 0;

    while (i < cant){          // busca por palabra

       if (strcmpi(A[i].nombre,Palabra)==0){

           MuestraUnoArreglo(A,i);

           pos = i;

           e++;

           resp = 'n';      // palabra encontrada, corta el while
       }

      i++;

    }

    if (e == 0){                // no lo encontro

        printf("\n Producto no encontrado, desea ingresarlo nuevamente? s/n : ");
        fflush(stdin);
        scanf("%c", &resp);

        if (resp == 's'){

             printf("\n Ingrese el producto : ");
             fflush(stdin);
             gets(Palabra);
        }

    }

    if (e > 1){

        resp = 'n';

        printf("\n Indique la medida del producto : ");
        scanf("%d", &medida);

        while (flag == 0){    // por si la medida ingresada es incorrecta

        while (j < cant && flag == 0){

            if ((strcmpi(A[j].nombre,Palabra)==0) && (A[j].medida == medida)){

                pos = j;

                flag = 1;
            }

            j++;

        }

        if (flag == 0 ){

            printf("\n Medida incorrecta, ingresela nuevamente : ");
            scanf("%d", &medida);

            j = 0;

        }

    }

    }

    }

return pos;

}

void CambiaValor (estructura A[],int pos)                                     // AUX (Modificar)
{

 char resp = 's';
 char palabra[30];
 int flag = 0 ;

 char tipo[] = {"tipo"};
 char medida[] = {"medida"};
 char precio[] = {"precio"};
 char precioCosto[] = {"precio costo"};
 char stock[] = {"stock"};

 while (resp == 's'){

 printf("\n Que elemento del producto desea cambiar ? : ");
 fflush(stdin);
 gets(palabra);

  if (strcmpi(palabra,tipo)==0){

    printf("\n Ingrese el nuevo nombre del producto : ");
    fflush(stdin);
    gets(&A[pos].nombre);

    flag = 1;

  }

  if (strcmpi(palabra,medida)==0){

    printf("\n Ingrese la nueva medida del producto : ");
    scanf("%d",&A[pos].medida);

    flag = 1;

  }

  if (strcmpi(palabra,precio)==0){

    printf("\n Ingrese el nuevo precio del producto : ");
    scanf("%f", &A[pos].precio);

    flag = 1;

  }

  if (strcmpi(palabra,precioCosto)==0){

    printf("\n Ingrese el nuevo precio de costo del producto : ");
    scanf("%f",&A[pos].precioCosto);

    flag = 1;

  }

  if (strcmpi(palabra,stock)==0){

    printf("\n Ingrese la cantidad de stock del producto : ");
    scanf("%d", &A[pos].stock);

    flag = 1;

  }

  if (flag == 0){

    printf("\n Palabra no encontrada \n");

  }

  MuestraUnoArreglo(A,pos);

  printf("\n Desea modificar otro elemento del producto ? s/n : ");
  fflush(stdin);
  scanf("%c",&resp);

  flag = 0;

 }

}

void MuestraUnoArreglo (estructura Arreglo[], int i)                            // AUX
{

    printf("\n --------------------------- \n");

    printf("   \t TIPO : Vaina %s \n",Arreglo[i].nombre);
    printf("   \t MEDIDA : %d cm \n", Arreglo[i].medida);
    printf("   \t PRECIO : $%.2f ($%.2f)\n", Arreglo[i].precio, Arreglo[i].precioCosto);
    printf("   \t STOCK : %d \n", Arreglo[i].stock);

    printf("\n --------------------------- \n");






}

void EliminarProducto (char vainas[])                                         /// PRINCIPAL
{

    estructura A[100];

    estructura aux[100];

    char producto[30];

    int cant = 0;

    int pos = 0;

    char control = 's';

    char pregunta = 's';


    while (control == 's'){

    cant = PasarArreglo(vainas,A);

    printf("\n Ingrese el producto que desea eliminar : ");
    fflush(stdin);
    gets(producto);

    pos = BuscaCelda(A,producto,cant);

    if (pos != -1){       // si encontro la palabra o no, o se arrepintio de borrar un producto

    printf("\n Esta seguro que desea borrar este producto? s/n : ");
    fflush(stdin);
    scanf("%c", &pregunta);

    if (pregunta == 's'){

    Eliminar(A,aux,cant,pos);

    OrdenaArreglo(aux,cant-1);     // cant -1 porque tiene un elemento menos (que fue eliminado)

    PasarArchivo(vainas,aux,cant-1);

    }

    }

        printf("\n Desea eliminar otro producto ? s/n : ");
        fflush(stdin);
        scanf("%c",&control);

    }

}

void Eliminar (estructura A[],estructura aux[], int cant, int pos)              // AUX (eliminarProducto)
{

int i = 0;

int j = 0;

while (i<cant){

    if (i != pos){

        aux[j] = A[i];

        j++;

    }

    i++;

}

}

void Vender (char vainas [])                                                  /// PRINCIPAL
{

char producto[30];

int cant = 0;

int pos = 0;

int stock = 0;

char control = 's';

char control2 = 's'; // para controlar si el estock ingresado no supera al que esta

estructura A [100];


cant = PasarArreglo(vainas,A);


while (control == 's'){ // por si la palabra que ingreso es incorrecta

printf("\n Ingrese el producto que desea vender : ");
fflush(stdin);
gets(producto);

pos = BuscaCelda2(A,producto,cant);

if (pos == -1){

    printf("\n Producto no encontrado \n ");

}
else{

    printf("\n Ingrese la cantidad de este producto que va a vender : ");
    scanf("%d", &stock);

    while (control2 == 's'){

    if (stock > A[pos].stock){

        printf("\n ERROR (Cantidad mayor a las disponibles)\n\n");

        printf("Ingrese el stock nuevamente : ");
        scanf("%d", &stock);

       }
       else {

            A[pos].stock = A[pos].stock - stock;

            control2 = 'x';

       }

    }
}

printf("\n Desea vender otro producto? s/n : ");
fflush(stdin);
scanf("%c", &control);

}

PasarArchivo(vainas,A,cant);

}

int  BuscaCelda2 (estructura A[], char Palabra[], int cant)
{

    int i = 0;

    int j = 0;

    int flag = 0;

    int e = 0;

    int medida = 0;

    int pos = -1;


    while (i < cant){          // busca por palabra

       if (strcmpi(A[i].nombre,Palabra)==0){

           MuestraUnoArreglo(A,i);

           pos = i;

           e++;

           }

      i++;

    }

    if (e > 1){

        printf("\n Indique la medida del producto : ");
        scanf("%d", &medida);

        while (flag == 0){    // por si la medida ingresada es incorrecta

        while (j < cant && flag == 0){   // Recorre de nuevo el arreglo

            if ((strcmpi(A[j].nombre,Palabra)==0) && (A[j].medida == medida)){   // Si el producto y la medida coincide retorna

                pos = j;

                flag = 1;
            }

            j++;

        }

        if (flag == 0 ){

            printf("\n Medida incorrecta, ingresela nuevamente : ");

            scanf("%d", &medida);

            printf("\n");

            j = 0;

        }

    }

    }

return pos;

}

void CrearContrasena (char contra [])
{

FILE * archi;

archi = fopen(contra, "wb");


char pass [30];

char resp = 'n';

int cant = 0;

int flag = 0;


if (archi!=NULL){

// ___________________________________

    while (resp == 'n'){

    flag = 0;

    while (flag == 0){

    printf("\n\n Ingrese una palabra como contraseña (minimo 4 letras): ");
    gets(pass);

    cant = strlen(pass);

    if (cant < 4){

        system("cls");

        printf("\n ERROR : Contrasenia menor a 4 caracteres");

        getch();

    }else{

        flag = 1;

        }

    }

    printf(" \n Confirma contraseña? s/n : ");
    fflush(stdin);
    scanf("%c", &resp);

    }
//printf("\n La contraseña es : %s", pass);
    fwrite(&pass, sizeof(char),1,archi);
//printf("\n La contraseña es : %s", pass);
}

fclose(archi);

}

void ComprobacionPass (char contra [])
{

FILE * archi;

archi = fopen(contra, "rb");

if (archi != NULL){

   char palabra [30];

   char pass [30];

   int flag = 0;

   fread(&pass,sizeof(char),1,archi);            // CONTRASEÑA ORIGINAL

    printf("PASS ORIGINAL : %s ", pass);

   while (flag == 0){

   printf("\n Ingrese la contraseña : ");        // CONTRASEÑA INGRESADA
   fflush(stdin);
   scanf("%s", &palabra);

   if (strcmpi(palabra,pass)==0){                         // COMPROBACION

      flag = 1;

      printf("\n Contraseña correcta ");

   }
   else{

     printf("\n Contraseña incorrecta, vuelva a intentarlo ");

     getch();

   }

   }

}
else{

    printf("\n ERROR: El archivo no contiene datos");

}

fclose(archi);

}

int ControlPass (char contra [])
{

FILE * archivo;

archivo = fopen(contra, "rb");

int flag = 0;


// _____________________________________


if (archivo != NULL){

    flag = 1;

    fclose(archivo);

}

return flag;

}

void leercontrasenia (char contra[])
{

    FILE * archi;

    archi = fopen(contra, "rb");

    char variable [30];

    if (archi != NULL){

        fread(&variable,sizeof(char),1,archi);

        printf("LA PASSWORD ES : %s", variable);

        getch();

    }

    fclose(archi);

}




