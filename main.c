#include "Projeto.h"  //nome do arquuivo estava escrito errado
#include <stdio.h>   //para incluir bibliotecas utiliza-se <>

int main(){
ListaDeTarefas lt;

char arquivo[] = "tarefas";
int codigo, opcao;

codigo=carregarTarefas(&lt, arquivo);  //faltou o &

if (codigo !=0){
printf("Lista de tarefas nao carregada\n");   //faltou pular a linha
lt.qtd=0;  //o valor deve ser igual a 0
}

do{
exibeMenu();
scanf("%d", &opcao);

if(opcao == 0){}
else if(opcao == 1){
    codigo=criarTarefa(&lt);
    if (codigo ==1 )
    printf("erro ao criar tarefa: Sem espacao disponivel\n");
    }
else if(opcao == 2){
    codigo=deletarTarefa(&lt);
    if (codigo ==1 )
    printf("erro ao deletar tarefa: nao existem tarefas para deletar\n");
    else if(codigo ==2)
    printf("erro ao deletar tarefa: posicao invalida\n");
}
else if(opcao == 3){
    codigo=listarTarefas(&lt);
   if (codigo ==1)   //o código de erro é 1 e não 2
   printf("Erro ao listar tarefas: nao existem tarefas para serem listadas");
}
else if (opcao == 4) {
    codigo = editarTarefa(&lt);
    if (codigo == 1)
        printf("Erro ao editar tarefa: Nenhuma tarefa disponivel.\n");
    else if (codigo == 2)
        printf("Erro ao editar tarefa: Posição invalida.\n");
}

else if (opcao == 5) {
    codigo = filtrarTarefas(&lt);
    if (codigo == 1)
        printf("Erro ao filtrar tarefas: Nenhuma tarefa disponivel.\n");
}
else if (opcao == 6) {
    codigo = duplicarTarefa(&lt);
    if (codigo == 1)
        printf("Erro ao duplicar tarefa: Nenhuma tarefa disponivel.\n");
    else if (codigo == 2)
        printf("Erro ao duplicar tarefa: Limite de tarefas atingido.\n");
    else if (codigo == 3)
        printf("Erro ao duplicar tarefa: Posicao invalida.\n");
}

else {
	printf("opcao invalida\n");
}
}while (opcao != 0);

codigo=salvarTarefas(&lt,arquivo);
if(codigo != 0)  //o codigo de erro é diferente de 0, não igual
printf("Erro ao salvar tarefas em arquivo");


//remoção de system("pause")
return 0;  //faltou o return 0 da funçao main

}
