#ifndef NEURONA_H
#define NEURONA_H

//#include <QMainWindow>
#include <iostream>

using namespace std;

//QT_BEGIN_NAMESPACE
//namespace Ui { class Neurona; }
//QT_END_NAMESPACE

class Neurona
{
   // Q_OBJECT

private:
    //Ui::Neurona *ui;
    // Atributos
    int id;
    float voltaje;
    int posicion_x;
    int posicion_y;
    int red;
    int green;
    int blue;

public:
   /* Neurona(QWidget *parent = nullptr);
    ~Neurona();*/
    Neurona();
    Neurona(const Neurona& n);

    //sobrecarga de operador de entrada y salida
    friend ostream& operator <<(ostream&, Neurona&);
    friend istream& operator >>(istream&, Neurona&);



};

template<class T>
class Lista  //  LISTA SIMPLEMENTE LIGADA  //
{
    private:
        class Nodo{  // CLASE NODO //;
            private:
                T dato;
                Nodo *sig; // Sig = Siguiente
            public:
                Nodo():sig(nullptr){};
                friend class Lista; // Nodo y Lista Clases amigas
                };

        Nodo* ancla; // cabecera


        bool posicionValida( Nodo* )const;

    public:
        class Exception : public std::exception{
            private:
                std::string msg;
                public:
                    explicit Exception(const char* message) : msg(message){}

                    explicit Exception(const std::string& message) : msg(message){}

                    virtual ~Exception() throw (){}

                    virtual const char* what() const throw(){
                        return msg.c_str();
                        }
                };


        Lista():ancla(nullptr){}; //Nulo = nullptr / incializar en nulo
        virtual ~Lista(){
        anula();
        };
        //Paqueteria():cont(0) {};// Inicializa

        // Metodos
        bool vacia()const; //no modifica atributos de la clase constante
        void inserta(T, Nodo*); //Puntero nodo //inserta al inicio
        bool elimina(Nodo*);
        Nodo* anterior(Nodo*)const;
        Nodo* primero()const;
        Nodo* ultimo()const;
        Nodo* siguiente(Nodo*)const;
        Nodo* localiza(T)const;
        void recupera(Nodo*)const;
        void anula();
        void imprime()const;
};



//   IMPLEMENTACION   //
/*
Paqueteria::Paqueteria(){
    anula();
}
*/
template <class T>
bool Lista<T>::posicionValida(Nodo* pos) const {
    Nodo* aux(ancla);

    while(aux != nullptr){
        if(aux == pos){
            return true;
        }

        aux = aux ->sig;
    }
    return false;
}


template<class T>
bool Lista<T>::vacia()const{
    if(ancla == nullptr)
        return true;
    return false;
}

template<class T>
void Lista<T>::inserta(T elem, Nodo* pos)
{
    Nodo* aux=new Nodo; //Crea nuevo nodo con new
    aux -> dato = elem; //Pase por valor
    if(pos==nullptr) // Inserta al principio
    {
        aux -> sig = ancla;
        ancla = aux;
        cout<< "\nPaquete registrado exitosamente :)";
    }
    else // Inserta en cualquier otro lugar
    {
        aux -> sig = pos -> sig;
        pos -> sig = aux;
        cout<< "\nPaquete registrado exitosamente";
    }

}

template<class T>
bool Lista<T>::elimina(Nodo* pos){
    if(vacia()){
        cout<<"\nPaqueteria vacia";
        return false;
    }
    else
    if(pos==nullptr) // Valida posicion
    {
        cout<<"\nPaquete no registrado";
        return false;
    }
    if(pos==ancla) // Elimina al principio
    {
        ancla=ancla->sig;
        cout<<"\nEl paquete que se encontraba al inicio ha sido eliminado...";

    }
    else // Elimina en cualquier otro lugar
        anterior(pos)->sig=pos->sig;
    //free
    delete(pos);
    //cout<<"\nSocio eliminado";
    return true;
}

template<class T>
typename Lista<T>::Nodo* Lista<T>::anterior(Nodo* pos)const
{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    Nodo* aux=ancla;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
typename Lista<T>::Nodo* Lista<T>::primero()const
{
    return ancla;
}
template<class T>
typename Lista<T>::Nodo* Lista<T>::ultimo()const
{
    if(vacia()){
        return nullptr;
    }
    Nodo* aux=ancla;
    while(aux->sig!=nullptr){ //Recorre
        aux=aux->sig;
    }
    return aux;
}

template<class T>
typename Lista<T>::Nodo* Lista<T>::siguiente(Nodo* pos)const{
    if(vacia() || pos==nullptr)
        return nullptr;
    return pos->sig;
}

template<class T>
typename Lista<T>::Nodo* Lista<T>::localiza(T elem)const{
    Nodo* aux=ancla;
    while(aux!=nullptr && aux->dato!=elem){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
void Lista<T>::recupera(Nodo* pos)const{
    if(!posicionValida(pos)){
        throw Exception ("Posicion invalida");
    }
    cout<<"\nPaquete encontrado: \n"<<pos->dato;
        //Excepciones
}

template<class T>
void Lista<T>::anula(){
    Nodo* aux;
    while(ancla != nullptr){
        aux= ancla;
        ancla= ancla->sig;
        delete(aux);
    }
}

template<class T>
void Lista<T>::imprime()const{
    if(vacia()){
        cout<<"\nPaqueteria vacia";
        return;}

    Nodo* aux =ancla;
    while(aux!=nullptr){
        std::cout<<aux->dato;
        aux=aux->sig;
    }
}

#endif // NEURONA_H
