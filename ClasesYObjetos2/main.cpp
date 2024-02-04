#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

class Materia
{
    private:
        int ClaveMateria;
        char Nombre[30];
        char ProfesorTit[30];
        char LibroTexto[30];
    protected:
    public:
        Materia() { ClaveMateria = 0; strcpy(Nombre, " "); strcpy(ProfesorTit, " "); strcpy(LibroTexto, " "); }
        Materia(int cm, const char n[], const char pt[], const char lt[]) { ClaveMateria = cm; strcpy(Nombre, n); strcpy(ProfesorTit, pt); strcpy(LibroTexto, lt); }

    bool operator==(const Materia& otro) const
    {
        return (ClaveMateria == otro.ClaveMateria);
    }

    bool operator!=(const Materia& otro) const
    {
        return !(*this == otro);
    }

    friend ostream& operator << (ostream &o, const Materia &mat)
    {
        o << "Clave: " << mat.ClaveMateria << endl;
        o << "Nombre: " << mat.Nombre << endl;
        o << "Profesor Titular: " << mat.ProfesorTit << endl;
        o << "Libro de texto: " << mat.LibroTexto << endl;
        return o;
    }
    friend istream& operator >> (istream &i, Materia &mat)
    {
        cout << "Clave: ";
        i >> mat.ClaveMateria;
        cout << "Nombre: ";
        i >> mat.Nombre;
        cout << "Profesor Titular: ";
        i >> mat.ProfesorTit;
        cout << "Libro de texto: ";
        i >> mat.LibroTexto;

        return i;
    }

    Materia operator+(const Materia& otro) const
    {
        Materia resultado(*this);
        strcat(resultado.Nombre, " y ");
        strcat(resultado.Nombre, otro.Nombre);
        return resultado;
    }

    void ProfesorTitu(const char profesorTit[30])
    {
        cout << "\t\t\t\t------------------- CAMBIAR PROFESOR TITULAR -------------------\n" << endl;
        cout << "Ingresa nombre del nuevo profesor: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignora caracteres adicionales en el buffer de entrada
        cin.getline(ProfesorTit, 30);

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Error: Has ingresado más caracteres de los permitidos. El nombre del profesor se truncará a 30 caracteres..." << endl;
        }
    }

    bool buscarPorClave(int clave) const
    {
        return (clave == ClaveMateria);
    }

    void ActualizaClave(int nuevaClave)
    {
        ClaveMateria = nuevaClave;
    }

    void Imprime()
    {
        cout << "\t\t\t------------------- OFERTA DE AGENDA DE AUTORREGISTRO -------------------\n" << endl;
        cout << "Clave de la materia: " << ClaveMateria << endl;
        cout << "Nombre de la materia: " << Nombre << endl;
        cout << "Profesor titular: " << ProfesorTit << endl;
        cout << "Libro de texto de la materia: " << LibroTexto << endl;
        system("PAUSE");
        system("cls");
    }
};

enum OPTIONS
{
    OPT_SALIR,     //0
    OPT_CONSULTA,  //1
    OPT_MODIFICAR  //2
};

enum OPTIONSMOD
{
    OPT_MODSALIR,       //0
    OPT_CAMBIARCLAVE,     //1
    OPT_CAMBIARPROFE,    //2
};

