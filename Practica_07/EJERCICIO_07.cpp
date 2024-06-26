#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

//Clase Libro
class Libro{
protected:
  string titulo;
  string autor;
  int ISBN;
  int anio;
  bool disponibilidad;

public:
  Libro(string _titulo, string _autor, int _ISBN, int _anio, bool _disponibilidad) {
    this -> titulo = _titulo;
    this -> autor = _autor;
    this -> ISBN = _ISBN;
    this -> anio = _anio;
    this -> disponibilidad = _disponibilidad;
  }

  string get_Titulo() {
    return titulo;
  }

  string get_Autor(){
    return autor;
  }

  int get_ISBN(){
    return ISBN;
  }

  int get_Anio(){
    return anio;
  }

  bool get_Disponibilidad(){
    return disponibilidad;
  }

  virtual void MostrarDatos(){
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Anio: " << anio << endl;
    cout << "Disponibilidad: " << disponibilidad << endl;
  };

  virtual void ActualizarDatos() = 0;
};

//Clase Usuarios
class Usuarios{
protected:
  string nombre;
  int ID;

public:
  Usuarios(string _nombre, int _ID){
    this -> nombre = _nombre;
    this -> ID = _ID;
  }

  string get_Nombre(){
    return nombre;
  }

  int get_ID(){
    return ID;
  }

  virtual void MostrarDatos(){
    cout << "Nombre: " << nombre << endl;
    cout << "ID: " << ID << endl;
  };

  virtual void ActualizarDatos() = 0;
};

// Clase Narrativo
class Narrativo : public Libro {
protected:
  int genero = 1;

public:
  Narrativo(string _titulo, string _autor, int _ISBN, int _anio, bool _disponibilidad, const int _genero) : Libro(_titulo, _autor, _ISBN, _anio, _disponibilidad) {
    this -> genero = _genero;
  }

  int get_Genero() {
    return genero;
  }

  void MostrarDatos() override {
    Libro::MostrarDatos();
    cout << "Genero: Narrativo (1)" << endl;
  }

  void ActualizarDatos() override {
    cout << "Actualizando datos del libro narrativo..." << endl;
    cout << "Nuevo titulo: ";
    cin >> titulo;
    cout << "Nuevo autor: ";
    cin >> autor;
    cout << "Nuevo ISBN: ";
    cin >> ISBN;
    cout << "Nuevo anio: ";
    cin >> anio;
    cout << "Nueva disponibilidad (1 para disponible, 0 para no disponible): ";
    cin >> disponibilidad;
  }
};

// Clase Lirica
class Lirica : public Libro {
protected:
  int genero = 2;

public:
  Lirica(string _titulo, string _autor, int _ISBN, int _anio, bool _disponibilidad, const int _genero) : Libro(_titulo, _autor, _ISBN, _anio, _disponibilidad) {
    this -> genero = _genero;
  }

  void MostrarDatos() override {
    Libro::MostrarDatos();
    cout << "Genero: Lirica (2)" << endl;
  }

  void ActualizarDatos() override {
    cout << "Actualizando datos del libro lirico..." << endl;
    cout << "Nuevo titulo: ";
    cin >> titulo;
    cout << "Nuevo autor: ";
    cin >> autor;
    cout << "Nuevo ISBN: ";
    cin >> ISBN;
    cout << "Nuevo anio: ";
    cin >> anio;
    cout << "Nueva disponibilidad (1 para disponible, 0 para no disponible): ";
    cin >> disponibilidad;
  }
};

// Clase Poetico
class Poetico : public Libro {
protected:
  int genero = 3;

public:
  Poetico(string _titulo, string _autor, int _ISBN, int _anio, bool _disponibilidad, const int _genero) : Libro(_titulo, _autor, _ISBN, _anio, _disponibilidad) {
    this -> genero = _genero;
  }

  void MostrarDatos() override {
    Libro::MostrarDatos();
    cout << "Genero: Poetico (3)" << endl;
  }

  void ActualizarDatos() override {
    cout << "Actualizando datos del libro poetico..." << endl;
    cout << "Nuevo titulo: ";
    cin >> titulo;
    cout << "Nuevo autor: ";
    cin >> autor;
    cout << "Nuevo ISBN: ";
    cin >> ISBN;
    cout << "Nuevo anio: ";
    cin >> anio;
    cout << "Nueva disponibilidad (1 para disponible, 0 para no disponible): ";
    cin >> disponibilidad;
  }
};

//Clase Estudiante
class Estudiante : public Usuarios{
protected:
  const int tipo = 1;
  string carrera;
  int semestre;

public:
  Estudiante(string _nombre, int _ID, string _carrera, int _semestre) : Usuarios(_nombre, _ID), carrera(_carrera), semestre(_semestre) {}

  void ActualizarDatos() override{
    cout << "Nuevo nombre: ";
    cin >> nombre;
    cout << "Nueva carrera: ";
    cin >> carrera;
    cout << "Nuevo semestre: ";
    cin >> semestre;
  }

