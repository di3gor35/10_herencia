#include <iostream>

using namespace std;

class Vehiculo {
	protected:
		string numeroPlaca, color, marca;
		float velocimetro;
	public:
		Vehiculo(){
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
		Automovil(){
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
		Camion(){
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

int main(){
	
	Vehiculo ve1("Z4C-142", "blanco", "Nissan", 50);
	
	ve1.mostrarDatos();
	
	Automovil aut("Y4C-987", "azul", "Toyota", 50, 4, 1);
	
	aut.mostrarAutomovil();	
	
	Camion cam("Z9J-154", "azul", "Toyota", 50, "manzanas");
	
	cam.mostrarCarga();
	
	return 0;
}