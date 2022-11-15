#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define AZUL    "\x1b[34m"
#define RESET   "\x1b[0m"
#define VERDE   "\x1b[32m"
#include <time.h>

void tabela();
int menu();
void info();
struct login                           // Contagem de caracteres maximos.
{
    char sexo[30];
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
    char lprofissao[30];
    char senha1[20];
    char idade[5];
}l;

struct login l;
void login1();
void login (void);
void registration (void);

int main (void)
{
    system("color FC");
    setlocale(LC_ALL, "portuguese");
    int option;
    // Tela de Menu inicial




   printf("                                  ,-----------------,              ,---------,\n");
   printf("                             ,------------------------,          ,/        ,/|\n");
   printf("                           ,                       ,. /        ,/        ,/  |\n");
   printf("                          +------------------------+  |      ,/        ,/    |\n");
   printf("                          |  .------------------.  |  |     +---------+      |\n");
   printf("                          |  |                  |  |  |     | -==----'|      |\n");
   printf("                          |  |  Pressione '1'   |  |  |     |         |      |\n");
   printf("                          |  |  para logar ou   |  |  |/----|`---=    |      |\n");
   printf("                          |  |  '2' para regi-  |  |  |   ,/|==== ooo |      ;\n");
   printf("                          |  |-strar um cliente |  |  |  // |     [!!]|    ,\n");
   printf("                          |  `------------------'  |,. .;'| |         |  ,\n");
   printf("                          +-----------------------+  ;;  |  |         |,\n"    );
   printf("                              /)____(/  //'   | +---------+\n");
   printf("                           _________/_  `,\n");
   printf("                          /  --------------  .-.  ---- /,   \,-----------\n");
   printf("                         / ==---------------==.-.  ---= //   ,`\--{)||     ,\n");
   printf("                        /==============---_---=/'   /_____,\n");
   printf("                        `-----------------------------'\n");




    printf(AZUL"\n Pressione: ");
    scanf("%d",&option);








    getchar();           // SE NUMERO = 2 VAI PARA O REGISTRO E SE FOR = 1 VAI PARA O LOGIN.


        if(option == 1)
        {
            system("CLS");
            login();
        }
        else if(option == 2)
        {
            system("CLS");
            login1();
        }
}
void leiaSenha(char password[], int tamanho)
{
    char tecla;
    int i = 0;

    tecla = getch();
    while (i < tamanho - 1 && tecla != '\r')
    {
        putch('*');
        password[i++] = tecla;
        tecla = getch();
    }
    password [i] = '\0';
}

