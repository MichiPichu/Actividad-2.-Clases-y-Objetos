#include "neurona.h"

//#include <QApplication>

#include "Neurona.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    //QApplication a(argc, argv);
    //Neurona w;
    //w.show();

    // VARIABLES
    char opc; // Opcion

    Lista<Neurona> Milista;
    Neurona a; // a = objeto


    // MENU
    while(1) //ciclo mientras para que el programa continue sin cerrarse
    {
        cout<<"\n\n------------------------------------";
        cout<<"\n 1) Agregar al inicio\n 2) Agregar al final\n 3) Mostrar\n 4)Salir\n";
        cout<<"------------------------------------";

        cout<<"\nIngrese un numero para elegir la opcion\n-> ";
        cin>>opc;

        system("cls");//limpiar pantalla

        switch(opc)
        {
        case '1':
            cout<<"\t------------------------";
            cout<<"\n\t Agregar al inicio"<<endl;
            cout<<"\t------------------------"<<endl<<endl;

            cin>>a;
            Milista.inserta(a,Milista.anterior(Milista.primero()));

            cout<<"\n\nPresiona una tecla para continuar...";
            getch();
            system("cls");
            break;

        case '2':
            cout<<"\t-----------------------";
            cout<<"\n\t  Agregar al final"<<endl;
            cout<<"\t-----------------------"<<endl<<endl;

            cin>>a;
            Milista.inserta(a,Milista.ultimo());

            cout<<"\n\nPresiona una tecla para continuar...";
            getch();
            system("cls");

            break;

        case '3':
            cout<<"\t---------------";
            cout<<"\n\t   Mostrar"<<endl;
            cout<<"\t---------------";

            cout<<"\n\nLista"<<endl;
            Milista.imprime();


            cout<<"\n\nPresiona una tecla para continuar...";
            getch();
            system("cls");
            break;

        case '4':
            exit(EXIT_SUCCESS);
            break;

        default:
            cout<<"Opcion invalida"<<endl;
            cout<<"\nPresiona una tecla para continuar...";
            getch();
            system("cls");
        }

    }

    return 0;

    //return a.exec();
}
