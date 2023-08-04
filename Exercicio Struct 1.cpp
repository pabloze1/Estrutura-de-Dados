#include<stdio.h>

void menu(){
    printf("\n");
    printf("\tMENU\n");
    printf(" (1) para cadastrar um livro \n");
    printf(" (2) para imprimir todos os livros cadastrados \n");
    printf(" (3) para imprimir o maior livro \n");
    printf(" (4) para sair \n\n");
}

struct Livro{

    char titulo[100];
    char autor[100];
    int numPaginas;

    void lerLivro(){
        printf("Digite o Titulo do livro: ");
        scanf("%[^\n]%*c", titulo);
        printf("Digite o Autor do livro: ");
        scanf("%[^\n]%*c", autor);
        printf("Digite a quantidade de paginas do livro: ");
        scanf("%d%*c", &numPaginas);
    }

    void imprimirLivros(){
        printf("Titulo do livro: %s\nAutor: %s\nNumero de Paginas: %d\n\n", titulo, autor, numPaginas);
    }
};

struct Biblioteca{

    Livro livros[10];
    int qtdLivros;
    int maiorLivro;

    Biblioteca(){
        qtdLivros = 0;
        maiorLivro = -999;
    }

    void ler(){
        if(qtdLivros < 10){
            livros[qtdLivros].lerLivro();
            if(livros[qtdLivros].numPaginas > maiorLivro){
                maiorLivro = qtdLivros;
            }
            qtdLivros++;
        }else
            printf("Biblioteca Lotada!\n");
    }

    void imprimir(){
        if(qtdLivros == 0){
            printf("Biblioteca Vazia!\n");
        }else{
            for(int i = 0; i < qtdLivros; i++){
                printf("Livro %d:\n",i+1);
                livros[i].imprimirLivros();
            }
        }

    }

    void imprimeMaior(){ //da pra fazer com variavel padrão!!!!!
        if(maiorLivro == -999){
            printf("Nenhum livro cadastrado!\n ");
        }else{
            printf("Maior Livro: ");
            livros[maiorLivro].imprimirLivros();
        }
    }

};

int main(){

    Biblioteca biblio;
    int op; 
    menu();
    printf("Digite a opcao desejada: ");
    scanf("%d%*c", &op);

    while(op != 4){
        switch(op){
        case 1:
            biblio.ler();
        break;
        case 2:
            biblio.imprimir();
        break;
        case 3:
            biblio.imprimeMaior();
        break;
        case 4:
            printf("Obrigado por utilizar!\n");
        break;
        default:
            printf("Opcao Invalida!\n");
        }
        menu();
        printf("Digite a opcao desejada: ");
        scanf("%d%*c",&op);
        printf("\n");
    }

    return 0;
}
