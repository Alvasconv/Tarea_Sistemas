#include <stdio.h>
#include "Funciones.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "Escritura.h"
#define CantidadUsuarios 10
#define CantidadProducto 50

struct Producto productosBodega[CantidadProducto];
struct Usuario usuarios[CantidadUsuarios];
int indiceBodega = 0;
int indiceUsuarios = 0;

struct Producto prodVacio;
struct Usuario userVacio;




//-----------------  FUNCIONES  ----------------------

//Muestra resumidamente los productos guardados en la bodega
void mostrarBodega(){
  for(int i=0;i<CantidadProducto;i++){
    if(productosBodega[i].codigo[0]!='\0'){
      printf("- nombre: %s\tprecio: %f\tcodigo:%s\n", productosBodega[i].nombre,productosBodega[i].precio,
  productosBodega[i].codigo);
    }
  }
};

//Añade el producto al array y suma uno al ind de bodega
void sumarBodega(struct Producto p){
  for(int i=0;i<CantidadProducto;i++){
    if((strcmp(productosBodega[i].codigo,prodVacio.codigo)==0)){
      productosBodega[i] = p;
      indiceBodega++;
      break;
    }
  }
  printf("Actualmente hay %d productos en la bodega\n",indiceBodega);
};

//Elimina un producto del array y resta uno en el ind de bodega
void restarBodega(struct Producto p){
  for(int i=0;i<CantidadProducto;i++){
    if((strcmp(productosBodega[i].codigo,p.codigo)==0)){
      productosBodega[i] = prodVacio;
      indiceBodega--;
      break;
    }
  }
  printf("Actualmente hay %d productos en la bodega\n",indiceBodega);
};

//Añade un usuario al array y suma uno al ind de usuarios
void addUsuario(struct Usuario u){
  for(int i=0;i<CantidadUsuarios;i++){
    if(strcmp(usuarios[i].user,userVacio.user)==0){
      usuarios[i] = u;
      indiceUsuarios++;
      break;
    }
  }
  printf("Actualmente hay %d usuarios en el sistema\n",indiceUsuarios);
};

//Elimina un usuario del array y resta uno en el ind de usuarios
void deleteUsuario(struct Usuario u){
  for(int i=0;i<CantidadUsuarios;i++){
    if(strcmp(usuarios[i].user,u.user)==0){
      usuarios[i] = userVacio;
      indiceUsuarios--;
      break;
    }
  }
  printf("Actualmente hay %d usuarios en el sistema\n",indiceUsuarios);
};

//Valida las credenciales de ingreso de un usuario
char* validarUser(char usuario[40], char pswrd[40]){
  for(int i=0;i<indiceUsuarios;i++){
    if(strncmp(usuarios[i].user, usuario,strlen(usuario)) == 0 && strncmp(usuarios[i].pswrd,pswrd, strlen(pswrd)) == 0) {
      printf("Ingreso Exitoso\n");
      return usuarios[i].rol;
    }
  }
  printf("Error de ingreso\n");
  return "";
};

// genera una venta validando el producto vendido por su codigo y restandolo de bodega con la funcion restarBodega
void venderProducto(char codeProducto[10])
{
  int i;
  for(i=0;i<CantidadProducto;i++){
    if(strncmp(productosBodega[i].codigo, codeProducto,strlen(codeProducto)) == 0){
      struct Venta v;
      printf("ingrese nombre del vendedor: ");
      scanf("%s",v.vendedor);
      printf("ingrese nombre del local: ");
      scanf(" %s",v.local);
      printf("ingrese precio del producto: ");
      fflush(stdin);
      scanf(" %f",&v.precio);
      v.fechaVenta = time(NULL);
      printf("VENTA EXITOSA\n");
      restarBodega(productosBodega[i]);
      escribirVenta(v);
    }
  }



}
// actualza el producto deseaado a travez de su codigo 
void updateProducto(int codigo){
  int i;
  for(i=0;i<50;i++){
    if (productosBodega[i].codigo == codigo ){
      printf("ingrese nombre producto: \n");
      scanf("%s",productosBodega[i].nombre);
      printf("ingrese la categoria: \n");
      scanf(" %s",productosBodega[i].categoria);
      printf("ingrese la marca: \n");
      scanf(" %s",productosBodega[i].marca);
      printf("ingrese el precio: \n");
      scanf("%f",&productosBodega[i].precio);
      printf("ingrese la bodega 1 o 2: \n");
      scanf(" %s",productosBodega[i].bodega);
    }
  }     
}



// registra nuevos productos
void registrarProducto()
{
  if(indiceBodega<CantidadProducto){
    struct Producto p;
    printf("ingrese bodega del producto: ");
    scanf(" %s",p.bodega);
    printf("ingrese nombre del producto: ");
    scanf("%s",p.nombre);
    printf("ingrese categoria del producto: ");
    scanf(" %s",p.categoria);
    printf("ingrese marca del producto: ");
    scanf(" %s",p.marca);
    printf("ingrese codigo del producto: ");
    scanf(" %s",p.codigo);
    printf("ingrese precio del producto: ");
    scanf(" %f",&p.precio);
    sumarBodega(p);
    escribirProducto(p);
  }
  else{
    printf("La bodega esta llena.");
  }

};
// registra nuevos usuarios 
void registrarUsuario()
{
  struct Usuario u;
  printf("ingrese usuario: ");
  scanf(" %s",u.user);
  printf("ingrese contraseña: ");
  scanf(" %s",u.pswrd);
  printf("ingrese su rol(vendedor, admin o bodeguero): ");
  scanf(" %s",u.rol);
  addUsuario(u);
  escribirUsuario(u);
};

// actualiza usuarios ya sea su nombre usuario o contraseña
void updateUsuario(char user[40])
{
  for(int i=0;i<CantidadUsuarios;i++){
    if(strcmp(usuarios[i].user,user)==0){ 
      int opcion;
      printf("Que desea actualizar: ");
      printf("1. Usuario \n 2. Contraseña \n");
      scanf("%d",&opcion);

      if(opcion == 1){
        printf("ingrese usuario nuevo: ");
        scanf("%s",usuarios[i].user);
      }
      else if(opcion == 2){
        printf("ingrese contraseña nueva: ");
        scanf("%s",usuarios[i].pswrd);
      }
      else{
        printf("Opcion incorrecta ");
      }
    } 

  }


};

void mostrarUsarios(){
  for(int i=0;i<CantidadUsuarios;i++){
    if(usuarios[i].user[0] != 0){
      printf("- usuario: %s\tcontraseña:%s\trol:%s\n",usuarios[i].user,
        usuarios[i].pswrd,usuarios[i].rol);
    }
  }
}



