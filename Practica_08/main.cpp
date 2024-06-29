#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

//Clases base

template <typename T>

class Libro {
protected:
    string titulo;
    string autor;
    int ISBN;
    int anio;
    bool disponibilidad;
    T genero;

public:

    Libro(string titulo, string autor, int ISBN, int anio, bool disponibilidad, T genero)
            : titulo(titulo), autor(autor), ISBN(ISBN), anio(anio), disponibilidad(disponibilidad), genero(genero) {}

    string get_titulo() {
        return titulo;
    }

    string get_autor() {
        return autor;
    }

    int get_ISBN() {
        return ISBN;
    }

    int get_anio() {
        return anio;
    }

    bool get_disponibilidad() {
        return disponibilidad;
    }

    T get_genero() {
        return genero;
    }

    virtual void mostrar_datos() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Anio: " << anio << endl;
        if(disponibilidad == true){
          cout << "Disponibilidad: disponible" << endl;
        } else{
          cout << "Disponibilidad: no disponible" << endl;
        }
        cout << "Genero: " << genero << endl;
    }

    virtual void actualizar_datos() = 0;
};


template <typename T>

class Usuarios {
protected:
    string nombre;
    int ID;
    T tipo;

public:

    Usuarios(string nombre, int ID, T tipo) : nombre(nombre), ID(ID), tipo(tipo) {}

    string get_nombre() {
        return nombre;
    }

    int get_ID() {
        return ID;
    }

    T get_tipo() {
        return tipo;
    }

    virtual void mostrar_datos() {
        cout << "nombre: " << nombre << endl;
        cout << "ID: " << ID << endl;
        cout << "tipo: " << tipo << endl;
    }

    virtual void actualizar_datos() = 0;
};


//Clases derivadas

class Narrativo : public Libro<int> {
public:

    Narrativo(string titulo, string autor, int ISBN, int anio, bool disponibilidad, int genero)
            : Libro(titulo, autor, ISBN, anio, disponibilidad, genero) {}

    void mostrar_datos() override {

        Libro::mostrar_datos();
        cout << "Genero: narrativo (1)" << endl;

    }

    void actualizar_datos() override {
        cout << "Actualizando datos del libro narrativo:" << endl;

        cout << "Nuevo titulo: ";
        cin >> titulo;

        cout << "Nuevo autor: ";
        cin >> autor;

        cout << "Nuevo ISBN: ";
        cin >> ISBN;

        cout << "Nuevo anio: ";
        cin >> anio;

        cout << "Estado actual: (1 para disponible, 0 para no disponible): ";
        cin >> disponibilidad;

    }
};


class Lirica : public Libro<int> {
public:

    Lirica(string titulo, string autor, int ISBN, int anio, bool disponibilidad, int genero)
            : Libro(titulo, autor, ISBN, anio, disponibilidad, genero) {}

    void mostrar_datos() override {

        Libro::mostrar_datos();
        cout << "Genero: lirica (2)" << endl;

    }

    void actualizar_datos() override {
        cout << "Actualizando datos del libro lirico..." << endl;

        cout << "Nuevo titulo: ";
        cin >> titulo;

        cout << "Nuevo autor: ";
        cin >> autor;

        cout << "Nuevo ISBN: ";
        cin >> ISBN;

        cout << "Nuevo anio: ";
        cin >> anio;

        cout << "Estado actual: (1 para disponible, 0 para no disponible): ";
        cin >> disponibilidad;

    }
};


class Poetico : public Libro<int> {
public:

    Poetico(string titulo, string autor, int ISBN, int anio, bool disponibilidad, int genero)
            : Libro(titulo, autor, ISBN, anio, disponibilidad, genero) {}

    void mostrar_datos() override {

        Libro::mostrar_datos();
        cout << "Genero: poetico (3)" << endl;

    }

    void actualizar_datos() override {
        cout << "Actualizando datos del libro poetico..." << endl;

        cout << "Nuevo titulo: ";
        cin >> titulo;

        cout << "Nuevo autor: ";
        cin >> autor;

        cout << "Nuevo ISBN: ";
        cin >> ISBN;

        cout << "Nuevo anio: ";
        cin >> anio;

        cout << "Estado actual: (1 para disponible, 0 para no disponible): ";
        cin >> disponibilidad;

    }
};


class Estudiante : public Usuarios<int> {
protected:

    string carrera;
    int semestre;

public:

    Estudiante(string nombre, int ID, int tipo, string carrera, int semestre)
            : Usuarios(nombre, ID, tipo), carrera(carrera), semestre(semestre) {}

    void actualizar_datos() override {
        cout << "Nuevo nombre: ";
        cin >> nombre;

        cout << "Nueva carrera: ";
        cin >> carrera;

        cout << "Nuevo semestre: ";
        cin >> semestre;

    }

    void mostrar_datos() override {

        Usuarios::mostrar_datos();
        cout << "carrera: " << carrera << endl;
        cout << "semestre: " << semestre << endl;

    }
};


class Profesor : public Usuarios<int> {
protected:

    string departamento;
    string titulo;

public:
    Profesor(string nombre, int ID, int tipo, string departamento, string titulo)
            : Usuarios(nombre, ID, tipo), departamento(departamento), titulo(titulo) {}

    void actualizar_datos() override {
        cout << "Nuevo nombre: ";
        cin >> nombre;

        cout << "Nuevo departamento: ";
        cin >> departamento;

        cout << "Nuevo titulo: ";
        cin >> titulo;

    }

    void mostrar_datos() override {

        Usuarios::mostrar_datos();
        cout << "Departamento: " << departamento << endl;
        cout << "Titulo: " << titulo << endl;

    }
};


class Investigador : public Usuarios<int> {
protected:

    string area_investigacion;
    string proyectos;

public:
    Investigador(string nombre, int ID, int tipo, string area_investigacion, string proyectos)
            : Usuarios(nombre, ID, tipo), area_investigacion(area_investigacion), proyectos(proyectos) {}

    void actualizar_datos() override {
        cout << "Nuevo nombre: ";
        cin >> nombre;

        cout << "Nueva area de investigacion: ";
        cin >> area_investigacion;

        cout << "Nuevos proyectos: ";
        cin >> proyectos;

    }

    void mostrar_datos() override {

        Usuarios::mostrar_datos();
        cout << "Area de investigacion: " << area_investigacion << endl;
        cout << "Proyectos: " << proyectos << endl;

    }
};


class Gerente {

private:
    vector<Libro<int>*> libros;
    vector<Usuarios<int>*> usuarios;
    vector<int> prestamos;

public:

    void agregar_libro(Libro<int>* libro) {
        libros.push_back(libro);
    }

    void agregar_usuario(Usuarios<int>* usuario) {
        usuarios.push_back(usuario);
    }

    void mostrar_libros() {
        cout << "Lista de libros:" << endl;
        for (size_t i = 0; i < libros.size(); ++i) {
            cout << "Indice " << i << ": ";
            libros[i] -> mostrar_datos();
            cout << endl;
        }
    }

    void mostrar_usuarios() {
        cout << "Lista de usuarios:" << endl;
        for (size_t i = 0; i < usuarios.size(); ++i) {
            cout << "Indice " << i << ": ";
            usuarios[i] -> mostrar_datos();
            cout << endl;
        }
    }

    void realizar_prestamo(int indice_usuario, int indice_libro) {
        prestamos.push_back(indice_usuario * libros.size() + indice_libro);
        guardar_prestamos_en_archivo();
    }

    void mostrar_prestamos() {
        cout << "Lista de prestamos:" << endl;
        for (auto indice : prestamos) {
            int indice_usuario = indice / libros.size();
            int indice_libro = indice % libros.size();
            cout << "Usuario: ";
            usuarios[indice_usuario]->mostrar_datos();
            cout << "Libro: ";
            libros[indice_libro]->mostrar_datos();
            cout << endl;
        }
    }

    void ordenar_libros_por_titulo() {
        sort(libros.begin(), libros.end(), [](Libro<int>* a, Libro<int>* b) {
            return a->get_titulo() < b->get_titulo();
        });
    }

    void guardar_prestamos_en_archivo() {
      try {
        ofstream archivo("prestamos.txt");
      if (!archivo.is_open()) {
          throw runtime_error("No se pudo abrir el archivo");
      }

      for (auto indice : prestamos) {
          archivo << indice << endl;
      }
        archivo.close();
        cout << "Prestamos guardados en prestamos.txt" << endl;
      } catch (const exception& e) {
          cerr << e.what() << endl;
    }
  }

    void cargar_prestamos_desde_archivo() {
      try {
        ifstream archivo("prestamos.txt");
      if (!archivo.is_open()) {
          throw runtime_error("No se pudo abrir el archivo");
      }

      prestamos.clear();
      int indice;

      while (archivo >> indice) {
          prestamos.push_back(indice);
      }
      archivo.close();
      cout << "Prestamos cargados desde prestamos.txt" << endl;
      } catch (const exception& e) {
        cerr << e.what() << endl;
      }
  }

};

int main() {
    Narrativo L_1 ("01", "Josesito", 123456789, 1605, true, 1);
    Lirica L_2 ("02", "Martha", 987654321, 1871, true, 2);
    Estudiante U_1 ("Grossman", 1001, 1, "Arquitectura", 3);
    Profesor U_2 ("Santiago", 2001, 2, "Ciencia", "Master");
    Investigador U_3 ("Joaquin", 3001, 3, "Gastronomía", "P_Lp_02");

    Gerente gerente;
    gerente.agregar_libro(&L_1);
    gerente.agregar_libro(&L_2);
    gerente.agregar_usuario(&U_1);
    gerente.agregar_usuario(&U_2);
    gerente.agregar_usuario(&U_3);


    gerente.ordenar_libros_por_titulo();
    gerente.mostrar_libros();


    gerente.mostrar_usuarios();

    gerente.realizar_prestamo(0, 1);
    gerente.realizar_prestamo(1, 0);

    gerente.mostrar_prestamos();


    gerente.cargar_prestamos_desde_archivo();
    gerente.mostrar_prestamos();

    return 0;
}

