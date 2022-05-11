#include <iostream>

using namespace std;

// utilizei o método das tensões de nós para calcular as correntes e as tensões do circuito 
// pedido no pré-relatório 1

int main(){
    double R[5], i[5] , v[5];
    double Vs, Vb, Vc, Vd;

    cout << "Informe os valores dos resistores na ordem crescente dos indices: (em K ohms)" << endl;
    for(int i = 0; i < 5; i++){
        cout << "R"<< i+1 << " = ";
        cin >> R[i];
    }
    cout << endl << "Informe a tensão na fonte de tensão contínua: (em volts)" << endl << "Vs = ";
    cin >> Vs;


    //são variáveis auxiliares para ajudarem na leitura e interpretação das equações
    double x = R[4]/R[0];
    double alpha = 1/R[2] - R[4]/(R[0]*R[3]);
    double beta = 1/R[2] + 1/R[3];
    double gama = R[4]/(R[0]*R[3]);
    double me = 1/R[0] + 1/R[1] + 1/R[2];

    // calcula as tensões dos nós b, c, d respectivamente
    Vc = Vs*( (1/R[0] + gama*me/alpha  + x/R[1] + x*gama/(alpha*R[1]))/(beta*me/alpha - 1/R[2] + x*beta/(alpha*R[1])));
    Vb = (-gama/alpha)*Vs + (beta/alpha)*Vc;
    Vd = Vs*(x + x*gama/alpha) - (x*beta/alpha)*Vc;

    // calcula as tensões em função das tensões dos nós calculada anteriormente
    i[0] = (Vs - Vb)/R[0] ;
    i[1] = (Vb-Vd)/R[1];
    i[2] = (Vb - Vc)/R[2];
    i[3] = (Vc - Vd)/R[3];
    i[4] = Vd/R[4];



    cout << endl << "Correntes e tensões em todos os elementos resistivos: "<< endl;
    for( int k = 0; k < 5; k++){
        v[k] = i[k]*R[k];  // calcula a tensão de cada elemento do circuito
        cout << "i" << k+1 << " = " << i[k] << " mA , V" << k+1 << " = " << v[k] << " V" << endl; 
    }
    /*
    -------- EXEMPLO DE OUTPUT, COMO PEDIDO NA QUESTÃO 4 -----------
    Informe os valores dos resistores na ordem crescente dos indices: (em K ohms)
    R1 = 1
    R2 = 2.2
    R3 = 1.2
    R4 = 1 
    R5 = 1.2

    Informe a tensão na fonte de tensão contínua: (em volts)
    Vs = 5

    Correntes e tensões em todos os elementos resistivos: 
    i1 = 1.51515 mA , V1 = 1.51515 V
    i2 = 0.757576 mA , V2 = 1.66667 V
    i3 = 0.757576 mA , V3 = 0.909091 V
    i4 = 0.757576 mA , V4 = 0.757576 V
    i5 = 1.51515 mA , V5 = 1.81818 V

    */
    return 0;
}
