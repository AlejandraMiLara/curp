// CYNDY ALEJANDRA MIRANDA LARA
// DESC: CURP
// Fecha: 04 de abril TERMINADO: 14 de abril
// CAML_ACT09_3-4.cpp

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/***********************************************
 *                                               *
 *                                               *
 *                PROTOTIPOS                     *
 *                                               *
 *                                               *
 ***********************************************/


// Funciones de limpieza y presentacion
void cls();
void pause();
void titulo();
void mensajeria(int estado);

// Funciones vali
int valifecha(char num[]);
int valitext(char text[]);
void valiestado(int cod_estado, char estado[]);
void valisexo(int cod_sexo, char sexo[]);

// Funciones especificas
void cat_die(char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char cat_die_i[]);
void diescisiete(char fecha[], char diescisiete_i[]);
void diesciocho(char fecha[], char diesciocho_i[]);
char retorna_consonante_interna(char text[]);
char retorna_vocal_interna(char text[]);

// Funciones de excepciones y verificaciones
int excepcion_mariajose(char primer_nombre[]);
int excepcion_compuestos(char primer_apellido[], char segundo_apellido[], char primer_nombre[]);
int excepcion_altisonantes(char curp[]);
int verifica_vacio(char text[]);
int verifica_vocal_interna(char text[]);

// Funciones principales
void menu();
int msges();
void comenzar(char curp[], char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char fecha[], int cod_estado, char estado[], int cod_sexo, char sexo[], char cat_die_i[], char diescisiete_i[], char diesciocho_i[]);
void genera_curp(char curp[], char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char fecha[], int cod_estado, char estado[], int cod_sexo, char sexo[], char cat_die_i[], char diescisiete_i[], char diesciocho_i[]);
void imprimir_curp(char curp[]);



/***********************************************
 *                                               *
 *                                               *
 *          DESARROLLO DE FUNCIONES              *
 *                                               *
 *                                               *
 ***********************************************/

/***********************************************
 * Funciones de limpieza y presentacion         *
 ***********************************************/

void cls()
{
    system("cls");
}


void pause()
{
    system("pause");
}


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

    switch (estado)
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
        printf("|   Introduce tu PRIMER APELLIDO                                                              |\n");
        printf("|   AVISO: Solo puedes ingresar letras de la A-Z, punto (.), diagonal (/),                    |\n");
        printf("|           guion (-), apostrofe ('), para el dieresis introduce X.                           |\n");
        printf("|-------------------------------------------------------------------------------------------- |\n");
        break;

    case 2:
        printf("|-------------------------------------------------------------------------------------------- |\n");
        printf("|   Introduce tu SEGUNDO APELLIDO                                                             |\n");
        printf("|   AVISO: Solo puedes ingresar letras de la A-Z, punto (.), diagonal (/),                    |\n");
        printf("|           guion (-), apostrofe ('), para el dieresis introduce X.                           |\n");
        printf("|-------------------------------------------------------------------------------------------- |\n");
        break;

    case 3:
        printf("|-------------------------------------------------------------------------------------------- |\n");
        printf("|   Introduce tu PRIMER NOMBRE                                                                |\n");
        printf("|   AVISO: Solo puedes ingresar letras de la A-Z, punto (.), diagonal (/),                    |\n");
        printf("|           guion (-), apostrofe ('), para el dieresis introduce X.                           |\n");
        printf("|-------------------------------------------------------------------------------------------- |\n");
        break;

    case 4:
        printf("|-------------------------------------------------------------------------------------------- |\n");
        printf("|   Introduce tu SEGUNDO NOMBRE                                                               |\n");
        printf("|   AVISO: -Solo puedes ingresar letras de la A-Z, punto (.), diagonal (/),                   |\n");
        printf("|           guion (-), apostrofe ('), para el dieresis introduce X.                           |\n");
        printf("|          -En caso de tener mas de dos nombres, introducir en este apartado todos juntos.    |\n");
        printf("|-------------------------------------------------------------------------------------------- |\n");
        break;

    case 5:
        printf("|-------------------------------------------------------------------------------------------- |\n");
        printf("|  Introduce tu FECHA de nacimiento:                                                          |\n");
        printf("|  FORMATO VALIDO: DD/MM/AAAA                                                                 |\n");
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

    case 7:
        printf("|-------------------------------------------------------------------------------------------- |\n");
        printf("|                                                                                             |\n");
        printf("|  Introduce tu SEXO:                                                                         |\n");
        printf("|  - 01: PARA MUJER  02: HOMBRE  -                                                            |\n");
        printf("|-------------------------------------------------------------------------------------------- |\n");
        break;

    }
}


