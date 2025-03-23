#include <iostream>
#include <string>

using namespace std;

class Instrumento {
    private:
        string nombre;
        float precio;
        int cantidad;

    public:
        Instrumento(string nombre, float precio, int cantidad) : nombre(nombre), precio(precio), cantidad(cantidad) {}

        string getNombre() const {
            return nombre;
        }

        float getPrecio() const {
            return precio;
        }

        int getCantidad() const {
            return cantidad;
        }

        void setCantidad(int cantidad) {
            this->cantidad = cantidad;
        }
};

class Factura {
    private:
        string nombreCliente;
        string fecha;
        float total;

    public:
        Factura(string nombreCliente, string fecha, float total) : nombreCliente(nombreCliente), fecha(fecha), total(total) {}

        string getNombreCliente() const {
            return nombreCliente;
        }

        string getFecha() const {
            return fecha;
        }

        float getTotal() const {
            return total;
        }

        void imprimir() const {
            cout << "Factura" << endl;
            cout << "--------------------------------------" << endl;
            cout << "Cliente: " << nombreCliente << endl;
            cout << "Fecha: " << fecha << endl;
            cout << "Total a pagar: $" << total << endl;
            cout << "--------------------------------------" << endl;
        }
};

void mostrarMenu() {
    cout << "Bienvenido a la Tienda de Instrumentos" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Guitarras" << endl;
    cout << "2. Baterías" << endl;
    cout << "3. Teclados" << endl;
    cout << "4. Salir" << endl;
    cout << "--------------------------------------" << endl;
}

void mostrarInstrumentos(const string& tipo, const Instrumento* instrumentos, int cantidad) {
    cout << "Instrumentos disponibles - " << tipo << endl;
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". " << instrumentos[i].getNombre() << " - $" << instrumentos[i].getPrecio() << endl;
    }
    cout << "--------------------------------------" << endl;
}

void comprarInstrumento(Instrumento* instrumentos, int cantidad, Factura& factura) {
    int opcion;
    int cantidadComprar;

    cout << "Ingrese el número del instrumento que desea comprar: ";
    cin >> opcion;

    if (opcion >= 1 && opcion <= cantidad) {
        cout << "Ingrese la cantidad que desea comprar: ";
        cin >> cantidadComprar;

        if (cantidadComprar > 0 && cantidadComprar <= instrumentos[opcion - 1].getCantidad()) {
            float subtotal = instrumentos[opcion - 1].getPrecio() * cantidadComprar;
            cout << "El subtotal a pagar es: $" << subtotal << endl;

            // Actualizar cantidad disponible
            instrumentos[opcion - 1].setCantidad(instrumentos[opcion - 1].getCantidad() - cantidadComprar);

            // Agregar al total de la factura
            factura = Factura(factura.getNombreCliente(), factura.getFecha(), factura.getTotal() + subtotal);
        } else {
            cout << "La cantidad ingresada no es válida." << endl;
        }
    } else {
        cout << "La opción ingresada no es válida." << endl;
    }
}

int main() {
    Instrumento guitarras[] = {Instrumento("Guitarra Eléctrica", 500, 5), Instrumento("Guitarra Acústica", 300, 10)};
    Instrumento baterias[] = {Instrumento("Batería Electrónica", 1000, 3), Instrumento("Bateria", 340, 200)};

    int opcion;
    Factura factura("Sin Nombre", "Sin Fecha", 0);

    do {
        mostrarMenu();
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarInstrumentos("Guitarras", guitarras, sizeof(guitarras) / sizeof(guitarras[0]));
                comprarInstrumento(guitarras, sizeof(guitarras) / sizeof(guitarras[0]), factura);
                break;
            case 2:
                mostrarInstrumentos("Baterías", baterias, sizeof(baterias) / sizeof(baterias[0]));
                comprarInstrumento(baterias, sizeof(baterias) / sizeof(baterias[0]), factura);
                break;
            case 3:
                cout << "No hay teclados disponibles en este momento." << endl;
                break;
            case 4:
                factura.imprimir();
                cout << "Gracias por visitar la Tienda de Instrumentos. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "La opción ingresada no es válida." << endl;
                break;
        }

        cout << endl;
    } while (opcion != 4);

    return 0;
}