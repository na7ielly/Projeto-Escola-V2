#include <stdio.h>
#include <string.h>
#include "disciplina.h"

#define VERDADEIRO 1
#define FALSO 0

int cadastrarDisciplina(int qtdDisciplinas, Disciplina disciplinas[], int maxDisciplinas, Professor professores[], int qtdProfessores) {
    char nomeDisciplina[MAXNOME];
    int codigo, matricula;
    Semestre periodoAtual;

    if (qtdDisciplinas == maxDisciplinas) {
        printf("Máximo de disciplinas atingido!\n");
        return FALSO;
    }

    printf("Código da disciplina: ");
    scanf("%d", &codigo);

    if (codigo < 0 || encontraCodigoDisciplina(codigo, qtdDisciplinas, disciplinas) != -1) {
        printf("Código inválido ou já cadastrado!\n");
        return FALSO;
    }

    disciplinas[qtdDisciplinas].codigo = codigo;

    printf("Digite o nome da disciplina: ");
    fgetc(stdin);
    fgets(disciplinas[qtdDisciplinas].nomeDisciplina, MAXNOME, stdin);
    disciplinas[qtdDisciplinas].nomeDisciplina[strlen(disciplinas[qtdDisciplinas].nomeDisciplina) - 1] = 0;

    if (encontraDisciplinaProfessor(qtdDisciplinas, disciplinas, disciplinas[qtdDisciplinas].nomeDisciplina) != -1) {
        printf("Disciplina já cadastrada!\n");
        return FALSO;
    }

    printf("Digite o semestre da disciplina (ano.período): ");
    scanf("%d.%d", &periodoAtual.ano, &periodoAtual.periodo);
    disciplinas[qtdDisciplinas].periodo = periodoAtual;

    printf("Digite a matrícula do professor responsável: ");
    scanf("%d", &matricula);

    int indiceProfessor = buscarProfessorPorMatricula(matricula, professores, qtdProfessores);
    if (indiceProfessor == -1) {
        printf("Professor com a matrícula %d não encontrado. Cadastro cancelado.\n", matricula);
        return FALSO;
    }

    disciplinas[qtdDisciplinas].matricula = matricula;
    disciplinas[qtdDisciplinas].ativo = VERDADEIRO;

    return VERDADEIRO;
}

void listarDisciplinas(int qtdDisciplinas, Disciplina disciplinas[]) {
    for (int i = 0; i < qtdDisciplinas; i++) {
        if (disciplinas[i].ativo) {
            printf("Código: %d, Nome: %s\n", disciplinas[i].codigo, disciplinas[i].nomeDisciplina);
        }
    }
}

int excluirDisciplina(int qtdDisciplinas, Disciplina disciplinas[]) {
    int codigo, posicaoDisciplina;

    printf("Código da disciplina: ");
    scanf("%d", &codigo);

    if (codigo <= 0) {
        printf("Código inválido!\n");
        return qtdDisciplinas;
    }

    posicaoDisciplina = encontraCodigoDisciplina(codigo, qtdDisciplinas, disciplinas);
    if (posicaoDisciplina == -1) {
        printf("Disciplina não encontrada!\n");
        return qtdDisciplinas;
    }

    disciplinas[posicaoDisciplina].ativo = FALSO;

    for (int i = posicaoDisciplina; i < qtdDisciplinas - 1; i++) {
        disciplinas[i] = disciplinas[i + 1];
    }

    return qtdDisciplinas - 1;
}

int atualizarDisciplina(int qtdDisciplinas, Disciplina disciplinas[]) {
    int codigo;
    printf("Digite o código da disciplina a ser atualizada: ");
    scanf("%d", &codigo);
    int indice = encontraCodigoDisciplina(codigo, qtdDisciplinas, disciplinas);

    if (indice == -1 || !disciplinas[indice].ativo) {
        printf("Disciplina não encontrada!\n");
        return FALSO;
    }

    printf("Digite o novo nome da disciplina: ");
    fgetc(stdin);
    fgets(disciplinas[indice].nomeDisciplina, MAXNOME, stdin);
    disciplinas[indice].nomeDisciplina[strlen(disciplinas[indice].nomeDisciplina) - 1] = 0;

    return VERDADEIRO;
}

int obtemOpcaoDisciplina() {
    int opcao;
    printf("\nOpções Disciplina:\n");
    printf("0: voltar\n");
    printf("1: cadastrar disciplina\n");
    printf("2: listar disciplinas\n");
    printf("3: atualizar disciplina\n");
    printf("4: excluir disciplina\n");

    scanf("%d", &opcao);
    return opcao;
}

int encontraDisciplinaProfessor(int qtdDisciplinas, Disciplina disciplinas[], char nomeDisciplina[]) {
    for (int i = 0; i < qtdDisciplinas; i++) {
        if (strcmp(disciplinas[i].nomeDisciplina, nomeDisciplina) == 0 && disciplinas[i].ativo) {
            return i;
        }
    }
    return -1;
}

int encontraCodigoDisciplina(int codigo, int qtdDisciplinas, Disciplina disciplinas[]) {
    for (int i = 0; i < qtdDisciplinas; i++) {
        if (disciplinas[i].codigo == codigo && disciplinas[i].ativo) {
            return i;
        }
    }
    return -1;
}
