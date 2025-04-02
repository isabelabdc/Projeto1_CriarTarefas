#define TOTAL_TAREFAS 100  //número máximo de tarefas é 100 e não 5

typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
} Tarefa;

typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefas;  //nome da estrutura estava errado

int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int listarTarefas(ListaDeTarefas *lt);
int editarTarefa(ListaDeTarefas *lt);  //nova função - editarTarefa
int filtrarTarefas(ListaDeTarefas *lt);  //nova função - filtrarTarefas

int carregarTarefas(ListaDeTarefas *lt, char *nome);   //nome estava no plural
int salvarTarefas(ListaDeTarefas *lt, char *nome);
void exibeMenu();
