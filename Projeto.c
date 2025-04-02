#include "Projeto.h"  //nome do arquivo estava escrito errado
#include <stdio.h>    //para incluir bibliotecas ultiliza-se <>
#include <string.h>   //para incluir bibliotecas ultiliza-se <>

int criarTarefa(ListaDeTarefas *lt){
    if(lt->qtd >= TOTAL_TAREFAS)
    return 1;
    
	Tarefa *t=&lt->tarefas[lt->qtd];

    printf("Entre com a prioridade da tarefa: ");
    scanf("%d", &t->prioridade);

    printf("Entre com a categoria da tarefa: ");
    scanf("%s[^\n]", t->categoria);   //permite o uso de espaços na categoria

    printf("Entre com a descricao da tarefa: ");
    scanf("%s[^\n]", t->descricao);   //permite o uso de espaços na descricao

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

void exibeMenu(){
    printf("menu\n");
    printf("1. Criar tarefa\n");
    printf("2. Deletar tarefa\n");
	printf("3. Listar tarefa\n");
	printf("0. Sair\n");
	}

