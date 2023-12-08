#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
} Produto;

typedef struct ElemLista {
    Produto produto;
    struct ElemLista *proximo;
} ItemLista;

ItemLista *inicializarLista() {
    return NULL;
}

ItemLista *adicionarProduto(ItemLista *lista) {
    Produto novoProduto;

    printf("\n Digite o codigo do produto: \n");
    scanf("%d", &novoProduto.codigo);

    printf("\n Digite a descricao do produto: \n");
    scanf(" %[^\n]s", novoProduto.descricao);

    printf("\n Digite a quantidade do produto: \n");
    scanf("%d", &novoProduto.quantidade);

    printf("\n Digite o valor do produto: \n");
    scanf("%f", &novoProduto.valor);

    ItemLista *novoItem = (ItemLista *)malloc(sizeof(ItemLista));
    novoItem->produto = novoProduto;
    novoItem->proximo = lista;

    printf("\n Produto cadastrado com sucesso \n");

    return novoItem;
}

void imprimirRelatorio(ItemLista *lista) {
    printf("\n Relatorio de produtos: \n");

    if (lista == NULL) {
        printf("\n Nenhum produto cadastrado \n");
    } else {
        ItemLista *atual = lista;

        while (atual != NULL) {
            printf("\n Codigo: %d", atual->produto.codigo);
            printf("\n Descricao: %s", atual->produto.descricao);
            printf("\n Quantidade: %d", atual->produto.quantidade);
            printf("\n Valor: R$ %.2f", atual->produto.valor);

            atual = atual->proximo;
        }
    }
}

void pesquisarProduto(ItemLista *lista) {
    int codigoPesquisa;
    printf("\n Digite o codigo do produto que deseja pesquisar: \n");
    scanf("%d", &codigoPesquisa);

    ItemLista *atual = lista;

    while (atual != NULL) {
        if (atual->produto.codigo == codigoPesquisa) {
            printf("\n Produto encontrado:");
            printf("\n Codigo: %d", atual->produto.codigo);
            printf("\n Descricao: %s", atual->produto.descricao);
            printf("\n Quantidade: %d", atual->produto.quantidade);
            printf("\n Valor: R$ %.2f", atual->produto.valor);
            return;
        }

        atual = atual->proximo;
    }

    printf("\n Produto nao encontrado \n");
}

ItemLista *removerProduto(ItemLista *lista) {
    int codigoRemocao;
    printf("\n Digite o codigo do produto que deseja remover: ");
    scanf("%d", &codigoRemocao);

    ItemLista *anterior = NULL;
    ItemLista *atual = lista;

    while (atual != NULL) {
        if (atual->produto.codigo == codigoRemocao) {
            if (anterior == NULL) {
                lista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            free(atual);
            printf("\n Produto removido com sucesso \n");
            return lista;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("\n Produto nao encontrado \n");
    return lista;
}

void liberarLista(ItemLista *lista) {
    ItemLista *atual = lista;
    ItemLista *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    ItemLista *listaEstoque = inicializarLista();
    int opcao;

    do {
        printf("\n Menu: \n");
        printf("\n 1 - Adicionar Produto");
        printf("\n 2 - Imprimir Relatorio");
        printf("\n 3 - Pesquisar Produto");
        printf("\n 4 - Remover Produto");
        printf("\n 5 - Sair");

        printf("\n Escolha uma opcao: \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listaEstoque = adicionarProduto(listaEstoque);
            break;
          
            case 2:
                imprimirRelatorio(listaEstoque);
            break;
          
            case 3:
                pesquisarProduto(listaEstoque);
            break;
          
            case 4:
                listaEstoque = removerProduto(listaEstoque);
            break;
          
            case 5:
                printf("\n Programa encerrado");
            break;
          
            default:
                printf("\n Opcao invalida. Tente novamente");
        }
    } while (opcao != 5);

    liberarLista(listaEstoque);

    return 0;
  
}