void login (void)
{
    char username[30],password[20];
    FILE *log;
    int logou = 0;

    log = fopen("login.txt","r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }

    // Area do login

    system("color FC");
    printf(AZUL"\nPor favor coloque suas credenciais de login\n\n");
    printf(VERDE"Nome de usuario:  ");
    gets(username);
    printf(VERDE"\nSenha: ");
    printf("\n");
    leiaSenha(password,20);
    //fgets(password, 20, stdin);
    fread(&l,sizeof(struct login),1,log);
    while(!feof(log))
        {
        if(strcmp(username, l.username) ==0 && strcmp(password, l.password) ==0)
            {
                printf("\nLogin bem sucedido\n");
                carreg();
                system("cls");
                logou = 1;
            }
        fread(&l,sizeof(struct login),1,log);
        }

    //login();

    fclose(log);
    if(logou)
    {
        menu();
    }
    else
    {
        system("CLS");
        printf("\nInformações incorretas\nPor favor coloque suas credenciais corretas\n\n");
    }
    return;
}




void registration(void)
{
    char firstname[15];
    FILE *log;

    log=fopen("login.txt","w");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }

    system("color F");
      //Area do registro
    printf(AZUL"\nBem vindo a UNIPC++. Precisamos de algumas informações para o registro\n\n");

    printf("\nPrimeiro nome:\n");
    fflush(stdin);
    scanf("%s",l.fname);

    printf("\nSobrenome:\n");
    fflush(stdin);
    scanf("%s",l.lname);
    int escolha;
    printf("\nProfissão:\n");
    printf("1 - Gerente de projetos\n");
    printf("2 - Atendente\n");
    printf("3 - Desenvolvedor\n");
    printf("4 - Tecnico em Redes\n");
    fflush(stdin);
    printf("Digite:");
    scanf("%d", &escolha);
    if (escolha == 1)
    {
        strcpy(l.lprofissao, "Gerente de PRJ");
    }
    else if (escolha == 2)
    {
        strcpy(l.lprofissao, "Atendente");
    }
    else if (escolha == 3)
    {
        strcpy(l.lprofissao, "Desenvolvedor");
    }
    else if (escolha == 4)
    {
        strcpy(l.lprofissao, "Tecnico de Redes");
    }
    int escolhaa;
    printf("\nSexo:\n");
    printf("1 - Masculino\n");
    printf("2 - Feminino\n");
    printf("Digite:");
    fflush(stdin);
    scanf("%d",&escolhaa);
    if (escolhaa == 1)
    {
        strcpy(l.sexo, "Masculino");
    }
    else if (escolhaa == 2)
    {
        strcpy(l.sexo, "Feminino");
    }

    printf("\nIdade:\n");
    fflush(stdin);
    scanf("%s",l.idade);

    printf(VERDE"Obrigado.\nAgora coloque seu nome de usuario e senha para ter acesso ao login.\n'assegure que seu nome de usuario tem menos de 30 caracteres'.\n'Assegure que sua senha tenha caracteres pequenos, grandes, numericos e especiais.'\n"RESET);

    printf("\nNome de usuario:\n");
    fflush(stdin);
    scanf("%s",l.username);
    printf("\nColoque a senha:\n");
    fflush(stdin);
    scanf("%s",l.password);
    printf("\nConfirme sua senha:\n");
    fflush(stdin);
    scanf("%s",l.password);


    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\nConfirmando detalhes...\n...\nBem vindo, %s!\n\n",firstname);
    printf("\nRegistro bem sucedido!\n");
    printf("Pressione qualquer tecla para continuar...");
        getchar();
        carreg();
    system("CLS");
    login();

}
void info(struct login l)
{
    system("cls");
    system("color FC");
    printf("\nSuas informações:\n\n");
    printf(AZUL"------------------------");
    printf("\nNome:  %s \n", l.fname);
    printf(AZUL"------------------------");
    printf("\nNome de Usuario: %s \n", l.username);
    printf(AZUL"------------------------");
    printf("\nSobrenome: %s \n",l.lname);
    printf(AZUL"------------------------");
    printf("\nProfissão:  %s  \n", l.lprofissao);
    printf(AZUL"------------------------");
    printf("\nSexo: %s \n", l.sexo);
    printf(AZUL"------------------------\n");
    printf("Idade: %s \n", l.idade);
}
int menu(void) {

    printf("\n                            Bem vindo !!\n");
    int opcao;
    do {
        printf("-----------------------------Menu-----------------------\n");
        printf("====================1) Suas informações\n");
        printf("====================2) Informações Empresariais\n");
        printf("====================3) SAIR\n");




        printf("\nDigite sua opção\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            {


                info(l);
                system("pause");
                system("cls");
                break;
            }
            case 2:
            {


                tabela();
                system("pause");
                system("cls");
                break;
            }
            case 3:
            {
                system("cls");
                return 0;
            }
        default:
            {
                system("cls");
                printf("Opção invalida. Tente novamente.\n");
                break;
            }

        }
    } while(opcao);
    return 0;
}


