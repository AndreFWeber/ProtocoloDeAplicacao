#include <iostream>
#include <limits>
#include <string>

#include "proto_aplicacao.h"

using namespace std;


void ImprimeJogo();
void ValidaJogada();
bool VerificaGanhador();
void IniciaJogo();

bool turno=false, jogador_local=false, revanche=false;
bool empate = false;
char matriz[3][3] = {{'1', '2', '3'},
		     {'4', '5', '6'}, 
		     {'7', '8', '9'}};

bool minha_marca=false;
    bool servidor;

//Criou o protocolo!
proto_aplicacao protocolo(8000);
 

int main()
{
	
    IniciaJogo();
    protocolo.finaliza(0);
 
/*  int opcao; 
    do{
	   cout << "Jogar a revanche?  1 para sim ou 0 para não" << endl;

	   while (!(cin >> opcao))
	    {
			cin.clear();
	    }

	    int op_oponente = protocolo.finaliza(opcao);		
	
	    if((opcao + op_oponente) == 2){
		 revanche = true;
		 cout << "A revanche contra o(a) " << protocolo.get_nome_adversario() << " vai começar " << endl;

	    	if(!servidor){
		    turno = !minha_marca;
		    jogador_local=false;
		}
		else{
			minha_marca = !protocolo.get_marca_adversario();
			jogador_local=true;
			turno = minha_marca;
		}
    		IniciaJogo();	
		break;
	    }
		
    }while(true);*/

}

void IniciaJogo()
{
    int marca;	

    string ip, nome; 	    

    if(!revanche){ 
	    cout << "Você será servidor? Entre 0 para não e 1 para sim  " << endl;
	    while (!(cin >> servidor))
	    {
			cin.clear();
	    }


	    cout << "Qual teu nome?  " << endl;
	    while (!(cin >> nome))
	    {
			cin.clear();
	    }

	    if(!servidor){	
		    cout << "Qual ip do teu adversário?  " << endl;
		    while (!(cin >> ip))
		    {
				cin.clear();
		    }

		    cout << "Entre com 0 para jogar como O ou com um valor maior para jogar com X " << endl;
		    while (!(cin >> marca))
		    {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout << "Por favor, entre com um número " << endl;
		    }

		    /*
			marca true vai ser X || marca false vai ser O
		    */
		    if(marca>0)minha_marca=true;

		    turno = !minha_marca;
		    jogador_local=false;
	    }

	    protocolo.initialize(servidor, ip, nome, marca);


	   if(servidor){
		minha_marca = !protocolo.get_marca_adversario();
		cout << "Jogarei contra o(a) " << protocolo.get_nome_adversario() << endl;
		jogador_local=true;
		turno = minha_marca;
	   }
    }


    cout << "Jogo da Velha\n";

    if(minha_marca){ 
	    cout << "Eu jogo com (X)\n";
	    cout << "Meu advesário vai jogar com O\n";
    }else{
	    cout << "Eu jogo com (O)\n";
	    cout << "Meu advesário vai jogar com X\n";
    }

    while (!VerificaGanhador())
    {
        ImprimeJogo(); //Printa a versao mais atualizada da matriz
        ValidaJogada();
	jogador_local != jogador_local;
        VerificaGanhador();
    }
    
    if (!turno && !empate)
    {
        ImprimeJogo();
        cout << endl << endl << "O jogador (X) ganhou!\n";

	if(!turno == minha_marca) cout << "Parabéns " << nome <<", você ganhou! E o(a) "<< protocolo.get_nome_adversario() << " perdeu" << endl; 
	else cout << "Poxa " << nome <<", você perdeu! E o(a) "<< protocolo.get_nome_adversario() << " ganhou" << endl; 
    }
    else if (turno && !empate)
    {
        ImprimeJogo();
        cout << endl << endl << "O jogador (O) ganhou!\n";

	if(turno == !minha_marca) cout << "Parabéns " << nome <<", você ganhou! E o(a) "<< protocolo.get_nome_adversario() << " perdeu" << endl; 
	else cout << "Poxa " << nome <<", você perdeu! E o(a) "<< protocolo.get_nome_adversario() << " ganhou" << endl; 

    }
    else
    {
        ImprimeJogo();
        cout << endl << endl << "Deu Velha!\n";
    }
}

void ImprimeJogo()
{
    cout << "---------------------" << endl << endl;
    cout << "     |     |     " << endl;
    cout << "  " << matriz[0][0] << "  |  " << matriz[0][1] << "  |  " << matriz[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << matriz[1][0] << "  |  " << matriz[1][1] << "  |  " << matriz[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << matriz[2][0] << "  |  " << matriz[2][1] << "  |  " << matriz[2][2] << endl;
    cout << "     |     |     " << endl;
}

void ValidaJogada()
{
    int escolhe=0;
    int linha = 0, coluna = 0;
    
    if (turno)
    {
        cout << "Vez do jogador X: ";
    }
    else if (!turno)
    {
        cout << "Vez do jogador O: ";
    }

    if(jogador_local){
	    while (!(cin >> escolhe))
	    {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Por favor, entre com um número " << endl;
	    }

	    protocolo.send(escolhe);
    }else{
	escolhe = protocolo.receive();
	cout << " " <<escolhe << endl;
    }

    jogador_local=!jogador_local;  

    switch (escolhe)
    {
        case 1: linha = 0; coluna = 0; break;
        case 2: linha = 0; coluna = 1; break;
        case 3: linha = 0; coluna = 2; break;
        case 4: linha = 1; coluna = 0; break;
        case 5: linha = 1; coluna = 1; break;
        case 6: linha = 1; coluna = 2; break;
        case 7: linha = 2; coluna = 0; break;
        case 8: linha = 2; coluna = 1; break;
        case 9: linha = 2; coluna = 2; break;
        default:
            cout << "Você não digitou um número válido. Tente de novo.\n";

            ValidaJogada();
    }
    
    if (turno && matriz[linha][coluna] != 'X' && matriz[linha][coluna] != 'O')
    {
        matriz[linha][coluna] = 'X';
        turno = false;
    }
    else if (!turno && matriz[linha][coluna] != 'X' && matriz[linha][coluna] != 'O')
    {
        matriz[linha][coluna] = 'O';
        turno = true;
    }
    else
    {
        cout << "Local já utilizado. Escolha outro número.\n";
        ValidaJogada();
    }

}

bool VerificaGanhador()
{
    for (int i = 0; i < 3; i++)//Verifica ganhador
    {
        if ((matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) || (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]) || (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) || (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]))
        {
            return true;
        }
    }
    
    for (int i = 0; i < 3; i++)//verifica empate
    {
        for (int j = 0; j < 3; j++)
        {
            if (matriz[i][j] != 'X' && matriz[i][j] != 'O')
            {
                return false;
            }
        }
    }
    empate = true;
    return true;
}
