#include <iostream>

using namespace std;

class Vehiculo {
	protected:
		string numeroPlaca, color, marca;
		float velocimetro;
	public:
		Vehiculo(){
			numeroPlaca = "A1A-111";
			color = "negro";
			marca = "Toyota";
			velocimetro = 0;
		}
		Vehiculo(string nPlaca, string c, string m, float v){
			numeroPlaca = nPlaca;
			color = c;
			marca = m;
			velocimetro = v;
		}
		void mostrarDatos(){
			cout << "\nEl numero de placa del vehiculo es " << numeroPlaca << endl;
			cout << "El color del vehiculo es " << color << endl;
			cout << "La marca del vehiculo es " << marca << endl;
			cout << "El velocimetro indica " << velocimetro << endl;
		}
		void cambiarVelocidad(float nuevaVelo){
			velocimetro = nuevaVelo;
		}
};

class Automovil : public Vehiculo {
	private:
		int cantidadPuertas, cantidadPasajeros;
	public:
		Automovil() : Vehiculo(){
			cantidadPuertas = 1;
			cantidadPasajeros = 0;
		}
		Automovil(string nP, string c, string m, float v, int cPu, int cPa) : Vehiculo(nP, c, m, v){
			cantidadPuertas = cPu;
			cantidadPasajeros = cPa;
		}
		void mostrarAutomovil(){
			mostrarDatos();
			cout << "El numero de puertas es " << cantidadPuertas << endl;
			cout << "El numero de pasajeros es " << cantidadPasajeros << endl;
		}
		void subirPasajeros(int paSuben){
			cantidadPasajeros += paSuben;
		}
		void bajarPasajeros(int paBajan){
			cantidadPasajeros -= paBajan;
		}
};

class Camion : public Vehiculo {
	private:
		string carga;
	public:
		Camion() : Vehiculo(){
			carga = "";
		}
		Camion(string nP, string c, string m, float v, string ca) : Vehiculo(nP, c, m, v){
			carga = ca;
		}
		void mostrarCarga(){
			cout << "\nLa carga del camion es " << carga;
		}
		void cambiarCarga(string nuevaCarga){
			carga = nuevaCarga;
		}
};

int main() {
    string placa, color, marca, carga;
    float velocidad;
    int cantPuertas, cantPasajeros;
    int opcion, pasajerosModificar;
    string nuevaCarga;
    float nuevaVelocidad;
    
    cout << "=== SISTEMA DE GESTION DE VEHICULOS ===" << endl;
    cout << "1. Crear y gestionar Automovil" << endl;
    cout << "2. Crear y gestionar Camion" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcion;
    
    switch(opcion) {
        case 1: {
            cout << "\n=== CREAR NUEVO AUTOMOVIL ===" << endl;
            cout << "Ingrese numero de placa: ";
            cin >> placa;
            cout << "Ingrese color: ";
            cin >> color;
            cout << "Ingrese marca: ";
            cin >> marca;
            cout << "Ingrese velocidad inicial: ";
            cin >> velocidad;
            cout << "Ingrese cantidad de puertas: ";
            cin >> cantPuertas;
            cout << "Ingrese cantidad de pasajeros inicial: ";
            cin >> cantPasajeros;
            
            Automovil auto1(placa, color, marca, velocidad, cantPuertas, cantPasajeros);
            
            do {
                cout << "\n=== MENU AUTOMOVIL ===" << endl;
                cout << "1. Mostrar datos del automovil" << endl;
                cout << "2. Cambiar velocidad" << endl;
                cout << "3. Subir pasajeros" << endl;
                cout << "4. Bajar pasajeros" << endl;
                cout << "5. Salir" << endl;
                cout << "Ingrese su opcion: ";
                cin >> opcion;
                
                switch(opcion) {
                    case 1:
                        auto1.mostrarAutomovil();
                        break;
                    case 2:
                        cout << "Ingrese nueva velocidad: ";
                        cin >> nuevaVelocidad;
                        auto1.cambiarVelocidad(nuevaVelocidad);
                        cout << "Velocidad actualizada" << endl;
                        break;
                    case 3:
                        cout << "Ingrese cantidad de pasajeros a subir: ";
                        cin >> pasajerosModificar;
                        auto1.subirPasajeros(pasajerosModificar);
                        cout << "Pasajeros agregados" << endl;
                        break;
                    case 4:
                        cout << "Ingrese cantidad de pasajeros a bajar: ";
                        cin >> pasajerosModificar;
                        auto1.bajarPasajeros(pasajerosModificar);
                        cout << "Pasajeros removidos" << endl;
                        break;
                }
            } while(opcion != 5);
            break;
    	}
        case 2: {
            cout << "\n=== CREAR NUEVO CAMION ===" << endl;
            cout << "Ingrese numero de placa: ";
            cin >> placa;
            cout << "Ingrese color: ";
            cin >> color;
            cout << "Ingrese marca: ";
            cin >> marca;
            cout << "Ingrese velocidad inicial: ";
            cin >> velocidad;
            cout << "Ingrese tipo de carga: ";
            cin.ignore();
            getline(cin, carga);
            
            Camion camion1(placa, color, marca, velocidad, carga);
            
            do {
                cout << "\n=== MENU CAMION ===" << endl;
                cout << "1. Mostrar datos del camion" << endl;
                cout << "2. Cambiar velocidad" << endl;
                cout << "3. Mostrar carga" << endl;
                cout << "4. Cambiar carga" << endl;
                cout << "5. Salir" << endl;
                cout << "Ingrese su opcion: ";
                cin >> opcion;
                
                switch(opcion) {
                    case 1:
                        camion1.mostrarDatos();
                        break;
                    case 2:
                        cout << "Ingrese nueva velocidad: ";
                        cin >> nuevaVelocidad;
                        camion1.cambiarVelocidad(nuevaVelocidad);
                        cout << "Velocidad actualizada" << endl;
                        break;
                    case 3:
                        camion1.mostrarCarga();
                        break;
                    case 4:
                        cout << "Ingrese nueva carga: ";
                        cin.ignore();
                        getline(cin, nuevaCarga);
                        camion1.cambiarCarga(nuevaCarga);
                        cout << "Carga actualizada" << endl;
                        break;
                }
            } while(opcion != 5);
            break;
    	}
        
        default:
            cout << "Opcion no valida" << endl;
    }
    
    return 0;
}