/*  Resolva T4 usando modulariza��o. Os dados de execu��o dever�o ser
    recebidos via argumento do programa na linha de comando.

    Exemplos de execu��es

    app 3 GCTTTCGACGAT GATCGAGCTTCGAA GGTCTAGCTAAT TCGA
    app N   bacteria1       bacteria2   bacteria3   virus(RNA)

    SAIDA_2 = Quantidade de bacterias: 3    N
    SAIDA_3 = Bacteria: GCTTTCGACGAT    
    SAIDA_3 = Bacteria: GATCGAGCTTCGAA
    SAIDA_3 = Bacteria: GGTCTAGCTAAT
    SAIDA_4 = Virus: TCGA
    SAIDA_5 = Bacteria infectada: GCTT
    SAIDA_5 = Bacteria infectada: GAGCTA
    SAIDA_5 = Bacteria infectada: GGTCTAGCTAAT
    SAIDA_6 = DNA resultante: GCT

    


    app 5 AGCT TGC CGCAA TGTC ATGTTC T

    SAIDA_2 = Quantidade de bacterias: 5
    SAIDA_3 = Bacteria: AGCT
    SAIDA_3 = Bacteria: TGC
    SAIDA_3 = Bacteria: CGCAA
    SAIDA_3 = Bacteria: TGTC
    SAIDA_3 = Bacteria: ATGTTC
    SAIDA_4 = Virus: T
    SAIDA_5 = Bacteria infectada: AGC
    SAIDA_5 = Bacteria infectada: GC
    SAIDA_5 = Bacteria infectada: CGCAA
    SAIDA_5 = Bacteria infectada: GC
    SAIDA_5 = Bacteria infectada: AGC
    SAIDA_6 = DNA resultante: GC


*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LIMITE_BACTERIAS 10
#define COMPR_BACTERIAS 1000
#define COMPR_VIRUS 1000



#define SAIDA_2 "\nSAIDA_2 = Quantidade de bacterias: %d"
#define SAIDA_3 "\nSAIDA_3 = Bacteria: %s"
#define SAIDA_4 "\nSAIDA_4 = Virus: %s"
#define SAIDA_5 "\nSAIDA_5 = Bacteria infectada: %s"
#define SAIDA_6 "\nSAIDA_6 = DNA resultante: %s"



char bac_contaminada[LIMITE_BACTERIAS][COMPR_BACTERIAS];
// objetivo: Apaga a substring = virus da bacteria
// parametros: bacteria, virus, numero de bacteria.
// retorno: nenhum
void apagar(char *bacteria_temp, char *virus_temp, int tamanho_virus, int num_bac){
    char *posicao_ocorrencia;
    while ((posicao_ocorrencia = strstr(bacteria_temp, virus_temp)) != NULL) {
        int indice = (posicao_ocorrencia - bacteria_temp);
        memmove(bacteria_temp + indice,bacteria_temp + indice + tamanho_virus, strlen(bacteria_temp) - indice - tamanho_virus + 1);
    }
    strcpy(bac_contaminada[num_bac], bacteria_temp);
}

// objetivo: Verificar se virus existe e tamanho e chama funcao para apagar
// parametros: bacteria, virus e o numero da bacteria
// retorno: nenhum
void remove_primeira_ocorrencia(char *bacteria, char *virus, int nbac){
    char bacteria_temp[COMPR_BACTERIAS];
    strcpy(bacteria_temp, bacteria);

    int tamanhoVirus = strlen(virus);
    if (tamanhoVirus == 0) {              
        printf(SAIDA_5, bacteria_temp);
        return;
    }

    // remove TODAS as ocorrências (inclusive as que aparecem após remover uma)
    apagar(bacteria_temp, virus, tamanhoVirus, nbac);
    printf(SAIDA_5, bacteria_temp);  // exibe “Bacteria infectada”

}


int main (int argc, char *argv[]){
    int nBacterias;
    char BACTERIAS[LIMITE_BACTERIAS][COMPR_BACTERIAS];
    //              limite = 10      comprimento = 1000
    char VIRUS[COMPR_VIRUS];
    //     comprimento = 1000

    nBacterias = atoi(argv[1]);     //recebe nBacterias como primeiro argumento
    printf(SAIDA_2,nBacterias);
    for(int i=2;i<argc-1;i++) {
        strcpy(BACTERIAS[i-2],argv[i]);
        printf(SAIDA_3,BACTERIAS[i-2]);
    }
    strcpy(VIRUS,argv[argc-1]);
    printf(SAIDA_4,VIRUS);

    //implemente a partir daqui sua solucao
    for (int i = 0; i < nBacterias; i++){
        remove_primeira_ocorrencia(BACTERIAS[i], VIRUS, i);
    }

/* verificacao(testes)
    for(int i = 0; i < nBacterias; i++){
        printf("\n%s", bac_contaminada[i]);
    }
*/
    return 0;
}

