#include <iostream>

class Constancia {
    private:
        std::string nombre;
        std::string carrera;
        int tma;
        float promG;
    public:
        Constancia():nombre(""),carrera(""),tma(-1),promG(-1) {};

        Constancia(const Constancia& c) {
            nombre = c.nombre;
            carrera = c.carrera;
            tma = c.tma;
            promG = c.promG;
            }

        Constancia& operator = (Constancia& c) {
            nombre = c.nombre;
            carrera = c.carrera;
            tma = c.tma;
            promG = c.promG;
            return *this;
            }

        friend bool operator==(Constancia& x,Constancia& y) {
            if(x.nombre.compare(y.nombre)==0 && x.carrera.compare(y.carrera)==0 && x.tma == y.tma && x.promG == y.promG) {
                return 1;
                }
            else {
                return 0;
                }

            }

        friend bool operator!=(Constancia& x,Constancia& y) {
            if(x.nombre.compare(y.nombre)==0 && x.carrera.compare(y.carrera)==0 && x.tma == y.tma && x.promG == y.promG) {
                return 0;
                }
            else {
                return 1;
                }

            }

        friend bool operator>(Constancia& x,Constancia& y) {
            if(x.tma > y.tma && x.promG > y.promG) {
                return 1;
                }
            else {
                return 0;
                }

            }

        friend bool operator<(Constancia& x,Constancia& y) {
            if(x.tma < y.tma && x.promG < y.promG) {
                return 1;
                }
            else {
                return 0;
                }

            }

        friend std::ostream & operator<<(std::ostream &O, Constancia &x) {
            O<<"\n Nombre: "<<x.nombre<<std::endl;
            O<<"\n Carrera: "<<x.carrera<<std::endl;
            O<<"\n Materias Aprobadas: "<<std::to_string(x.tma)<<std::endl;
            O<<"\n Promedio General: "<<std::to_string(x.promG)<<std::endl;
            return O;
            }
        friend std::istream & operator>>(std::istream &O, Constancia &x) {
            std::cout<<"\n Nombre: ";
            O>>x.nombre;
            std::cout<<"\n Carrera: ";
            O>>x.carrera;
            std::cout<<"\n Total de Materias Aprobadas: ";
            O>>x.tma;
            std::cout<<"\n Promedio General: ";
            O>>x.promG;
            return O;
            }

        std::string getNombre() const {
            return nombre;
            }


        std::string getCarrera() const {
            return carrera;
            }

        int getTma() const {
            return tma;
            }

        float getPromG() const {
            return promG;
            }

        void setNombre(const std::string& n) {
            nombre = n;
            }

        void setCarrera(const std::string& c) {
            carrera = c;
            }

        void setTma(const int& t) {
            tma = t;
            }

        void setPromG(const float& p) {
            promG = p;
            }
    };


template<class T>
class Cola;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class Cola<T>;
};

template<class T>
class Cola{
private:
    node<T>* lista;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
public:
    Cola():lista(nullptr){};
    bool vacia()const;
    void Enqueue(T elem);
    void Dequeue();
    void imprimir()const;
    T& Front();
};

template<class T>
void Cola<T>::Enqueue(T elem){
    insertar(ultimo(),elem);

}

template<class T>
void Cola<T>::Dequeue(){
    eliminar(primero());
}

template<class T>
T& Cola<T>::Front(){
    if(!vacia()){
        return primero()->data;
    }

}


template<class T>
void Cola<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<aux->data<<"-> ";
        aux=aux->sig;
    }
}

template<class T>
bool Cola<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void Cola<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* Cola<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* Cola<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* Cola<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool Cola<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

int main()
{
     Cola<Constancia> MiCola;
    Constancia x;
    int op;

    do{
        std::cout<<"1. Dar de alta solicitud de alumno"<<std::endl;
        std::cout<<"2. Elaborar una constancia"<<std::endl;
        std::cout<<"3. Salir"<<std::endl;
        std::cout<<"Opcion: ";std::cin>>op;

        switch(op){
        case 1:
            std::cin>>x;
            MiCola.Enqueue(x);
            break;
        case 2:
            if(MiCola.vacia()){
                std::cout<<"NO HAY ELEMENTOS EN LA COLA\n";
            }else{
                x = MiCola.Front();
                MiCola.Dequeue();
                std::cout<<"***********Constancia**********\n: \n";
                std::cout<<x;
            }
        }
    }while(op!=3);


    return 0;
}