/***********************************************
 * Funciones vali                              *
 ***********************************************/

/**
 * Valida la entrada de una fecha en el formato DD/MM/AAAA.
 * 
 * Se solciita  una fecha y verifica que 
 * cumpla con el formato y los rangos validos
 *
 */

int valifecha(char fecha[])
{
    int valido = 0;

    do
    {
        valido = 1;
        printf(" -> : ");

        if (!fgets(fecha, 11, stdin))
        {
            printf("\nError al leer la entrada.\n");
            valido = 0;
        }

        int longitud = strlen(fecha);

        if (fecha[longitud - 1] == '\n')
        {
            fecha[longitud - 1] = '\0';
        }

        if (longitud != 10 || fecha[2] != '/' || fecha[5] != '/')
        {
            printf("\nFormato de fecha incorrecto. Debe ser DD/MM/AAAA.\n");
            valido = 0;
            continue;
        }

        int dia = atoi(fecha);
        int mes = atoi(fecha + 3);
        int anio = atoi(fecha + 6);

        if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1900 || anio > 2024)
        {
            printf("\nFecha fuera de rango. Introduce una fecha valida.\n");
            valido = 0;
        }

    } while (!valido);

    return 1;
}


/**
 * 
 *Valida una cadena ingresada
 *Verifica que la cadena ingresada no contenga caracteres
 *no permitidos, espacios en blanco al inicio o al final, y transforma
 *caracteres con tilde en su equivalente sin ellos
 *
 */

int valitext(char text[])
{
    int valido = 0;

    do
    {
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

        char punto = 46;
        char diagonal = 47;
        char guion = 45;
        char apost = 39;

        // char vocales_acent_min[] = {160, 130, 161, 162, 163};
        // char vocales_acent_may[] = {181, 144, 214, 224, 233};
        char vocales_min[] = {'a', 'e', 'i', 'o', 'u'};
        char vocales_may[] = {'A', 'E', 'I', 'O', 'U'};

        printf(" -> : ");
        if (!fgets(text, 100, stdin))
        {
            printf("\nError al leer la entrada.\n");
            valido = 0;
        }

        int longitud = strlen(text);

        // Eliminar el caracter de nueva linea si existe
        if (text[longitud - 1] == '\n')
        {
            text[longitud - 1] = '\0';
        }

        // Verificar si el texto contiene espacios en blanco al inicio o al final
        if (isspace(text[0]) || isspace(text[longitud-1]))
        {
            printf("\nEl texto no puede contener espacios en blanco al inicio o al final.\n");
            valido = 0;
        }

        // Verificar si el texto contiene caracteres no permitidos
        for (int i = 0; text[i] != '\0'; i++)
        {
            if (!(isalpha(text[i]) || text[i] == ' ' || text[i] == enie_min || text[i] == enie_may || text[i] == '.' || text[i] == '/' || text[i] == '-' || text[i] == '\''))
            {
                printf("\nCaracter no permitido. Intentalo de nuevo.\n");
                valido = 0;
                break;
            }
        }

        // Cambios
        for (int i = 0; text[i] != '\0'; i++)
        {
            // De tildes
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

            // De x
            if (text[i] == enie_min || text[i] == enie_may|| text[i] == punto || text[i] == diagonal || text[i] == guion || text[i] == apost )
            {
                text[i] = x_may;
            }
        }

        // Mayusculas
        for (int i = 0; text[i] != '\0'; i++)
        {
            text[i] = toupper(text[i]);
        }

    } while (!valido);

    return 1;
}


/**
 * Valida un codigo de estado ingresado por el usuario
 * Verifica que el codigo de estado ingresado sea un numero
 * valido del 1 al 33 y asigna el codigo a estado[]
 */


