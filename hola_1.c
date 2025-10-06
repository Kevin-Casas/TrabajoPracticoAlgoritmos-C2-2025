#include <stdio.h>

int main() {
    FILE *archivo;
    char linea[256]; // Buffer para almacenar cada línea
    
    // Abrir el archivo en modo lectura
    archivo = fopen("F:/Algoritmos/hola.txt", "r");
    // Para poner ruta absoluta con windows hay que poner barra y NO BARRA INVERITDA NO

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo hola.txt\n");
        printf("Asegurate de que el archivo existe en el mismo directorio\n");
        return 1; // Salir con código de error
    }
    
    printf("Contenido del archivo hola.txt:\n");
    printf("===============================\n");
    
    // Leer y mostrar línea por línea
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }
    
    // Cerrar el archivo
    fclose(archivo);
    
    printf("\n===============================\n");
    printf("Fin del archivo\n");
    
    return 0;
}