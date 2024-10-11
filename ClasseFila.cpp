#include <stdio.h>
#include <stdlib.h>

#define LimpaTela system("clear");

class ClasseFila
{
public:
    //Construtor da classe agora temos dois controladores
    ClasseFila(int i,int f);
    //Verifica se a fila est� vazia
    bool FilaVazia();
    //Faz a verificacao se a fila esta cheia
    bool FilaCheia();
    //Insere Valor na fila
    void Enqueue(int valor);
    //Remove valor da fila
    int Dequeue();
    //Mostra fila
    void MostrarFila();
private:
    int fila[5];
    int ini;
    int fim;
};

ClasseFila::ClasseFila(int i, int f)
{
    ini = i;
    fim = f;
}

bool ClasseFila::FilaVazia()
{
    if(ini == -1 && fim == -1)
        return true;
    else
        return false;
}

bool ClasseFila::FilaCheia()
{
    //Aqui � um c�digo que vai ser utilizado varias vezes,
    //Regra 1 - Verifica se o fim atingiu o tamanho da fila e o inicio est� no zero
    //Regra 2 - Verifica se aumentando o inicio de 1 ele fica igual ao fim (ou seja a fila circulou)
    if((fim + 1) % 5 == ini){
        return true;
    } else{
        return false;
    }
}

void ClasseFila::Enqueue(int valor)
{
    //Toda a inser��o deve aumentar o valor do FIM em 1.
    //Regra 1 � Se a fila estiver vazia ser� o �nico momento que ser� colocado o valor de INICIO e FIM com o valor zero.
    //Regra 2 � Se no momento de aumentar o valor do FIM este valor ficar igual ao INICIO deve retornar a mensagem de FILA CHEIA.
    //Regra 3 � Se no momento de aumentar o valor do FIM este valor ficar igual ao tamanho da fila, neste caso 5, voc� deve
    //verificar se o valor do INICIO � igual a zero. Se o valor do INICIO � igual a zero deve retornar mensagem FILA CHEIA,
    //caso contr�rio o valor de FIM recebe 0.
    //Ap�s obedecer todas as regras insira o valor de entrada na posi��o que ficou o FIM, por exemplo: FILA[FIM] = VALOR
    if(FilaCheia()){
        printf("FILA CHEIA!\n");
        return;
    }

    if(FilaVazia()){
        ini = 0;
        fim = 0;
    }else{
        fim = (fim + 1) % 5;
    }

    fila[fim] = valor;
}

int ClasseFila::Dequeue()
{
    //Toda retirada deve aumentar o valor do INICIO em 1.
    //Regra 1 � Se no momento da retirada o valor de INICIO e FIM estiver em -1 deve dar a mensagem de FILA VAZIA.
    //Regra 2 - Se no momento antes de aumentar o valor do INICIO ele estiver igual o FIM deve colocar a fila em situa��o de vazia, ou seja, INICIO e FIM com -1.
    //Regra 3 � Se no momento de aumentar o valor do INICIO este valor ficar igual ao tamanho da fila, neste caso 5,
    //voc� deve verificar se o FIM � maior ou igual a zero, se sim voc� dever� colocar o valor de INICIO igual a 0.
    if(FilaVazia()){
        printf("FILA VAZIA!\n");
        return -1;
    }

    int valor = fila[ini];

    if(ini == fim){
        ini = -1;
        fim = -1;
    }else{
        ini = (ini + 1) % 5;
    }

    return valor;
}

void ClasseFila::MostrarFila()
{
    //Como estamos usando Fila circular, para mostra a Fila deve ser feito Dequeue e Enqueue at� ela circular totalmente
    //N�o pode percorrer o vetor
    //Na Fila n�o ser� necess�ria fila auxiliar
    if(FilaVazia()){
        printf("FILA VAZIA!\n");
    }else{
        int i = ini;
        printf("Fila: ");
        while(true){
            printf("%d ", fila[i]);
            if(i == fim){
                break;
            }
            i = (i + 1) % 5;
        }
        printf("\n");
    }
}


int main()
{
    int OP;
    ClasseFila FilaObj(-1,-1);
    while(1)
    {
        LimpaTela;
        printf("1 - Inserir na Fila.\n");
        printf("2 - Retirar da Fila.\n");
        printf("3 - Mostrar Fila.\n");
        printf("0 - Sair.\n");
        printf("Entre com a opcao: ");
        scanf("%d", &OP);
        if (OP == 0)
            break;
        else if(OP == 1){
            int valor;
            printf("Digite um valor para inserir na fila: ");
            scanf("%d", &valor);
            FilaObj.Enqueue(valor);
        }
        else if(OP == 2){
            int valor;
            valor = FilaObj.Dequeue();
            if(valor != -1){
                printf("Valor removido: %d\n", valor);
            }
        }
        else if(OP == 3)
        {
            FilaObj.MostrarFila();
        }
        system("pause");
    }
    return 0;
}