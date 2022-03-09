#include <iostream>

using namespace std;

class Retangulo {
    public:
	    void Display();
        void Display_area();
        void Display_perimetro();
        void Draw();
        void SetValues( double a, double c );

    private:
	    double comp;   // Length of a box
    	double altura; // Height of a box
};

void Retangulo::Display() {
    cout << "O rectangulo de " << comp << " X " << altura << endl;
}

void Retangulo::Display_area() {
    double area = altura * comp;

    cout << "O rectangulo de " << comp << " X " << altura << " area= " << area << endl;
}

void Retangulo::Display_perimetro() {
    double perimetro = 2 * ( altura + comp );

    cout << "O rectangulo de " << comp << " X " << altura << " perimetro= " << perimetro << endl;
}

void Retangulo::Draw() {
    for( int i = 0; i < altura; i++ ) {
        for( int j = 0; j < comp; j++ )
            cout << "*";
        cout << endl;
    }
}

void Retangulo::SetValues( double a, double c ) {
    altura = a;
    comp = c;
}

class Paralelipipedo : Retangulo {
    public:
	    void Display();
        void Display_volume();
        void Rodar_solido();
        void SetValues( double a, double c, double p, bool e );

    private:
	    double prof;   // Depth of a box
        bool estado;   // true is horizontal, otherwise vertical
};

void Paralelipipedo::Display() {
    cout << "O paralelipipedo de " << comp << " X " << altura << " X " << prof << " <-" << ( estado ? "horizontal" : "vertical" ) << endl;
}

void Paralelipipedo::Display_area() {
    double volume = altura * comp * prof;

    cout << "O paralelipipedo de " << comp << " X " << altura << " X " << prof << " volume= " << volume << endl;
}

void Paralelipipedo::Rodar_solido() {
    estado = not estado;
}

void Paralelipipedo::SetValues( double a, double c, double p, bool e ) {
    altura = a;
    comp = c;
    prof = p;
    estado = e;
}

int main() {
	Paralelipipedo P1;
    Paralelipipedo P2;

    P1.SetValues( 5.0, 6.0, 7.0, true );
    P2.SetValues( 5.0, 7.0, 8.0, false );
    
    P1.Display();
    P1.Display_volume();
    P2.Display();
    P2.Display_volume();

    P1.Rodar_solido();
    P1.Display();
    P1.Rodar_solido();
    P1.Display();

	return 0;
}