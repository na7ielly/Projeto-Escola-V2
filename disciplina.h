#include "semestre.h"
#include "professor.h"

#define MAXNOME 100

#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct {
    int ativo;
    char nomeDisciplina[MAXNOME];
    int codigo;
    int matricula;  // Matrícula do professor responsável
    Semestre periodo;
} Disciplina;

int cadastrarDisciplina(int qtdDisciplinas, Disciplina disciplinas[], int maxDisciplinas, Professor professores[], int qtdProfessores);
void listarDisciplinas(int qtdDisciplinas, Disciplina disciplinas[]);
int excluirDisciplina(int qtdDisciplinas, Disciplina disciplinas[]);
int atualizarDisciplina(int qtdDisciplinas, Disciplina disciplinas[]);
int obtemOpcaoDisciplina();
int buscarDisciplinaPorNomeProfessor(int qtdDisciplinas, Disciplina disciplinas[], char nomeDisciplina[], int matricula);
int encontraCodigoDisciplina(int codigo, int qtdDisciplinas, Disciplina disciplinas[]);
int encontraDisciplinaProfessor(int qtdDisciplinas, Disciplina disciplinas[], char nomeDisciplina[]);

#endif
