#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;

	int valorInserido = novo->valor;

	novo->prox = NULL;


	if (primeiro == NULL) 
		// se lista estiver vazia, insere o novo elemento no inicio
	{
		primeiro = novo;
		ultimo = novo;
	}
	else if (valorInserido < primeiro->valor)
		// se o valor a ser inserido for menor que o primeiro elemento, insere no inicio 
	{
		// o valor atual da variavel "primeiro" é atribuido ao próximo nó
		novo->prox = primeiro;
		// e o nono valor(menor) é atribuido ao primeiro nó
		primeiro = novo;
	}
	else {
		// Percorre a lista para encontrar o local correto para inserir o novo elemento
		NO* anterior = NULL;
		NO* atual = primeiro;

		while (atual != NULL && atual->valor < valorInserido) {
			anterior = atual;
			atual = atual->prox;
		}

		if (atual == NULL || atual->valor > valorInserido) {
			// Insere o novo elemento após o anterior
			anterior->prox = novo;
			novo->prox = atual;
			if (atual == NULL) {
				ultimo = novo;
			}
		}
		else {
			cout << "O valor já existe na lista";
			free(novo);
		}
	}
}

void excluirElemento()
{
	int elemento;
	cout << "Digite o elemento a ser excluido: ";
	cin >> elemento;

	NO* anterior = NULL;
	NO* atual = primeiro;

	while (atual != NULL) {
		if (atual->valor == elemento) {
			if (anterior == NULL) {
				primeiro = atual->prox;
			}
			else {
				anterior->prox = atual->prox;
			}
			free(atual);
			cout << "Elemento " << elemento << " excluido com sucesso." << endl;
			return;
		}
		else if (atual->valor > elemento) {
			// O elemento não está na lista
			cout << "Elemento " << elemento << " nao encontrado na lista." << endl;
			return;
		}
		else {
			anterior = atual;
			atual = atual->prox;
		}
	}
}
NO* posicaoElemento(int numero)
{
	NO* anterior = NULL;
	NO* atual = primeiro;

	while (atual != NULL && atual->valor < numero) {
		anterior = atual;
		atual = atual->prox;
	}

	if (atual != NULL && atual->valor == numero) {
		return atual;
	}
	else {
		return NULL;
	}

}

void buscarElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}

	int numero;
	cout << "Digite o elemento a ser buscado: ";
	cin >> numero;

	NO* encontrado = posicaoElemento(numero);

	if (encontrado == NULL) {
		cout << "Elemento nao encontrado \n";
	}
	else {
		cout << "Elemento encontrado: " << encontrado->valor << endl;
	}

}