void valiestado(int cod_estado, char estado[])
{
    int valido = 0;

    do
    {
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


/**
 * Valida un codigo de sexo ingresado
 * Verifica que el codigo de sexo ingresado sea 1 para MUJER o 2 para HOMBRE
 * y asigna el codigo en sexo[]
 */


void valisexo(int cod_sexo, char sexo[])
{
    int valido = 0;

    do
    {
        valido = 1;
        printf(" -> : ");

        if (scanf("%d", &cod_sexo) != 1 || (cod_sexo != 1 && cod_sexo != 2))
        {
            printf("\nCodigo de sexo no valido. Debe ser: 1 para MUJER y 2 para HOMBRE.\n");
            valido = 0;
        }
        else
        {
            switch (cod_sexo)
            {
            case 1:
                strcpy(sexo, "M");
                break;

            case 2:
                strcpy(sexo, "H");
                break;
            }
        }

        while (getchar() != '\n');

    } while (!valido);
}


/***********************************************
 * Funciones especificas                        *
 ***********************************************/

/**
 * Genera las primeras consonantes internas de los apellidos y nombres ingresados
 * Busca la primera consonante interna de cada componente (apellido paterno, apellido materno y nombre)
 * En caso de no encontrar consonantes internas se asigna una X
 */


void cat_die(char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char cat_die_i[])
{
    int long_pa = strlen(primer_apellido);
    int long_sa = strlen(segundo_apellido);
    int long_pn = strlen(primer_nombre);

    for (int i = 1; i < long_pa; i++)
    {
        if (primer_apellido[i] != 'A' && primer_apellido[i] != 'E' && primer_apellido[i] != 'I' && primer_apellido[i] != 'O' && primer_apellido[i] != 'U')
        {
            cat_die_i[0] = primer_apellido[i];
            break;
        }

        cat_die_i[0] = 'X';
    }

    for (int i = 1; i < long_sa; i++)
    {
        if (segundo_apellido[i] != 'A' && segundo_apellido[i] != 'E' && segundo_apellido[i] != 'I' && segundo_apellido[i] != 'O' && segundo_apellido[i] != 'U')
        {
            cat_die_i[1] = segundo_apellido[i];
            break;
        }

        cat_die_i[1] = 'X';
    }

    for (int i = 1; i < long_pn; i++)
    {

        // Verificar si el primer nombre está en la lista de excepciones para usar el segundo nombre
        if (excepcion_mariajose(primer_nombre))
        {

            if (segundo_nombre[i] != 'A' && segundo_nombre[i] != 'E' && segundo_nombre[i] != 'I' && segundo_nombre[i] != 'O' && segundo_nombre[i] != 'U')
            {
                cat_die_i[2] = segundo_nombre[i];
                break;
            }

            cat_die_i[2] = 'X';
        }


        if (primer_nombre[i] != 'A' && primer_nombre[i] != 'E' && primer_nombre[i] != 'I' && primer_nombre[i] != 'O' && primer_nombre[i] != 'U')
        {
            cat_die_i[2] = primer_nombre[i];
            break;
        }

        cat_die_i[2] = 'X';
    }
}


/**
 * Genera el digito correspondiente al año de nacimiento
 * Asigna A si el año de nacimiento esta entre 2000 y 2010
 * B si esta entre 2011 y 2020 y C si esta entre 2021 y 2030
 * Si el año de nacimiento es anterior a 2000 o posterior a 2030 se asigna 0 en su lugar
 */


void diescisiete(char fecha[], char diescisiete_i[]) {
    int anio = atoi(fecha + 6);

    if (anio <= 1999 || anio >= 1900) 
    {
        diescisiete_i[0] = '0';
    }

    if (anio <= 2024 || anio > 1999) 
    {
        if (anio >= 2000 && anio <= 2010) 
        {
            diescisiete_i[0] = 'A';
        }

        if (anio >= 2011 && anio <= 2020) 
        {
            diescisiete_i[0] = 'B';
        }

        if (anio >= 2021 && anio <= 2030) 
        {
            diescisiete_i[0] = 'C';
        }
    }
}


/**
 * Genera el digito correspondiente al año de nacimiento para la posicion 18 del CURP
 * Si el año de nacimiento es anterior a 2000 se asigna 0
 * si es 2000 se asigna 1 y se incrementa en 1 por cada 5 años desps del 2000
 */


void diesciocho(char fecha[], char diesciocho_i[])
{
    int anio = atoi(fecha + 6);

    if (anio < 2000)
    {
        diesciocho_i[0] = '0';
    }

    else
    {
        // Calcular el valor basado en la diferencia del año actual con 2000
        int valor = (anio - 2000) / 5 + 1;
        
        diesciocho_i[0] = valor + '0';
    }
}


//*********************//

char retorna_consonante_interna(char text[])
{
    char consonante = '\0';
    const char vocales[] = "AEIOU";

    for (int i = 1; text[i] != '\0'; i++)
    {
        int es_vocal = 0;

        for (int j = 0; vocales[j] != '\0'; j++)
        {
            if (text[i] == vocales[j])
            {
                es_vocal = 1;
                break;
            }
        }

        if (!es_vocal && isalpha(text[i]))
        {
            consonante = text[i];
            break;
        }
    }

    return consonante;
}


//*********************//

char retorna_vocal_interna(char text[])
{
    char vocal_interna = '\0';
    char vocales[] = "AEIOU";

    for (int i = 1; text[i] != '\0'; i++)
    {
        int es_consonante = 1;

        for (int j = 0; vocales[j] != '\0'; j++)
        {
            if (text[i] == vocales[j])
            {
                es_consonante = 0;
                break;
            }
        }

        if (!es_consonante && isalpha(text[i]))
        {
            vocal_interna = text[i];
            break;
        }
    }

    return vocal_interna;
}




/***********************************************
 * Funciones de excepcion y verificacion        *
 ***********************************************/

//*********************//

int excepcion_mariajose(char texto[])
{
    char excepciones[][10] = {"MARIA", "MARXA", "MA.", "MA", "M.", "M", "JOSE", "JOSX", "J.", "J"};
    int num_excepciones = 10;

    for (int i = 0; i < num_excepciones; i++)
    {
        if (strcmp(texto, excepciones[i]) == 0)
        {
            return 1; // excepcion encontrada
        }
    }

    return 0; // no es una excepcion
}


//*********************//

int excepcion_compuestos(char texto[])
{
    char excepciones[][20] = {"DA", "LOS", "LA","DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "Y", "EL", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON"};
    int num_excepciones = sizeof(excepciones) / sizeof(excepciones[0]);

    for (int i = 0; i < num_excepciones; i++)
    {
        if (strcmp(texto, excepciones[i]) == 0)
        {
            return 1; // excepcion encontrada
        }
    }

    return 0; // no es una excepcion
}


//*********************//

int excepcion_altisonantes(char curp[])
{
    char lista[][5] = {
        "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO",
        "COGE", "COJA", "COJE", "COJI", "COJO", "CULO", "FETO", "GUEY",
        "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KOGE", "KOJO", "KAKA",
        "KULO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MION", "MOCO",
        "MULA", "PEDA", "PEDO", "PENE", "PUTA", "PUTO", "QULO", "RATA",
        "RUIN"
    };

    int num_palabras = sizeof(lista) / sizeof(lista[0]);

    for (int i = 0; i < num_palabras; i++)
    {
        if (strncmp(curp, lista[i], 4) == 0)
        {
            return 1; // Es una palabra altisonante
        }
    }

    return 0; // No es una palabra altisonante
}



//*********************//

int verifica_vacio(char text[])
{
    int longitud = strlen(text);

    if(longitud == 0)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}


//*********************//

int verifica_vocal_interna(char text[])
{
    char vocales[] = "AEIOU";
    int i, j;

    for (i = 1; text[i] != '\0'; i++) {
        for (j = 0; vocales[j] != '\0'; j++) {
            if (text[i] == vocales[j]) {
                return 1;
            }
        }
    }
    return 0;
}



/***********************************************
 * Funciones principales                        *
 ***********************************************/

//****************

void menu()
{
    int op;
    char curp[20];
    char primer_apellido[100];
    char segundo_apellido[100];
    char primer_nombre[100];
    char segundo_nombre[100];
    char fecha[11] = "00/00/0000";
    int cod_estado;
    char estado[10];
    int cod_sexo;
    char sexo[2];
    char cat_die_i[4];
    char diescisiete_i[5];
    char diesciocho_i[5];


    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            comenzar(curp, primer_apellido, segundo_apellido, primer_nombre, segundo_nombre, fecha, cod_estado, estado, cod_sexo, sexo, cat_die_i, diescisiete_i, diesciocho_i);
            break;
        }

    } while (op != 0);
}


