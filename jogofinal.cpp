#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include "boneco.h"

//structs
typedef struct posicao{
	float max;
	
    float min;  
	
	int numeroarea;
	
}area;

typedef struct lanc{
	float angulo;
	float distancia;
	float velocidadelancamento;
	float velocidadesalto;
	

}lancamento;

typedef struct rod{

	lancamento lanc[5];
}ronda;

typedef struct player{
	float altura;
	int pontos;
	int falhas;
	char nome[20];
	ronda rodada[3];
	
}jogador;

typedef struct final{
	float altura;
    char nome[20];
    int pontos[3];
	int numerofalhas[3];
}Final;

typedef struct player2{
	float altura;
	int pontos;
	char nome[20];
	lancamento lanc;
}jogador2;



//DECORACAO:
void cabecalho(){
	system("cls");
	printf("                      ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("                      ::::::::::::::::::::::::::JOGO DE BASQUETE::::::::::::::::::::::::::\n");
    printf("                      ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\n");
    printf("\n");
}  
void cabecalho1(){
	system("cls");
	printf("               ::::::::::::::::::::::::::::::::::::::::::::::::::                      \n");
    printf("               :::::::::::::::::::MULTIJOGADOR:::::::::::::::::::                      \n");
    printf("               ::::::::::::::::::::::::::::::::::::::::::::::::::                      \n");
    printf("\n");
    printf("\n");
}  
void cabecalho3(){
	system("cls");
	printf("               :::::::::::::::::::::::::::::::::::::::::::::::::                      \n");
    printf("               :::::::::::::::::::::::SOLO::::::::::::::::::::::                      \n");
    printf("               :::::::::::::::::::::::::::::::::::::::::::::::::                      \n");
    printf("\n");
    printf("\n");
}  
void cabecalho4(){
		system("cls");
	printf("               ::::::::::::::::::::::::::::::::::::::::::::::::::::                      \n");
    printf("               :::::::::::::::::::::::TABELA:::::::::::::::::::::::                      \n");
    printf("               ::::::::::::::::::::::::::::::::::::::::::::::::::::                      \n");
    printf("\n");
    printf("\n");
}
void printmenu(){
	cabecalho();
	printf("MULTIJOGADOR------------------------------1)\n");
	printf("SOLO--------------------------------------2)\n");
	printf("TABELA DE PONTUACOES----------------------3)\n");  
	printf("SAIR--------------------------------------4)\n");
	printf("Selecione uma opcao!\n");
	

}





//FUNCAO QUE TEM COMO OBJETIVO PRINTAR UMA AREA NO EXECUTOR
void printarea(area p){
	printf("Pontos da area:%d     Limite minimo:%f    Limite maximo:%f\n",p.numeroarea,p.min,p.max);
}



//FUNCAO QUE GERA UMA POSICAO(FLOAT) ALEATORIA DENTRO DE UMA DETERMINADA AREA(PASSADA COMO PARAMETRO) E RETORNA ESSA POSICAO
float criarposicao(area a){
float dist;

		dist=a.min+(float)rand()/((float)RAND_MAX/(a.max-a.min));
					
	
return dist;	
}

//FUNCAO QUE GERA POSICOES(INTEIRO) ENTRE 0 E 14 MAS SEM INCLUIR O 0 , RETORNANDO ESSE VALOR
int criarposicao2(){
	srand(time(NULL));
	int dist;
    int d=1;
		
		while(d==1){
		
				dist=rand()%14;
				if(dist==0){
					d=1;
				}else{
					d=0;
				}
}
return dist;	
}


//FUNCAO QUE TEM O PAPEL DE PREENCHER A STRCUCT JOGADOR.RONDA.LANCAMNETO.ANGULO RECEBENDO 3 INTEIROS QUE REPRESENTAM AS POSICOES DOS CICLOS DOS JOGADORES(I) ,DAS RONDAS(R) E DO LANACEMNTO(L)
void criarangulo(jogador player[],int i,int r,int l){
int c=1;

//ESTE CICLO VICIADO TEM COMO OBJETIVO NAO PERMITIR A ENTRADA DE VALORES IMPROPRIOS                     

while(c==1){
	printf("Angulo de lancamento (entre 0 e 80 graus):");
	scanf("%f",&player[i].rodada[r].lanc[l].angulo);
	if((player[i].rodada[r].lanc[l].angulo>0)&&(player[i].rodada[r].lanc[l].angulo<80)){
		c=0;
	}else{
	
	c=1;	
	char string[100];
	if(!(player[i].rodada[r].lanc[l].angulo = atof(string))){
 		fgets(string, 100, stdin);
 		c=1;
		 printf("Por favor insira um numero entre 0 e 80!\n");
 	}
	if ((player[i].rodada[r].lanc[l].angulo<0)||(player[i].rodada[r].lanc[l].angulo>80)){
		c=1;
		printf("Por favor insira um numero entre 0 e 80!\n");
	}
	printf("\n");		
}
} 
}

//FUNCAO QUE TEM O PAPEL DE PREENCHER A STRCUCT JOGADOR.RONDA.LANCAMNETO.VELOCIDADELANCAMENTO RECEBENDO 3 INTEIROS QUE REPRESENTAM AS POSICOES DOS CICLOS DOS JOGADORES(I) ,DAS RONDAS(R) E DO LANACEMNTO(L)
void criarvelocidadeL(jogador player[],int i,int r,int l){

int d=1;

//CICLO VICIADO QUE IMPEDE A ENTRADA DE VALORES IMPROPRIOS       
while(d==1){
	printf("Velocidade de lancamento (entre 0 e 30 m/s): ");
    scanf("%f",&player[i].rodada[r].lanc[l].velocidadelancamento);
    
		           	
    if((player[i].rodada[r].lanc[l].velocidadelancamento>0)&&(player[i].rodada[r].lanc[l].velocidadelancamento<30)){
      	d=0;
	}else{
	d=1;
				
	char string[100];
	if(!(player[i].rodada[r].lanc[l].velocidadelancamento = atof(string))){
 		fgets(string, 100, stdin);
 		d=1;
		 printf("Por favor insira um numero entre 0 e 30!\n");
 	}
	 	
	if ((player[i].rodada[r].lanc[l].velocidadelancamento<0)||(player[i].rodada[r].lanc[l].velocidadelancamento>30)){
		printf("Por favor insira um numero entre 0 e 30!\n");
		d=1;
	}


	printf("\n");	
}	
}
}

//FUNCAO QUE TEM O PAPEL DE PREENCHER A STRCUCT JOGADOR.RONDA.LANCAMNETO.VELOCIDADESALTO RECEBENDO 3 INTEIROS QUE REPRESENTAM AS POSICOES DOS CICLOS DOS JOGADORES(I) ,DAS RONDAS(R) E DO LANACEMNTO(L)
void criarvelocidadeS(jogador player[],int i,int r,int l){
int b=1;

//CICLO VICIADO QUE IMPEDE A ENTRADA DE VALORES IMPROPRIOS                    
              
              	while(b==1){
					printf("Velocidade do salto (entre 0 e 6.1 m/s): ");
    	           	scanf("%f",&player[i].rodada[r].lanc[l].velocidadesalto);
               	
        	       	if(player[i].rodada[r].lanc[l].velocidadesalto<=6.1&&player[i].rodada[r].lanc[l].velocidadesalto>=0){
            	   	b=0;
				   	}else{
				   	printf("Por favor insira um numero entre 0 e 6.1!\n");
				   	
				  	}
               	}
    			printf("\n");                         
               
}

//FUNCAO QUE TEM O PAPEL DE PREENCHER A STRCUCT JOGADOR.ALTURA E JOGADOR.NOME RECEBENDO 1 INTEIRO QUE REPRESENTA A POSICAO DOS CICLO DOS JOGADORES(I) 
void caracteristicasjogador(jogador play[],int i){
	
int d=1;  
	  
printf("Introduza o nome do jogador %d: ",i+1);
scanf("%s",play[i].nome);
printf("\n");
    
  //ESTE CICLO VICIADO TEM COMO OBJETIVO EVITAR VALORES IMPROPRIOS PARA A ALTURA UMA VEZ QUE O HOMEM MAIS ALTO TEM 2.5M E O MAIS BAIXO 0.5              
            
while(d==1){
			    
    printf("Indique a altura do jogador %d (entre 0.50 e 2.50 metros):",i+1);
    scanf("%f",&play[i].altura);
               		    
	if((play[i].altura>0.50)&&(play[i].altura<2.50)){
        d=0;
	}else{
	
		d=1;				
	char string[100];
	if(!(play[i].altura = atof(string))){
 		fgets(string, 100, stdin);
 		printf("Por favor insira um numero entre 0.50 e 2.50!\n");
 		d=1;
 	}
	if (((play[i].altura<0.50)||(play[i].altura>2.50))&&(play[i].altura>2.50!=0)){
		printf("Por favor insira um numero entre 0.50 e 2.50!\n");
		d=1;
	}
	printf("\n");
}
}
}

//FUNCAO QUE CALCULA A ALTURA DE SALTO (SEM SOMAR A ALTURA DO JOGADOR) E RETORNA ESSE VALOR
float alturasalto(jogador play[],int i,int r,int l){
	float a, b;
  	b=play[i].rodada[r].lanc[l].velocidadesalto;
  	a=(b*b) / (2*9.8);	
	return a;
}

//FUNCAO QUE CRIA AS AREAS DE JOGO SENDO ATRIBUIDO COMO PARAMETROS UMA VARIAVEL AREA E O 0 E 0 14 QUE SAO OS VALORES MIN E MAX QUE O CAMPO TEM
void geraArea(area pos[], float a, float b){
 
int j;
float mx, mn;

//ESTE CICLO PERMITE A REALIZACAO DO PREECHIMENTO SEM QUE ACHA CRUZAMENTO DE AREAS 
	
system("cls");
a=0;
mn=0;
mx=0;
pos[0].max=0;
pos[1].max=0;
pos[2].max=0;
for(j=0;j<3;j++){
	 
	pos[j].numeroarea=j+1;
	printf("Area:%d\n",pos[j].numeroarea);
	printf("Introduza o limite maximo da area %d (em metros):\n",pos[j].numeroarea);
	scanf("%f",&mx);
	mn=a;
	
	if((mx<=b)&&(mn<mx)){
		a=mx;
	    pos[j].min=mn;
	    pos[j].max=mx;
	}
	
	if((mx>b)||(mn>=mx)){
			
		char string[100];
		if(!(mx = atof(string))){
 			fgets(string, 100, stdin);
 			printf("Valores nao aceites!\n");
 		}
		j--;
	}
	
	if ((mx>=14)&&(j==0)){
		printf("Valores nao aceites!\n");
		j--;
		a=0;
	}
	
	if ((mx>=14)&&(j==1)){
		printf("Valores nao aceites!\n");
		j--;
		a=mn;	
	}
	
	if ((mx!=14)&&(j==2)){
		printf("Valores nao aceites!\n");
		j--;
		a=mn;
	}	
		
	printf("\n");
}
}

//FUNCAO RESPONSAVEL POR COLOCAR A ANIMACAO RECEBENDO COMO PARAMENTROS OS VALORES QUE SAO PRECISOS PARA CALCULAR SE A BOLA ENTROU OU NAO 
void animacao1(float p1,float a,float ac,float p2,float ang,float v ,float alturajogador){
	float h1;
	float h2;
	h1=(p1*tan(ang))-((9.8*p1*p1)/(2*v*v*cos(ang)*cos(ang)));
	h2=(p2*tan(ang))-((9.8*p2*p2)/(2*v*v*cos(ang)*cos(ang)));
// E DE SALIENTAR QUE CASO A ALTURA H1 FOR MAIOR QUE A ALTURA DO CESTO MENOS A ALTURA DO PONTO DE LANCAMENTO E H2 FOR MENOR ENTAO OCORREU PONTO
// ESTE CALCULO BASEIA SE NOS CENTRO DE MASSA DA BOLA DE BASQUETE DE FORMA A OCORRER PONTO	
	if(h1>=(ac-a)&&h2<=(ac-a)&&a==alturajogador){
	//entra sem salto
	printiniciosemsalto();
	printacerto();	
		
	}else if(h1>=(ac-a)&&h2<=(ac-a)&&a!=alturajogador){
		//entra com salto
		printiniciocomsalto();
		printacerto();
	}else if(h1>=(ac-a)&&h2>=(ac-a)&&a==alturajogador){
		//falha sem salto e passa por cima do cesto
			printiniciosemsalto();
			printfalhamaior();
	}else if(h1>=(ac-a)&&h2>=(ac-a)&&a!=alturajogador){
		//falha com salto e passa por cima do cesto
			printiniciocomsalto();
			printfalhamaior();
	}else if(h1<=(ac-a)&&h2<=(ac-a)&&a==alturajogador){
		//falha sem salto e passa por baixo do cesto
			printiniciosemsalto();
			printfalhamenor();
	}else {
		//falha com salto e passa por baixo do cesto	
			printiniciocomsalto();
			printfalhamenor();
	}
}

//FUNCAO QUE CRIA UM ANGULO PARA A STRUCT JOGADOR2 E ESTA E UTILIZADA SOMENTE NA MORTE SUBITA 
void criarangulo2(jogador2 player[],int i){

int c=1;
while(c==1){
				   
	printf("Angulo de lancamento (entre 0 e 80 graus):");
	scanf("%f",&player[i].lanc.angulo);
		if((player[i].lanc.angulo>0)&&(player[i].lanc.angulo<80)){
			c=0;
		}else{
		
		c=1;
		char string[100];
		if(!(player[i].lanc.angulo = atof(string))){
 			fgets(string, 100, stdin);
 			c=1;
			 printf("Por favor insira um numero entre 0 e 80!\n");
 		}
 		
		if ((player[i].lanc.angulo<0)||(player[i].lanc.angulo>80)){
			c=1;
			printf("Por favor insira um numero entre 0 e 80!\n");
		}
		printf("\n");		
}
} 
}
//FUNCAO QUE CRIA UMA VELOCIDADE DE LANCAMENTO PARA A STRUCT JOGADOR2 E SO SE UTILIZA NA MORTE SUBITA 
void criarvelocidadeL2(jogador2 player[],int i){

int d=1;
while(d==1){
	
	printf("Velocidade de lancamento (entre 0 e 30 m/s):");
    scanf("%f",&player[i].lanc.velocidadelancamento);
	if((player[i].lanc.velocidadelancamento>0)&&(player[i].lanc.velocidadelancamento<30)){
    	d=0;;
	}else{
	
	d=1;	
	char string[100];
	if(!(player[i].lanc.velocidadelancamento = atof(string))){
 		fgets(string, 100, stdin);
 		d=1;
		 printf("Por favor insira um numero entre 0 e 30!\n");
 	}     
	           	
	if ((player[i].lanc.velocidadelancamento<0)||(player[i].lanc.velocidadelancamento>30)){
		d=1;
		printf("Por favor insira um numero entre 0 e 30!\n");
	}
	printf("\n");	
}	     
}
}
//FUNCAO QUE CRIA VELOCIDADE DE SALTO PARA A STRUCT JOGADOR2 E SO SE UTILIZA NA MORTE SUBITA 
void criarvelocidadeS2(jogador2 player[],int i){
int b=1;

                    
              
                 while(b==1){
				printf("Velocidade do salto (entre 0 e 6.1 m/s): ");
               	scanf("%f",&player[i].lanc.velocidadesalto);
               	
               	if(player[i].lanc.velocidadesalto<=6.1&&player[i].lanc.velocidadesalto>=0){
               	b=0;
				   }else{
				   	printf("Por favor insira um numero entre 0 e 6.1!\n");
				   	
				   }
               }
    printf("\n");               
               
}



//FUNCAO QUE RETORNA A ALTURA DO SALTO RECEBENDO COMO PARAMETROS A VARIAVEL PLAY2 E UM INTEIRO QUE SE REFERE A RESPETIVA POSICAO E SO SE UTILIZA NA MORTE SUBITA
float alturasalto2(jogador2 play2[],int i){
  float a, b;
  b=play2[i].lanc.velocidadesalto;
  a=(b*b) / (2*9.8);	
	return a;
}

//DECORACAO
void cabecalho2(){
	system("cls");
	printf("xxxxxxxxxxxxx\n");
	printf("|   MORTE   |\n");
    printf("|  SUBITA!! |\n");
    printf("xxxxxxxxxxxxx\n");
    printf("\n");
    printf("\n");
}  

//FUNCAO RESPONSAVEL POR REALIZAR A MORTE SUBITA QUE NO FINAL RETORNA O VALOR DE QUANTOS JOGADORES OBTIVERAM A PONTUACAO MAIOR(ACUM3) DE FORMA A REALIZAR UMA RECURSIVIDADE NA MAIN E FILTAR OS JOGADOREES ATE TER UM VENCEDOR
int mortesubita(jogador2 play2[],int acum2){
  int numerosobrar=acum2;
  int i;
  int j;
  int k;
  float alturainicial;
  int distancia;
  int d=1;
  float p1;
  float p2;
  float a;
  float ac=3.05;
  float v;
  float ang;
  float y1;
  float y2;
  int acum1=0;
  int acum3=0;
         cabecalho2(); 
  printf("Altura do cesto:%f\n",ac);
  
  	distancia=criarposicao2();
	 
  
  //NESTE CICLO VERIFICA SE SE ENCESTOU OU NAO SENDO PREENCHIDO OS RESPETIVOS REQUESITOS PARA SE REALIZAR O LANCAMENTO(UM LANCAMENTO COM EXITO VALE 1 PONTO E SEM EXITO 0)
  for(i=0;i<numerosobrar;i++){
	cabecalho2();
  	printf("Distancia ao cesto:%d\n",distancia);
  	
  	printf("%s:\n",play2[i].nome);
  	criarangulo2(play2,i);
  	criarvelocidadeS2(play2,i);
  	criarvelocidadeL2(play2,i);
  	alturainicial=alturasalto2(play2,i)+play2[i].altura;
  	
   	p1=distancia-0.331;
   
   	a=alturainicial;
  
   	p2=distancia-0.119;
   
   	ang=3.1415926*play2[i].lanc.angulo/180; //3.1415926;
   	
   	v=play2[i].lanc.velocidadelancamento;
   
   	y1=(p1*tan(ang))-((9.8*p1*p1)/(2*v*v*cos(ang)*cos(ang)));
   	y2=(p2*tan(ang))-((9.8*p2*p2)/(2*v*v*cos(ang)*cos(ang)));
   	printf("y1:%f\n",y1);
   	printf("y2:%f\n",y2);
   	printf("ac-a=%f",ac-a);
   	system("pause");
   	animacao1( p1, a, ac, p2, ang, v , play2[i].altura);
   	system("pause");
    if(y1>=(ac-a)&&y2<=(ac-a)){
        play2[i].pontos=1;
        printf("\n\nACERTOU!!!!!\n\n");
        system("pause");;
  	}else{
  		play2[i].pontos=0;
  		printf("\n\nFALHOU!!!\n\n");
  		system("pause");
  	}	 
}

//ESTE CICLO TEM COMO OBJETIVO COLOCAR O MAIOR VALOR OBTIDO NOS PONTOS E COLOCAR NA VARIAVEL ACUM1 SENDO QUE ANTES DE ENTRAR NO CICLO ELA VALIA 0
 for(j=0;j<numerosobrar;j++){
 	if(play2[j].pontos>=acum1){
 		acum1=play2[j].pontos;
	}
 }
 
 acum3=0;
 
 //FUNCAO QUE TEM COMO OBJETIVO COLOCAR OS JOGADORES QUE MARCARAM NAS PRIMEIRAS POSICOES SENDO PREENCHIDO O ACUM3 COM O VALOR DE QUANTOS JOAGDORES TIVERAM ESSA PONTUACAO DE FORMA A DEPOIS PODER SO TRABALHAR COM ESSES JOGADORES
 for(k=0;k<numerosobrar;k++){
 	cabecalho2();
   	if(play2[k].pontos==acum1){
   		acum3=acum3+1;
   		play2[acum3-1].altura=play2[k].altura;
   		strcpy(play2[acum3-1].nome,play2[k].nome);
   		printf("Jogador/a %s passou\n",play2[acum3-1].nome);
   		system("pause");
   	}	
 } 
 
return acum3;
}


//FUNCAO RESPONSAVEL POR GRAVAR A MINHA STRUCT FINAL NUM FICHEIRO TEXTO EM FORMATO TABELA E RECEBE COMO PARAMETROS O NOME DO FICHEIRO,A STRUCT FINAL E O NUMERO DE JOGADORES QUE PARTICIPAMRAM
void gravarjogoemtexto(Final *final,int numerojogadores,char filename[]){
	FILE *ficheiro;
	ficheiro=fopen(filename,"w");
	int i;

	
	if (ficheiro==NULL){
		printf("Erro de carregamento!\n");
		return ;
	}else{
		fprintf(ficheiro,"______________________________________________________________________________________________________________\n");
		fprintf(ficheiro,"|                |___________________PONTOS___________________________________________Falhas_________________|\n");
		fprintf(ficheiro,"|     JOGADOR    |                                            |                                              |\n");
		fprintf(ficheiro,"|                |                   rodada                   |                     rodada                   |\n");
		fprintf(ficheiro,"|                |____________________________________________|______________________________________________|\n");
		fprintf(ficheiro,"|________________|_______1_______|______2______|_______3______|_______1_______|________2_______|______3______|\n");
		for(i=0;i<numerojogadores;i++){
	
		fprintf(ficheiro,"    %s               %d              %d              %d            %d               %d             %d         \n",final[i].nome,final[i].pontos[0],final[i].pontos[1],final[i].pontos[2],final[i].numerofalhas[0],final[i].numerofalhas[1],final[i].numerofalhas[2]);
		}
	}
fclose(ficheiro);	
}

//FUNCAO RESPONSAVEL POR GRAVAR NUM FICHEIRO BINARIO A STRUCT FINAL RECENTO COMO PRAAMTRO A MESMA ,O NUMERO DE JOGADOREES E O NOME DO FICHEIRO
void gravarjogoembinario(Final *final,int numerojogadores,char filename[]){
	FILE *ficheiro;
	ficheiro=fopen(filename,"wb");
	int i;

	
	if (ficheiro==NULL){
		printf("Erro de carregamento!\n");
		return ;
	}else{
		for(i=0;i<numerojogadores;i++){
			fwrite(&final[i],sizeof(Final),1,ficheiro);
		}
	}
	
	
fclose(ficheiro);	
}

//FUNCAO RESPONSAVEL POR LER O FICHEIRO BINARIO CRIADO PELA FUNCAO ANTERIOR E SERA UTILIZADA PRA IMPRIMIR A TEBELA NO EXECUTAVEL
void lerjogoembinario(char filename[],int n,Final*f){
	
	FILE*file;
	int size=sizeof(Final),i,count=0;
	file=fopen(filename,"rb");
	f = (Final *)malloc(n*size);
	if(file==NULL){
		printf("Erro de carregamento!\n");
		return ;	
	}else{
	
		while(count<n && fread(&f[count],size,1,file)){
		printf("______________________________________________________________________________________________________________\n");
		printf("|                |___________________PONTOS___________________________________________Falhas_________________|\n");
		printf("|     JOGADOR    |                                            |                                              |\n");
		printf("|                |                   rodada                   |                     rodada                   |\n");
		printf("|                |____________________________________________|______________________________________________|\n");
		printf("|________________|_______1_______|______2______|_______3______|_______1_______|________2_______|______3______|\n");
	
		printf("    %s               %d              %d              %d            %d               %d             %d         \n",f[count].nome,f[count].pontos[0],f[count].pontos[1],f[count].pontos[2],f[count].numerofalhas[0],f[count].numerofalhas[1],f[count].numerofalhas[2]);
		
		
		
		count++;
		}
	}
fclose(file);	
}

//FUNCAO MAIN ONDE ESTAO PRESENTES AS FUNCOES ANTERIORES E AQUI FOI ELABORADO O MENU E FORMAS RECURSIVAS DE CRIAR O JOGO COM SUCESSO 
int main() {
    
	//VARIAVEIS UTILIZADAS DURANTE A EXECUCAO 
	time_t t;
    srand((unsigned) time(&t));
	float p1;
    float a1;
    float ac;
    float p2;
    float ang;
    float v;	
    float y1;
    float y2;
    float t1;
    float c1;
    float raiz;
	int areajogada;
	float posicaojogada;
	float alturainicial;
	float dist[3];
	int acum;
	int acum1;
	int acum2;
	int acum3;
	int numlanc;
	int numerojogadores;
	float diametrobola=0.238;
	float diametrocesto=0.45;
	float alturacesto=3.05;
	int i;
	int nf;
	int np;
	int j;
	int l;
	int r;
	int n;
	int k;
	int e;
	int p;
	int v1;
	int v2;
	int g;
	float ai;
	float a=0;
	float b=14;
	float mx;
	float mn;
	char c;
	char cd;
	area pos[3];
	area areainicial;
	char nome1[20];
	char filename[20];
	char filename2[20];
	jogador play[100];
	jogador2 play2[100];//serve para filtrar jogadores na morte subita 
	Final * final=NULL;
	Final * f=NULL;
	int u;
	
//CICLO VICIADO RESPONSAVEL POR MOSTRAR O MENU E SELECIONAR OPCAO PARA ENTRAR NUM MODO DE JOGO E MAL ACABE RETORNAR AO CICLO E ESTE ACABA ASSIM QUE SE SELECIONA A OPCAO SAIR
	while(n!=4){
		printmenu();
		scanf("%d",&n);
		switch(n){
			//MODO MULTIJOGADOR
			case 1:
				 final=NULL;
				cabecalho1();
              //INICIALMEMTE SAO GERADAS AS AREAS DO JOGO COM ESTA FUNCAO
		        geraArea(pos,a,b);
		     
               //IMPRIMIR AS AREAS NO EXECUTAVEL
	           for(i=0;i<3;i++){
		       printarea(pos[i]);
	           }
			//MOSTRA A ALTURA DO CESTO NO EXECUTAVEL
              printf("Altura do cesto:%f\n",alturacesto);
			   //printf("introduz a altura do cesto:");
               //scanf("%f",&alturacesto);
               //CICLO COM O OBJETIVO DE SABER QUANTOS JOGADORES VAO PARTICIPAR SENDO QUE TEM DE ESTAR ENTRE 2 E 10 SENAO VOLTA O CICLO AO INICIO 
			   	while(1){
			    	printf("Numero de jogadores que vao participar (entre 2 e 10):");
               		scanf("%d",&numerojogadores);
               	
               		if((numerojogadores>=2)&&(numerojogadores<=10)){
               			break;
					}
					
				   	char string[100];
					if(!(numerojogadores = atoi(string))){
 						fgets(string, 100, stdin);
 						//printf("Por favor insira um numero entre 2 e 10!\n");
 					}
					if ((numerojogadores<=2)||(numerojogadores>10)){
						printf("Por favor insira um numero entre 2 e 10!\n");
					}
				printf("\n");	
				}

			 
			//FUNCAO QUE TEM COMO OBJETIVO DEFENIR O NUMERO DE LANCAMENTOS DE CADA RODADA SENDO QUE TEM DE ESTRA COMPREENDIDOS ENTRE 1 E 5	 
	           	while(1){
			      	printf("Numero de lancamentos por rodada (entre 1 e 5):");
               		scanf("%d",&numlanc);
               	
               		if(numlanc>0 && numlanc<=5){
               			break;
				   	}
					
				   	char string[100];
					if(!(numlanc = atoi(string))){
 						fgets(string, 100, stdin);
 					}
					if ((numlanc<=0)||(numlanc>5)){
						printf("Por favor insira um numero entre 1 e 5!\n");
					}
				printf("\n");	
				} 
			   
               
			   //IMPRIMIR AS DISTANCIAS EM QUE CADA RONDA COMECA SENDO QUE AUMENTA A DIFICULDADE NO AVANCAR DE RONDA POIS A RONDA UM COMECA NA AREA 1 , A 2 NA AREA 2 E A 3 NA AREA 3  
                 
              dist[0]=criarposicao(pos[0]);
              dist[1]=criarposicao(pos[1]);
              dist[2]=criarposicao(pos[2]);
              printf("Distancia ao cesto no inicio da ronda 1 para todos os jogadores:%f\n",dist[0]);
              printf("Distancia ao cesto no inicio da ronda 2 para todos os jogadores:%f\n",dist[1]);
              printf("Distancia ao cesto no inicio da ronda 3 para todos os jogadores:%f\n",dist[2]);
               
               
              //ALOCAR MEMORIA NO APONTADOR FINAL 
               final =(Final*) malloc(sizeof(Final)*numerojogadores);
              
               system("pause");
               
			   
			   
			  //ESTE CICLO INICIAL REPRESENTA O MUDAR DE JOGADOR SENDO QUE DENTRO DESTE CICLO ESTA O CICLO DAS RONDAS E DENTRO DO CICLO DAS RONDAS ESTA O CICLO DOS LANCANMENTOS 
			   for(i=0;i<numerojogadores;i++)  {
               	system("cls");
               //PREENCHIMEMTO DAS CARACTERISTICAS DO JOGADOR USANDO ESTA FUNCAO
               	caracteristicasjogador(play, i);
               
			   //ATRIBUICAO A VARIAVEL FINAL O NOME E ALTURA PRESENTE NA VARIAVEL PLAY DE FORMA A PREENCHER A FINAL QUE FUTURAMENTE SERA USADA 
			    strcpy(final[i].nome,play[i].nome);
                final[i].altura=play[i].altura;
               
               //CICLO DAS RONDAS (3 RONDAS AO TODO) 
               for(r=0;r<3;r++){
               
               // AO MUDAR DE RONDA SAO INICIADOS O NP(NUMERO DE PONTOS POR RONDA) A ZERO E O NF(NUMERO DE FALHAS POR RONDA) A ZERO E SAO ATRIBUIDAS A AREAINICIAL O VALOR DA AREA ONDE COMECA A RONDA QUE ESTRA PRESNETE NA VARIAVEL POS 
               	np=0;
               	nf=0;
                areainicial=pos[r];
               
			   // ATRIBUICAO A VARIAVEL AI O VALOR DA DISTANCIA MAIS EM CIMA SENDO ESSA MUDADA AO MUDAR DE RONDA E DURANTE OS LANCAMENTOS 
			    ai=dist[r];
			
               	//INICIA SE CADA RONDA COM O ACUMULADOR A ZERO
               	acum=0;
              
			  //CICLO QUE PREENCHE OS LANCAMENTOS DE CADA RONDA
			   for(l=0;l<numlanc;l++){
               system("cls");
			   
			   printf("Posicao neste lancamento:%f\n",ai);
			   printf("Area:%d\n",areainicial.numeroarea);	
			   printf("Jogador:%s ;Lancamento %d de %d ;Rodada %d:\n",play[i].nome,l+1,numlanc,r+1);
               
			   //FUNCOES RESPONSAVEIS POR PREENCHER A VELOCIADADE DE LANCAMENTO ,O ANGULO E A VELOCIADE DE SALTO SENDO QUE SAO ATRIBUIDAS COMO PARAMETROS AS POSICOES EM CADA CICLO E A VARIAVEL PLAY DE FORMA A PREEENCHER A STRUCT
			   criarangulo(play,i,r,l);
               criarvelocidadeS(play,i,r,l);
               criarvelocidadeL(play,i,r,l);
			   
			   //VARIAVEL ALTURAINICIAL QUE RESULTA DA REALIZACAO DA FUNCAO ALTURASALTO SOMADA COM A ALTURA DO RESPETIVO JOGADOR
			   alturainicial=alturasalto(play,i,r,l)+play[i].altura;
			  
			  
			  
		       //VARIAVEIS QUE CORRENSPONDEM AOS LIMITES ONDE O CENTRO DE MASSA DA BOLA PODE ENTRAR DE FORMA A SER PONTO, UMA VEZ QUE O DIAMETRO DO ARO VALE 0.45 E O RAIO DA BOLA VALE 0.119 ENTAO O UNICO INTERVALO ONDE A BOLA PODE ENTRAR E ENTRE P1 E P2
			   p1=ai-0.331;
			   p2=ai-0.119;
               
			   //ALTURA INICIAL DE LANCAMENTO
			   a=alturainicial;
               //ALTURA DO CESTO
               ac=alturacesto;
              
              //ANGULO DE LANCAMENTO CONVERTIDO A RADIANOS
               ang=3.1415926*play[i].rodada[r].lanc[l].angulo/180; //3.1415926;
               
               //VELOCIADADE DE LANCAMENTO
               v=play[i].rodada[r].lanc[l].velocidadelancamento;
              
              //ALTURA RELATIVAMENTE AO  PONTO DE LANCAMENTO SENDO QUE Y1 E ATE AO P1 E Y2 E ATE AO P2 RELATIVAMENTE A DISTANCIA HORIZONTAL
               y1=(p1*tan(ang))-((9.8*p1*p1)/(2*v*v*cos(ang)*cos(ang)));
               y2=(p2*tan(ang))-((9.8*p2*p2)/(2*v*v*cos(ang)*cos(ang)));
              
			   system("cls");
               
               //COLOCACAO DE UMA ANIMACAO EM TEMPO REAL
			   animacao1( p1 , a, ac , p2 , ang , v ,play[i].altura );
               system("pause");
             
             
               printf("y1:%f\n",y1);
               printf("y2:%f\n",y2);
               printf("ac-a:%f\n",ac-a);
			   
			   //ESTE CICLO TEM COMO OBJETVO A VERIFICACAO SE A BOLA ENTROU OU NAO 
			   if(y1>=(ac-a)&&y2<=(ac-a)){
               np=np+areainicial.numeroarea;//NUMERO DE PONTOS
               acum=0;
               printf("\n\nACERTOU!!!!!\n\n");
               
			   system("pause");
			   //so sobe de area se o numero de area for menor que 3 ( este numeroarea sera usado para subir de area ou descer colocando esse numero no array de areas de forma a ir buscar a area desejada)
			   if(areainicial.numeroarea<3){
           	   areainicial.numeroarea=areainicial.numeroarea+1;
           	   areainicial=pos[areainicial.numeroarea-1];
           	   ai=criarposicao(areainicial);
               }else{
               	areainicial=pos[areainicial.numeroarea-1];
           	    ai=criarposicao(areainicial);
			   }


              }else{
              	printf("\n\nFALHOU!!!\n\n");
	          nf=nf+1; // nf = Nº de Falhanços
	          if(acum<1&&areainicial.numeroarea>=1){
		      //INCREMENTACAO DO ACUM CASO ESTE SEJA MENOR QUE 1 POIS SO DESCE DE AREA SE FALHAR 2 VEZES
			  acum=acum+1;
		      //DAQUI PARA A FRENTE E VERIFICADO SE SE ENCONTTRA NA AREA 1 OU NAO CASO FALHE E SE O ACUM E 1 OU NAO DE FORMA A SABER SE ACUMULA OU DESCE DE AREA
	         }else if(acum==1&&areainicial.numeroarea>1){
		     acum=0;
		     areainicial.numeroarea=areainicial.numeroarea-1;
		     areainicial=pos[areainicial.numeroarea-1];
           	 ai=criarposicao(areainicial);
	         }else if(acum==1&&areainicial.numeroarea==1){
		     acum=0;
		     areainicial.numeroarea=areainicial.numeroarea;
		     areainicial=pos[areainicial.numeroarea-1];
           	 ai=criarposicao(areainicial);
	         }
	         system("pause");
             }
			 //IMPRIMIR SE FALHOU OU MARCOU E QUANTOS PONTOS TEM PARA ALEM DO ACUM E DA RESPETIVA AREA(DESTA FORMA VERIFICO SE O ACUM SE COMPORTA COMO DEVE SER E SE A AREA TAMBEM) 		
		       printf("Numero de pontos:%d\n\n",np);
		       printf("Numero de falhas:%d\n\n",nf);
		       printf("acum:%d\n\n",acum);
		       printf("Area:%d\n\n",areainicial.numeroarea);
		       
		
			
			}
			//NUMERO DE PONTOS E FALHAS DE CADA RONDA(ESTES FORAM PASSADOS PARA A STRUCT FINAL PARA DEPOIS SER ESTA A SER GRAVADA NO FICHEIRO)
		     final[i].pontos[r]=np;
		     final[i].numerofalhas[r]=nf;
		   
		    
			system("pause");
               	}
               
               	//SOMATORIO DO NUMERO DE FALHAS E PONTOS NO FINAL DAS 3 RONDAS DE FORMA A SABER QUANTOS PONTOS OBTEVE CADA JOGADOR E QUANTAS FALHAS (ESTAS FORAM ARMAZENADAS NA STRCT JOGADOR)
               	play[i].pontos=0;
               	for(p=0;p<3;p++){
               		play[i].pontos=	play[i].pontos+final[i].pontos[p];
               		play[i].falhas=	play[i].falhas+final[i].numerofalhas[p];
               	
               	
				   }
				   //IMPRIMIR O NUMERO DE PONTOS E FLAHAS DE CADA JOGADO AO TODO
				   	printf("Numero total de pontos do jogador %s e:%d\n",play[i].nome,play[i].pontos);
               		printf("Numero total de falhas do jogador %s e:%d\n",play[i].nome,play[i].falhas);
				   	system("pause");
			   	}
			   
			   	//ESTE CICLO TEM COMO OBJETIVO SABER SE VAI SER PARA GUARDAR A TABELA DE PONTOS E FALHAS DE CADA RONDA E ASSIM POR JOGADOR NUM FICHEIRO,CASO SEJA DEVE SE GRAVAR NUM FICHEIRO BINARIO E NUM EM TEXTO DEVENDO POR ISSO TER NOMES DIFERENTES AMBOS OS FICHEIROS
			   	g=1;
			   	while(g==1){
			   
			   	printf("Deseja gravar a tabela das rondas?(sim->1 e nao->2)\n");
			   	scanf("%d",&u);
			   	if(u==1){
			   		printf("NOTA:escolha nomes diferentes tanto para modo binario como para texto\n");
			   		printf("Introduza o nome do ficheiro onde deseja guardar (binario):");
			   		scanf("%s",filename);
			   		strcat(filename,".txt");
			   		printf("Introduza o nome do ficheiro onde deseja guardar (texto):");
			   		scanf("%s",filename2);
			   		strcat(filename2,".txt");
			   		//GRAVA JOGO EM BINARIO
			   		gravarjogoembinario(final,numerojogadores,filename);
			   		//GRAVAR JOGO EM TEXTO
			   		gravarjogoemtexto(final, numerojogadores, filename2);
			   		g=0;
				}else if(u==2){
					g=0;
				}else if(u!=1&&u!=2){
					char string[100];
					if(!(u = atoi(string))){
 						fgets(string, 100, stdin);
 						g=1;
						 printf("Por favor selecione os numeros 1 ou 2!\n");
 				}else if(u<1||u>2){
 					
 					printf("Por favor selecione uma opcao valida!\n");
 					g=1;
				 }
					g=1;
		   		}
				}
	           //APARTIR DAQUI VAI SER REALIZADA A VERIFICACO DO VENCEDOR D JOGO
			   acum1=0;
			   acum2=0;
			   acum3=0;
			   //ESTE CICLO TEM COMO OBJETIVO DETERMINAR O MAIOR VALOR DE PONTUACAO DE TODOS OS PARTICIPANTES
			   for(v1=0;v1<numerojogadores;v1++){
			   	if(play[v1].pontos>=acum1){
			   		acum1=play[v1].pontos;//determinar o maior valor de pontos entre todos
			   		
				   }
			   
	          	} 
	          	//ESTE CICLO VERIFICA QUANTOS JOGADORES TEM A MAIOR PONTUACAO E ACUMULA NO ACUM2 SENDO DEPOIS ESSES JOGADORES COLOCADOS NAS PRIMEIRAS POSICOES ATE O ACUM 2 ACABAR
	          	for(v2=0;v2<numerojogadores;v2++){
	          	if(play[v2].pontos==acum1){
	          		acum2=acum2+1;//verifica quantos jogadores empatados existe e serve tmb para colocar nas posicoes do play2
	          	// COLOCACAO DOS JOGADORES COM MAIOR PONTUACAO PARA AS PRIMEIRAS POSICOES E ATRIBUICAO ADEQUADA DO NOME E DA ALTURA
	          		strcpy(play2[acum2-1].nome,play[v2].nome);
	          		play2[acum2-1].altura=play[v2].altura;
	          		
				  }	
	          		
				  }
				 //CASO SO EXISTA UM JOGADOR COM A MAIOR PONTUACAO ENTAO ESSE E O VENCEDOR
				  if(acum2==1){
				  	printf("VENCEDOR:%s\n",play2[acum2-1].nome);
				  	//CASO CONTRARIO ENTRA NA MORTE SUBITA
				  }else{
				  	//CICLO QUE VAI FILTRANDO OS JOGADORES NO DECORRER DA MORTE SUBITA ATE SO SOBRAR UM JOGADOR
				   while(acum3!=1){
				  	acum3=mortesubita(play2,acum2);
				  	acum2=acum3;
				  	
				       }
				    //O JOGADOR QUE SOBRAR E O VENCEDOR   
				  printf("VENCEDOR:%s\n\n",play2[acum3-1].nome);
				  	 }
			  
			   
			   
			   free(final);
			   
			
			   system("pause");
			   break;
			
			
			case 2:
			
			//MODO SOLO
			
			// A ELABORACAO DESTE MODO SOLO E IGUAL AO MODO MULTIJOGADOR SO QUE NAO EXISTE MORTE SUBITA NEM VENCEDOR POIS E APENAS UM JOGADOR A JOGAR E ALEM DO MAIS NAO E PERMITIDO JOGAR NEM MAIS NEM MENOS QUE UM SO JOGADOR
			
				final=NULL;
			    cabecalho3();

		        geraArea(pos,a,b);
		     
               
	           for(i=0;i<3;i++){
		       printarea(pos[i]);
	           }
			
              printf("Altura do cesto:%f\n",alturacesto);
			   
               
			   	numerojogadores=1;
			 
				while(1){
			      	printf("Numero de lancamentos por rodada (entre 1 e 5):");
               		scanf("%d",&numlanc);
               	
               		if(numlanc>0 && numlanc<=5){
               			break;
				   	}
					
				   	char string[100];
					if(!(numlanc = atoi(string))){
 						fgets(string, 100, stdin);
 						printf("Por favor insira um numero entre 1 e 5!\n");
 					}
					if ((numlanc<=0)||(numlanc>5)){
						printf("Por favor insira um numero entre 1 e 5!\n");
					}
				printf("\n");	
				}


              dist[0]=criarposicao(pos[0]);
              dist[1]=criarposicao(pos[1]);
              dist[2]=criarposicao(pos[2]);
              printf("Distancia ao cesto no inicio da ronda 1 :%f\n",dist[0]);
              printf("Distancia ao cesto no inicio da ronda 2 :%f\n",dist[1]);
              printf("Distancia ao cesto no inicio da ronda 3 :%f\n",dist[2]);
               
			   
               final =(Final*) malloc(sizeof(Final)*numerojogadores);
               
               system("pause");
             
			   
			   
			   
			   
			   for(i=0;i<numerojogadores;i++)  {
               	system("cls");
            
               	caracteristicasjogador(play, i);
                strcpy(final[i].nome,play[i].nome);
                final[i].altura=play[i].altura;
               
               for(r=0;r<3;r++){
              
               	np=0;
               	nf=0;
                areainicial=pos[r];
                ai=dist[r];
			
               	
               	acum=0;
               for(l=0;l<numlanc;l++){
               system("cls");
			
			   printf("Posicao neste lancamento:%f\n",ai);
			   printf("Area:%d\n",areainicial.numeroarea);	
			   printf("Jogador:%s ;Lancamento %d de %d ;Rodada %d:\n",play[i].nome,l+1,numlanc,r+1);
               criarangulo(play,i,r,l);
               criarvelocidadeS(play,i,r,l);
               criarvelocidadeL(play,i,r,l);
			   alturainicial=alturasalto(play,i,r,l)+play[i].altura;
			  
			  
			  
		
			   p1=ai-0.331;
			  
               a=alturainicial;
              
               ac=alturacesto;
               
               p2=ai-0.119;
              
               ang=3.1415926*play[i].rodada[r].lanc[l].angulo/180; //3.1415926;
              
               v=play[i].rodada[r].lanc[l].velocidadelancamento;
               
               y1=(p1*tan(ang))-((9.8*p1*p1)/(2*v*v*cos(ang)*cos(ang)));
               y2=(p2*tan(ang))-((9.8*p2*p2)/(2*v*v*cos(ang)*cos(ang)));
               
			   system("cls");
               animacao1( p1 , a, ac , p2 , ang , v ,play[i].altura );
               system("pause");
              
              
               printf("y1:%f\n",y1);
               printf("y2:%f\n",y2);
               printf("ac-a:%f\n",ac-a);
			   if(y1>=(ac-a)&&y2<=(ac-a)){
               np=np+areainicial.numeroarea;
               acum=0;
               printf("\n\nACERTOU!!!!!\n\n");
               
			   system("pause");
			   if(areainicial.numeroarea<3){
           	   areainicial.numeroarea=areainicial.numeroarea+1;
           	   areainicial=pos[areainicial.numeroarea-1];
           	   ai=criarposicao(areainicial);
               }else{
               	areainicial=pos[areainicial.numeroarea-1];
           	    ai=criarposicao(areainicial);
			   }


              }else{
              	printf("\n\nFALHOU!!!\n\n");
	          nf=nf+1; // nf = Nº de Falhanços
	          if(acum<1&&areainicial.numeroarea>=1){
		      acum=acum+1;
		      
	         }else if(acum==1&&areainicial.numeroarea>1){
		     acum=0;
		     areainicial.numeroarea=areainicial.numeroarea-1;
		     areainicial=pos[areainicial.numeroarea-1];
           	 ai=criarposicao(areainicial);
	         }else if(acum==1&&areainicial.numeroarea==1){
		     acum=0;
		     areainicial.numeroarea=areainicial.numeroarea;
		     areainicial=pos[areainicial.numeroarea-1];
           	 ai=criarposicao(areainicial);
	         }
	         system("pause");
             }		
		       printf("Numero de pontos:%d\n\n",np);
		       printf("Numero de falhas:%d\n\n",nf);
		       printf("acum:%d\n\n",acum);
		       printf("area:%d\n\n",areainicial.numeroarea);
		       
			
		
			
			}
		     final[i].pontos[r]=np;
		     final[i].numerofalhas[r]=nf;
		     
		    
			system("pause");
               }
               play[i].pontos=0;
               	for(p=0;p<3;p++){
               		play[i].pontos=	play[i].pontos+final[i].pontos[p];
               		play[i].falhas=	play[i].falhas+final[i].numerofalhas[p];
               	
               	
				   }
				   	printf("Numero total de pontos do jogador %s e:%d\n",play[i].nome,play[i].pontos);
               		printf("Numero total de falhas do jogador %s e:%d\n",play[i].nome,play[i].falhas);
				   	system("pause");
			   }
			   g=1;
			   while(g==1){
			   
			   printf("Deseja gravar a tabela das rondas?(Sim - 1; Nao - 2)\n");
			   scanf("%d",&u);
			   if(u==1){
			   printf("NOTA:escolha nomes diferentes tanto para modo binario como para texto\n");
			   printf("Introduza o nome do ficheiro onde deseja guardar (binario):");
			   scanf("%s",filename);
			   strcat(filename,".txt");
			   printf("Introduza o nome do ficheiro onde deseja guardar (texto):");
			   scanf("%s",filename2);
			   strcat(filename2,".txt");
			   gravarjogoembinario(final,numerojogadores,filename);
			   gravarjogoemtexto(final, numerojogadores, filename2);
			   g=0;
		}else if(u==2){
			g=0;
		}else if(u!=1&&u!=2){
			char string[100];
			if(!(u = atoi(string))){
 				fgets(string, 100, stdin);
 				printf("Por favor selecione os numeros 1 ou 2!\n");
 			}
				if ((u<1)||(u>2)){
					printf("Por favor selecione uma opcao valida!\n");
					//scanf("%d",&u);
				}
			g=1;
		   }
               	}
		
		
			   free(final);
			
				system("pause");
				break;
			case 3:
				
				//ESTE MODO SERVE PARA IMPRIMIR NA CONSOLA A TABELA DE PONTOS DAS 3 RODADAS SENDO SO VERIFICADA PARA FICHEIROS BINARIOS E EVITANDO ASSIM TER DE SAIR DO JOGO PARA VER A TABELA
				cabecalho4();
				printf("Qual e o nome do jogo/arquivo que deseja carregar(binario)?:");
				scanf("%s",filename);
				strcat(filename,".txt");
				lerjogoembinario(filename,10,f);
				
				
				free(f);
				system("pause");
			    break;	
		
	        case 4:
	        	// MODO SAIR
	        	return 0;
	           break;
		
			
			default :
				
				char string[100];
				if(!(n = atoi(string))){
 					fgets(string, 100, stdin);
 					printf("Por favor selecione um numero entre 1 e 4!\n");
 				}
			
				if ((n<0)||(n>=4)){
					printf("Por favor selecione uma opcao valida!\n");
					scanf("%d",&n);
				}
          		system("pause");
				break;
         }
	 }
		
		
		
	

	

return 0;	
} 

