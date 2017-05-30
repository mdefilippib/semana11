#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// Clase contenida
struct TPunto
{
    int x;
    int y;
};

// Clase contenedor
class CMapa
{
    string nombreArchivo;
    string ciudad;
    vector<TPunto> listaPuntos; // Agregar puntos relacion 1 a muchos
    public:
    
        // Declaracion de constructores
        CMapa()
        {
            ciudad = "Lima";
            nombreArchivo = "datos.txt";
        }
        
        CMapa(string ciudad, string nombreArchivo)
        {
            this->ciudad = ciudad;
            this->nombreArchivo = nombreArchivo;
        }
        
        // Metodos de Procesamiento
        void agregarPunto(int x, int y)
        {
            listaPuntos.push_back({x,y});
            grabarArchivo();
        }
        void listarPuntos()
        {
            for (auto punto: listaPuntos)
                cout << "Punto x,y = (" << punto.x << ", " << punto.y << ")" << endl;
        }
        void eliminarPuntoPorX(int x) //Moverse de atras para adelante en el vector
        {
            for (int i = listaPuntos.size() -1; i >=0; i--)
            {
                if (listaPuntos[i].x == x)
                    listaPuntos.erase(listaPuntos.begin()+i);
            }
            grabarArchivo();
        }
        
        void grabarArchivo()
        {
            // Creando el archivo
            ofstream archivo(nombreArchivo);
            archivo << "posX, posY" << endl;
            for (auto punto: listaPuntos)
                archivo << punto.x << ", " << punto.y << endl;
            archivo.close();
        }
};

// Metodo Menu
int menu()
{
     int opcion = 0;
     
    do
    {
        system ("clear");
        cout << "MENU" << endl;
        cout << string(4, '~') << endl << endl;
        
        cout << "1. Ingresar Puntos" << endl;
        cout << "2. Listar Puntos" <<  endl;
        cout << "3. Eliminar por posicion X: "<< endl;
        
        cout << "0. Para salir" << endl <<  endl;
        cout << "Opcion : ";
        cin >> opcion;
        return opcion;
    }
    while (opcion < 0 || opcion > 3);
}

int main()
{
    CMapa mapa;       // Mapa de Lima
    int opcion = 0;
    do 
    {
        opcion = menu();    // Opcion del menu
        int x,y;
        // Creamos un switch de opciones
        switch (opcion)
        {
            case 1:
                system("clear");
                cout << "Ingrese el valor de X: "; cin >> x;
                cout << "Ingrese el valor de Y: "; cin >> y;
                mapa.agregarPunto(x,y);
                break;
            case 2: 
                system("clear");
                mapa.listarPuntos();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 3:
                system("clear");
                cout << "Ingrese la posicion X del punto a borrar: "; cin >> x;
                mapa.eliminarPuntoPorX(x);
                break;
                
        }
    }
     while (opcion !=0);
        
    return 0;
}