void login1()
{
    system("color FC");
    int senha2;
    int login1;
    printf("\nNome Adm:\n");
    fflush(stdin);
    scanf("%d", &login1);
    printf("\nSenha Adm:\n");
    fflush(stdin);
    scanf("%d", &senha2);
    carreg();
    if(login1 && senha2 == 123)
    {
        registration();
        system("cls");
    }
    else
    {
        printf("Informação Incorreta!\n");
    }
}
void tabela()
{
    system("cls");
    int opc;


    system("color FC");
    printf("\nTabela de Informações:\n\n");
    printf(AZUL"------------------------\n");
    printf("Funcionarios:\n\n");
    printf("\nGerente de Projetos  | Salario = R$ 11.964,00\n");
    printf(AZUL"------------------------\n");
    printf("\nTecnico em redes  | Salario = R$ 1.983,00\n");
    printf(AZUL"------------------------\n");
    printf("\nAtendente  | Salario = R$ 1.212,00\n");
    printf(AZUL"------------------------\n");
    printf("\nDesenvolvedor Back-End  | Salario = R$ 22.915,82\n");
    printf(AZUL"------------------------\n");
    printf("Proxima tabela - Digite 1\n");
    printf("Sair da Tabela - Digite 2\n");
    scanf("%d", &opc);

    if (opc == 1)
    {
        system("cls");
        int opc2;

    system("color FC");
    printf("Tabela de Informações:\n\n");
    printf(AZUL"------------------------");
    printf("Equipamentos:\n\n");
    printf("Televisão smart 32  | Valor total = R$ 1.000,00  | Quantidade = 1\n");
    printf(AZUL"------------------------ \n");
    printf("Mesa de Reunião  | Valor total = R$ 1.200,00  | Quantidade = 1\n");
    printf(AZUL"------------------------\n");
    printf("Telefone de atendimento  | Valor total = R$ 1.200,00  | Quantidade = 6\n");
    printf(AZUL"------------------------\n");
    printf("Balcão de recepção  | Valor total = R$ 1.500,00  | Quantidade = 1\n");
    printf(AZUL"------------------------\n");
    printf("Kit Cadeira de escritorio  | Valor total = R$ 3.600,00  | Quantidade = 12\n");
    printf(AZUL"------------------------\n");
    printf("Mesa de Escritorio  | Valor total = R$ 9.000,00  | Quantidade = 6\n");
    printf(AZUL"------------------------\n");
    printf("Fone Headset  | Valor total = R$ 360,00    | Quantidade = 6\n");
    printf(AZUL"------------------------\n");
    printf("Teclado e Mouse | Valor total = R$ 3.600,00  | Quantidade = 6\n");
    printf(AZUL"------------------------\n");
    printf("Computadores Pichau  | Valor total = R$ 12.000,00 | Quantidade = 6\n");
    printf(AZUL"------------------------\n");
    printf("Sair da Tabela - Digite 2\n");
    scanf("%d", &opc2);
    if (opc2 == 2)
    {
        system("cls");
        return 0;
    }
    else
    {
        printf("COMANDO INVALIDO!");
        system("pause");
        system("cls");
        return 0;
    }
    }
    else if (opc == 2)
    {
        system("cls");
        return 0;
    }
    else
    {
        printf("COMANDO INVALIDO!");
        system("pause");
        system("cls");
        return 0;
    }
}



  void limpa_linha(void);

  void carreg(int argc, char **argv){
     int i, j;

     system ("cls");//limpa tela
     printf ("\n\nCarregando: \n\n");

     for (i = 0; i <= 100; i++){
        printf ("%d%%  ", i);
        fflush (stdout);//garante a escrita de dados imediatamente na tela
        //repare mod 10, eu limito a qtd de pontos q serao gerados
        for (j = 0; j < i%10; j++){
           printf(".");
        }
        fflush (stdout);//garante a escrita de dados imediatamente na tela
        usleep(6000);//função espera por tempo, parametro em microsegundos.
        limpa_linha();
     }
  };

  void limpa_linha(){
     int i;//indice do caracter na linha
     int max_caracter=50;//indica o maximo de caracter que a linha pode chegar a ter, para linhas com mt texto, coloque um nmr bem maior
     printf("\r");//retorna para o inicio da linha que pretende reutilizar, isso não limpa a linha, apenas posiciona cursor ao inicio da linha

     //Agora precisamos limpar a linha,
     //substitui todos os caracteres existentes por espaço em branco
     for(i=0;i<max_caracter;i++){
        printf(" ");//vai preenchendo a linha com espaços em branco
     }

     printf("\r");//volta ao inicio da linha , dessa vez ela está em branco.

  }


