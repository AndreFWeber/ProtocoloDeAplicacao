
#ifndef	_PROTO_APLICACAO_H_
#define	_PROTO_APLICACAO_H_

#include <iostream>
#include <string>
#include "TCPBaseSocket.h"
#include <parser_Ptcmensagem.h>

using namespace std;

class proto_aplicacao {

public:
	/*
	*O construtor desta classe é utilizado para inicializar a máquina de estados do protocolo
	*e inicializar um socket server com a porta recebido como paramêtro:
	*
	*@porta_server - Número da porta que será aberta no servidor.
	*/
	proto_aplicacao(int porta_server);
	~proto_aplicacao();

	//Há 5 métodos que fazem parte da API deste protocolo: 

	/* O método initialize deve ser usado no começo de uma partida para trocar informações sobre os jogadores 
	*  e para realizar a conexão via sockets.
	*
	*  #RETORNO 
	*  # Um inteiro que representa o estado da conexão com o adversário. -1 é uma falha e 0 um sucesso.	  
	*
	*  @ PARÂMETROS
	*  @servidor: Deve ser considerado TRUE quando o jogador for um servidor. Se o jogador quiser se conectar a um outro jogador-servidor ele deve passar esse parametro como FALSE	
	*  @ip: Deve ser passado o ip de um jogador-servidor para que o jogador local se conecte. Se o primeiro parametro (bool servidor) for verdadeiro então o valor de ip pode ser NULL.  	
	*  @nome: Nome que o jogador local assumirá.
	*  @marca: Marca que o jogador local assumirá.	
	*/
	int initialize(bool servidor, string ip, string nome, bool marca);

	/* O método send deve ser usado para enviar a posição do jogador local para o adversário remoto.
	*  #RETORNO 
	*  # Retorna 0 por padrão.
	*
	*  @ PARÂMETROS
	*  @posicao: Indica a posicao no tabuleiro que o jogador local acabou de escolher.
	*/
	int send(int posicao);

	/* O método receive deve ser usado para receber a posição do adversário remoto.
	*
	*  #RETORNO 
	*  # Retorna a posição no tabuleiro que o jogador remoto escolheu.
	*/
	int receive();

	/* O método finaliza deve ser utilizado ao fim de uma partida.
	*
	*  #RETORNO 
	*  # Retorna a condição de fim escolhida pelo adverário. Um adversário pode enviar qualquer valor
	*    inteiro como condição. 
	*
	*  @ PARÂMETROS
	*  @condicao: O jogador local deve enviar uma condição de finalização da partida. Esta condição pode ser utilizada como bem entendido
	*             na aplicação. Indicação de uma revanche talvez?
	*/
	int finaliza(int condicao);

	bool get_marca_adversario(){ return marca_oponente; };
	string get_nome_adversario(){ return nome_oponente; };

private:
	enum Estados {
			inicio, joga, espera_jogada, fim
	};
	int fsm();
    	// estado atual da MEF
	int estado;
	string ip, ip_oponente;
	string nome, nome_oponente;
    	bool marca, marca_oponente, servidor;
	int posicao_envio;
	int condicao_fim;

	void WriteLogFile(string szString);

	Connection * sock;

    	//Criação do socket TCP
    	TCPClientSocket client;
	TCPServerSocket server;	

    TInicio Asn1_init;
    TPosicao Asn1_posicao;
    TErro Asn1_erro;
    TFim Asn1_fim;
};

#endif	/* _POS_H_ */

