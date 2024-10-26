#include "data.h"

#define MAXNOME 100
#define MAXCPF 11

#ifndef PROFESSOR_H
#define PROFESSOR_H

typedef struct 
{
    int ativo;
    int matricula;
    char nome[MAXNOME];
    char sexo;
    Data data_nascimento;
    char cpf[MAXCPF];
} Professor;

// Funções para manipulação de professores
int cadastrarProfessor(int qtdProfessores, Professor professores[], int maxProfessores);
void listarProfessores(int qtdProfessores, Professor professores[]);
int atualizarProfessor(int qtdProfessores, Professor professores[], int matricula);
int excluirProfessor(int *qtdProfessores, Professor professores[], int matricula);
int obtemOpcaoProfessor();

// Funções auxiliares de busca
int encontraMatriculaProfessor(int qtdProfessores, Professor professores[], int matricula);
int buscarProfessorPorMatricula(int matricula, Professor professores[], int qtdProfessores);

#endif 
