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
};

class Circulo : public Figura {
	private:
		float radio;
	public:
		Circulo(){
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
		Rectangulo(string c, float b, float h) : Figura(c){
			base = b;
			altura = h;
		}
};

int main(){
	Triangulo tr("rojo", );
}