#include "proto_aplicacao.h"
#include <limits>

int main() {
  proto_aplicacao protocolo(8000);

  protocolo.initialize(false, "191.36.10.178", "PeDeCabra", false);

/* USA SE FOR SERVIDOR

  cout << "Jogo da Velha\n";

  cout << "Vez do jogador 1 (X): ";
  //  cin >> escolhe;
  int escolhe=0;
  while (!(cin >> escolhe))
  {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Por favor, entre com um número " << endl;
  }

*/

  cout << "O zé jogou " << protocolo.receive() << endl;


 protocolo.send(4);	

 /*  TMensagem pkt;
 
  pkt.set_id(1234);
  pkt.set_nome("manoel");
 
  // verifica se os valores contidos na estrutura de dados respeitam
  // a especificação
  pkt.check_constraints();
 
  // mostra a estrutura de dados na tela
  cout << "Estrutura de dados em memória (antes de codificação XER):" << endl;
  pkt.show();

  //Criação do socket TCP
  TCPClientSocket client;
  // conecta no servidor da wiki
  client.connect("localhost", 8000); 
  
  for (int i =0; i<5;i++) {
	  // cria o codificador
	  ostringstream out;
	  TMensagem::XerSerializer encoder(out);
	 
	  // codifica a estrutura de dados
	  encoder.serialize(pkt);
	 
	  cout << endl;
	  cout << out.str() << endl;

	  // faz uma requisição HTTP
	  client.send(out.str());
  }
  

  TMensagem pkt;
 
  // define o valor do campo "id"
  pkt.set_id(8);
 
  // Acessa o campo choice, que será referenciado
  // pela variável "msg" (note o operador &)
  TMensagem::Choice_msg & msg = pkt.get_msg();
 
  // Dentro de "msg" acessa-se "inicio": isso faz
  // com que o campo choice contenha um valor do tipo
  // "Login" (não pode mais ser mudado).
  TLogin login = msg1.get_inicio();
 
  // define os valores dos campos de "inicio"
  login.set_usuario("aluno");
  login.set_senha("blabla...");


  return 0;

  // cria o decodificador
  istringstream inp(out.str());
  TMensagem::XerDeserializer decoder(inp);
 
  // tenta decodificar uma estrutura de dados
  TMensagem * other = decoder.deserialize();
 
  cout << endl;
 
  if (other) {
    cout << "Estrutura de dados obtida da decodificação XER:" << endl;
    other->show();
  } else cerr << "Erro: não consegui decodificar a estrutura de dados ..." << endl;
 
  // devem-se destruir explicitamente as estruturas de dados obtidas 
  // do decodificador 
  delete other; */  
}
