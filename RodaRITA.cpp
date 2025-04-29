#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;
 
struct motorista{

	   string nome;

	   string placa;

	   string veiculo;

	   double nota;	

};
 
struct usuario

{

	string nome;

	string senha;

	string user;

};
 
void log(char opcao, usuario login[]);

double porcentagem(int horas);

double tempo();

int Smotorista(int op, motorista ficha[]);
 
void DefCor(int Cor);
 
int main (){

	setlocale(LC_ALL, "Portuguese");

	srand(time(NULL));

	int km = rand() % 10 + 1;

	int op;

	int hora, minuto;

	int pontos = 0;

	int np = 2;

	int porcentagem = 1;

	int i = 0;

	double corrida = 0;

	double juros = 0.;

	string nome;

	char l;

	usuario login[10];

	motorista ficha[5];

	ficha[1].nome = "Jose Armando";

	ficha[1].veiculo = "Honda Civic";

	ficha[1].placa = "GKE-0215";

	ficha[1].nota = 4.2;

	ficha[2].nome = "Paulo Augusto";

	ficha[2].veiculo = "Toyota Etios";

	ficha[2].placa = "A57D5Q";

	ficha[2].nota = 4.6;

	ficha[3].nome = "Pedro Augusto";

	ficha[3].veiculo = "CBX-250";

	ficha[3].placa = "ASD-6212";

	ficha[3].nota = 4.8;

	ficha[4].nome = "Jonas Bernardo";

	ficha[4].veiculo = "Fan-150";

	ficha[4].placa = "65ASD4";

	ficha[4].nota = 4.4;
	
	DefCor(15);
	cout << "Faça o login, ou em caso de novo usuario faça registro: " << endl;

	do{
		DefCor(3);
		cout << "(1) - Para login." << endl;
		cout<< "(2) - Para se registrar." << endl;
		DefCor(15);
		cout << endl << "Selecione: "; cin >> l;

	} while(l != '1' && l != '2');


	log(l, login);


	//menu principal

	cout << endl;

	cout << "---------" << endl;

	cout << "BEM VINDO " <<endl;

	cout << "---------" << endl;

	cout << "Menu de viajens:" <<endl;

	cout << endl;

	do{	
	DefCor(11);
	cout<<"1 - Encomenda"<<endl;
	cout<<"2 - Moto"<<endl;
	cout<<"3 - Carro"<<endl; 
	cout<<"4 - Corrida Compartilhada"<<endl;
	cout<<"5 - Contratar Motorista"<<endl;
	DefCor(15);
		cout << endl;

		cin>>op;

		cout << endl;

	 }while(op != 1 && op != 2 && op != 3 && op != 4 && op != 5);

	 Sleep(200);

	 juros = tempo();

	 cout << fixed << setprecision(2);
	 
	 DefCor(15);
	 cout << "Juros sobre o valor da corrida: " << juros  << "%" << endl << endl;

	 Sleep(1800);
 
	switch (op){
		//encomenda

		case 1:{

			corrida = (5 + 3*km)*porcentagem;

			corrida = corrida + (corrida * juros);

			if(corrida>=10){

				pontos = (corrida/10)*100;	

			}

			break;

		}

		//moto

		case 2:{

			corrida = 4. + 2*km;

			corrida = corrida + (corrida * juros);

			if(corrida>=10){

				pontos = (corrida/10)*100;	

			}

			break;

		}

		//carro

		case 3:{

			corrida = 5. + 3*km;

			corrida = corrida + (corrida * juros);

			if(corrida>=10){

				pontos = (corrida/10)*100;	

			}

			break;

		}

		//corrida compartilhada

		case 4:{

			srand(time(NULL));

			np = rand()%3 + 1;

			cout << endl << "Numero de pessoas na corrida: " << np << endl << endl; 

			corrida = (5. + (3*km)/np);

			corrida = corrida + (corrida * juros);

			if(corrida>=10){

				pontos = (corrida/10)*100;	

			}

			break;

		}

		//contratar motorista

		case 5:{

			corrida = 300;

			if(corrida>=10){

				pontos = (corrida/10)*100;	

			}

			break;

		}

	}

	i = Smotorista(op, ficha);

	Sleep(500);

	cout << endl << "--Motorista escolhido--" << endl;

	cout << "Nome: " << ficha[i].nome << endl;

	cout << "Veiculo: " << ficha[i].veiculo << endl;

	cout << "Placa do veiculo: " << ficha[i].placa << endl;

	cout << "Nota: " << ficha[i].nota << endl;

	cout << endl;

	cout << endl;

	cout << "--Motorista a caminho";

	for(int j = 0; j < 3; j++){

		cout << ".";

		Sleep(1000);

	}

	cout << endl;

	cout << endl << "--Corrida em andamento";

	for(int j = 0; j < 5; j++){

		cout << ".";

		Sleep(1000);

	}

	cout << endl << endl << "--Corrida finalizada--";

	Sleep(500);

	cout << endl << fixed << setprecision(2);

	cout << "Kms percorrido: " << km <<endl;

	Sleep(500);

	cout << "Preco total: " << corrida << endl;

	Sleep(500);

	cout << "pontos ganhos: "<<pontos;

	return 0;

}


//--------------------------------------------------------------------------------------------------------

//Função para login;