  void MostrarDatos() override {
    Usuarios::MostrarDatos();
    cout << "Tipo: Estudiante (1)" << endl;
    cout << "Carrera: " << carrera << endl;
    cout << "Semestre: " << semestre << endl;
}
};

//CLase profesor
class Profesor : public Usuarios {
protected:
  const int tipo = 2;
  string departamento;
  string titulo;

public:
  Profesor(string _nombre, int _ID, string _departamento, string _titulo) : Usuarios(_nombre, _ID), departamento(_departamento), titulo(_titulo) {}

  void ActualizarDatos() override {
    cout << "Nuevo nombre: ";
    cin >> nombre;
    cout << "Nuevo departamento: ";
    cin >> departamento;
    cout << "Nuevo título ";
    cin >> titulo;
  }

  void MostrarDatos() override {
    Usuarios::MostrarDatos();
    cout << "Tipo: Profesor (2)" << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Título: " << titulo << endl;
  }
};

//Clase investigador
class Investigador : public Usuarios {
protected:
  const int tipo = 3;
  string areaInvestigacion;
  string proyectos;

public:
  Investigador(string _nombre, int _ID, string _areaInvestigacion, string _proyectos) : Usuarios(_nombre, _ID), areaInvestigacion(_areaInvestigacion), proyectos(_proyectos) {}

void ActualizarDatos() override {
  cout << "Nuevo nombre: " << endl;
  cin >> nombre;
  cout << "Nuevo area de investigacion: " << endl;
  cin >> areaInvestigacion;
  cout << "Nuevos proyectos: ";
  cin >> proyectos;
}

void MostrarDatos() override {
  Usuarios :: MostrarDatos();
  cout << "Tipo: investigador (3)" << endl;
  cout << "Área de investigación: " << areaInvestigacion << endl;
  cout << "Proyectos: " << proyectos << endl;
}
};


// Clase Gerente
class Gerente {
private:
    vector<Libro*> libros;
    vector<Usuarios*> usuarios;
    vector<int> prestamos;

public:
    void AgregarLibro(Libro* libro) {
        libros.push_back(libro);
    }

    void AgregarUsuario(Usuarios* usuario) {
        usuarios.push_back(usuario);
    }

    void MostrarLibros() {
        cout << "******* Lista de Libros *******" << endl;
        for (size_t i = 0; i < libros.size(); ++i) {
            cout << "Índice " << i << ": ";
            libros[i]->MostrarDatos();
            cout << endl;
        }
    }

    void MostrarUsuarios() {
        cout << "******* Lista de Usuarios *******" << endl;
        for (size_t i = 0; i < usuarios.size(); ++i) {
            cout << "Índice " << i << ": ";
            usuarios[i]->MostrarDatos();
            cout << endl;
        }
    }

    void RealizarPrestamo(int indiceUsuario, int indiceLibro) {
        prestamos.push_back(indiceUsuario * libros.size() + indiceLibro);
        GuardarPrestamosEnArchivo();
    }


    void MostrarPrestamos() {
        cout << "******* Lista de Prestamos *******" << endl;
        for (auto indice : prestamos) {
            int indiceUsuario = indice / libros.size();
            int indiceLibro = indice % libros.size();
            cout << "Usuario: ";
            usuarios[indiceUsuario]->MostrarDatos();
            cout << "Libro: ";
            libros[indiceLibro]->MostrarDatos();
            cout << endl;
        }
    }

private:

    void GuardarPrestamosEnArchivo() {
        ofstream archivo("prestamos.txt");
        if (archivo.is_open()) {
            for (auto indice : prestamos) {
                archivo << indice << endl;
            }
            archivo.close();
            cout << "Prestamos guardados en prestamos.txt" << endl;
        } else {
            cout << "No se pudo abrir el archivo prestamos.txt para guardar los préstamos." << endl;
        }
    }
};

int main() {

    Narrativo libro1("A", "Autorx", 123456789, 1605, true, 1);
    Lirica libro2("B", "Autory", 987654321, 1871, true, 2);
    Estudiante usuario1("C", 1001, "Ingenieria", 3);
    Profesor usuario2("Castillo", 2001, "Ciencias", "Maestro");
    Investigador usuario3("Sideral", 3001, "Fisica", "Proyecto 69");

    Gerente gerente;
    gerente.AgregarLibro(&libro1);
    gerente.AgregarLibro(&libro2);
    gerente.AgregarUsuario(&usuario1);
    gerente.AgregarUsuario(&usuario2);
    gerente.AgregarUsuario(&usuario3);

    gerente.MostrarLibros();
    cout << endl;
    gerente.MostrarUsuarios();


    gerente.RealizarPrestamo(0, 1);
    gerente.RealizarPrestamo(1, 0);


    gerente.MostrarPrestamos();

    return 0;
}