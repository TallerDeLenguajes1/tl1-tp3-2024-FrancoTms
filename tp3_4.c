#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NOMBRES 50

typedef struct{
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}PRODUCTO;

typedef struct{
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
PRODUCTO *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}CLIENTE;

//Funciones
float costoProducto(PRODUCTO producto);

int main(){
    srand(time(NULL));
    int cantClientes;
    float costoTotal, precioFinal = 0;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

    //Cantidad de Clientes
    printf("Cantidad de clientes (1-5): ");
    scanf("%d", &cantClientes);

    //Reserva Dinamica de Clientes
    CLIENTE *clientes;
    clientes = (CLIENTE *)malloc(cantClientes * sizeof(CLIENTE));


    //Cargar Clientes
    for (int i = 0; i < cantClientes; i++)
    {
        clientes[i].ClienteID = i + 1;

        clientes->NombreCliente=(char *)malloc(MAX_NOMBRES * sizeof(char));
        printf("\nIngrese el nombre del Cliente N. %d: ", i + 1);
        fgets(clientes[i].NombreCliente, MAX_NOMBRES, stdin);

        clientes[i].CantidadProductosAPedir = 1 + rand() % 6;

        clientes->Productos = (PRODUCTO *)malloc(clientes[i].CantidadProductosAPedir * sizeof(PRODUCTO));

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % 1 + 10;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = rand() % 11 + 100;
            costoTotal = costoProducto(clientes[i].Productos[j]);
        }
    }
    
    //Mostrar en pantalla
        for (int i = 0; i < cantClientes; i++)
    {
        printf("\nCliente ID: %d", clientes[i].ClienteID);
        printf("\nNombre Cliente: %s", clientes[i].NombreCliente);
        printf("\nCliente ID: %d", clientes[i].CantidadProductosAPedir);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("\nProducto ID: %d", clientes[i].Productos[j].ProductoID);
            printf("\nCantidad: %d", clientes[i].Productos[j].Cantidad);
            printf("\nTipo Producto: %s", clientes[i].Productos[j].TipoProducto);
            printf("\nPrecio Unitario: $%.2f", clientes[i].Productos[j].PrecioUnitario);
            printf("\nCosto Total Producto: $%.2f", costoTotal);
            precioFinal += costoTotal;
        }
        printf("\nTotal a pagar Cliente N. %d = $%.2f", i + 1, precioFinal);
        precioFinal = 0;
    }
    
    //Liberar memoria
    for (int i = 0; i < cantClientes; i++)
    {
        free(clientes);     
    }
    
    return 0;
}
float costoProducto(PRODUCTO producto){
    float costo = producto.PrecioUnitario * producto.Cantidad;
    return costo;
}