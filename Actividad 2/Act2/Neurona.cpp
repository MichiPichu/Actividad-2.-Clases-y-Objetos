#include "Neurona.h"
#include <iostream>

using namespace std;

///Implementacion

// Constructores de la clase Neurona //

Neurona::Neurona(){}

Neurona::Neurona(const Neurona& n)
{
    id = n.id;
    voltaje = n.voltaje;
    posicion_x = n.posicion_x;
    posicion_y = n.posicion_y;
    red = n.red;
    green = n.green;
    blue = n.blue;
};



// Sobrecarga de operadores de entrada y salida

ostream& operator << (ostream& o,Neurona& n2)
{
    cout<<"\nId: ";
    o<<n2.id;
    cout<<"\nVoltaje: ";
    o<<n2.voltaje;
    cout<<"\nPosicion x: ";
    o<<n2.posicion_x;
    cout<<"\nPosicion y: ";
    o<<n2.posicion_y;
    cout<<"\nRed: ";
    o<<n2.red;
    cout<<"\nGreen: ";
    o<<n2.green;
    cout<<"\nBlue: ";
    o<<n2.blue;
    cout<<endl;
    return o;
}

istream& operator>>(istream& o,Neurona& n2)
{
    cout<<endl;
    cout<<"Ingresa id: ";
    o>>n2.id;
    cout<<"Ingresa voltaje: ";
    o>>n2.voltaje;
    cout<<"Ingresa posicion x: ";
    o>>n2.posicion_x;
    cout<<"Ingresa posicion y: ";
    o>>n2.posicion_y;
    cout<<"Ingresa red: ";
    o>>n2.red;
    cout<<"Ingresa green: ";
    o>>n2.green;
    cout<<"Ingresa blue: ";
    o>>n2.blue;
    return o;
}
