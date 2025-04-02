#include "Projeto.h"  //nome do arquivo estava escrito errado
#include <stdio.h>    //para incluir bibliotecas ultiliza-se <>
#include <string.h>   //para incluir bibliotecas ultiliza-se <>

int criarTarefa(ListaDeTarefas *lt){
    if(lt->qtd >= TOTAL_TAREFAS)
    return 1;
    
	Tarefa *t=&lt->tarefas[lt->qtd];

    printf("Entre com a prioridade da tarefa: ");
    scanf("%d", &t->prioridade);
    getchar();  //limpa o scanf

    printf("Entre com a categoria da tarefa: ");
    scanf(" %[^\n]", t->categoria);    //[^\n] permite o uso de espaços na categoria

    printf("Entre com a descricao da tarefa: ");
    scanf(" %[^\n]", t->descricao);    //[^\n] permite o uso de espaços na descricao

    lt->qtd++;

    return 0;
}

int deletarTarefa(ListaDeTarefas *lt){
   if(lt->qtd == 0)
   return 1;
   
   int pos;
   printf("Entre com a posicao que deseja deletar: ");
   scanf("%d", &pos);
   
   if(pos <0 || pos > lt->qtd - 1)  //> e não <
   return 2;
   
   for (; pos<lt->qtd-1; pos++){
   	lt->tarefas[pos].prioridade=lt->tarefas[pos+1].prioridade; 
	   strcpy(lt->tarefas[pos].descricao, lt->tarefas[pos+1].descricao);  //essa linha refere-se a descricao e não a categoria
	   strcpy(lt->tarefas[pos].categoria, lt->tarefas[pos+1].categoria);

   }
   
    lt->qtd--;
	return 0;
}
int listarTarefas(ListaDeTarefas *lt){
	if(lt->qtd == 0)
	return 1;
	

int i;
for(i=0; i< lt->qtd; i++){
	printf("Pos: %d \t Prioridade: %d \t Categoria: %s\n", i, 
	lt->tarefas[i].prioridade, lt->tarefas[i].categoria);
	printf("Descricao: %s\n", lt->tarefas[i].descricao);
}
    return 0;
}

int carregarTarefas(ListaDeTarefas *lt, char *nome){  //faltou o asterisco(*) antes de nome
   FILE *fp=fopen(nome, "rb");
   if (fp == NULL)
   return 1;
   
   fread(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

int salvarTarefas(ListaDeTarefas *lt, char *nome){
   FILE *fp=fopen(nome, "wb");  //faltou o ponto e vírgula(;)
   if (fp == NULL)
   return 1;
   
   fwrite(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

//nova função - editarTarefa
int editarTarefa(ListaDeTarefas *lt) {
    //retorna 1 caso não haja tarefas na lista
    if (lt->qtd == 0) {
        printf("Erro: Não há tarefas para editar.\n");
        return 1;
    }

    //retorna 2 caso a posição for inválida
    int pos;
    printf("Digite a posição da tarefa que deseja editar: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= lt->qtd) {
        printf("Erro: Posição inválida.\n");
        return 2;
    }

    Tarefa *t = &lt->tarefas[pos];

    printf("Editando tarefa na posição %d:\n", pos);
    printf("Prioridade atual: %d\n", t->prioridade);
    printf("Nova prioridade: ");
    scanf("%d", &t->prioridade);

    printf("Categoria atual: %s\n", t->categoria);
    printf("Nova categoria: ");
    scanf(" %[^\n]", t->categoria);

    printf("Descrição atual: %s\n", t->descricao);
    printf("Nova descrição: ");
    scanf(" %[^\n]", t->descricao); 

    return 0;
}

void exibeMenu(){
    printf("menu\n");
    printf("1. Criar tarefa\n");
    printf("2. Deletar tarefa\n");
	printf("3. Listar tarefa\n");
    printf("4. Editar tarefa\n");  //adicionando nova função ao menu
	printf("0. Sair\n");
	}

