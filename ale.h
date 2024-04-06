#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();

void cls();
void titulo();
void comenzar(char primer_apellido[]);
void mensajeria(int estado);

int valinum(int ri, int rt, char msg[]);
void valitext(char text[]);



//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************//

int msges()
{ int op;
  printf("\n");
  printf ("   M  E   N   U \n");
  printf("1.- OBTENER CURP \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
  return op;
}

//****************

void menu()
{
    int op;
    char primer_apellido[100];
    char segundo_apellido[100];
    char primer_nombre[100];
    char segundo_nombre[100];
    char tercer_nombre[100];
    int ent_fed;
    int municipio;
    int dia_nac;
    int mes_nac;
    int anio_nac;

  do{
      op=msges();
      switch (op)
      {
        case 1:
        comenzar(primer_apellido);
              break;
      }

    }while (op != 0);


}

//*********************//

void cls()
{
    system("cls");
}

//*********************//

void pause()
{
    system("pause");
}

//*********************//

void comenzar(char primer_apellido[])
{
    cls();
    titulo();
    mensajeria(0);
    pause();

    cls();
    titulo();
    mensajeria(1);
    
    valitext(primer_apellido);

}


//*********************//

int valinum(int ri, int rt, char msg[])
{
    int num;
    char xnum[30];

    do
    {
        puts(msg);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
    } while (num < ri || num > rt);

    return num;
    
    //ej: cal1 = valinum(0,100, "calif 1:");
}


void valitext(char text[]) {
    int valido = 0;

    do {
        valido = 1;
        
        printf(" -> : ");
        gets(text);

        

        // Verificamos si el texto contiene espacios en blanco al inicio o al final
        if (isspace(text[0]) || isspace(text[strlen(text) - 1])) {
            printf("\nEl texto no puede contener espacios en blanco al inicio o al final.\n");
            valido = 0;
            break;
        }

        // Si el texto es válido y excede el tamaño del búfer, mostramos un mensaje de advertencia
        if (valido && strlen(text) >= 100) {
            printf("\nEl texto excede el tamaño máximo permitido. Por favor, ingréselo nuevamente.\n");
            valido = 0;
            break;
        }
        
    } while (!valido); // Repetimos hasta que el texto sea válido
}



//*********************//

void titulo()
{
    printf("\n");
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("|                                                                                             |\n");
    printf("|                                    O B T E N E R    C U R P                                 |\n");
    printf("|                                                                                             |\n");
    printf("|-------------------------------------------------------------------------------------------- |\n");

}


void mensajeria(int estado)
{

    switch(estado)
    {
        case 0:
            printf("|-------------------------------------------------------------------------------------------- |\n");
            printf("|                                                                                             |\n");
            printf("| Con el siguiente programa podr%cs obtener tu CURP, se necesita tu informaci%cn confidencial,  |\n", 160, 162);
            printf("| si est%cs de acuerdo PRESIONA ENTER.                                                         |\n", 160);
            printf("|                                                                                             |\n");
            printf("|-------------------------------------------------------------------------------------------- |\n");
            printf("\n\n");
        break;

        case 1:
            printf("|-------------------------------------------------------------------------------------------- |\n");
            printf("|                                                                                             |\n");
            printf("| Introduce tu PRIMER APELLIDO                                                                |\n");
            printf("|                                                                                             |\n");
            printf("|-------------------------------------------------------------------------------------------- |\n");
        break;
    }

}
