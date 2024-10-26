#include "data.h"

#define MAXNOME 100
#define MAXCPF 11

typedef struct
{
    int ativo;
    int matricula;
    char nome[MAXNOME];
    char sexo; // M: masculino, F: feminino
    Data data_nascimento;
    char cpf[MAXCPF];
} Aluno;

int cadastrarAluno (int qtdAlunos, Aluno alunos[], int maxAlunos);
void listarAlunos (int qtdAlunos, Aluno alunos[]);
int atualizarAluno(int qtdAlunos, Aluno alunos[], int matricula);
int excluirAluno(int *qtdAlunos, Aluno alunos[], int matricula);
int obtemOpcaoAluno ();
int encontraMatricula (int qtdAlunos, Aluno alunos[], int matricula);