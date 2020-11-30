#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char marca[20];
    int tipo;
    float peso;
} eVehiculo;
eVehiculo* vehiculo_new();
eVehiculo* vehiculo_newParametros(char* idStr,char* marcaStr,char* tipostr, char * peso);
int vehiculo_setPeso(eVehiculo* pV,float peso);
int vehiculo_setId(eVehiculo* pV,int id);
int vehiculo_setMarca(eVehiculo* pv,char* marca);
int vehiculo_setipo(eVehiculo* pV,int tipo);
int saveAsTex(char * path, eVehiculo v);
int saveAsBinary(char * path, eVehiculo v);


int main()
{

    eVehiculo v = {1,"vv 1",1,1.0};
    saveAsBinary("archivo.bin",v);
    saveAsTex("archivo.csv",v);
    eVehiculo *v2 = vehiculo_newParametros("2","ss","3","2.5");

}

eVehiculo* vehiculo_new()
{
    return (eVehiculo *) malloc(sizeof(eVehiculo));
}
eVehiculo* vehiculo_newParametros(char* idStr,char* marcaStr,char* tipostr, char * pesostr)
{
    eVehiculo * auxVehiculo;
    auxVehiculo = vehiculo_new();
    if(auxVehiculo != NULL && idStr != NULL && marcaStr!= NULL && tipostr != NULL && pesostr!= NULL )
    {
        if(vehiculo_setId(auxVehiculo,atoi(idStr))&& vehiculo_setMarca(auxVehiculo,marcaStr) && vehiculo_setipo(auxVehiculo,atoi(tipostr)) && vehiculo_setPeso(auxVehiculo,atof(pesostr)))
        {
            printf("error \n");
        }
        else
        {
            vehiculo_setId(auxVehiculo,atoi(idStr));
            vehiculo_setMarca(auxVehiculo,marcaStr) ;
            vehiculo_setipo(auxVehiculo,atoi(tipostr)) ;
            vehiculo_setPeso(auxVehiculo,atof(pesostr));
        }
    }
    return auxVehiculo;


}
int vehiculo_setId(eVehiculo* pv,int id)
{
    int error = 1;

    if(pv != NULL )
    {
        if(id >= 0)
        {
            pv ->id = id;
            error = 0;

        }
        else
        {
            printf("Id invalido \n");
        }
    }
    return error;

}
int vehiculo_setMarca(eVehiculo* pv,char* marca)
{
    int error = 1;
    fflush(stdin);
    if(pv != NULL)
    {
        if(strlen(marca) > 0)
        {
            strcpy(pv ->marca,marca);
            error = 0;

        }
        else
        {
            printf("tipo invalido \n");
        }
    }
    return error;
}
int vehiculo_setipo(eVehiculo* pv,int tipo)
{
    int error = 1;

    if(pv != NULL )
    {
        if(tipo >= 0)
        {
            pv ->tipo = tipo;
            error = 0;

        }
        else
        {
            printf("tipo invalido \n");
        }
    }
    return error;

}
int vehiculo_setPeso(eVehiculo* pv,float peso)
{
    int error = 1;

    if(pv != NULL )
    {
        if(peso >= 0)
        {
            pv ->peso = peso;
            error = 0;

        }
        else
        {
            printf("Peso invalido \n");
        }
    }
    return error;

}
int saveAsTex(char * path, eVehiculo v)
{
    int error = 1;
    FILE * f = fopen(path,"a");
    if(f == NULL)
    {
        printf("No se puede abrir el archivo \n");
    }

    else
    {
        error=(fprintf(f,"%d,%s,%d,%f\n",v.id,v.marca,v.tipo,v.peso)<0);

    }
    fclose(f);
    if(!error)
    {
        printf("Archivo guardado ok \n");

    }
    return error;
}

int saveAsBinary(char * path, eVehiculo v)
{
    int error = 1;
    FILE * f = fopen(path,"wb");
    if(f == NULL)
    {
        printf("No se puede abrir el archivo \n");
    }
    else
    {
        error =(fwrite(&v, sizeof(eVehiculo), 1, f)<0);

    }
    if(!error)
    {
        printf("Archivo guardado ok \n");

    }
    fclose(f);
    return error;
}
