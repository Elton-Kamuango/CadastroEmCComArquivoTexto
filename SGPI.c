#include "conio.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "dos.h"
#include <locale.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,i;
//Estrutura da empresa.
struct Empresa {
	char proprietario[30];
	char nome[30];
	char tipo[10];
	char codigo[10];
	float imposto;
}empresa[100];//fim da estrutura empresa.
//Criar e abrir arquivo 
FILE*abrirArquivo(char modo, char caminho[30]){
FILE*arquivo;
switch (modo){
	case 'g':
		arquivo=fopen(caminho, "wt");
		break;
	case 'l':
		arquivo=fopen(caminho, "rt");
		break;
	
	case 'a':
		arquivo=fopen(caminho, "a");
		break;
}
if(arquivo==NULL){
	printf("Não foi possível abrir o ficheiro");
	exit(0);
}
return arquivo;
}//Fim abrir arquivo
void fecharArquivo(FILE*arquivo){
	fclose(arquivo);
}//fechar arquivo
//Registo de empresas
void RegistarEmpresa(){
int i=1;
	FILE * arquivo;
	arquivo = fopen("lista.txt","a");
    printf("\n\t\t\t\t\t\t====* Página de Registo de Empresas *==== \n");    
    printf("\n-> Quantas empresas deseja registar? \n");
    scanf("%d", &n);

  	for(i=1;i<=n;i++){
	    puts("");
	    printf("\n-> Nome do proprietário da empresa: ");
	    scanf("%s",&empresa[i].proprietario);
	    printf("\n-> Nome da empresa: ");
	    scanf("%s", &empresa[i].nome);
	    printf("\n-> Tipo de Empresa: ");
	    scanf("%s", &empresa[i].tipo);
	    printf("\n-> Código da Empresa: ");
	    scanf("%s", &empresa[i].codigo);   
	    if(arquivo == NULL){
	    	printf("Não foi possível abrir o arquivo");
	    }
	    
	    fprintf(arquivo,"%s ",empresa[i].proprietario);
	    fprintf(arquivo," %s ",empresa[i].nome);
	    fprintf(arquivo," %s ",empresa[i].tipo);
	    fprintf(arquivo," %s \n",empresa[i].codigo);
	    
  	}  
    printf("\n\n**operação realizada com sucesso**");
    fclose(arquivo);
	getch(); 
}//Fim registo.
//Pagamento de impostos
void PagarImposto(){
    int x;
    float rendimento,imposto;
    char code[10];
    FILE * arquivo;
	arquivo = fopen("Pagamento.txt","a");
    printf("\n\t\t ======* Página de Pagamento *======\n"); 
    
    printf("\n-> Digite o Código da empresa:  ");
    scanf("%s", &code);
	fgets(empresa[i].codigo,10,stdin);
    for(i=1;i<=n;i++){
	    if(strcmp(code,empresa[i].codigo)==0){
          x=1;
          printf("\n *Nome da Empresa: %s", empresa[i].nome);
          printf("\n\n-> Rendimento deste ano: ");
          scanf("%f", &rendimento) ;
          if(rendimento >= 0){
            empresa[i].imposto = rendimento*0.3;
            printf("\n\a Imposto pago de %f",empresa[i].imposto,"Kz ");
            printf("\n\a Pagamento processado com sucesso!!!");
            getch();
          }
          else{
	          printf("\n\a *Erro: O rendimento tem que ser positivo");
	          getch();
	          break;
          }
        }
        if(arquivo == NULL){
	    	printf("Não foi possível abrir o arquivo");
	    }
	    
	    fprintf(arquivo, "%s %f \n",empresa[i].nome, empresa[i].imposto);
	    fclose(arquivo);
    }
    if(x!=1)
    printf("\n\a\a *-- Erro: Código não atribuido! --*"); 
    printf("\n\n *-- Aguarde... --*");
    getch();
}//Fim Pagamento.
//Listagem de Empresas
void ListarEmpresas(){
	char proprietario[30];
	char nome[30];
	char tipo[10];
	char codigo[10];
	FILE*arquivo;
	arquivo=abrirArquivo('l', "lista.txt");
	printf("\n\t\t\t\tLISTA DE EMPRESAS REGISTADAS\n\n");
	printf("\n|--------------------------------------------------------------------------------------------------------");
	printf("\n|Nome do Proprietário:  \t| Nome da Empresa:  \t\t| Tipo:  \t\t| Código: \n");
	do{	
    	printf("\n| %s\t", proprietario);
    	printf("\t\t  %s\t",nome);
    	printf("\t\t\t  %s\t",tipo);
    	printf("\t %s",codigo);
    	
		fscanf(arquivo, "%s  %s %s %s",&proprietario, &nome, &tipo, &codigo);
	}	
	while(!feof(arquivo));
	printf("\n|--------------------------------------------------------------------------------------------------------");
	fecharArquivo(arquivo);

}//Fim Listagem.
//Listar Pagamentos
void ListarPagamento(){
	char nome[30];
	float imposto;
	FILE*arquivo;
	arquivo=abrirArquivo('l', "Pagamento.txt");
	printf("\n\t\t\t\tLISTA DE EMPRESAS E VALORES PAGOS DE IMPOSTO\n\n");
	do{	
    	printf("\nEmpresa: %s -  Valor Pago: %f\t",nome,imposto);
		fscanf(arquivo, "%s  %f",&nome, &imposto);
	}while(!feof(arquivo));	

fecharArquivo(arquivo);

}//Fim Listagem
//Limpar Listas
void EliminarEmpresas(){
	FILE * arquivo;
	arquivo = fopen("lista.txt","wt");
	if(arquivo == NULL){
	    printf("Não foi possível abrir o arquivo");
	}
	    
	printf("\n\n**Limpeza da Lista Concluída!!!\nA Lista esta agora vazia**");
    fclose(arquivo);
	getch(); 
  	}  
  	void EliminarPagamento(){
	FILE * arquivo;
	arquivo = fopen("Pagamento.txt","wt");
	if(arquivo == NULL){
	    printf("Não foi possível abrir o arquivo");
	}
	    
	printf("\n\n**Limpeza da Lista Concluída!!!\nA Lista esta agora vazia**");
    fclose(arquivo);
	getch(); 
  	}//Fim Limpar Listas
     
    //Função principal
