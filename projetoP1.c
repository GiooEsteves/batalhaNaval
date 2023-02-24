#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// variáveis
char *campoC[10][10];
char *campoCOculto[10][10];
char *campoJ[10][10];
char *letras[10] = {"A","B","C","D","E","F","G","H","I","J"};
char *numeros[10]= {"1","2","3","4","5","6","7","8","9","10"};
int qtdNavios;
int modelo;
int linha;
int coluna;
char charLinha;
int acumulador = 0;
int erros = 0;
int linhaC;
int colunaC;
 
// menu de escolha de modelo de mavios  
void modelos(){
  printf("================================================================\n");
  printf("=        1)                  2)                  3)            =\n");
  printf("=                                                              =\n");
  printf("=           #                   #                   #          =\n");
  printf("=           #                  ###                #####        =\n");
  printf("=           #                   #                              =\n");
  printf("=           #                   #                              =\n");
  printf("================================================================\n");
}

// cria campo do jogador
void criaCampoJogador(){ 
  for(int i=0; i<10;i++){
    for(int j=0;j<10;j++){
      campoJ[i][j] = " ";
    }
  } 
}

// cria campo do computador
void criaCampoComputador(){ 
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      campoC[i][j] = "~";
    }
  } 
}

// cria campo oculto do computador
void criaCampoComputadorOculto(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			campoCOculto[i][j] = " ";
		}
	}
}

// imprimindo o campo do jogador
void imprimeSeuCampo(){
	printf("======== SEU MAPA ========\n");
	printf("  ");
	for(int i=0;i<10;i++){
		printf("%s ", numeros[i]);
	}
	printf("\n");
	for(int i=0;i<10;i++){
		printf("%s ", letras[i]);
	    for(int j=0;j<10;j++){
	      printf("%s ", campoJ[i][j]);
	    }
	    printf("\n");
	}	
} 
  
// imprimindo o campo do computador
void imprimeCampoOponente(){
	printf("======= MAPA OPONENTE =======\n");
	printf("  ");
	for(int i=0;i<10;i++){
		printf("%s ", numeros[i]);
	}
	printf("\n");
	for(int i=0;i<10;i++){
		printf("%s ", letras[i]);
	    for(int j=0;j<10;j++){
	      printf("%s ", campoC[i][j]);
	    }
	    printf("\n");
	}	
} 

void imprimeCampoOculto(){
	printf("======= MAPA OPONENTE =======\n");
	printf("  ");
	for(int i=0;i<10;i++){
		printf("%s ", numeros[i]);
	}
	printf("\n");
	for(int i=0;i<10;i++){
		printf("%s ", letras[i]);
	    for(int j=0;j<10;j++){
	      printf("%s ", campoCOculto[i][j]);
	    }
	    printf("\n");
	}	
}

// transforma o char da linha do campo em inteiro
int transformaLinhaEmInteiro(charLinha){
  charLinha = toupper(charLinha);
  linha = charLinha - 65;
  return linha;
}

