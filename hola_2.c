#include <stdio.h>
#include <string.h> // Para usar strchr

int main() {
    FILE *archivo;
    char linea[256]; // Buffer para almacenar cada línea
    char *token;
    
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
    
    int primera_linea = 1; // Para controlar cuando imprimir los asteriscos
    
    // Leer y mostrar línea por línea
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        // Si no es la primera línea, imprimir separador de asteriscos
        if (!primera_linea) {
            printf("****************************\n");
        }
        primera_linea = 0;
        
        // Dividir la línea en tokens usando espacio como delimitador
        token = strtok(linea, " \n"); // Los delimitadores son espacio y salto de línea
        
        while (token != NULL) {
            printf("%s\n", token); // Imprimir cada palabra en nueva línea
            token = strtok(NULL, " \n"); // Continuar con la siguiente palabra
        }
    }
    
    // Cerrar el archivo
    fclose(archivo);
    
    printf("\n===============================\n");
    printf("Fin del archivo\n");
    
    return 0;
}