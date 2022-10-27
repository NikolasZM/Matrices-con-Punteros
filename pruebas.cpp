#include <iostream>

using namespace std;

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

            }else{
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

        void imprimirMat(){
            
            for(int i{0}; i < filas; ++i){
                cout << "|  ";
                for(int j{0}; j < columnas; ++j){

                    cout << mat[i][j] << "  ";

                }
                cout << "|" << "\n";
            }
        }

    void borrarMat(){

            for(int i{0}; i < columnas; ++i){

                delete []mat[i];
            
            }
            
        delete []mat;



    }

};

int main(){

    matriz uno(4,4);
    uno.getTamaño();
    uno.imprimirMat();
    uno.borrarMat();


    matriz dos(12, 12);
    dos.getTamaño();
    dos.imprimirMat();
    dos.borrarMat();

    matriz tres(12, 2);
    tres.getTamaño();
    tres.imprimirMat();
    tres.borrarMat();

}