int main()
{
    setlocale(LC_ALL, "spanish");

    int opt;

    Materia Programacion(123456, "Programación", "Dr Aquiles A Prieto", "Python para mongoles 3ra edición");
    Materia BasesDeDatos(987654, "Bases de Datos", "Mtro Francisco Gido Rico", "Bases de datos 101 Chuntaro ED");
    std::cin>>Programacion;

    do
    {
        cout << "\t     --------------------------------------- GdlIT ---------------------------------------\n\n" << endl;
        cout << "(1) Consultar oferta de materias.\n" << endl;
        cout << "(2) Modificar datos de materia.\n" << endl;
        cout << "(0) Salir.\n" << endl;
        cout << "Seleccione una opción: ";
        cin >> opt;

        system("cls");

        switch (opt)
        {
        case OPT_CONSULTA:
            int clave;

            cout << "\t\t\t------------------- CONSULTA DE OFERTA DE AUTORREGISTRO -------------------\n" << endl;
            cout << "\nIngresa la clave de la materia: ";
            cin >> clave;

            system("cls");

            if (Programacion.buscarPorClave(clave))
            {
                Programacion.Imprime();
            }
            else if (BasesDeDatos.buscarPorClave(clave))
            {
                BasesDeDatos.Imprime();
            }
            else
            {
                cout << "\n\nLa clave que ingresaste no corresponde a ninguna materia en oferta." << endl;
                system("PAUSE");
                system("cls");
            }
            break;

        case OPT_MODIFICAR:
            int optMod;
            do
            {
                cout << "\t\t\t------------------ MODIFICAR DATOS DE MATERIA ------------------\n" << endl;
                cout << "(1) Cambiar clave de la materia.\n" << endl;
                cout << "(2) Cambiar el profesor titular de la materia.\n" << endl;
                cout << "(0) Salir.\n" << endl;
                cout << "Seleccione una opción: ";
                cin >> optMod;

                system("cls");

                switch (optMod)
                {
                    case OPT_CAMBIARCLAVE:
                        cout << "\t\t\t\t------------------- MODIFICAR CLAVE -------------------\n" << endl;
                        cout << "\nIngresa la clave de la materia: ";
                        cin >> clave;

                        system("cls");

                        if (Programacion.buscarPorClave(clave))
                        {
                            int nuevaClave;
                            cout << "\t\t\t\t------------------- MODIFICAR CLAVE -------------------\n" << endl;
                            cout << "Ingresa la clave nueva: ";
                            cin >> nuevaClave;
                            Programacion.ActualizaClave(nuevaClave);
                            system("cls");
                        }
                        else if (BasesDeDatos.buscarPorClave(clave))
                        {
                            int nuevaClave;
                            cout << "\t\t\t\t------------------- MODIFICAR CLAVE -------------------\n" << endl;
                            cout << "Ingresa la clave nueva: ";
                            cin >> nuevaClave;
                            BasesDeDatos.ActualizaClave(nuevaClave);
                            system("cls");
                        }
                        else
                        {
                            cout << "\n\nLa clave que ingresaste no corresponde a ninguna materia." << endl;
                            system("PAUSE");
                            system("cls");
                        }
                        break;

                    case OPT_CAMBIARPROFE:
                        cout << "\t\t\t\t------------------- CAMBIAR PROFESOR -------------------\n" << endl;
                        cout << "\nIngresa la clave de la materia a modificar: ";
                        cin >> clave;

                        system("cls");

                        if (Programacion.buscarPorClave(clave))
                        {
                            Programacion.ProfesorTitu("Nuevo Profe");
                            system("PAUSE");
                            system("cls");
                        }
                        else if (BasesDeDatos.buscarPorClave(clave))
                        {
                            BasesDeDatos.ProfesorTitu("Nuevo Profe");
                            system("PAUSE");
                            system("cls");
                        }
                        else
                        {
                            cout << "\n\nLa clave que ingresaste no corresponde a ningún profesor afiliado a la institución." << endl;
                            system("PAUSE");
                            system("cls");
                        }
                        break;
                    case OPT_MODSALIR:
                        {
                            cout << "\n\n\n\n\n\n\t\t\t\t\t\tVolviendo al menú principal...\n\n\n\n" << endl;
                            system("cls");
                        }
                        break;
                    default:
                        cout << "Opción inválida..." << endl;
                        system("PAUSE");
                        system("cls");
                        break;
                    }
            } while(optMod != OPT_MODSALIR);
            break;

        case OPT_SALIR:
            cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tSaliendo...\n\n\n\n" << endl;
            break;

        default:
            cout << "Opción inválida..." << endl;
            system("PAUSE");
            system("cls");
            break;
        }
    }while(opt != OPT_SALIR);

    return 0;
}

