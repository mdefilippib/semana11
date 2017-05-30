#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

// Crear clases
struct TLlanta
{
    string marca;
    float radio;
    string perfil;
    float espesor;
};

struct TMotor
{
    float cilindros;
    float potencia;
    string posicion;
    string distribucion;
    float revs;
};

struct TTimon
{
    float radio;
    string marca;
};

struct TAsiento
{
    string material;
    string color;
};

class CAuto 
{
    TMotor motor;                    //Relación con ocurrencia 1 a 1
    TTimon timon;
    vector<TLlanta> listaLlantas;    //Relación con ocurrencia 1 a muchos
    vector<TAsiento> listaAsientos;
    
    public:
        CAuto()
        {
            // Crear 4 llantas
            for (int i = 0; i < 4; i++)
                listaLlantas.push_back({"Dunlop",17,"estandar",8});
            
            // Crear 5 asientos
            for (int i = 0; i < 5; i++)
                listaAsientos.push_back({"Cuero","Negro"});
            
            // Definimos el timon     
            timon.marca = "Serie";
            timon.radio = 7;
            
            // Definimos el motor
            motor.cilindros = 4;
            motor.potencia = 250;
            motor.posicion = "delantero";
            motor.distribucion = "en linea";
            motor.revs = 5000;
        }
        
        CAuto(int nLlantas, int nAsientos, TTimon timon, TMotor motor)
        {
            // Crear n llantas
            for (int i = 0; i < nLlantas; i++)
                listaLlantas.push_back({"Pirelli",20,"Bajo",12});
            
            // Crear n asientos
            for (int i = 0; i < nAsientos; i++)
                listaAsientos.push_back({"Alcantara","Negro"});
                
            // Definimos el timon    
            this->timon = timon;
            
            // Definimos el motor
            this->motor = motor;
        }
};


// Programa Principal
int main()
{
    CAuto estandar; 
    
    TTimon timon;
    timon.marca = "Sparco";
    timon.radio = 7;
    
    TMotor motor;
    motor.cilindros = 10;
    motor.potencia = 700;
    motor.posicion = "central";
    motor.distribucion = "V";
    motor.revs = 8000;
    
    CAuto(4, 2, timon, motor);
    
    return 0;
}

