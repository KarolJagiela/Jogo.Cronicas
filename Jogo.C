#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define SO_CORRO 76


	struct Jogador{
		
		char Nome [30];
		int vida;
		int level;
		int ouro;
		int x;
		int y;
		int pocoes;
		int armas;
		int comida;
		int sanidade;
		int eVivo;
		int eFim;
		int reliquia;
	};

	Jogador InventarioInicial( struct Jogador jogador){
		
		jogador.vida = 50;
		jogador.level = 1;
		jogador.ouro = 20;
		jogador.pocoes = 2;
		jogador.armas = 1;
		jogador.comida = 2;
		jogador.sanidade = 20;
		jogador.eVivo = 1;
		jogador.eFim = 1;
		jogador.reliquia = 0;
		jogador.x;
		jogador.y;
		
		
		return jogador;
	}
	
	void MostrarInventario(struct Jogador jogador){
	
		printf("\n-=====================================- Inventario -=================================- \n");
		printf("vida = %d \t level = %d  \t ouro = %d    Pos = (%d,%d) \t \npocoes = %d\t armas = %d\t comida = %d\t sanidade = %d\t\n reliquias: %d \n",jogador.vida,jogador.level,jogador.ouro,jogador.y,jogador.x,jogador.pocoes,jogador.armas,jogador.comida,jogador.sanidade,jogador.reliquia);
		printf("======================================================================================");
	
}
	
void inicializarMapa(char Mapa[5][15], struct Jogador jogador ){
	
	for(int i=0;i<5;i++){
		for(int j=0;j<15;j++){
			Mapa[i][j]= '.';
					
		}
	}

	Mapa[jogador.y][jogador.x] = '!';

}
	
void imprimirMapa(char Mapa [5][15], struct Jogador jogador){


	for(int i=0;i<5;i++) {
		for(int j=0; j<15;j++) {
			printf("%c ", Mapa[i][j]);
	
		}
		printf("\n");
	}
	
	Mapa[jogador.y][jogador.x] = '!';
}

void esperarTab(){
	char tecla;
 	printf("\n\n >> Pressione ENTER para continuar.....<<\n");
 	
 	do{
 		tecla = getchar();
	 }while (tecla != '\n');
	 
	 system("cls");
}

	Jogador combates(struct Jogador jogador){
		
	int combateM;
	int combateJ;
	int combateSJ;
	int combateS;
	
	srand(time(NULL));

	if((jogador.y==2) && (jogador.x==3) ){
		
        combateM = rand() % 20 + 1;  
        printf("dado inimigo: %d\t", combateM);
        
        combateJ = rand() % 20 + 1;  
        printf("seu dado: %d\t", combateJ);
        
 	}	else if(jogador.sanidade==2){
 		
 		srand(time(NULL));
 		
 		combateS = rand() % 20 + 1;  
        printf("dado de Sanidade:  %d\t", combateS);
        
        combateSJ = rand() % 20 + 1;  
        printf("seu dado de Sanidade:  %d\t", combateSJ);
 			
	 }
	 
	 if(combateM<combateJ){
	 	
	 	printf("voce ganhou 2 pontos de sanidade! \n");
	 	
	 	jogador.sanidade=+2;
	 	
	 }
	 
	 else if(combateM>combateJ){
	 	
	 	jogador.eVivo=0;
	 	
	 }
	 
	 if(combateS<combateSJ){
	 	
	 	printf("voce esta com 2 de sanidade agora!");
	 	
	 	jogador.sanidade=+2;
	 }
	 
	 else if(combateS>combateSJ){
	
	 	jogador.eVivo=0;
	 }
	 
 	return jogador;
}

