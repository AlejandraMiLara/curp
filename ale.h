#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();

void cls();
void titulo();
void comenzar(char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char fecha[], int cod_estado, char estado[]);
void mensajeria(int estado);

int valifecha(char num[]);
int valitext(char text[]);
void valiestado(int cod_estado, char estado[]);



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

    // Limpiar el bufer
    while (getchar() != '\n');

    return op;
}


//****************

void menu()
{
    int op;
    char curp[18];
    char primer_apellido[100];
    char segundo_apellido[100];
    char primer_nombre[100];
    char segundo_nombre[100];
    int cod_estado;
    char estado[10];
    int municipio;
    char fecha[11] = "00/00/0000";

  do{
      op=msges();
      switch (op)
      {
        case 1:
            comenzar(primer_apellido, segundo_apellido, primer_nombre, segundo_nombre, fecha, cod_estado, estado);
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

void comenzar(char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char fecha[], int cod_estado, char estado[])
{

/*
    cls();
    titulo();
    mensajeria(0);
    pause();

    cls();
    titulo();
    mensajeria(1);
    valitext(primer_apellido);

    cls();
    titulo();
    mensajeria(2);
    valitext(segundo_apellido);

    cls();
    titulo();
    mensajeria(3);
    valitext(primer_nombre);

    cls();
    titulo();
    mensajeria(4);
    valitext(segundo_nombre);

    cls();
    titulo();
    mensajeria(5);
    valifecha(fecha);

*/

    cls();
    titulo();
    mensajeria(6);
    valiestado(cod_estado, estado);




}


//*********************//

void valiestado(int cod_estado, char estado[])
{
    int valido = 0;

    do {
        valido = 1;
        printf(" -> : ");

        if (scanf("%d", &cod_estado) != 1 || cod_estado < 1 || cod_estado > 33)
        {
            printf("\nCodigo de estado no valido. Debe ser un numero del 1 al 33.\n");
            valido = 0;
        }
        else
        {
            switch (cod_estado)
            {
                case 1:
                    strcpy(estado, "AS");
                    break;
                case 2:
                    strcpy(estado, "BC");
                    break;
                case 3:
                    strcpy(estado, "BS");
                    break;
                case 4:
                    strcpy(estado, "CC");
                    break;
                case 5:
                    strcpy(estado, "CL");
                    break;
                case 6:
                    strcpy(estado, "CM");
                    break;
                case 7:
                    strcpy(estado, "CS");
                    break;
                case 8:
                    strcpy(estado, "CH");
                    break;
                case 9:
                    strcpy(estado, "DF");
                    break;
                case 10:
                    strcpy(estado, "DG");
                    break;
                case 11:
                    strcpy(estado, "GT");
                    break;
                case 12:
                    strcpy(estado, "GR");
                    break;
                case 13:
                    strcpy(estado, "HG");
                    break;
                case 14:
                    strcpy(estado, "JC");
                    break;
                case 15:
                    strcpy(estado, "MC");
                    break;
                case 16:
                    strcpy(estado, "MN");
                    break;
                case 17:
                    strcpy(estado, "MS");
                    break;
                case 18:
                    strcpy(estado, "NT");
                    break;
                case 19:
                    strcpy(estado, "NL");
                    break;
                case 20:
                    strcpy(estado, "OC");
                    break;
                case 21:
                    strcpy(estado, "PL");
                    break;
                case 22:
                    strcpy(estado, "QT");
                    break;
                case 23:
                    strcpy(estado, "QR");
                    break;
                case 24:
                    strcpy(estado, "SP");
                    break;
                case 25:
                    strcpy(estado, "SL");
                    break;
                case 26:
                    strcpy(estado, "SR");
                    break;
                case 27:
                    strcpy(estado, "TC");
                    break;
                case 28:
                    strcpy(estado, "TS");
                    break;
                case 29:
                    strcpy(estado, "TL");
                    break;
                case 30:
                    strcpy(estado, "VZ");
                    break;
                case 31:
                    strcpy(estado, "YN");
                    break;
                case 32:
                    strcpy(estado, "ZS");
                    break;
                case 33:
                    strcpy(estado, "NE");
                    break;
            }
        }

        while (getchar() != '\n');

    } while (!valido);

}



//*********************//

int valifecha(char fecha[]) {
    int valido = 0;

    do {
        valido = 1;
        printf(" -> : ");

        if (!fgets(fecha, 11, stdin)) {
            printf("\nError al leer la entrada.\n");
            valido = 0;
        }

        int longitud = strlen(fecha);

        if (fecha[longitud - 1] == '\n') {
            fecha[longitud - 1] = '\0';
        }

        // Verificar el formato 
        if (longitud != 10 || fecha[2] != '/' || fecha[5] != '/') {
            printf("\nFormato de fecha incorrecto. Debe ser XX/XX/XXXX.\n");
            valido = 0;
        }

        // Verificar si la fecha contiene solo numeros
        for (int i = 0; i < 10; i++) {
            if (i != 2 && i != 5 && (fecha[i] < '0' || fecha[i] > '9')) {
                printf("\nLa fecha debe contener solo números. \n");      
                valido = 0;
                break;
            }
        }

        // Obtener el día, mes y año como enteros
        int dia = (fecha[0] - '0') * 10 + (fecha[1] - '0');
        int mes = (fecha[3] - '0') * 10 + (fecha[4] - '0');

        int anio = atoi(fecha + 6);

        // Verificar dias
        if (dia < 1 || dia > 31) {
            printf("\nEl dia debe estar en el rango del 01 al 31.\n");
            valido = 0;
            break;
        }

        // Verificar mes
        if (mes < 1 || mes > 12) {
            printf("\nEl mes debe estar en el rango del 01 al 12.\n");
            valido = 0;
            break;
        }

        // Verificar año
        if (anio < 1900 || anio > 2024) {
            printf("\nEl a%co debe estar en el rango de 1900 a 2024.\n", 164);
            valido = 0;
            break;
        }

    } while (!valido);

    return 1;
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
            printf("\nError al leer la entrada.\n");
            valido = 0;
        }

        int longitud = strlen(text);

        // Eliminar el caracter de nueva linea si existe
        if (text[longitud - 1] == '\n') {
            text[longitud - 1] = '\0';
        }

        // Verificar si el texto contiene espacios en blanco al inicio o al final
        if (isspace(text[0]) || isspace(text[longitud - 1])) {
            printf("\nEl texto no puede contener espacios en blanco al inicio o al final.\n");
            valido = 0;
        }

        // Verificar si el texto contiene caracteres no permitidos
        for (int i = 0; text[i] != '\0'; i++) {
            if (!(isalpha(text[i]) || text[i] == ' ' || text[i] == enie_min || text[i] == enie_may )) {
                printf("\nCaracter no permitido. Intentalo de nuevo.\n");
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
            printf("| AVISO: Solo puedes ingresar letras de la A-Z                                                |\n");
            printf("|-------------------------------------------------------------------------------------------- |\n");
        break;

        case 2:
            printf("|-------------------------------------------------------------------------------------------- |\n");
            printf("|                                                                                             |\n");
            printf("| Introduce tu SEGUNDO APELLIDO                                                               |\n");
            printf("| AVISO: Solo puedes ingresar letras de la A-Z                                                |\n");
            printf("|-------------------------------------------------------------------------------------------- |\n");
        break;

        case 3:
            printf("|-------------------------------------------------------------------------------------------- |\n");
            printf("|                                                                                             |\n");
            printf("| Introduce tu PRIMER NOMBRE                                                                  |\n");
            printf("| AVISO: Solo puedes ingresar letras de la A-Z                                                |\n");
            printf("|-------------------------------------------------------------------------------------------- |\n");
        break;

        case 4:
            printf("|-------------------------------------------------------------------------------------------- |\n");
            printf("|                                                                                             |\n");
            printf("| Introduce tu SEGUNDO NOMBRE                                                                 |\n");
            printf("| AVISO: Si tienes mas de dos nombres, en esta captura introduce todos juntos.                |\n");
            printf("|-------------------------------------------------------------------------------------------- |\n");
        break;

        case 5:
            printf("|-------------------------------------------------------------------------------------------- |\n");
            printf("|  Introduce tu FECHA de nacimiento:                                                          |\n");
            printf("|  FORMATO VALIDO: XX/XX/XXXX                                                                 |\n");
            printf("|  AVISO: Solo puedes ingresar numeros y el diagonal                                          |\n");
            printf("|-------------------------------------------------------------------------------------------- |\n");
        break;

        case 6:
            printf("|-------------------------------------------------------------------------------------------- |\n");
            printf("|     Ingresa el CODIGO del ESTADO    |   Estado                                              |\n");
            printf("|-------------------------------------------------------------------------------------------- |\n");
            printf("|   01                               |   Aguascalientes                                       |\n");
            printf("|   02                               |   Baja California                                      |\n");
            printf("|   03                               |   Baja California Sur                                  |\n");
            printf("|   04                               |   Campeche                                             |\n");
            printf("|   05                               |   Coahuila de Zaragoza                                 |\n");
            printf("|   06                               |   Colima                                               |\n");
            printf("|   07                               |   Chiapas                                              |\n");
            printf("|   08                               |   Chihuahua                                            |\n");
            printf("|   09                               |   Ciudad de Mexico                                     |\n");
            printf("|   10                               |   Durango                                              |\n");
            printf("|   11                               |   Guanajuato                                           |\n");
            printf("|   12                               |   Guerrero                                             |\n");
            printf("|   13                               |   Hidalgo                                              |\n");
            printf("|   14                               |   Jalisco                                              |\n");
            printf("|   15                               |   Mexico                                               |\n");
            printf("|   16                               |   Michoacan de Ocampo                                  |\n");
            printf("|   17                               |   Morelos                                              |\n");
            printf("|   18                               |   Nayarit                                              |\n");
            printf("|   19                               |   Nuevo Leon                                           |\n");
            printf("|   20                               |   Oaxaca                                               |\n");
            printf("|   21                               |   Puebla                                               |\n");
            printf("|   22                               |   Queretaro                                            |\n");
            printf("|   23                               |   Quintana Roo                                         |\n");
            printf("|   24                               |   San Luis Potosi                                      |\n");
            printf("|   25                               |   Sinaloa                                              |\n");
            printf("|   26                               |   Sonora                                               |\n");
            printf("|   27                               |   Tabasco                                              |\n");
            printf("|   28                               |   Tamaulipas                                           |\n");
            printf("|   29                               |   Tlaxcala                                             |\n");
            printf("|   30                               |   Veracruz de Ignacio de la Llave                      |\n");
            printf("|   31                               |   Yucatan                                              |\n");
            printf("|   32                               |   Zacatecas                                            |\n");
            printf("|   33                               |   Nacido en el Extranjero                              |\n");
            printf("|-------------------------------------------------------------------------------------------- |\n");
        break;
    }

}