void log(char opcao, usuario login[]){

	int s1, s2;

	int nvr;

	int t = 2;	

	string senha;

	string user;

	string situacao;

	string nome;

	login[0].user = "admin";

	login[0].senha = "admin";

	for(int i = 1; i <= 5; i++){

		login[i].user = "vazio";

		login[i].senha = "vazio";

	}

	do{

		cin.ignore();

		if(opcao == '1'){

			do{

				cout << endl << "Entre com usuario:" << endl; 

				getline(cin, user);

				cout << "Entre com a senha:"<< endl; 

				getline(cin, senha);

				for(int i = 0; i < 5; i++){

					if(user == login[i].user){

						s1 = 1;

					}

					if(senha == login[i].senha){

						s2 = 1;

					}

				}


				if(s1 == 1 && s2 == 1){

					cout << endl << "Login aprovado" << endl;

					situacao = "Aprovado";

				}

				else

				{

					cout << endl << "Usuario ou senha incorretos" << endl;

					situacao = "Negado";

					do{

						cout << "Deseja se registrar?" << endl << "(1) Para sim;" << endl <<"(2) Para nao." << endl;

						cout << endl << "Selecione: "; cin >> nvr; 

					}while(nvr != 1 && nvr != 2);

					if(nvr == 1){

						opcao = '2';

						cin.ignore();

						situacao = "Aprovado";

					}

					else{

						opcao = '1';

						cin.ignore();

					}

				}

			} while(situacao == "Negado");

		}

		if(opcao == '2'){

			cout << "Entre com seu nome: "; getline(cin, nome);

			cout << "Escolha um usuario: "; getline(cin, user);

			cout << "Escolha uma senha: "; cin >> senha;

			for(int i = 0; i < 5; i++){

				if(user == login[i].user){

					cout << "Usuario ja utilizado" <<endl << "Utilize outro usuario" << endl;

					opcao = '2';

					log(opcao, login);

				}

			}

			login[t].nome = nome;

			login[t].user = user;

			login[t].senha = senha;

			cout << "Cadastro realizado com sucesso." << endl << "Efetue o login." <<endl;

			opcao = '1';

			t++;

			situacao = "Reprovado";

		}

	} while(situacao != "Aprovado");

}

//-----------------------------------------------------------------------------------------------------

//Função para selecionar o motorista;

int Smotorista(int op, motorista ficha[]){

	int selecao;

	//Seleção de veiculos, caso a opção seja de encomenda, carro, compartilhada ou motorista contratado;

	if(op != 2){	

		cout << "--Motoristas encontrados--"<< endl;

		cout << "Nome: " << ficha[1].nome << endl;

		cout << "Veiculo: " << ficha[1].veiculo << endl;

		cout << "Placa do veiculo: " << ficha[1].placa << endl;

		cout << "Nota: " << ficha[1].nota << endl;

		cout << endl;

		cout << "Nome: " << ficha[2].nome << endl;

		cout << "Veiculo: " << ficha[2].veiculo << endl;

		cout << "Placa do veiculo: " << ficha[2].placa << endl;

		cout << "Nota: " << ficha[2].nota  << endl;

		cout << endl;

		do{

			cout << "Selecione (1) para o Sr. "<< ficha[1].nome << endl;

			cout << "Selecione (2) para o Sr. "<< ficha[2].nome << endl;

			cout << endl << "Selecione: "; cin >> selecao;

		}while(selecao != 1 && selecao != 2);

	}

	//Opções de motorista caso seja na modalidade moto;

	else{

		cout << "--Motoristas encontrados--"<< endl;

		cout << ficha[3].nome << endl;

		cout << ficha[3].veiculo << endl;

		cout << ficha[3].placa << endl;

		cout << ficha[3].nota << endl;

		cout << endl;

		cout << ficha[4].nome << endl;

		cout << ficha[4].veiculo << endl;

		cout << ficha[4].placa << endl;

		cout << ficha[4].nota  << endl;

		cout << endl;

		do{

			cout << "Selecione (3) para o Sr. "<< ficha[3].nome << endl;

			cout << "Selecione (4) para o Sr. "<< ficha[4].nome << endl;

			cout << endl << "Selecione: "; cin >> selecao;

		}while(selecao != 3 && selecao != 4);

	}

	return selecao;

}

//-----------------------------------------------------------------------------------------------------


//Função de calculo de porcentagem extra que somará ao valor final, dependendo da hora;

double porcentagem(double horas){

	double porcentagem = 0;

	if(horas >= 7 && horas < 9 || horas >= 19 && horas < 23){

		porcentagem = 0.05;

	} else if(horas >= 9 && horas < 19){

			porcentagem = 0.;

		} else 

			porcentagem = 0.15;

 
	return porcentagem;	

}

//-------------------------------------------------------------------------------------------------------

//Função de leitura de horário da maquina;

double tempo(){

	int horas, minuto;

    double hora;

	double percent;

	// Obtém o tempo atual

    time_t tempo_atual = time(NULL);

	// Converte o tempo atual para uma estrutura de tempo local

    tm* tempo_local = localtime(&tempo_atual);

    horas = tempo_local->tm_hour;

    minuto = tempo_local->tm_min;

	// Imprime o horário atual
    DefCor(15);
    cout << "Horario atual do sistema: ";

    cout << tempo_local->tm_hour << ":" << tempo_local->tm_min << ":" << tempo_local->tm_sec << endl;

	hora = tempo_local->tm_hour;
 
	percent = porcentagem(hora);
 
	return percent; 

}

//função que deixa letra colorida

void DefCor(int Cor){

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h,Cor); 

};