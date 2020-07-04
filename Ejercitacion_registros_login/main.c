#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
1era etapa:
Poder guardar los datos a medida que los usuarios se quieran registrar ( usuario y clave)

2da etapa:
Poder mostrar todos los usuarios registrados en tu sistema

3era etapa:
Poder logearse al sistema si su usuario y clave son correctos
*/
typedef struct
{
    char usuario[50];
    char contrasena[50];

}Eusers;

int main()
{
    int opcion;
    Eusers listaUsuarios[3];
    int i;
    Eusers auxUsuarios;
    FILE* pArchivo;

    do{

        printf("\n1 - Cargar \n 2 - Mostrar \n 3 - Loguear \n 4 - Salir \n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
            pArchivo = fopen("archivo.csv", "w");

            if(pArchivo!=NULL)
            {
                for(i=0; i<3; i++)
                {
                printf("Ingrese usuario: ");
                scanf("%s", listaUsuarios[i].usuario);
                printf("Ingrese contrasena: ");
                scanf("%s", listaUsuarios[i].contrasena);

                }
                fwrite(listaUsuarios, sizeof(Eusers), 3, pArchivo);
                fclose(pArchivo);
                printf("Cargado con exito");

            } else {
                printf("No se pudo realizar la carga");
            }
            break;
            case 2:
            pArchivo = fopen("archivo.csv", "r");
            if(pArchivo!=NULL)
            {
                fread(listaUsuarios, sizeof(Eusers), 3, pArchivo);

                for(i=0; i<3; i++)
                {
                printf("\n%s -- %s", listaUsuarios[i].usuario, listaUsuarios[i].contrasena);
                }

            }
            fclose(pArchivo);
            break;
            case 3:
            printf("Ingrese usuario: ");
            scanf("%s", auxUsuarios.usuario);
            printf("Ingrese contrasena: ");
            scanf("%s", auxUsuarios.contrasena);

            for(i=0; i<3; i++)
            {
                if(strcmp(listaUsuarios[i].usuario, auxUsuarios.usuario)==0 && strcmp(listaUsuarios[i].contrasena, auxUsuarios.contrasena)==0)
                {
                    printf("\nUser ok");
                    break;

                }
            }

            if(i==3)
            {
                  printf("\nUser inexistente");
            }

            break;


        }


    }while(opcion!=4);

    return 0;
}
