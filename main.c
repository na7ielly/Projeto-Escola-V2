#include <stdio.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"

#define MAXALUNOS 3
#define MAXPROFESSORES 3
#define MAXDISCIPLINAS 3

#define VERDADEIRO 1
#define FALSO 0

// Protótipos
int obtemOpcaoGeral();

int main() {
    Aluno alunos[MAXALUNOS];
    Professor professores[MAXPROFESSORES];
    Disciplina disciplinas[MAXDISCIPLINAS];

    int qtdAlunos = 0;
    int qtdProfessores = 0;
    int qtdDisciplinas = 0;

    printf("\nPROJETO ESCOLA\n");

    int opcao;
    int sair = FALSO;

    while (!sair) {
        opcao = obtemOpcaoGeral();

        switch (opcao) {
            case 0: // Sair
                sair = VERDADEIRO;
                break;

            case 1: { // Módulo Aluno
                printf("\nMódulo Aluno\n");

                int opcaoAluno;
                int sairAluno = FALSO;

                while (!sairAluno) {
                    opcaoAluno = obtemOpcaoAluno();

                    switch (opcaoAluno) {
                        case 0: // Sair
                            sairAluno = VERDADEIRO;
                            break;

                        case 1: { // Cadastrar
                            int cadastrado = cadastrarAluno(qtdAlunos, alunos, MAXALUNOS);
                            if (cadastrado) {
                                qtdAlunos++;
                                printf("Aluno cadastrado com sucesso!\n");
                            } else {
                                printf("Matrícula não realizada!\n");
                            }
                            break;
                        }
                        case 2: // Listar
                            listarAlunos(qtdAlunos, alunos);
                            break;

                        case 3: { // Atualizar
                            int atualizado = atualizarAluno(qtdAlunos, alunos);
                            if (atualizado) {
                                printf("Aluno atualizado com sucesso!\n");
                            } else {
                                printf("Atualização não realizada!\n");
                            }
                            break;
                        }
                        case 4: { // Excluir
                            int excluido = excluirAluno(qtdAlunos, alunos);
                            if (excluido) {
                                printf("Aluno excluído com sucesso!\n");
                                qtdAlunos--;
                            } else {
                                printf("Exclusão não realizada!\n");
                            }
                            break;
                        }
                        default:
                            printf("Opção inválida!\n");
                    }
                }
                break;
            }
            case 2: { // Módulo Professor
                printf("\nMódulo Professor\n");

                int opcaoProfessor;
                int sairProfessor = FALSO;

                while (!sairProfessor) {
                    opcaoProfessor = obtemOpcaoProfessor();

                    switch (opcaoProfessor) {
                        case 0: // Sair
                            sairProfessor = VERDADEIRO;
                            break;

                        case 1: { // Cadastrar
                            int cadastrado = cadastrarProfessor(qtdProfessores, professores, MAXPROFESSORES);
                            if (cadastrado) {
                                qtdProfessores++;
                                printf("Professor cadastrado com sucesso!\n");
                            } else {
                                printf("Matrícula não realizada!\n");
                            }
                            break;
                        }
                        case 2: // Listar
                            listarProfessores(qtdProfessores, professores);
                            break;

                        case 3: { // Atualizar
                            int atualizado = atualizarProfessor(qtdProfessores, professores);
                            if (atualizado) {
                                printf("Professor atualizado com sucesso!\n");
                            } else {
                                printf("Atualização não realizada!\n");
                            }
                            break;
                        }
                        case 4: { // Excluir
                            int excluido = excluirProfessor(qtdProfessores, professores);
                            if (excluido) {
                                printf("Professor excluído com sucesso!\n");
                                qtdProfessores--;
                            } else {
                                printf("Exclusão não realizada!\n");
                            }
                            break;
                        }
                        default:
                            printf("Opção inválida!\n");
                    }
                }
                break;
            }
            case 3: { // Módulo Disciplina
                printf("\nMódulo Disciplina\n");

                int opcaoDisciplina;
                int sairDisciplina = FALSO;

                while (!sairDisciplina) {
                    opcaoDisciplina = obtemOpcaoDisciplina();

                    switch (opcaoDisciplina) {
                        case 0: // Sair
                            sairDisciplina = VERDADEIRO;
                            break;

                        case 1: { // Cadastrar
                            int cadastrado = cadastrarDisciplina(qtdDisciplinas, disciplinas, MAXDISCIPLINAS, professores, qtdProfessores);
                            if (cadastrado) {
                                qtdDisciplinas++;
                                printf("Disciplina cadastrada com sucesso!\n");
                            } else {
                                printf("Cadastro não realizado!\n");
                            }
                            break;
                        }
                        case 2: // Listar
                            listarDisciplinas(qtdDisciplinas, disciplinas);
                            break;

                        case 3: { // Atualizar
                            int atualizado = atualizarDisciplina(qtdDisciplinas, disciplinas);
                            if (atualizado) {
                                printf("Disciplina atualizada com sucesso!\n");
                            } else {
                                printf("Atualização não realizada!\n");
                            }
                            break;
                        }
                        case 4: { // Excluir
                            int excluido = excluirDisciplina(qtdDisciplinas, disciplinas);
                            if (excluido) {
                                printf("Disciplina excluída com sucesso!\n");
                                qtdDisciplinas--;
                            } else {
                                printf("Exclusão não realizada!\n");
                            }
                            break;
                        }
                        default:
                            printf("Opção inválida!\n");
                    }
                }
                break;
            }
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0; // Finaliza o programa
}

// Funções

int obtemOpcaoGeral() {
    int opcao;

    printf("\nOpções:\n");
    printf("0: sair\n");
    printf("1: aluno\n");
    printf("2: professor\n");
    printf("3: disciplina\n");

    scanf("%d", &opcao);
    
    return opcao;
}
