#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

//-----------------------------------------
void leerUsuarios(){
  FILE *archivo;
  char texto[50];
  char *datos;
  char tabla[3][50];
  archivo = fopen("usuarios.txt","r");

  while(feof(archivo)==0){
    fgets(texto,50, archivo);
    struct Usuario u;
    int i=0;
    datos = strtok( texto, "-" );
    
    while( datos != NULL )
    {
      strcpy(tabla[i], datos);
      datos = strtok( NULL, "-" );
      i++;
    }
    strcpy(u.rol, tabla[0]);
    strcpy(u.user, tabla[1]);
    strcpy(u.pswrd, tabla[2]);
    addUsuario(u);
  }
}

//---------------------------------------

void leerProductos(){
  FILE *archivo;
  char texto[50];
  char *datos;
  char tabla[6][70];
  archivo = fopen("productos.txt","r");
  

  while(feof(archivo)==0){
    fgets(texto,70, archivo);
    struct Producto p;
    int i=0;
    datos = strtok( texto, "-" );
    while( datos != NULL )
    {
      strcpy(tabla[i], datos);
      datos = strtok( NULL, "-" );
      i++;
    }
    strcpy(p.codigo, tabla[0]);
    strcpy(p.nombre, tabla[1]);
    p.precio = strtof(tabla[2], NULL);
    strcpy(p.marca, tabla[3]);
    strcpy(p.categoria, tabla[4]);
    strcpy(p.bodega, tabla[5]);
    sumarBodega(p);
  }
  
}

//---------------------------------------

void leerVentas(){
  FILE *archivo;
  char texto[50];
  char *datos;
  char tabla[4][70];
  archivo = fopen("productos.txt","r");

  while(feof(archivo)==0){
    fgets(texto,70, archivo);
    struct Venta v;
    int i=0;
    datos = strtok( texto, "-" );
    while( datos != NULL )
    {
      strcpy(tabla[i], datos);
      datos = strtok( NULL, "-" );
      i++;
    }
    v.fechaVenta = strtol(tabla[0], NULL, 10);
    strcpy(v.local, tabla[1]);
    strcpy(v.vendedor, tabla[2]);
    v.precio = strtof(tabla[3], NULL);
    
  }
}


//--------------------------------------------------
void escribirUsuario(struct Usuario nuevoUsuario) {
      FILE *archivo = fopen("usuarios.txt", "a");
      if (archivo == NULL) {
          perror("Error al abrir el archivo");
          exit(EXIT_FAILURE);
      }
      fprintf(archivo, "%s-%s-%s\n", nuevoUsuario.rol, nuevoUsuario.user, nuevoUsuario.pswrd);
      fclose(archivo);
  }

void escribirProducto(struct Producto nuevoProducto) {
    FILE *archivo = fopen("productos.txt", "a");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }
    fprintf(archivo, "%s-%s-%f-%s-%s-%s\n", nuevoProducto.codigo, nuevoProducto.nombre, nuevoProducto.precio, nuevoProducto.marca, nuevoProducto.categoria, nuevoProducto.bodega);
    fclose(archivo);
}

void escribirVenta(struct Venta nuevaVenta) {
    FILE *archivo = fopen("ventas.txt", "a");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }
    fprintf(archivo, "%s-%s-%f-%s\n", nuevaVenta.local, nuevaVenta.vendedor, nuevaVenta.precio),ctime(&nuevaVenta.fechaVenta);;
    fclose(archivo);
}
