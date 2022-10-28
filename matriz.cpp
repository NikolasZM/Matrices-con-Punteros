#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;
#define	GREEN 	"\x1B[32m"
#define	DF 		"\x1B[39m"

class matriz{
public:
    int **mat;
    int filas;
    int columnas;
    matriz(int f = 0, int c = 0){
        filas = f;
        columnas = c;
        if ((f > 0)&&(c > 0)){
            mat = new int*[filas];      
            for(int i{0}; i < filas; ++i){
                mat[i] = new int[columnas];
            }
            }else {
                mat = nullptr;
            }
            for(int i{0}; i < filas; ++i){
                for(int a{0}; a < columnas; ++a){
                    mat[i][a]= 0;
                }
            }
    }

    void getTamaño(){
        cout << "\n\nfilas: " << filas << "\nColumnas: " << columnas << "\n" << "___________" << "\n\n";
    }

	void funcion_01() {		//funcion_01
		srand(time(NULL));
		for (int i{0};i<filas;++i) {
			for (int j{0};j<columnas;++j) {
				mat[i][j]=rand() % 100;
			}
		}
		cout<<GREEN<<"\nMatriz Creada\n"<<DF;
	}

	void funcion_02() {		//funcion_02
		for (int i{0};i<filas;++i) {
			cout<<"| ";
			for (int j{0};j<columnas;++j) {	
				cout<<setw(3)<<mat[i][j]<<" ";
			}
			cout<<"|\n";
		}
	}

void funcion_03() {
	int fil,col,x;
	cout<<"\nIngresa el valor de las filas.";
	cin>>fil;
	cout<<"\nIngresa el valor de las columnas.";
	cin>>col;
	cout<<"\nIngresa el nuevo valor.";
	cin>>x;
	if ((0>fil)&&(fil<filas)&&(0>col)&&(col<columnas)) {
	mat[fil][col]=x;
	cout<<GREEN<<"\nEl valor fue modificado exitosamente.\n"<<DF;
	}else {
		cout<<"Los valores ingresados no son correctos";
	}

}

void funcion_04(){
	for(int f{0}; f < filas ; ++f){
		for(int c{0}; c < columnas ; ++c){

			if(f == c){
				mat[f][c] = 0;
			}

		}
	}
	cout<<GREEN<<"\nLa digonal es igual a 0.\n"<<DF;
}

	void funcion_05() {
		int a,b,c;
        int a1{0},b1{0},c1{0};

		while (true) {
		
            cout<<"\nIngresa el primer numero a buscar\n>>";
            cin>>a;
            cout<<"\nIngresa el segundo numero a buscar\n>>";
            cin>>b;
            cout<<"\nIngresa el tercer numero a buscar\n>>";
            cin>>c;
		if ((0<=a<100)&&(0<=b<100)&&(0<=c<100)) {
    	for (int i{0};i<filas;++i) {
        for (int j{0};j<columnas;++j) {
            if (mat[i][j]==a) {
                ++a1;
            }else if (mat[i][j]==b) {
                ++b1;
            }else if (mat[i][j]==c) {
                ++c1;
            }else {
                continue;
            }
        }
    }
    break;
	}else {
		cout<<"\nUn valor ingresado no es valido, recuerda que los numeros deben estar entre 0 y 99\n";
		continue	;
	}
	}
	        cout<< GREEN <<"El numero "<< DF <<a<<" se repite "<<a1<<" veces.\n";
            cout<< GREEN <<"El numero "<< DF <<b<<" se repite "<<b1<<" veces.\n";
            cout<< GREEN <<"El numero "<< DF <<c<<" se repite "<<c1<<" veces.\n";
}

void funcion_06() {
        int a,b;
        cout<<"\nIngresa el numero de 2 cifras a buscar.\n>>";
        cin>>a;
        cout<<"\nIngresa el numero entre 100 y 200 que será su reemplazo.\n>>";
        cin>>b;
        while(true) {
		if ((0<=a)&&(a<100)&&(99<b)&&(b<201)) {
		int aux{0};
		for (int i{0};i<filas;++i) {
	        for (int j{0};j<columnas;++j) {
      		if (mat[i][j]==a) {
	      		mat[i][j]=b;
      			++aux;
      		}
      		}
    	}  
    	if (aux==0) {
    		cout<<GREEN<<"\nNo se encontro ningun valor de ese tipo."<<DF;
    	}else {
	    	cout<<GREEN<<"\nLos valores fueron cambiados"<<DF;
	    }
		break;
		}else {
			cout<<"\nUno o mas valores son incorrectos, recuerda que el primer numero debe estar entre 0 y 99, y el segundo numero entre 100 y 200\n";
			continue;
		}
	}
	}

