#include "aluno.h"
#include <stdio.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0

int cadastrarAluno(int qtdAlunos, Aluno alunos[], int maxAlunos) {
    if (qtdAlunos == maxAlunos) {
        printf("Máximo de alunos atingido!\n");
        return -1;
    }

    int matricula;
    printf("Matrícula do aluno: ");
    scanf("%d", &matricula);

    if (matricula < 0) {
        printf("Matrícula inválida!\n");
        return -1;
    }

    if (encontraMatricula(qtdAlunos, alunos, matricula) != -1) {
        printf("Matrícula já cadastrada!\n");
        return -1;
    }

    Aluno novoAluno;
    novoAluno.matricula = matricula;
    printf("Nome do aluno: ");
    fgetc(stdin); // Limpar o buffer
    fgets(novoAluno.nome, MAXNOME, stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0'; // Remove o '\n'

    printf("Sexo do aluno (M/F): ");
    scanf(" %c", &novoAluno.sexo);

    printf("Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &novoAluno.data_nascimento.dia, &novoAluno.data_nascimento.mes, &novoAluno.data_nascimento.ano);

    printf("CPF: ");
    fgetc(stdin); // Limpar o buffer
    fgets(novoAluno.cpf, MAXCPF, stdin);
    novoAluno.cpf[strcspn(novoAluno.cpf, "\n")] = '\0';

    novoAluno.ativo = VERDADEIRO;
    alunos[qtdAlunos] = novoAluno;

    return 0;
}

void listarAlunos(int qtdAlunos, Aluno alunos[]) {
    if (qtdAlunos == 0) {
        printf("Não há alunos cadastrados!\n");
    } else {
        for (int i = 0; i < qtdAlunos; i++) {
            if (alunos[i].ativo) {
                printf("\nMatrícula: %d\n", alunos[i].matricula);
                printf("Nome: %s\n", alunos[i].nome);
                printf("Sexo: %c\n", alunos[i].sexo);
                printf("Data de nascimento: %02d/%02d/%04d\n", alunos[i].data_nascimento.dia, alunos[i].data_nascimento.mes, alunos[i].data_nascimento.ano);
                printf("CPF: %s\n", alunos[i].cpf);
            }
        }
    }
}

int atualizarAluno(int qtdAlunos, Aluno alunos[], int matricula) {
    int pos = encontraMatricula(qtdAlunos, alunos, matricula);
    if (pos == -1) {
        printf("Aluno não encontrado.\n");
        return -1;
    }

    printf("Atualizando dados do aluno:\n");
    printf("Nome: ");
    fgetc(stdin);
    fgets(alunos[pos].nome, MAXNOME, stdin);
    alunos[pos].nome[strcspn(alunos[pos].nome, "\n")] = '\0';

    printf("Sexo (M/F): ");
    scanf(" %c", &alunos[pos].sexo);

    printf("Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &alunos[pos].data_nascimento.dia, &alunos[pos].data_nascimento.mes, &alunos[pos].data_nascimento.ano);

    printf("CPF: ");
    fgetc(stdin);
    fgets(alunos[pos].cpf, MAXCPF, stdin);
    alunos[pos].cpf[strcspn(alunos[pos].cpf, "\n")] = '\0';

    return 0;
}

int excluirAluno(int *qtdAlunos, Aluno alunos[], int matricula) {
    int pos = encontraMatricula(*qtdAlunos, alunos, matricula);
    if (pos == -1) {
        printf("Aluno não encontrado.\n");
        return -1;
    }

    alunos[pos].ativo = FALSO;

    if (pos < *qtdAlunos - 1) {
        for (int i = pos; i < *qtdAlunos - 1; i++) {
            alunos[i] = alunos[i + 1];
        }
    }

    (*qtdAlunos)--; // Reduz o número de alunos
    return 0;
}

int encontraMatricula(int qtdAlunos, Aluno alunos[], int matricula) {
    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].matricula == matricula && alunos[i].ativo) {
            return i;
        }
    }
    return -1;
}

int obtemOpcaoAluno() {
    int opcao;
    printf("\nOpções Aluno:\n");
    printf("0: Voltar\n");
    printf("1: Cadastrar aluno\n");
    printf("2: Listar alunos\n");
    printf("3: Atualizar aluno\n");
    printf("4: Excluir aluno\n");

    scanf("%d", &opcao);
    return opcao;
}