Jogador escurinho(Jogador jogador, char Mapa[5][15]){
	
		int escolha;
		int dadoJ;
		int dadoT;
		
		srand(time(NULL));
		
        
	printf("voce esta na sala escura! tenha cuidado por onde anda! \n");
	
	if(jogador.y == 0 && jogador.x == 0){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade\n");
	}
	
	if(jogador.y == 0 && jogador.x == 1){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade\n");
	}
	
	if (jogador.y == 0 && jogador.x == 2){
		
		jogador.sanidade -= 1;
	
		printf("voce esta perdendo sanidade!\n");
		printf("porem.. voce encontra um bau! \n");
		
		printf("deseja abrir? (digite 1 para abrir ou 2 para continuar)\n");
		scanf("%d", &escolha);
	
		if(escolha ==1){
			
			dadoT = rand() % 20 + 1;  
        	printf("dado teste: %d\t", dadoT);
        
        	dadoJ = rand() % 20 + 1;  
       	 	printf("seu dado: %d\t", dadoJ);
			
			if(dadoJ>dadoT){
			
				printf("voce achou uma pocao de sanidade! \n");
				jogador.sanidade += 4;
		
		}
		
		else if(dadoJ<dadoT){
			
			printf("voce nao passou :( tente novamente! \n");
			
		}
	}
		
		else if(escolha ==2){
			
			printf("continue em frente\n");
			
		}
	}
		
	if (jogador.y == 0 && jogador.x == 3){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade!\n");
		
	}	
	
	if(jogador.y == 0 && jogador.x == 4){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade!\n");
	}
	
	if(jogador.y == 0 && jogador.x == 5){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade!\n");
		
		printf("porem! voce achou um bau! \n");
		printf("deseja abrir? (digite 1 para abrir ou 2 para sair\n");
		scanf("%d",&escolha);
		
		if(escolha ==1){
			
			dadoT = rand() % 20 + 1;  
        printf("dado teste: %d\t", dadoT);
        
        dadoJ = rand() % 20 + 1;  
        printf("seu dado: %d\t", dadoJ);
			
			if(dadoJ>dadoT){
			
			printf("voce achou uma pocao de sanidade! \n");
				jogador.sanidade += 4;
		
		}
		
		else if(dadoJ<dadoT){
			
			printf("voce nao passou :(, tente novamente! \n");
			
		}
	}
		
		else if(escolha ==2){
			
			printf("continue em frente\n");
			
		}
	}
		
	if(jogador.y == 4 && jogador.x == 14){
			
			printf("voce achou uma bau!\n");
			printf("deseja abrir? (digite 1 para abrir ou 2 para sair) \n");
			scanf("%d",& escolha);
			
	
			if(escolha ==1){
			
			printf("voce encontrou a reliquia da espada!\n");
			
			jogador.reliquia += 1;
			
			printf("ache a saida!\n");
	}
		
		else if(escolha ==2){
			
			printf("continue em frente\n");
			
		}
	}
	
	
	if(jogador.y == 1 && jogador.x == 3){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade");
	}
	
	if(jogador.y == 3 && jogador.x == 7){
		
		printf("tem um bau!\n");
		printf("deseja abrir? (digite 1 para abrir ou 2 para sair) \n");
		scanf("%d", &escolha);
		
		if(escolha==1){
			printf("nao tem nada otario KSKKKSKSKSKSKSKSKSK \n");
			
		}
		
		else if(escolha==2){
			printf("continue em frente\n");
		}
		
	}
	
		if(jogador.y == 4 && jogador.x == 8){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade\n");
	}
	
		if(jogador.y == 0 && jogador.x == 9){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade\n");
	}
	
		if(jogador.y == 3 && jogador.x == 9){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade\n");
	}
	
		if(jogador.y == 3 && jogador.x == 10){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade\n");
	}
	
	if(jogador.y == 4 && jogador.x == 5){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade!\n");
		
		printf("porem! voce achou um bau! \n");
		printf("deseja abrir? (digite 1 para abrir ou 2 para sair\n");
		scanf("%d",&escolha);
		
		if(escolha ==1){
			
			dadoT = rand() % 20 + 1;  
        printf("dado teste: %d\t", dadoT);
        
        dadoJ = rand() % 20 + 1;  
        printf("seu dado: %d\t", dadoJ);
			
			if(dadoJ>dadoT){
			
			printf("voce achou uma pocao de sanidade! \n");
				jogador.sanidade += 4;
		
		}
		
		else if(dadoJ<dadoT){
			
			printf("voce nao passou :(, tente novamente! \n");
			
		}
	}
		
		else if(escolha ==2){
			
			printf("continue em frente\n");
			
		}
	}
	
	if(jogador.y == 5 && jogador.x == 5){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade!\n");
		
		printf("porem! voce achou um bau! \n");
		printf("deseja abrir? (digite 1 para abrir ou 2 para sair\n");
		scanf("%d",&escolha);
		
		if(escolha ==1){
			
			dadoT = rand() % 20 + 1;  
        printf("dado teste: %d\t", dadoT);
        
        dadoJ = rand() % 20 + 1;  
        printf("seu dado: %d\t", dadoJ);
			
			if(dadoJ>dadoT){
			
			printf("voce achou uma pocao de sanidade! \n");
				jogador.sanidade += 4;
		
		}
		
		else if(dadoJ<dadoT){
			
			printf("voce nao passou :(, tente novamente! \n");
			
		}
	}
		
		else if(escolha ==2){
			
			printf("continue em frente\n");
			
		}
	}
	
	if(jogador.y == 4 && jogador.x == 5){
		jogador.sanidade -= 1;
		
		printf("voce esta perdendo sanidade!\n");
		
		printf("porem! voce achou um bau! \n");
		printf("deseja abrir? (digite 1 para abrir ou 2 para sair\n");
		scanf("%d",&escolha);
		
		if(escolha ==1){
			
			dadoT = rand() % 20 + 1;  
        printf("dado teste: %d\t", dadoT);
        
        dadoJ = rand() % 20 + 1;  
        printf("seu dado: %d\t", dadoJ);
			
			if(dadoJ>dadoT){
			
			printf("voce achou uma pocao de sanidade! \n");
				jogador.sanidade += 4;
		
		}
		
		else if(dadoJ<dadoT){
			
			printf("voce nao passou :(, tente novamente! \n");
			
		}
	}
		
		else if(escolha ==2){
			
			printf("continue em frente\n");
			
		}
	}
	
	if((jogador.y == 4 && jogador.x == 0) && jogador.reliquia == 1 )	{
		
		printf("Voce saiu da caverna!\n");
		
		jogador.eFim=0;
		
		}
		
	return jogador;
}

	Jogador moverJogador(Jogador jogador, char direcao){
		
		switch (direcao){
			
		case 'w':
			if (jogador.y > 0) jogador.y--;
			break;
			
		case 's':
			if (jogador.y < 5 - 1) jogador.y++;
			break;
			
		case 'a':
			if(jogador.x > 0) jogador.x--;
			break;
			
		case 'd':
			if (jogador.x < 15 -1) jogador.x++;
			break;
			
		case 'e':
		jogador=combates(jogador);
			break;
			
		default:
			printf("comando invalido! \n");
		}
		
		return jogador;
	}
	
	void Historia(){
		printf("seja bem-vindo");
		esperarTab();
		printf(">>>>>Cronicas<<<<<");
		esperarTab();
		printf("ep1: A Espada de Lognus");
		esperarTab();
		printf("nesse jogo que se passa na grecia antiga, voce um guerreiro leal a rainha\n embarcara numa jornada em um lugar escuro e assustador atras da reliquia da espada!\n");
		esperarTab();
		printf("em atena... a muitos anos atras..");
		esperarTab();
		printf("nas cavernas montanhosas.. vivi um enorme dragao");
		esperarTab();
		printf("onde atormentava todos os povos ali perto..");
		esperarTab();
		printf("porem.. reza a lenda..");
		esperarTab();
		printf("que um guerreiro, dito seu nome como Artorios, derrotou esse dragao com a espeda escalibur..");
		esperarTab();
		printf("com isso.. a espada se partiu, e a reliquia de lugnos..");
		esperarTab();
		printf("Reliquia essa que tinha todo o poder da espada..");
		esperarTab();
		printf("foi parar nas profundezas sombrias de atena..");
		esperarTab();
		printf("e o guerreiro?..");
		esperarTab();
		printf("sumiu junto a fumaca do dragao..");
		esperarTab();
		printf("porem..depois de muito tempo.. o dragao voltou..");
		esperarTab();
		printf("e eh seu dever..");
		esperarTab();
		printf("encontrar a reliquia.. e devolver a espada..");
		esperarTab();
		printf("contamos com voce, guerreiro.");
		esperarTab();
		
	}
	
	regras(){
		
		printf(">>>>>REGRAS<<<<<");
		esperarTab();
		printf("ande pela sala escura e encontre a reliquia");
		esperarTab();
		printf("conforme voce andar perdera sanidade, entao cuidado!");
		esperarTab();
	}
	
	final(){
		
		esperarTab();
		printf("agora..voce saiu da caverna..");
		esperarTab();
		printf("segurando a reliquia em sua mao..");
		esperarTab();
		printf("o dragao sobrevoanda a cidade de atena..");
		esperarTab();
		printf("tudo destruido..");
		esperarTab();
		printf("gritos ecoando por toda a parte..");
		esperarTab();
		printf("'a espada esta guardada na sala secreta...' voce pensa");
		esperarTab();
		printf("voce so precisa conseguir entrar..");
		esperarTab();
		printf(">>>>>Descricao de cena<<<<<");
		esperarTab();
		printf("voce esta segurando a reliquia em sua mao, ela brilha em azul claro, a sua armadura brilha com o fogo queimando o reino\n o dragao pousa em uma das casas, fechando as asas\n e encarando a sua pobre alma humana tentando se passar por um misero heroi\n Dragao: Mero mortal, achas que uma pedra brilhante ira me derrotar? voces humanas sao tao idiotas.\n voce: Nao eh apenas a pedra que irei usar contra voce, dragao medrilcre.\n");
		esperarTab();
		printf("voce olha para a reliquia..");
		esperarTab();
		printf("..........");
		esperarTab();
		esperarTab();
		printf("tudo depende de voce....");
		esperarTab();
		printf("Honre seu pai..");
		esperarTab();
		printf("o nome da familia Artorios ainda nao se apagou..");
		esperarTab();
		esperarTab();
		printf("PARABENS! voce terminou a primeira parte, agora teras que esperar a parte 2 \n que Michel ira fazer pois eu nao aguento mais :)");
		esperarTab();
		esperarTab();
		printf(">>>>>>>>>>CREDITOS<<<<<<<<<<");
		esperarTab();
		printf("feito pela Karoline Jagiela!");
		esperarTab();
		printf("os nomes foi tudo ideia do Michel");
		esperarTab();
		printf("espero que tenha gostado!");
		printf("um beijo");
		
	}
	

int main(){
	
	int j = 0;
	int i = 0;
	char Mapa[5][15]; 
	char comando;
	struct Jogador jogador;
	
	printf("digite seu nome de usuario: \n");
	fgets(jogador.Nome,sizeof(jogador.Nome), stdin);
			
	system("cls");
	
	regras();
	
	printf("jogador: %s \n", jogador.Nome);
	
	
	Historia();
	
	jogador=InventarioInicial(jogador);
	MostrarInventario(jogador);

	while(1){
			
		inicializarMapa (Mapa , jogador);
		jogador = escurinho(jogador,Mapa);	
		imprimirMapa (Mapa ,jogador);
		MostrarInventario(jogador);
		
		printf("\n digite Comando (w = up, s=down, a = letf, d = rigth, q= exit)\n");
		scanf("%c", &comando);
		
		if((comando == 'q') || (jogador.eVivo==0) || (jogador.eFim ==0)){
			break;
		}
		
		jogador = moverJogador(jogador, comando);
	
	}
	
	final();
	
	return SO_CORRO;
}