//****************

int msges()
{
    int op;
    printf("\n");
    printf("   M  E   N   U \n");
    printf("1.- OBTENER CURP \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);

    while (getchar() != '\n');

    return op;
}


//****************

void comenzar(char curp[], char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char fecha[], int cod_estado, char estado[], int cod_sexo, char sexo[], char cat_die_i[], char diescisiete_i[], char diesciocho_i[])
{

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

    cls();
    titulo();
    mensajeria(6);
    valiestado(cod_estado, estado);

    cls();
    titulo();
    mensajeria(7);
    valisexo(cod_sexo, sexo);

    cat_die(primer_apellido, segundo_apellido, primer_nombre, segundo_nombre, cat_die_i); 
    diescisiete(fecha, diescisiete_i);
    diesciocho(fecha, diesciocho_i);

    genera_curp(curp, primer_apellido, segundo_apellido, primer_nombre, segundo_nombre, fecha, cod_estado, estado, cod_sexo, sexo, cat_die_i, diescisiete_i, diesciocho_i);
    
    cls();
    titulo();
    imprimir_curp(curp);


    pause();
}


//*********************//

void genera_curp(char curp[], char primer_apellido[], char segundo_apellido[], char primer_nombre[], char segundo_nombre[], char fecha[], int cod_estado, char estado[], int cod_sexo, char sexo[], char cat_die_i[], char diescisiete_i[], char diesciocho_i[])
{
    
    //POSICION 0 Y 1
    //corresponde a los dos primeros elementos del primer apellido

    if(!verifica_vacio(primer_apellido))
    {
        // Identificar posiciones vacias en el apellido compuesto
        int posiciones_vacias_apellido[10];
        int cont = 0;

        for (int i = 0; primer_apellido[i] != '\0'; i++)
        {
            if (primer_apellido[i] == ' ')
            {
                posiciones_vacias_apellido[cont] = i;
                cont++;
            }
        }

        // Si hay posiciones vacias es compuesto
        if (cont > 0)
        {
            int inicio = 0;
            char apellido_parte[100] = {0}; 

            // Dividir el apellido en partes basadas en las posiciones vacias
            for (int i = 0; i <= cont; i++)
            {
                int fin;
                if (i == cont)
                {
                    fin = strlen(primer_apellido);
                }
                else
                {
                    fin = posiciones_vacias_apellido[i];
                }

                // Copiando
                for(int j = inicio; j < fin; j++)
                {
                    apellido_parte[j - inicio] = primer_apellido[j];
                }

                // Añadir el caracter nulo
                apellido_parte[fin - inicio] = '\0';

                // Verificar
                if (!excepcion_compuestos(apellido_parte))
                {
                    
                    if (!verifica_vocal_interna(apellido_parte))
                    {
                        curp[0] = apellido_parte[0];
                        curp[1] = 'X';
                    }
                    else
                    {
                        // Copiar los primeros dos caracteres
                        curp[0] = apellido_parte[0];
                        curp[1] = apellido_parte[1];
                        break; 
                    }
                }

                inicio = posiciones_vacias_apellido[i] + 1;
            }
        }

        else
        {
            // Si no hay posiciones vacias no es compuesto
            curp[0] = primer_apellido[0];
            curp[1] = primer_apellido[1];
        }

    }

    else
    {
        curp[0] = 'X';
        curp[1] = 'X';
    }

    //POSICION 2
    //corresponde al primer elemento del segundo apellido

    if(!verifica_vacio(segundo_apellido))
    {
        // Identificar posiciones vacias en el apellido compuesto
        int posiciones_vacias_apellido[10] = {0};
        int cont = 0;

        for (int i = 0; segundo_apellido[i] != '\0'; i++)
        {
            if (segundo_apellido[i] == ' ')
            {
                posiciones_vacias_apellido[cont] = i;
                cont++;
            }
        }

        // Si hay posiciones vacias es compuesto
        if (cont > 0)
        {
            int inicio = 0;
            char apellido_parte[100] = {0}; 

            // Dividir el apellido en partes basadas en las posiciones vacias
            for (int i = 0; i <= cont; i++)
            {
                int fin;

                if (i == cont)
                {
                    fin = strlen(segundo_apellido);
                }

                else
                {
                    fin = posiciones_vacias_apellido[i];
                }

                for(int j = inicio; j < fin; j++)
                {
                    apellido_parte[j - inicio] = segundo_apellido[j];
                }

                // Añadir el caracter nulo
                apellido_parte[fin - inicio] = '\0';

                // Verificar
                if (!excepcion_compuestos(apellido_parte))
                {
                    
                    curp[2] = apellido_parte[0];
                    break; 
                }

                inicio = posiciones_vacias_apellido[i] + 1;
            }
        }

        else
        {
            // Si no hay posiciones vacias no es compuesto
            curp[2] = segundo_apellido[0];
        }

    }

    else
    {
        //si esta vacio
        curp[2] = 'X';
    }


    //POSICION 3
    //corresponde al primer elemento del primer nombre
    

    // Verificar si el primer nombre está en la lista de excepciones para el segundo nombre
    if (excepcion_mariajose(primer_nombre))
    {
        // Si el primer nombre está en la lista de excepciones, usar el segundo nombre
        curp[3] = segundo_nombre[0];
    }
    else
    {
        // Si no esta en la lista de excepciones usar el primer nombre
        curp[3] = primer_nombre[0];
    }

    // Completar el resto de la CURP
    curp[4] = fecha[8];
    curp[5] = fecha[9];
    curp[6] = fecha[3];
    curp[7] = fecha[4];
    curp[8] = fecha[0];
    curp[9] = fecha[1];


    curp[10] = sexo[0];


    curp[11] = estado[0];
    curp[12] = estado[1];


    //POSICION 13


        // Identificar posiciones vacias en el apellido compuesto
        int posiciones_vacias_apellido[10] = {0};
        int cont = 0;

        for (int i = 0; primer_apellido[i] != '\0'; i++)
        {
            if (primer_apellido[i] == ' ')
            {
                posiciones_vacias_apellido[cont] = i;
                cont++;
            }
        }

        // Si hay posiciones vacias es compuesto
        if (cont > 0)
        {
            int inicio = 0;
            char apellido_parte[100] = {0}; 

            // Dividir el apellido en partes basadas en las posiciones vacias
            for (int i = 0; i <= cont; i++)
            {
                int fin;
                if (i == cont)
                {
                    fin = strlen(primer_apellido);
                }
                
                else
                {
                    fin = posiciones_vacias_apellido[i];
                }

                for(int j = inicio; j < fin; j++)
                {
                    apellido_parte[j - inicio] = primer_apellido[j];
                }

                // Añadir el caracter nulo
                apellido_parte[fin - inicio] = '\0';

                // Verificar
                if (!excepcion_compuestos(apellido_parte))
                {
                    
                    curp[13] = retorna_consonante_interna(apellido_parte);
                    break; 
                }

                inicio = posiciones_vacias_apellido[i] + 1;
            }
        }

        else
        {
            // Si no hay posiciones vacias no es compuesto
            curp[13] = cat_die_i[0];
        }

    
    
    if(verifica_vacio(segundo_apellido))
    {
        curp[14] = 'X';
    }
    else
    {
        curp[14] = cat_die_i[1];
    }

    
    // POSICION 15
    

    curp[15] = cat_die_i[2];



    curp[16] = diescisiete_i[0];
    curp[17] = diesciocho_i[0];
    curp[18] = '\0';


    // Verificar si la persona no tiene ningun apellido
    if (verifica_vacio(primer_apellido) && verifica_vacio(segundo_apellido))
    {
        strcpy(curp, "PERSONA DESCONOCIDA");
        curp[20] = '\0';
    }

    // Verificar altisonantes
    if (excepcion_altisonantes(curp))
    {
        curp[1] = 'X';
    }

}


//*********************//


void imprimir_curp(char curp[])
{
        printf("\n");
        printf("|-------------------------------------------------------------------------------------------- |\n");
        printf("|                                                                                             |\n");
        printf("|        C U R P :  %s                                                         |\n", curp);
        printf("|                                                                                             |\n");
        printf("|-------------------------------------------------------------------------------------------- |\n");
}

