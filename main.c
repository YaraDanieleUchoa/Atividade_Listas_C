// TRABALHO DE C - PRIMEIRA ATIVIDADE - LISTAS


#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int dado;
    struct Elemento* proximo;
} Elemento;

typedef struct Lista {
    Elemento* inicio;
} Lista;

// Criar Lista
Lista* criarLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

// Inseerir Lista
void inserirLista(Lista* lista, int valor) {
    Elemento* novoElemento = (Elemento*) malloc(sizeof(Elemento));
    novoElemento->dado = valor;
    novoElemento->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoElemento;
    } else {
        Elemento* temp = lista->inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoElemento;
    }
}

// Exibir Lista
void exibirLista(Lista* lista) {
    if (lista->inicio == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Elemento* temp = lista->inicio;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Verificar Lista Vazia
int verificarVazia(Lista* lista) {
    return lista->inicio == NULL;
}

// Buscar Lista
Elemento* buscarLista(Lista* lista, int valor) {
    Elemento* temp = lista->inicio;
    while (temp != NULL) {
        if (temp->dado == valor) {
            return temp;
        }
        temp = temp->proximo;
    }
    return NULL;
}

// Excluir Lista
void excluirLista(Lista* lista, int valor) {
    if (lista->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }

    Elemento* temp = lista->inicio;
    Elemento* anterior = NULL;

    if (temp != NULL && temp->dado == valor) {
        lista->inicio = temp->proximo;  
        free(temp);
        return;
    }

    while (temp != NULL && temp->dado != valor) {
        anterior = temp;
        temp = temp->proximo;
    }

    if (temp == NULL) {
        printf("Elemento %d não encontrado.\n", valor);
        return;
    }

    anterior->proximo = temp->proximo;
    free(temp);
}

// Liberar Lista
void liberarLista(Lista* lista) {
    Elemento* temp = lista->inicio;
    while (temp != NULL) {
        Elemento* proximo = temp->proximo;
        free(temp);
        temp = proximo;
    }
    lista->inicio = NULL;
    free(lista);
}

// Função para inserir em ordem crescente
void inserirOrdenado(Lista* lista, int valor) {
    Elemento* novoElemento = (Elemento*) malloc(sizeof(Elemento));
    novoElemento->dado = valor;
    novoElemento->proximo = NULL;

    if (lista->inicio == NULL || lista->inicio->dado >= valor) {
        novoElemento->proximo = lista->inicio;
        lista->inicio = novoElemento;
    } else {
        Elemento* temp = lista->inicio;
        while (temp->proximo != NULL && temp->proximo->dado < valor) {
            temp = temp->proximo;
        }
        novoElemento->proximo = temp->proximo;
        temp->proximo = novoElemento;
    }
}


int main() {
    Lista* lista = criarLista();

    inserirOrdenado(lista, 5);
    inserirOrdenado(lista, 2);
    inserirOrdenado(lista, 8);
    inserirOrdenado(lista, 3);

    printf("Elementos da lista: ");
    exibirLista(lista);

    printf("Verificando se a lista está vazia: %s\n", verificarVazia(lista) ? "Sim" : "Não");

    int valor = 3;
    Elemento* resultado = buscarLista(lista, valor);
    if (resultado != NULL) {
        printf("Elemento %d encontrado na lista.\n", valor);
    } else {
        printf("Elemento %d não encontrado na lista.\n", valor);
    }

    excluirLista(lista, 2);
    printf("Lista após a exclusão do elemento 2: ");
    exibirLista(lista);

    liberarLista(lista);

    return 0;
}
