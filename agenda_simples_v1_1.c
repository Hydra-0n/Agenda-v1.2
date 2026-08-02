#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX 100

typedef struct
{
    char nome[100];
    char telefone[20];
    char cpf[15];
    char email[80];
    char data_cadastro[20];
} Pessoa;

Pessoa agenda[MAX];
int total = 0;

void cadastrar()
{
    if (total >= MAX)
    {
        printf("\nLimite de cadastros atingido!\n");
        return;
    }

    printf("\n--- CADASTRAR PESSOA ---\n");
    printf("Nome: ");
    scanf(" %[^\n]", agenda[total].nome);
    printf("Telefone: ");
    scanf(" %[^\n]", agenda[total].telefone);
    printf("CPF: ");
    scanf(" %[^\n]", agenda[total].cpf);
    for (int i = 0; i < total; i++)
    {
        if (strcmp(agenda[i].cpf, agenda[total].cpf) == 0)
        {
            printf("\nErro: CPF ja cadastrado!\n");
            return;
        }

    }
    time_t agora;
    struct tm *data;
    time(&agora);
    data = localtime(&agora);
    sprintf(agenda[total].data_cadastro,
        "%02d/%02d/%d %02d:%02d",
        data->tm_mday,
        data->tm_mon + 1,
        data->tm_year + 1900,
        data->tm_hour,
        data->tm_min);

    printf("Email: ");
    scanf(" %[^\n]", agenda[total].email);

    total++;
    printf("\nPessoa cadastrada com sucesso!\n");
}

void listar()
{
    if (total == 0)
    {
        printf("\nNenhuma pessoa cadastrada.\n");
        return;
    }

    printf("\n--- LISTA DE PESSOAS ---\n");

    printf("Total de pessoas: %d\n", total);

    for (int i = 0; i < total; i++)
    {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
        printf("CPF: %s\n", agenda[i].cpf);
        printf("Email: %s\n", agenda[i].email);
        printf("------------------------\n");
        printf("Data de cadastro: %s\n", agenda[i].data_cadastro);
        printf("data da ultima edicao: %s\n", agenda[i].data_cadastro);
    }
}

void pesquisar()
{
    char cpf[15];
    printf("\n--- PESQUISAR PESSOA ---\n");
    printf("Digite o CPF da pessoa: ");
    scanf(" %[^\n]", cpf);

    for (int i = 0; i < total; i++)
    {
        if (strcmp(agenda[i].cpf, cpf) == 0)
        {
            printf("\nPessoa encontrada:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("CPF: %s\n", agenda[i].cpf);
            printf("Email: %s\n", agenda[i].email);
            printf("Data de cadastro: %s\n", agenda[i].data_cadastro);
            printf("Data da ultima edicao: %s\n", agenda[i].data_cadastro);
            return;

        }
    }

    printf("\nPessoa nao encontrada.\n");
}

void editar()
{
    char cpf[15];
    printf("---------------------\n");
    printf("--- EDITAR PESSOA ---\n");
    printf("---------------------\n");
    printf("Digite o CPF da pessoa a ser editada: ");
    scanf(" %[^\n]", cpf);

    for (int i = 0; i < total; i++)
    {
        if (strcmp(agenda[i].cpf, cpf) == 0)
        {
            printf("\nPessoa encontrada. Digite os novos dados:\n");
            printf("Nome: ");
            scanf(" %[^\n]", agenda[i].nome);
            printf("Telefone: ");
            scanf(" %[^\n]", agenda[i].telefone);
            printf("Email: ");
            scanf(" %[^\n]", agenda[i].email);
            printf("\nPessoa editada com sucesso!\n");
            return;
            time_t agora;
            struct tm *data;
            time(&agora);
            data = localtime(&agora);
            sprintf(agenda[i].data_cadastro,
                "%02d/%02d/%d %02d:%02d",
                data->tm_mday,
                data->tm_mon + 1,
                data->tm_year + 1900,
                data->tm_hour,
                data->tm_min);
        }
    }
    printf("\nPessoa nao encontrada.\n");
}

void buscar_por_nome()
{
    char nome[100];
    printf("\n--- BUSCAR POR NOME ---\n");
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]", nome);

    int encontrado = 0;
    for (int i = 0; i < total; i++)
    {
        if (strstr(agenda[i].nome, nome) != NULL)
        {
            printf("\nPessoa encontrada:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("CPF: %s\n", agenda[i].cpf);
            printf("Email: %s\n", agenda[i].email);
            printf("Data de cadastro: %s\n", agenda[i].data_cadastro);
            printf("Data da ultima edicao: %s\n", agenda[i].data_cadastro);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("\nNenhuma pessoa com este nome encontrada.\n");
    }
}

void excluir()
{
    char cpf[15];
    printf("\n--- EXCLUIR PESSOA ---\n");
    printf("Digite o CPF da pessoa a ser excluida: ");
    scanf(" %[^\n]", cpf);

    for (int i = 0; i < total; i++)
    {
        if (strcmp(agenda[i].cpf, cpf) == 0)
        {
            for (int j = i; j < total - 1; j++)
            {
                agenda[j] = agenda[j + 1];
            }
            total--;
            printf("\nPessoa excluida com sucesso!\n");
            return;
        }
    }

    printf("\nPessoa nao encontrada.\n");
}

int main()
{
    int opcao;
     


    do
    {
        
        printf("\n=== MENU PRINCIPAL ===\n");
          time_t agora;
            struct tm *data;
            time(&agora);
            data = localtime(&agora);
            printf("Data atual: %02d/%02d/%d\n",
            data->tm_mday,
            data->tm_mon + 1,
            data->tm_year + 1900);

            printf("Hora atual: %02d:%02d:%02d\n",
            data->tm_hour,
            data->tm_min,
            data->tm_sec);
            
        printf("1 - Cadastrar pessoa\n");
        printf("2 - Listar pessoas\n");
        printf("3 - Pesquisar pessoa\n");
        printf("4 - Editar pessoa\n");
        printf("5 - Excluir pessoa\n");
        printf("6 - Buscar por nome\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
         
        switch (opcao)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            listar();
            break;
        case 3:
            pesquisar();
            break;
        case 4:
            editar();
            break;
        case 5:
            excluir();
            break;
        case 6:
            buscar_por_nome();
            break;
        case 0:
            printf("\nSaindo do programa...\n");
            break;
        default:
            printf("\nOpcao invalida! Tente novamente.\n");

        }
        
  
    } while (opcao != 0);


    return 0;
}