int main() {
	int op,op1,i,k,r,senha;
	char name[15];
	setlocale(LC_ALL,"Portuguese");
	printf("\n*********************************************************************************************************************************************************************");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tINICIAR SESSÃO\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
	printf("\n\n-> Introduza o seu nome: ");
	scanf("%s",&name);
	setbuf(stdin,NULL);
	printf("\n-> Introduza a palavra passe do sistema: ");
	scanf("%d",&senha);
	printf("\n*********************************************************************************************************************************************************************");
	if(senha==1234) {
		inicio:
		system("cls");
		printf(" _______________________________________________________________________________________________________________________________________________________________________");
		printf("|\n\t\t\t\t\t\t\tBEM VINDO AO SISTEMA DE PAGAMENTO DE IMPOSTOS\t\t\t\n\n");
		printf("\n\n|\t\t\t\t\t1-Registar Empresa \t\t\t2-Regularizar Imposto\t\t\n\n\n\n|\t\t\t\t\t3-Listar Empresas\t\t\t4-Limpar Listas\t\t\n\n\n\n\t\t\t\t\t\t\t\t0 - Sair\t\t\t\n\n");
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tFuncionário: %s\n",name);
		printf("|_______________________________________________________________________________________________________________________________________________________________________");
		printf("\n-> Digite o número correspondente a opção desejada: ");
		scanf("%d", &op);
	switch(op){
		case 1:
			system("cls");
			RegistarEmpresa();
			system("cls");
			goto inicio;
			break;
		case 2:
			system("cls");
			PagarImposto();
			system("cls");
			goto inicio;
			break;
		case 3:
			inicio2:
			system("cls");
			printf("Página de Listagem");
			printf("\n\n\n1- Listar Empresas Registadas\n\n2- Listar Empresas que Pagaram imposto\n\n0- Voltar ao menú principal\n\n");
			printf("\n-> Digite o número correspondente a opção desejada: ");
			scanf("%d", &k);
			switch(k){
				case 1:
					system("cls");
					ListarEmpresas();
					getch();
					system("cls");
					goto inicio2;
				break;
				case 2:
					system("cls");
					ListarPagamento();
					getch();
					system("cls");
					goto inicio2;
				break;
				case 0:
					system("cls");
					goto inicio;
				break;
				default:
					printf("Número não atribuido!!!");
					getch();
					goto inicio2;
					}
					break;
		case 4:
			inicio3:
			system("cls");
			printf("Seja bem-vindo a página de limpeza de listas");
			printf("\n\n1- Limpar Lista de Empresas registadas\n\n2- Limpar Lista de pagamento\n\n0- Voltar ao menú principal\n\n");
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tFuncionário: %s\n",name);
			printf("\n-> Digite o número correspondente a opção desejada: ");
			scanf("%d",&op1);
			switch(op1){
				case 1:
					ListarEmpresas();
				
					printf("\n\n-> Tem certeza que quer limpar a lista de empresas registadas([1]-sim [0]-não)?: ");
					scanf("%d",&r);	
					if(r==1){
					EliminarEmpresas();
					system("cls");
					goto inicio3;
					}
				break;
				case 2:
					ListarPagamento();
					printf("\n\n-> Tem certeza que quer limpar a lista de empresas registadas([1]-sim [0]-não)?: ");
					scanf("%d",&r);	
					if(r==1){
					EliminarPagamento();
					system("cls");
					goto inicio3;
				}
				break;
				case 0:
					system("cls");
					goto inicio;
				default:
					printf("Número não atribuido!!!");
					getch();
					goto inicio3;
			}
			system("cls");
			goto inicio3;
		break;
		case 0:
			system("cls");
			printf("Terminando...\n");
			exit(1);
		break;
		default:
			printf("Número não atribuido!!!");
			getch();
			goto inicio;
		}
	}	
else
printf("\nA palavra passe do sistema esta incorreta!!\n");
getch();
system("cls");
main();

	return 0;
}
