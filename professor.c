#include "professor.h"
#include <stdio.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0

int cadastrarProfessor(int qtdProfessores, Professor professores[], int maxProfessores) {
    int matricula;
    if (qtdProfessores == maxProfessores) {
        printf("Máximo de professores atingido!\n");
        return FALSO;
    }

    printf("Matrícula do professor: ");
    scanf("%d", &matricula);
    if (matricula < 0 || encontraMatriculaProfessor(qtdProfessores, professores, matricula) != -1) {
        printf("Matrícula inválida ou já cadastrada!\n");
        return FALSO;
    }
    professores[qtdProfessores].matricula = matricula;

    printf("Nome do professor: ");
    fgetc(stdin);
    fgets(professores[qtdProfessores].nome, MAXNOME, stdin);
    professores[qtdProfessores].nome[strlen(professores[qtdProfessores].nome) - 1] = '\0';

    printf("Sexo do professor: ");
    scanf(" %c", &professores[qtdProfessores].sexo);

    printf("Data de nascimento (dia/mês/ano): ");
    scanf("%d/%d/%d", &professores[qtdProfessores].data_nascimento.dia, &professores[qtdProfessores].data_nascimento.mes, &professores[qtdProfessores].data_nascimento.ano);

    printf("CPF: ");
    fgetc(stdin);
    fgets(professores[qtdProfessores].cpf, MAXCPF, stdin);
    professores[qtdProfessores].cpf[strlen(professores[qtdProfessores].cpf) - 1] = '\0';

    professores[qtdProfessores].ativo = VERDADEIRO;

    return VERDADEIRO;
}

void listarProfessores(int qtdProfessores, Professor professores[]) {
    if (qtdProfessores == 0) {
        printf("Não há professores cadastrados!\n");
    } else {
        for (int i = 0; i < qtdProfessores; i++) {
            if (professores[i].ativo) {
                printf("Matrícula: %d\n", professores[i].matricula);
                printf("Nome: %s\n", professores[i].nome);
                printf("Sexo: %c\n", professores[i].sexo);
                printf("Data de nascimento: %d/%d/%d\n", professores[i].data_nascimento.dia, professores[i].data_nascimento.mes, professores[i].data_nascimento.ano);
                printf("CPF: %s\n", professores[i].cpf);
            }
        }
    }
}

int atualizarProfessor(int qtdProfessores, Professor professores[]) {
    int matricula, posicaoProfessor;
    printf("Matrícula do professor: ");
    scanf("%d", &matricula);

    posicaoProfessor = encontraMatriculaProfessor(qtdProfessores, professores, matricula);
    if (posicaoProfessor == -1) {
        printf("Matrícula não encontrada!\n");
        return FALSO;
    }

    printf("Novo nome: ");
    fgetc(stdin);
    fgets(professores[posicaoProfessor].nome, MAXNOME, stdin);
    professores[posicaoProfessor].nome[strlen(professores[posicaoProfessor].nome) - 1] = '\0';

    printf("Novo sexo: ");
    scanf(" %c", &professores[posicaoProfessor].sexo);

    printf("Nova data de nascimento (dia/mês/ano): ");
    scanf("%d/%d/%d", &professores[posicaoProfessor].data_nascimento.dia, &professores[posicaoProfessor].data_nascimento.mes, &professores[posicaoProfessor].data_nascimento.ano);

    printf("Novo CPF: ");
    fgetc(stdin);
    fgets(professores[posicaoProfessor].cpf, MAXCPF, stdin);
    professores[posicaoProfessor].cpf[strlen(professores[posicaoProfessor].cpf) - 1] = '\0';

    return VERDADEIRO;
}

int excluirProfessor(int *qtdProfessores, Professor professores[], int matricula) {
    int posicaoProfessor = encontraMatriculaProfessor(*qtdProfessores, professores, matricula);

    if (posicaoProfessor == -1) {
        printf("Matrícula não encontrada!\n");
        return FALSO;
    }

    professores[posicaoProfessor].ativo = FALSO;

    // Ajustar a lista de professores
    for (int i = posicaoProfessor; i < *qtdProfessores - 1; i++) {
        professores[i] = professores[i + 1];
    }
    (*qtdProfessores)--;

    return VERDADEIRO;
}

int obtemOpcaoProfessor() {
    int opcao;
    printf("\nOpções Professor:\n");
    printf("0: voltar\n");
    printf("1: cadastrar professor\n");
    printf("2: listar professores\n");
    printf("3: atualizar professor\n");
    printf("4: excluir professor\n");
    scanf("%d", &opcao);
    return opcao;
}

int encontraMatriculaProfessor(int qtdProfessores, Professor professores[], int matricula) {
    for (int i = 0; i < qtdProfessores; i++) {
        if (professores[i].matricula == matricula && professores[i].ativo)
            return i;
    }
    return -1;
}

int buscarProfessorPorMatricula(int matricula, Professor professores[], int qtdProfessores) {
    return encontraMatriculaProfessor(qtdProfessores, professores, matricula);
}
