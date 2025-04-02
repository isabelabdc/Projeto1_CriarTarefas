# Projeto1_CriarTarefas

GRUPO: Isabela Bonoto de Castro , Gustavo Runge Passarelli

PROBLEMAS CORRIGIDOS: --Erros em 'Projeto.h':

++Linha 1 - Número máximo de tarefas é 100 e não 5;

++Linha 12 - Nome da estrutura "ListaDeTarefas" estava sem o "s" no final;

++Linha 18 - "nome" estava com "s" no final;

--Erros em 'Projeto.c':

++Linha 1 - O nome do arquivo é 'Projeto.h' com p maiúsculo, e não 'projeto.h';

++Linhas 2 e 3 - Para incluir bibliotecas, utiliza-se <> e não aspas("");

++Linha 13 - Foi adicionado 'getchar()' para limpar o scanf e corrigir um bug;

++Linhas 15 e 18 - "%s" dentro do scanf foi trocado para "%[^\n]", para permitir o uso de espaços ao escrever a categoria e descrição;

++Linha 33 - Utilizou-se o símbolo de menor(<), quando o certo era usar maior(>);

++Linha 38 - Mudança de 'categoria' para 'descricao', pois categoria está sendo copiada duas vezes;

++Linha 60 - Faltou o asterisco(*) depois de char;

++Linha 71 - Faltou o ponto e vírgula(;) no final da linha;

--Erros em 'main.c':

++Linha 1 - O nome do arquivo é 'Projeto.h' com p maiúsculo, e não 'projeto.h';

++Linha 2 - Para incluir bibliotecas, utiliza-se <> e não aspas("");

++Linha 10 - Faltou o operador de endereços '&' antes de 'lt';

++Linha 13 - '/n' foi adicionado, pois faltou pular a linha;

++Linha 14 - O valor a ser atribuído a lt.qtd (quantidade de tarefas) em caso de falha de carregamento é 0;

++Linha 36 - O código de erro na função 'listarTarefas' é 1 e não 2;

++Linha 45 - O certo é '!=0' e não '==0', pois 0 é o código de retorno caso não tenha erros, então só se for diferente(!=) de 0, que avisamos ao usuário que tem erros;

++Linha 49 - Remoção de 'system("pause")';

++Linha 50 - Foi adicionado o return da função main;



FUNÇÕES IMPLEMENTADAS:

++Editar tarefas: permite que o usuário altere a prioridade, categoria e descrição de uma tarefa já existente;

++Filtrar tarefas: filtra tarefas por prioridade ou categoria, dependendo da escolha do usuário;

++Duplicar tarefas: permite que o usuário duplique/copie uma tarefa existente para a próxima posição da lista de tarefas;



FORMA DE COMPILAÇÃO E EXECUÇÃO DO CÓDIGO:

Para compilar e executar o código, foi feito o download do MinGW-w64, que permite compilar programas usando o GCC. 

Após fazer o devido download, digite o seguinte código no prompt de comando ou terminal, para compilar os dois arquivos juntos:

 "gcc main.c Projeto.c -o programa"

Esse código vai gerar um arquivo chamado "programa.exe", apenas digite "programa.exe" no prompt de comando/terminal e o programa será executado.
