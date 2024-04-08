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
int valitext(char text[]);



//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************//

int msges()
{ 
    int op;
    printf("\n");
    printf ("   M  E   N   U \n");
    printf("1.- OBTENER CURP \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf ("%d",&op);

    // Limpiar el búfer
    while (getchar() != '\n');

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
    printf("%s", primer_apellido);


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


int valitext(char text[]) {
    int valido = 0;

    do {
        valido = 1;

        char a_t_min = 160;
        char e_t_min = 130;
        char i_t_min = 161;
        char o_t_min = 162;
        char u_t_min = 163;

        char a_t_may = 181;
        char e_t_may = 144;
        char i_t_may = 214;
        char o_t_may = 224;
        char u_t_may = 233;

        char enie_min = 164;
        char enie_may = 165;

        char x_may = 88;

        //char vocales_acent_min[] = {160, 130, 161, 162, 163};
        //char vocales_acent_may[] = {181, 144, 214, 224, 233};
        char vocales_min[] = {'a', 'e', 'i', 'o', 'u'};
        char vocales_may[] = {'A', 'E', 'I', 'O', 'U'};
        
        printf(" -> : ");
        if (!fgets(text, 100, stdin)) {
            // Error al leer la entrada
            printf("\nError al leer la entrada. Inténtalo de nuevo.\n");
            valido = 0;
        }

        int longitud = strlen(text);

        // Eliminar el caracter de nueva linea si existe
        if (text[longitud - 1] == '\n') {
            text[longitud - 1] = '\0';
        }

        // Verificar longitud
        if (longitud == 0 || longitud > 100) {
            printf("\nEl texto no puede estar vacio o exceder los 100 caracteres.\n");
            valido = 0;
        }

        // Verificar si el texto contiene espacios en blanco al inicio o al final
        if (isspace(text[0]) || isspace(text[longitud - 1])) {
            printf("\nEl texto no puede contener espacios en blanco al inicio o al final.\n");
            valido = 0;
        }

        // Verificar si el texto contiene caracteres no permitidos
        for (int i = 0; text[i] != '\0'; i++) {
            if (!(isalpha(text[i]) || text[i] == ' ' || text[i] == enie_min || text[i] == enie_may )) {
                printf("\nCaracter no permitido. Inténtalo de nuevo.\n");
                valido = 0;
                break;
            }
        }

        // Cambios
        for (int i = 0; text[i] != '\0'; i++) {
            //De tildes
            if (text[i] == a_t_min || text[i] == a_t_may)
            {
                    text[i] = vocales_may[0];
            }

            if (text[i] == e_t_min || text[i] == e_t_may)
            {
                    text[i] = vocales_may[1];
            }
            
            if (text[i] == i_t_min || text[i] == i_t_may)
            {
                    text[i] = vocales_may[2];
            }

            if (text[i] == o_t_min || text[i] == o_t_may)
            {
                text[i] = vocales_may[3];
            }

            if (text[i] == u_t_min || text[i] == u_t_may)
            {
                    text[i] = vocales_may[4];
            }

            //De x
            if (text[i] == enie_min || text[i] == enie_may) {
                text[i] = x_may;
            }
        }

        // Mayusculas
        for (int i = 0; text[i] != '\0'; i++) {
            text[i] = toupper(text[i]);
        }
              
    } while (!valido); 

    return 1;
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

