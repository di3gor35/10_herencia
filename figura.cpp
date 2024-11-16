#include <iostream>
#include <cmath>

using namespace std;

class Figura {
	protected:
		string color;
	public:
		Figura(){
			color = "blanco";
		}
		Figura(string nuevoColor){
			color = nuevoColor;
		}
		string obtenerColor(){
			return color;
		}
};

class Circulo : public Figura {
	private:
		float radio;
	public:
		Circulo() : Figura(){
			radio = 1;
		}
		Circulo(string c, int r) : Figura(c){
			radio = r;
		}
		float calcularArea(){
			return M_PI*radio*radio;
		}
		float calcularPerimetro(){
			return M_PI*2*radio;
		}
};

class Rectangulo : public Figura {
	private:
		float base, altura;
	public:
		Rectangulo() : Figura(){
			base = 2;
			altura = 1;
		}
		Rectangulo(string c, float b, float h) : Figura(c){
			base = b;
			altura = h;
		}
		float calcularArea(){
			return base*altura;
		}
};

class Triangulo : public Figura {
	private:
		float base, altura;
		string tipo;
	public:
		Triangulo() : Figura(){
			base = 1;
			altura = 2;
			tipo = "acutangulo";
		}
		Triangulo(string c, float b, float h, string t) : Figura(c){
			base = b;
			altura = h;
			tipo = t;
		}
		float calcularArea(){
			return (base*altura)/2;
		}
};

int main() {
    string color;
    float radio, base, altura;
    string tipoTriangulo;
    char opcion;
    
    
    cout << "Crear nuevo circulo:" << endl;
    cout << "Ingrese color: ";
    cin >> color;
    cout << "Ingrese radio: ";
    cin >> radio;
    
    Circulo circulo2(color, radio);
    cout << "\nCirculo creado - Color: " << circulo2.obtenerColor() 
         << "\nArea: " << circulo2.calcularArea() 
         << "\nPerimetro: " << circulo2.calcularPerimetro() << endl;
    
  
    cout << "\nCrear nuevo rectangulo:" << endl;
    cout << "Ingrese color: ";
    cin >> color;
    cout << "Ingrese base: ";
    cin >> base;
    cout << "Ingrese altura: ";
    cin >> altura;
    
    Rectangulo rectangulo2(color, base, altura);
    cout << "\nRectangulo creado - Color: " << rectangulo2.obtenerColor() 
         << "\nArea: " << rectangulo2.calcularArea() << endl;

    cout << "\nCrear nuevo triangulo:" << endl;
    cout << "Ingrese color: ";
    cin >> color;
    cout << "Ingrese base: ";
    cin >> base;
    cout << "Ingrese altura: ";
    cin >> altura;
    cout << "Ingrese tipo de triangulo: ";
    cin >> tipoTriangulo;
    
    Triangulo triangulo2(color, base, altura, tipoTriangulo);
    cout << "\nTriangulo creado - Color: " << triangulo2.obtenerColor() 
         << "\nArea: " << triangulo2.calcularArea() << endl;
    
    return 0;
}