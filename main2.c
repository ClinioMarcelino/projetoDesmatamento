#include <stdio.h>
#define l 24 
#define c 27

/* Grupo: 
Aluno 1: Clinio Marcelino de Freitas
*/

// Espero q goste das minha soluções e da forma q pensei nos problemas

int main(void) {
	int i,j,h,k;

    int unDesmatadas[3],sair=0,casos=0;
    int indexMaioreEstrada[3];
    int tamanhoMaiorEstrada = 0;
    int M[l][c],sup=0,esq=0,dir=0,inf=0,area=0,areaMaxima=0,o;


	int janeiro[l][c] = {
		{40,40,36,36,40,36,36,40,40,40,40,36,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40},
		{40,40,40,40,36,40,40,40,40,40,40,40,40,40,40,36,40,40,40,40,40,40,40,40,40,40,40},
		{40,40,40,40,40,40,40,73,40,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40},
		{40,40,36,40,40,40,40,40,36,36,40,40,40,36,40,40,40,40,40,40,40,40,36,40,40,40,40},
		{40,40,40,40,40,40,40,36,36,40,36,36,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40},
		{40,40,40,40,36,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40},
		{40,40,40,40,40,36,40,40,40,40,41,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40},
		{40,40,40,40,41,40,36,36,40,40,40,40,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40},
		{40,36,40,40,40,40,36,36,36,40,36,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40},
		{40,36,40,36,40,40,36,40,40,40,40,40,40,40,36,36,40,40,40,40,40,40,40,40,40,40,40},
		{40,40,40,40,40,36,40,40,36,40,40,40,40,36,40,40,40,40,40,40,40,40,40,40,40,40,40},
		{36,40,40,40,36,40,40,36,36,40,40,40,40,36,40,40,40,40,40,40,40,40,40,40,40,40,40},
		{36,40,40,40,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40},
		{36,36,40,40,36,40,40,40,40,40,36,40,40,40,36,36,36,36,36,36,36,36,36,40,40,40,40},
		{40,36,40,40,40,40,40,40,40,4,36,36,36,36,36,36,36,40,40,40,40,36,36,40,40,40,40},
		{40,36,36,40,40,40,40,40,40,36,36,36,36,36,36,40,40,40,40,40,40,36,36,40,40,40,40},
		{36,36,36,40,40,40,36,40,40,40,36,36,36,36,36,40,40,40,36,36,40,40,36,40,40,40,40},
		{36,36,40,40,40,36,40,40,36,36,40,40,36,36,36,40,40,36,36,36,40,40,36,40,40,40,40},
		{36,36,36,40,40,36,40,40,40,40,36,36,40,40,40,36,36,36,36,36,36,36,36,40,40,40,40},
		{40,36,36,40,40,36,40,40,36,36,36,36,40,40,40,36,36,36,40,40,36,36,40,40,40,40,40},
		{40,40,36,36,40,40,36,36,36,36,36,36,40,40,40,40,36,36,36,40,36,36,40,40,40,40,40},
		{40,40,40,40,40,40,36,36,40,36,36,36,36,36,36,36,36,36,40,40,40,40,40,40,40,40,40},
		{40,73,41,36,40,40,40,40,40,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40},
		{40,40,40,36,40,40,40,40,40,40,40,40,36,36,36,36,40,40,40,40,40,40,40,40,40,40,40}
	};

	int fevereiro[l][c]={
		{36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36},
		{36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36},
		{36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36},
		{36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36},
		{36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36},
		{36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36},
		{36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36},
		{4,4,4,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36},
		{40,40,40,40,40,40,36,36,36,36,36,36,36,36,36,40,40,40,36,36,36,36,36,36,36,36,36},
		{109,109,109,109,109,109,72,40,72,72,72,72,40,40,40,73,105,73,40,36,36,40,40,40,36,36,36},
		{141,141,141,141,141,109,72,72,72,72,72,72,40,40,40,73,109,73,40,36,36,40,40,40,36,36,36},
		{109,109,109,109,109,109,72,40,72,72,72,72,40,40,40,73,109,73,40,36,36,40,40,40,36,36,36},
		{109,109,109,141,141,109,72,40,72,72,72,72,40,36,40,109,109,109,40,40,40,36,36,36,36,36,36},
		{109,109,109,141,141,141,72,40,72,72,72,72,40,36,40,109,109,109,40,40,40,36,36,36,36,36,36},
		{109,109,109,109,141,109,72,40,72,72,72,72,40,36,40,109,109,109,40,40,40,36,36,36,36,36,36},
		{72,72,72,72,72,72,40,40,40,73,109,73,40,36,40,72,72,72,40,40,40,36,36,36,36,36,36},
		{40,40,40,72,72,72,40,36,40,73,109,73,40,36,36,72,72,72,40,40,40,36,36,36,36,36,36},
		{72,72,72,72,72,72,40,40,40,73,109,73,40,36,40,72,72,72,40,40,40,36,36,36,36,36,36},
		{109,109,109,109,109,109,109,109,109,109,109,109,73,109,73,40,40,40,36,36,36,36,36,36,36,36,36},
		{141,141,141,109,109,109,109,141,109,109,109,109,109,109,109,40,36,40,36,36,36,36,36,36,36,36,36},
		{109,109,109,109,109,109,109,109,109,109,109,109,73,109,73,40,36,40,36,36,36,36,36,36,36,36,36},
		{109,109,109,109,141,109,72,72,72,40,40,40,40,40,40,36,36,36,40,40,40,36,36,36,36,36,36},
		{109,109,109,141,141,109,72,72,72,40,36,36,36,36,36,36,36,36,40,40,40,36,36,36,36,36,36},
		{109,109,109,109,141,109,72,72,72,40,40,40,36,36,36,36,36,36,40,40,40,36,36,36,36,36,36}
	};

	int marco[l][c] = {
		{36,36,36,36,36,36,36,36,36,36,36,36,36,109,109,109,141,109,109,73,4,72,145,109,141,109,109},
		{36,36,36,36,36,36,36,40,36,36,36,40,36,72,141,141,141,141,145,73,4,40,108,104,109,141,145},
		{40,36,36,36,36,40,40,40,40,36,40,4,36,109,145,109,109,141,141,72,36,36,72,109,141,109,76},
		{40,36,40,36,36,36,36,40,40,40,36,36,36,72,109,109,109,145,77,36,36,40,76,109,145,108,72},
		{36,36,40,40,36,36,36,40,40,40,36,40,109,109,76,109,77,109,40,36,40,40,109,109,145,141,109},
		{36,36,36,36,36,36,36,40,40,40,36,36,72,108,109,109,109,109,109,109,73,36,40,73,109,141,109},
		{40,36,36,36,36,36,40,40,40,36,40,36,36,109,145,141,145,141,145,109,36,40,72,109,109,109,109},
		{40,36,36,40,36,36,40,36,36,36,36,36,72,109,109,109,109,141,109,40,36,72,109,141,141,109,72},
		{40,40,40,40,36,36,40,40,40,40,40,40,36,77,141,145,109,108,36,36,40,36,72,109,141,141,109},
		{109,109,109,109,109,109,40,40,40,72,72,72,40,36,109,109,109,109,72,40,36,40,109,109,141,141,145},
		{109,109,109,141,141,141,72,40,40,72,72,72,40,73,109,73,109,141,145,40,4,40,72,109,141,109,109},
		{109,109,109,109,141,109,72,40,40,72,72,72,40,109,113,73,109,109,109,40,4,72,109,109,109,109,40},
		{72,104,105,141,141,141,40,40,40,72,72,72,36,40,72,109,141,141,104,73,40,72,145,145,141,109,109},
		{72,104,105,141,145,141,40,40,40,72,72,72,40,40,76,109,141,141,109,72,40,72,73,72,109,141,109},
		{72,72,72,141,141,141,40,40,40,72,72,72,40,72,109,109,109,109,72,40,40,40,72,72,109,145,109},
		{40,40,40,72,72,72,40,40,40,72,108,72,40,36,40,109,145,145,40,4,36,40,109,113,145,109,40},
		{40,40,40,72,72,72,40,40,40,72,109,72,40,36,40,109,109,108,40,36,40,40,40,40,109,72,36},
		{40,40,40,72,72,72,40,40,40,72,109,72,40,36,77,77,109,76,40,40,40,40,36,36,40,40,36},
		{109,109,109,109,109,109,109,109,109,109,109,109,73,109,76,72,109,109,40,40,40,40,40,40,36,40,40},
		{109,109,109,109,109,109,141,141,141,109,109,109,109,109,109,72,40,109,72,36,40,40,40,40,40,40,40},
		{109,109,109,109,109,109,109,109,109,109,109,109,73,77,72,40,36,40,40,36,72,40,40,36,40,40,36},
		{104,109,109,109,109,109,72,40,72,40,40,40,36,36,36,40,40,40,36,40,40,40,40,36,40,40,40},
		{109,109,109,141,141,109,72,40,40,40,40,40,36,36,40,40,40,40,40,40,72,40,36,40,36,36,40},
		{104,108,108,109,109,109,72,40,40,40,40,40,40,40,40,36,36,40,40,40,72,40,40,40,40,4,40}
    };

    printf("\nBem vindo ao desafio de desmatamento.");

    do{
        printf("\n-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~");
        printf("\n\nEscolha qual tarefa deseja vizualizar:");
        printf("\n1 - Tarefa 1");
        printf("\n2 - Tarefa 2");
        printf("\n3 - Tarefa 3");
        printf("\n4 - Tarefa Adicional");
        printf("\n9 - Finalizar Aplicacao\n\n");

        scanf("%d",&casos);

        switch(casos){
            case 1:
                //    CALCULO DAS UNIDADES DESMATADAS EM CADA MES
                for(i=0;i<3;i++){
                    unDesmatadas[i]=0;
                }

                
                for(i=0;i<3;i++){
                    for(h=0;h<l;h++){
                        for(j=0;j<c;j++){
                            switch (i)
                            {
                            case 0:
                                if(janeiro[h][j]>50){
                                    unDesmatadas[i]++;
                                }
                            break;
                            case 1:
                                if(fevereiro[h][j]>50){
                                    unDesmatadas[i]++;
                                }
                            break;
                            case 2:
                                if(marco[h][j]>50){
                                    unDesmatadas[i]++;
                                }
                            break;
                            }
                        }
                    }
                }

                printf("\n-~-~-~-~- Tarefa 1 -~-~-~-~-");
                printf("\n\na) ");
                printf(" %d unidades desmatadas em Janeiro",unDesmatadas[0]);
                printf("\n %d unidades desmatadas em Fevereiro",unDesmatadas[1]);
                printf("\n %d unidades desmatadas em Marco",unDesmatadas[2]);

                //  MEDIA PERCENTUAL DE DESMATAMENTO
                float mediaPercentual[3];

                for(i=0;i<3;i++){
                    mediaPercentual[i] = unDesmatadas[i];
                    mediaPercentual[i]/=l*c;
                    
                }

                printf("\n\nb) ");
                printf(" %.2f%% percentual desmatamento Janeiro",mediaPercentual[0]*100);
                printf("\n%.2f%% percentual desmatamento Fevereiro",mediaPercentual[1]*100);
                printf("\n%.2f%% percentual desmatamento Marco",mediaPercentual[2]*100);
                
                // UNIDADES MAIS DESMATADAS QUE NO MES ANTERIOR
                int varDesmatamento[2]={0,0};

                for(h=0;h<2;h++){
                    for(i=0;i<l;i++){
                        for(j=0;j<c;j++){
                            if(h==0){
                                if(fevereiro[i][j]>janeiro[i][j]){
                                    varDesmatamento[h]++;
                                }
                            }
                            if(h==1){
                                if(marco[i][j]>fevereiro[i][j]){
                                    varDesmatamento[h]++;
                                }
                            }
                        }
                    }
                }

                printf("\n\nc) ");  
                printf(" %dun é a variacao de desmatamento de Janeiro->Fevereiro",varDesmatamento[0]);
                printf("\n%dun é a variacao de desmatamento de Fevereiro->Marco",varDesmatamento[1]);
                sair=0;
            break;
            case 2:
                // GRAFICOS DE DESMATAMENTO
                printf("\n-~-~-~-~- Tarefa 2 -~-~-~-~-");
                printf("\n\nGrafico do aumento +20%% desmatamento Janeiro->Fevereiro");
                for(i=0;i<l;i++){
                    printf("\n");
                    for(j=0;j<c;j++){
                        if(fevereiro[i][j]>(1.2*janeiro[i][j])){
                            printf("*");
                        }else{
                            printf("_");
                        }
                    }
                }

                printf("\n\nGrafico do aumento +20%% desmatamento Fevereiro->Marco");
                for(i=0;i<l;i++){
                    printf("\n");
                    for(j=0;j<c;j++){
                        if(marco[i][j]>(1.2*fevereiro[i][j])){
                            printf("*");
                        }else{
                            printf("_");
                        }
                    }
                }
                sair=0;
            break;
            case 3:
                //  LINHAS DE DESMATAMENTO, ESTRADAS
                printf("\n-~-~-~-~- Tarefa 3 -~-~-~-~-");
                for(i=0;i<l;i++){
                    for(j=0;j<c;j++){
                        if(fevereiro[i][j]>50){
                            for(h=j+1;h<c;h++){
                                if(fevereiro[i][h]<50){
                                    break;
                                }
                                else{
                                    if(tamanhoMaiorEstrada == 0){                                            
                                        tamanhoMaiorEstrada = h-j;
                                    }else if(tamanhoMaiorEstrada < (h-j)){
                                        tamanhoMaiorEstrada = h-j;
                                        indexMaioreEstrada[0] = i;
                                        indexMaioreEstrada[1] = j;
                                        indexMaioreEstrada[2] = h;
                                    }
                                }
                            }
                        
                        }    
                    }
                }

                for(i=0;i<l;i++){
                    for(j=0;j<c;j++){
                        if(marco[i][j]>50){
                            for(h=j+1;h<c;h++){
                                if(marco[i][h]<50){
                                    break;
                                }
                                else{
                                    if(tamanhoMaiorEstrada < (h-j)){
                                        tamanhoMaiorEstrada = h-j;
                                        indexMaioreEstrada[0] = i;
                                        indexMaioreEstrada[1] = j;
                                        indexMaioreEstrada[2] = h;
                                    }
                                }
                            }                    
                        }    
                    }
                }
                    

                printf("\n\nIndex inicio maior estrada: [%d][%d]",indexMaioreEstrada[0],indexMaioreEstrada[1]);
                printf("\nIndex final maior estrada: [%d][%d]",indexMaioreEstrada[0],indexMaioreEstrada[2]);
                sair=0;
            break;
            case 4:
                //  MAIOR SUBMATRIZ DE AREA DESMATADA
                printf("\n-~-~-~-~- Tarefa Adicional -~-~-~-~-"); 

                for(i=0;i<l;i++){
                    for(j=0;j<c;j++){
                        if(janeiro[i][j]>=50){
                            M[i][j] = 1;
                        }
                        else{
                            M[i][j] = 0;
                        }   
                    }
                }

                int larg = c,alt=l;
                for(i=0;i<l;i++){
                    for(j=0;j<c;j++){
                        if(M[i][j] == 1){
                            if(M[i+1][j]==1 && M[i+1][j+1]==1 && M[i][j+1]==1){
                                h=j;

                                while(M[i][h]==1){
                                    h++;
                                }
                                larg = h-1;
                                area = (h-j+1);

                                if(areaMaxima == 0){
                                    areaMaxima = area;
                                    sup = i;
                                    inf = i;
                                    dir = h;
                                    esq = j;
                                }else if(area>areaMaxima){
                                    areaMaxima = area;
                                    sup = i;
                                    inf = i;
                                    dir = h;
                                    esq = j;
                                }
                                
                                for(k=i;k<alt;k++){
                                    for(o=j;o<larg;o++){
                                        if(M[k][o]==0){
                                            larg=o;
                                        }
                                        area = (k-i+1)*(o-j+1);
                                        if(area>areaMaxima){
                                            areaMaxima = area;
                                            sup = i;
                                            inf = k;
                                            dir = o;
                                            esq = j;
                                        }

                                    }

                                }
                            }else if(M[i+1][j]==1){
                                    h=i;

                                    while(M[h][j]==1){
                                        h++;
                                    }
                                    alt = h-1;
                                    area = (h-i+1);

                                    if(areaMaxima == 0){
                                        areaMaxima = area;
                                        sup = i;
                                        inf = i;
                                        dir = h;
                                        esq = j;
                                    }else if(area>areaMaxima){
                                        areaMaxima = area;
                                        sup = i;
                                        inf = i;
                                        dir = h;
                                        esq = j;
                                    }
                                    
                                    for(k=i;k<alt;k++){
                                        for(o=j;o<larg;o++){
                                            if(M[k][o]==0){
                                                larg=o;
                                            }
                                            area = (k-i+1)*(o-j+1);
                                            if(area>areaMaxima){
                                                areaMaxima = area;
                                                sup = i;
                                                inf = k;
                                                dir = o;
                                                esq = j;
                                            }

                                        }

                                    }
                            }else if(M[i][j+1]==1){
                                h=j;

                                while(M[i][h]==1){
                                    h++;
                                }
                                larg = h-1;
                                area = (h-j+1);
                                if(areaMaxima == 0){
                                    areaMaxima = area;
                                    sup = i;
                                    inf = i;
                                    dir = h;
                                    esq = j;
                                }else if(area>areaMaxima){
                                    areaMaxima = area;
                                    sup = i;
                                    inf = i;
                                    dir = h;
                                    esq = j;
                                }
                            }else{
                                areaMaxima = 1;
                                sup=i;
                                inf=i;
                                dir=j;
                                esq=j;
                            }

                        }
                    }   
                }

            printf("\nMatriz de tamanho %dx%d,comecando na posicao[%d][%d] da matriz principal de Janeiro",(inf-sup+1),(dir-esq+1),sup,esq);
            printf("\n");

            for(i=sup;i<=inf;i++){
                    for(j=esq;j<=dir;j++){
                        printf("%d ",janeiro [i][j]);
                    }
                    printf("\n");
                }        


                for(i=0;i<l;i++){
                    for(j=0;j<c;j++){
                        if(fevereiro[i][j]>=50){
                            M[i][j] = 1;
                        }
                        else{
                            M[i][j] = 0;
                        }   
                    }
                }

                for(i=0;i<l;i++){
                    for(j=0;j<c;j++){
                        if(M[i][j] == 1){
                            if(M[i+1][j]==1 && M[i+1][j+1]==1 && M[i][j+1]==1){
                                h=j;

                                while(M[i][h]==1){
                                    h++;
                                }
                                larg = h-1;
                                area = (h-j+1);

                                if(areaMaxima == 0){
                                    areaMaxima = area;
                                    sup = i;
                                    inf = i;
                                    dir = h;
                                    esq = j;
                                }else if(area>areaMaxima){
                                    areaMaxima = area;
                                    sup = i;
                                    inf = i;
                                    dir = h;
                                    esq = j;
                                }
                                
                                for(k=i;k<alt;k++){
                                    for(o=j;o<larg;o++){
                                        if(M[k][o]==0){
                                            larg=o;
                                        }
                                        area = (k-i+1)*(o-j+1);
                                        if(area>areaMaxima){
                                            areaMaxima = area;
                                            sup = i;
                                            inf = k;
                                            dir = o;
                                            esq = j;
                                        }

                                    }

                                }
                            }

                        }
                    }   
                } 

                printf("\nMatriz de tamanho %dx%d,comecando na posicao[%d][%d] da matriz principal de Fevereiro",(inf-sup+1),(dir-esq+1),sup,esq);
                printf("\n");

                for(i=sup;i<=inf;i++){
                    for(j=esq;j<=dir;j++){
                        printf("%d ",fevereiro[i][j]);
                    }
                    printf("\n");
                }

                

                for(i=0;i<l;i++){
                    for(j=0;j<c;j++){
                        if(marco[i][j]>=50){
                            M[i][j] = 1;
                        }
                        else{
                            M[i][j] = 0;
                        }   
                    }
                }

                for(i=0;i<l;i++){
                    for(j=0;j<c;j++){
                        if(M[i][j] == 1){
                            if(M[i+1][j]==1 && M[i+1][j+1]==1 && M[i][j+1]==1){
                                h=j;

                                while(M[i][h]==1){
                                    h++;
                                }
                                larg = h-1;
                                area = (h-j+1);

                                if(areaMaxima == 0){
                                    areaMaxima = area;
                                    sup = i;
                                    inf = i;
                                    dir = h;
                                    esq = j;
                                }else if(area>areaMaxima){
                                    areaMaxima = area;
                                    sup = i;
                                    inf = i;
                                    dir = h;
                                    esq = j;
                                }
                                
                                for(k=i;k<alt;k++){
                                    for(o=j;o<larg;o++){
                                        if(M[k][o]==0){
                                            larg=o;
                                        }
                                        area = (k-i+1)*(o-j+1);
                                        if(area>areaMaxima){
                                            areaMaxima = area;
                                            sup = i;
                                            inf = k;
                                            dir = o;
                                            esq = j;
                                        }

                                    }

                                }
                            }
                        }
                    }   
                } 


                printf("\nMatriz de tamanho %dx%d,comecando na posicao[%d][%d] da matriz principal de Marco",(inf-sup+1),(dir-esq+1),sup,esq);
                printf("\n");

                for(i=sup;i<=inf;i++){
                    for(j=esq;j<=dir;j++){
                        printf("%d ",marco[i][j]);
                    }
                    printf("\n");
                }

                
                sair=0;
            break;
            case 9:

                sair=3;
            break;
            default:
                sair++;
                printf("Desculpa nao foi possivel identificar sua solicitacao");
                printf("\nTentativa %d/3",sair);

        } 

    }while(sair!=3);

    printf("\n\nObrigado pela atencao e preocupacao com o meio ambiente!\n\n");



return 0;
}