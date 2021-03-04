#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registradorAluno{
  char nome[50];
  char sobrenome[50];
  char turma[10];
  char resultado[20];
  long matricula;
  float crAluno, frequencia;//frequencia * 100;
};

int main () {
  int n, m, qtdeAlunos;//n = cont_alunos e m = cont_notas;
  int acimaMedia = 0, abaixoMedia = 0;
  float soma = 0, somaMedias = 0;
  float mediaAluno[n], mediaTurma;
  do{
    printf("\nQuantos alunos serão registrados? ");
    scanf("%d", &qtdeAlunos);
    if(qtdeAlunos <= 0){
      printf("\n\t***Quantidade inválida! Tente novamente...***\n");
    }
    printf("\n-------------------------------------------------\n");
  }while(qtdeAlunos <= 0);

  struct registradorAluno RegAluno[qtdeAlunos];
  float score[qtdeAlunos][m];

  for(n = 0; n < qtdeAlunos; n++){
    printf("\nQual é o nome e o sobrenome do(a) aluno(a) %d? ", (n+1));
    scanf("%s %s", RegAluno[n].nome, RegAluno[n].sobrenome);
    strcat(RegAluno[n].nome, " ");
    strcat(RegAluno[n].nome, RegAluno[n].sobrenome);
    printf("\nQual é o número de matrícula? ");
    scanf("%ld", &RegAluno[n].matricula);
    printf("\nInserindo as notas: \n");
    for(m = 0; m < 4; m++){
      printf("\tNota %d: ", (m+1));
      scanf("%f", &score[n][m]);
      soma = soma + score[n][m];
    }
    printf("\nQual a frequência (%%) do aluno? ");
    scanf("%f", &RegAluno[n].frequencia);

    mediaAluno[n] = soma / 4;
    somaMedias = somaMedias + mediaAluno[n];
    RegAluno[n].crAluno =  (mediaAluno[n] * RegAluno[n].frequencia) / 100;
    soma = 0;

    if(RegAluno[n].crAluno < 7){
      strcpy(RegAluno[n].resultado, "Reprovado(a)");
    } else {
      strcpy(RegAluno[n].resultado, "Aprovado(a)");
    }
    if(n < (qtdeAlunos - 1)){
      printf("\n-------------------------------------------------\n\n");
    }
  }
  printf("\n-------------------------------------------------\n");
  for(n = 0; n < qtdeAlunos; n++){
    printf("\n%d) Nome: %s | Matrícula: %ld \n", (n+1), RegAluno[n].nome, RegAluno[n].matricula);
    printf("   Média: %.1f | Frequência: %.1f %% | C.R: %.1f | Resultado: %s\n", mediaAluno[n], RegAluno[n].frequencia, RegAluno[n].crAluno, RegAluno[n].resultado);
    printf("\n-------------------------------------------------\n");
    if(mediaAluno[n] < 7){
      abaixoMedia = abaixoMedia + 1;
    } else if(mediaAluno[n] >= 7){
      acimaMedia = acimaMedia + 1;
    }
  }
  mediaTurma = somaMedias / qtdeAlunos;
  printf("\nDECLARAÇÕES FINAIS: \n\n*Média da turma: %.1f; \n*Quantidade de alunos acima da média: %d; \n*Quantidade de alunos abaixo da média: %d.\n\n", mediaTurma, acimaMedia, abaixoMedia);
  return 0;
}