	void funcion_07(){

	int aux{0};

	for(int f{0}; f < filas ; ++f){
		for(int c{0}; c < columnas ; ++c){
			if (mat[f][c]%5 == 0){
				mat[f][c] *= 10;
				++aux;
			}
		}
	}

	if(aux == 0 ){
		cout<<GREEN<<"\nNo hay multiplos de 5\n"<<DF;
	}else{
		cout<<GREEN<<"\nTodos los multiplos de 5 son multiplicados por 10\n"<<DF;
	}

}
void borrarMat(){
            for(int i{0}; i < columnas; ++i){
                delete []mat[i];
            }           
        delete []mat;
    }

void funcion_08(){

	int **aux;
    aux = new int*[filas];      
            for(int i{0}; i < filas; ++i){
                aux[i] = new int[columnas];
            }

	for(int fila{0}; fila < filas ; ++fila){
		for(int columna{0}; columna < columnas ; ++columna){
			aux[fila][columna] = mat[fila][columna];
		}
	}

	for(int i{0}; i < columnas; ++i){

                delete []mat[i];
            
            }
            
        delete []mat;


	mat = new int*[columnas];      
            for(int i{0}; i < columnas; ++i){
                mat[i] = new int[filas];
            }

	for(int fila{0}; fila < filas ; ++fila){
		for(int columna{0}; columna < columnas ; ++columna){
			mat[columna][fila] = aux[fila][columna];
		}
	}
	int h;
	h=filas;
	filas = columnas;
	columnas = h;

	cout<<GREEN<<"\nLa matriz fue transpuesta\n"<<DF;
	}

    

};

int main() {
		
	std::system("cls");
	int opt{0};
	matriz Matriz1(10,5);
	while (true) {
		switch(opt) {
			case 0:
				cout<<"\nElija una opcion:\n<1> Crea una matriz con valores aleatorios.\n<2>Imprima la matriz\n<3>Modifica un valor especifico de la matriz.\n";
				cout<<"<4>Convierte los valores en la diagonal de la matriz por valores igual a cero.\n";
				cout<<"<5>Ingresa 3 valores y se buscara cuantas veces se encuentran esos valores en la matriz\n";
				cout<<"<6>Reemplaza un numero a buscar por otro numero entre 100 y 200.\n<7>Multiplos de 5 por 10.\n<8>Transpuesta\n<9>Cierra el programa.";
				cout<<"\n" << ">>";
				cin>>opt;
				break;
			case 1:
				Matriz1.funcion_01();
				opt=0;
				break;
			case 2:
				Matriz1.funcion_02();
				opt=0;
				break;
			case 3:
				Matriz1.funcion_03();
				opt=0;
				break;
			case 4:
				Matriz1.funcion_04();
				opt=0;
				break;
			case 5: {
                Matriz1.funcion_05();
                opt=0;
                break; }	
            case 6: {
            	Matriz1.funcion_06();
            	opt=0;
            	break; }    
			case 7:
				Matriz1.funcion_07();
				opt=0;
				break;
			case 8:
				Matriz1.funcion_08();
				opt=0;
				break;
			case 9:
				Matriz1.borrarMat();
				cout<<"bye";
				return 0;
			default:
				cout<<"Opcion invalida";
				opt=0;
				break;
		}
	}
}