// aloca os navios no campo de batalha do jogador
void menuAlocaNaviosJog(){
  printf("Escolha um modelo de navio:\n");
  modelos();
  scanf("%d", &modelo);
  
  switch(modelo){
    case 1:
      printf("\n");
      imprimeSeuCampo();
      printf("\nDigite a posicao do bico do navio, sua extremidade mais alta, no formato (Linha Coluna)... ");
      scanf(" %c%d", &charLinha, &coluna);
      linha = transformaLinhaEmInteiro(charLinha); 
      
      if(campoJ[linha][coluna] == " " && campoJ[linha + 1][coluna] == " " && campoJ[linha + 2][coluna] == " " && campoJ[linha + 3][coluna] == " "){
        campoJ[linha][coluna] = "#";
        campoJ[linha + 1][coluna] = "#";
        campoJ[linha + 2][coluna] = "#";
        campoJ[linha + 3][coluna] = "#";
      }else{
        printf("Posição já ocupada\n");
        menuAlocaNaviosJog();
      }
      break;
    case 2:
      printf("\n");
      imprimeSeuCampo();
      printf("\nDigite a posicao do bico do navio (sua extremidade mais alta) no formato Linha Coluna... ");
      scanf(" %c%d", &charLinha, &coluna);
      linha = transformaLinhaEmInteiro(charLinha);
      
      if(campoJ[linha][coluna] == " " && campoJ[linha+1][coluna] == " " && campoJ[linha+1][coluna-1] == " " && campoJ[linha+1][coluna+1] == " " && campoJ[linha + 2][coluna] == " " && campoJ[linha + 3][coluna] == " "){
    		campoJ[linha][coluna] = "#";
    		campoJ[linha+1][coluna] = "#";
    		campoJ[linha+1][coluna-1] = "#";
    		campoJ[linha+1][coluna+1] = "#";
    		campoJ[linha+2][coluna] = "#";
    		campoJ[linha+3][coluna] = "#";
	    }else{
    		printf("Posição já ocupada\n");
        menuAlocaNaviosJog();
	    }
      break;
    case 3:
      printf("\n");
      imprimeSeuCampo();
      printf("\nDigite a posicao do bico do navio (sua extremidade mais alta) no formato Linha Coluna... ");
      scanf(" %c%d", &charLinha, &coluna);
      linha = transformaLinhaEmInteiro(charLinha);
      
      if(campoJ[linha][coluna] == " " && campoJ[linha+1][coluna] == " " && campoJ[linha+1][coluna-2]== " " && campoJ[linha+1][coluna-1] == " " && campoJ[linha+1][coluna+1] == " " && campoJ[linha+1][coluna+2]){
    		campoJ[linha][coluna] = "#";
    		campoJ[linha+1][coluna-2] = "#";
    		campoJ[linha+1][coluna-1] = "#";
    		campoJ[linha+1][coluna] = "#";
    		campoJ[linha+1][coluna+1] = "#";
    		campoJ[linha+1][coluna+2] = "#";		
	   }else{
		    printf("Posição já ocupada\n");
        menuAlocaNaviosJog();
	   }
      break;
    default:
      printf("Modelo invalido");
      menuAlocaNaviosJog();
      break;
    }
}    

// aloca os navios no campo de batalha do computador
void menuAlocaNaviosComp(){
  modelo = rand() % 2 +1;
  switch(modelo){
    case 1:
      linha = rand() % 9;
      coluna = rand() % 9;
      if(campoCOculto[linha][coluna] == " " && campoCOculto[linha + 1][coluna] == " " && campoCOculto[linha + 2][coluna] == " " && campoCOculto[linha + 3][coluna] == " "){
        campoCOculto[linha][coluna] = "#";
        campoCOculto[linha + 1][coluna] = "#";
        campoCOculto[linha + 2][coluna] = "#";
        campoCOculto[linha + 3][coluna] = "#";
      }else{
        menuAlocaNaviosComp();
      }
      break;
    case 2:
      linha = rand() % 9;
      coluna = rand() % 9;
      if(campoCOculto[linha][coluna] == " " && campoCOculto[linha+1][coluna] == " " && campoCOculto[linha+1][coluna-1] == " " && campoCOculto[linha+1][coluna+1] == " " && campoCOculto[linha + 2][coluna] == " " && campoCOculto[linha + 3][coluna] == " "){
    		campoCOculto[linha][coluna] = "#";
    		campoCOculto[linha+1][coluna] = "#";
    		campoCOculto[linha+1][coluna-1] = "#";
    		campoCOculto[linha+1][coluna+1] = "#";
    		campoCOculto[linha+2][coluna] = "#";
    		campoCOculto[linha+3][coluna] = "#";
	    }else{
        menuAlocaNaviosComp();
      }
      break;
    case 3:
      linha = rand() % 9;
      coluna = rand() % 9;
      if(campoCOculto[linha][coluna] == " " && campoCOculto[linha+1][coluna] == " " && campoCOculto[linha+1][coluna-2] == " " && campoCOculto[linha+1][coluna-1] == " " && campoCOculto[linha+1][coluna+1] == " " && campoCOculto[linha+1][coluna+2]){
    		campoCOculto[linha][coluna] = "#";
    		campoCOculto[linha+1][coluna-2] = "#";
    		campoCOculto[linha+1][coluna-1] = "#";
    		campoCOculto[linha+1][coluna] = "#";
    		campoCOculto[linha+1][coluna+1] = "#";
    		campoCOculto[linha+1][coluna+2] = "#";		
    	}else{
        menuAlocaNaviosComp();
      }
      break;
    default:
      printf("Modelo invalido");
      break;
    }
}

void combateJogador(){
  printf("\nEscolha uma posição para atacar no formato (Linha Coluna): ");
  scanf(" %c%d", &charLinha, &coluna);
  linha = transformaLinhaEmInteiro(charLinha);
  
  if(campoCOculto[linha][coluna] == "#"){
    printf("\n");
    printf("UM NAVIO FOI ATINGIDO");
    printf("\n");
    campoC[linha][coluna] = "X";
  }else{
    printf("\n");
    printf("ERROU");
    printf("\n");
    campoC[linha][coluna] = " ";
  }
  imprimeCampoOponente();
}

void verificacaoAtaqueOponente(){
  if(campoJ[linha][coluna] == "#"){
    printf("\n");
    printf("UM DOS SEUS NAVIOS FOI ATINGIDO\n");
    printf("\n");

    campoJ[linha][coluna] = " ";
    acumulador += 1;

    linhaC = linha;
    colunaC = coluna;
    erros = 0;
    printf("\n");
    imprimeSeuCampo();
  }else{
    printf("\n");
    printf("ERROU\n");
    printf("\n");
   
    erros += 1;
    printf("\n");
    imprimeSeuCampo(); 
    if(erros == 2){
      erros = 0;
      acumulador = 0;
    }
  }
}

void combateComputador(){
  if(acumulador == 0){
    linha = rand() % 9;
    coluna = rand() % 9;
    verificacaoAtaqueOponente();
  }else{
    int valor;
    valor = rand() % 3;
    switch (valor){
      case 0:
        if(campoJ[linhaC - 1][colunaC] != "X" && campoJ[linhaC - 1][colunaC] != " "){
          linha = linhaC - 1;
          coluna = colunaC;
          verificacaoAtaqueOponente();
        }
        break;
      case 1:
        if(campoJ[linhaC][colunaC - 1] != "X" && campoJ[linhaC][colunaC - 1] != " "){
          linha = linhaC;
          coluna = colunaC - 1;
          verificacaoAtaqueOponente();
        }
        break;
      case 2:
        if(campoJ[linhaC][colunaC + 1] != "X" && campoJ[linhaC][colunaC + 1] != " "){
          linha = linhaC;
          coluna = colunaC + 1;
          verificacaoAtaqueOponente();
        }
        break;
      case 3:
        if(campoJ[linhaC + 1][colunaC] != "X" && campoJ[linhaC + 1][colunaC] != " "){
          linha = linhaC + 1;
          coluna = colunaC;
          verificacaoAtaqueOponente();
        }
        break;
    }
  }
}

int main() { 
  srand(time(0)); 
// cabeçalho do jogo
  printf("================================================================\n");
  printf("=                        BATALHA NAVAL                         =\n");
  printf("================================================================\n");
  printf("\nBem vindo ao jogo.\n");
  
  printf("\nDigite quantos navios serao usados... ");
  scanf("%d", &qtdNavios); 
  
// chamada para montar os navios do jogador
  criaCampoJogador();
  for(int p=0;p<qtdNavios;p++){
 	  menuAlocaNaviosJog(); 
    printf("\n");
    imprimeSeuCampo();
  }
  
// chamada para montar os navios do computador
	criaCampoComputadorOculto();
	for(int p=0; p<qtdNavios; p++){
		menuAlocaNaviosComp();
	}
	
// inicio do jogo
  printf("\n");
	imprimeSeuCampo();  
  printf("\n");
  imprimeCampoOponente(); 
  printf("\n");
  
// combate
  do{
    combateJogador();
    combateComputador();
  }while(campoJ == "#" || campoCOculto == "#");

  printf("================================================================\n");
  printf("=                         FIM DE JOGO                          =\n");
  printf("================================================================\n");
  
  return 0;
}
