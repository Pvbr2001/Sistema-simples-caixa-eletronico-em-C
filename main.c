#include <stdio.h>
#include <stdlib.h>

struct cadastro{
char nome[20];    
int numero;
int senha;
};
    
int painel_inicial;
int senha, senha_admin, endereco, endereco_admin, opcao, valor, i, j = 0, k, calc_qtd_cedula, escolha_user, nova_cedula, outra_operacao = 0, deposito, sair;
float saldo_user[2] = {900, 0};
int cedulas[4] = {100, 20, 2, 1}; 
int quantidade_Cedulas[4] = {0};
int quantidade_notas[4] = {40, 40, 40, 40};
struct cadastro cadastro[2];
    
void caixa_eletronico(){
        cadastro[0].numero = 87;
        cadastro[0].senha = 123;
        printf("\t\t\t\t*** Senai Bank ***\n");
        printf("\n\n\t\t\t\t1- entrar\n\n\t\t\t\t2- cadastrar-se\n\n\t\t\t\t3- painel administrador\n\nescolha: ");
        scanf("%d", &escolha_user);
        getchar();
        while(escolha_user <= 0 || escolha_user > 3){
            printf("\nescolha inválida!\n\ninforme uma opção válida: ");
            scanf("%d", &escolha_user);
            getchar();
        }
        system("clear");//Obs: se for rodar no windows, troca o "clear" por "cls".
    }
void cad(){
        if(j == 1){
            printf("Quantidade máxima de cadastro foi atingido!");
            return;
        }
        
        while(escolha_user == 2){
            j++;
            
            do{
                printf("\n\n\t\t\t***Painel de cadastro***\n\n");
                for(i = 1; ; i++){
                    printf("\ninforme seu nome: ");
                    fgets(cadastro[i].nome,20,stdin);
            
                    printf("\n\t\t\t\t\t\t3- sair\ninforme uma sequência numérica: ");
                    scanf("%d", &cadastro[i].numero);
                    getchar();
                if(cadastro[i].numero == 3){
                    return;
                }
                printf("\n\t\t\t\t\t\t3- sair\ninforme uma senha numérica: ");
                scanf("%d", &cadastro[i].senha);
                getchar();
                if(cadastro[i].senha == 3){
                    return;
                }
                break;
                }
                if(cadastro[i].numero <= 0 || cadastro[i].senha <= 0){
                    system("clear");//Obs: se for rodar no windows, troca o "clear" por "cls".
                    printf("\n\n\t\t\tdados cadastrais inválidos!\n\t\t\ttente novamente.\n\n");
                }
            }
            while(cadastro[i].numero <= 0 || cadastro[i].senha <= 0);
            system("clear");//Obs: se for rodar no windows, troca o "clear" por "cls".
            printf("\n\n\t\t\tcadastro efetuado com sucesso!\n\n");
            return;
        }
    }    
    
void user_padrao(){
    int redepositar, resacar;
        
        for(i = 0; i < 4; i++){
            if(quantidade_notas[i] == 0){
                printf("\t\tAviso: O caixa está em modo manutenção!");
            return;
            }   
        }
        printf("\t\t\t\t\t***Painel de login***\n");
        printf("\n\n\t\t\t\t\t\t3- sair\nInforme o Número da conta: ");
        scanf("%d", &endereco); //87
        getchar();
        if(endereco == 3){
            return;
        }
        
        printf("\n\n\t\t\t\t\t\t3- sair\ninforme a sua senha: ");
        scanf("%d", &senha);//123
        getchar();
        if(senha == 3){
            return;
        }
        if(endereco <= 0 || senha <= 0){
                    system("clear");//Obs: se for rodar no windows, troca o "clear" por "cls".
                    printf("\n\n\t\t\tnúmero da conta ou senha incorretos");
                    return;
                }
        system("clear");//Obs: se for rodar no windows, troca o "clear" por "cls".
        do{
            system("clear");
            for(k = 0; k < 2; k++){
                if(endereco == cadastro[k].numero && senha == cadastro[k].senha){
                
                    do{
                        printf("\n\t\t\t\t\tSEJA BEM VINDO(A) %s \n", cadastro[k].nome);
                        printf("\n\t\t\t\tCédulas disponíveis: R$%d  R$%d  R$%d ", cedulas[0], cedulas[1], cedulas[2]);
                        if(cedulas[3] == 2){
                            printf(" %d", cedulas[3]);
                        }
                        printf("\n\n\t\t\t\t\t\t\t\t\t\tSaldo: R$%.2f", saldo_user[k]);
                        printf("\n\n\n\t1- R$ 50\t\t4- digite um valor desejado.\n\n\t2- R$100\t\t5- Depósito\n\n\t3- R$200\t\t6- sair");
                        printf("\n\n\nEscolha uma opção: ");
                        scanf("%d", &opcao);
                        if(opcao < 1|| opcao > 6){
                            system("clear");//Obs: se for rodar no windows, troca o "clear" por "cls".
                            printf("escolha inválida\ntente novamente com um valor válido\n");
                        }
                        getchar();
                    }
                    
                    while(opcao < 1|| opcao > 6);
            
                    switch(opcao){
                
                        case 1: valor = 50;
                        break;
                
                        case 2: valor = 100;
                        break;
                
                        case 3: valor = 200;
                        break;
                            
                        case 4: printf("\nDigite o valor: ");
                                scanf("%d", &valor);
                                while(valor <= 0){
                                    printf("\nerro! informe um valor válido: ");
                                    scanf("%d", &valor);
                                    getchar();
                                }
                        break;
                        
                        case 5:
                                printf("informe o valor para depósito: ");
                                scanf("%d", &deposito);
                                getchar();
                                if(deposito == 3){
                                    return;
                                }
                                while(deposito <= 0){
                                    printf("valor inválido!\n informe um valor válido: ");
                                    scanf("%d", &deposito);
                                    getchar();
                                    }
        
                                saldo_user[k] += deposito;    
                                printf("\n\n\t\t\t\t**depósito efetuado com sucesso!**");
                             
                                printf("\n\n\t\t\t\t\t1- voltar\n\nescolha: ");
                                scanf("%d", &outra_operacao);
                                break;
                                
                        case 6: return;
                        
                        default:;
                    }
                    if(valor <= saldo_user[k]){
                        while (valor % 2 != 0){
                            printf("Não é possível realizar a operação!\nEste caixa realiza apenas operações com valores pares");
                            printf("\ninforme um valor válido: ");
                            scanf("%d", &valor);
                            getchar();
                        }
                        if(valor > (quantidade_notas[0]*cedulas[0] + quantidade_notas[1]*cedulas[1] + quantidade_notas[2]*cedulas[2] + quantidade_notas[3]*cedulas[3])){
                            printf("não é possível sacar esse valor com a quantidade de cédulas no momento!");
                            return;
                        }
                        
                    saldo_user[k] -= valor;
                    
                    for (i = 0; i < 4; i++) {
                        if (valor >= cedulas[i]) { 
                            calc_qtd_cedula = valor / cedulas[i];
                        
                            if(calc_qtd_cedula > quantidade_notas[i]){
                                calc_qtd_cedula = quantidade_notas[i];
                                valor -= calc_qtd_cedula * cedulas[i];
                            }
                            
                            if (calc_qtd_cedula > 0) {
                                quantidade_Cedulas[i] = calc_qtd_cedula; 
                                valor %= cedulas[i];
                            }
                        }
                    }
                    
                    if(valor > 0){
                        printf("caixa em modo manutencão!");
                    }
                    
                    if(opcao != 5){
                        if (valor == 0) {
                            printf("\nSaque efetuado!\n");
                            printf("\nQuantidade de cédulas:\n");
                        } 
                        for (i = 0; i < 4; i++) {
                            if (quantidade_Cedulas[i] > 0) {
                                printf("%d cédulas de R$%d\n", quantidade_Cedulas[i], cedulas[i]);
                            }
                        }
                        printf("\n\n\t\t\t\t1- Fazer outra operação\t\t2- Sair\n\nescolha: ");
                        scanf("%d", &outra_operacao);
                        break;
                        if(outra_operacao == 2){
                            return;
                        }
                    }    
                }
                    else{
                        printf("\n\t\t\t\t**Saldo insuficiente!**");
                    }
                    
                    printf("\n\n\t\t\t\t1- Fazer outra operação\t\t2- sair\n\nescolha: ");
                    scanf("%d", &outra_operacao);
                    break;
                    getchar();
                    
                    if(outra_operacao == 2){
                        return;
                    }
                }
                
                if((endereco != cadastro[0].numero || endereco != cadastro[1].numero) &&
                    (senha != cadastro[0].senha && senha != cadastro[1].senha)) {
                    printf("Número da conta ou senha incorretos!");
                    return;
                }
                
            }
        
        for(i = 0; i < 4; i++){
                quantidade_notas[i] -= quantidade_Cedulas[i];
        }
    }
    while(outra_operacao == 1);
}
        
    void user_admin(){
        printf("\n\n\t\t\t\t\t\t3- sair\nInforme o Número da conta: ");
        scanf("%d", &endereco_admin); //87
        getchar();
        if(endereco_admin == 3){
            return;
        }
        
        printf("\n\n\t\t\t\t\t\t3- sair\ninforme a sua senha: ");
        scanf("%d", &senha_admin);
        getchar();
        if(senha_admin == 3){
            return;
        }
        
        if(endereco_admin == 14 && senha_admin == 555){
            int op_admin, recarga, cedula_1 = 1, cedula_2 = 1, cedula_3 = 1, cedula_4 = 1;
            system("clear");//Obs: se for rodar no windows, troca o "clear" por "cls".
            printf("\n\n\t\t\t***Seja bem vindo ao painel administrador!***\n\n");
            for(i = 0; i < 4; i++){
                if(quantidade_notas[i] == 0){
                    printf("\t*Aviso:A nota de R$%d está em falta\n", cedulas[i]);
                }
            }
        
        do{
            printf("\n\n1- visualizar quantidade de cédulas\t\t2- recarga de cédulas\n\n3- adicionar nova cedula\t\t\t4- sair\n\n\nopção: ");
            scanf("%d", &op_admin);
            getchar();
            if(op_admin < 1 || op_admin > 4){
                printf("escolha incorreta!\ninforme um valor válido: ");
                scanf("%d", &op_admin);
            }
        }
        while(op_admin < 1 || op_admin > 4);
    
        switch(op_admin){
            case 1:
                for(i = 0; i < 3; i++){
                    printf("%d notas de R$%d\n", quantidade_notas[i], cedulas[i]);
                }
                if(cedulas[3] == 2){
                    printf("%d notas de R$%d\n", quantidade_notas[3], cedulas[3]);
                }
            break;
        
            case 2:
            do{
                printf("\n\n1- recarregar cédulas de R$%d\n\n2- recarregar cédulas de R$%d\n\n3- recarregar cédulas de R$%d\n\n", cedulas[0], cedulas[1], cedulas[2]);
                if(cedulas[3] == 2){
                    printf("4- recarregar cédulas de R$%d\n\n", cedulas[3]);
                }
                printf("\n\n\n\t\t\t\t\t\t5- sair\nQual nota deseja realizar a recarga?: ");
                scanf("%d", &recarga);
                getchar();
                
                if(recarga == 5){
                    return;
                }
                
                if(recarga <= 0 || recarga > 5){
                    printf("escolha incorreta!\ninforme uma opção válida: ");
                    scanf("%d", &recarga);
                }
            }
            while(recarga <= 0 || recarga > 4);
            break;
            
            case 3: 
                printf("cedulas disponíveis para adicionar:\n\n1- R$200\n2- R$50\n3- R$10");
                printf("\n\n\t\t\t\t\t\t4- sair\ninforme qual cédula você quer adicionar: ");
                scanf("%d", &nova_cedula);
                getchar();
            
                if(nova_cedula == 4){
                    return;
                }
                
                while(nova_cedula < 1 || nova_cedula > 4){
                    printf("valor inválido!\ninforme um valor válido: ");
                    scanf("%d", &nova_cedula);
                    getchar();
                }
                
                if(nova_cedula > 0 && nova_cedula < 4){
                    printf("\n\n\t\t\tUma nova cédula foi adicionada com sucesso!");
                }
                
                switch(nova_cedula){
                    case 1: 
                        quantidade_notas[3] = quantidade_notas[2];
                        quantidade_notas[2] = quantidade_notas[1];
                        quantidade_notas[1] = quantidade_notas[0];
                        quantidade_notas[0] = 40;
                        cedulas[0] = 200;
                        cedulas[1] = 100;
                        cedulas[2] = 20;
                        cedulas[3] = 2;
                    break;
                        
                    case 2:
                        quantidade_notas[3] = quantidade_notas[2];
                        quantidade_notas[2] = quantidade_notas[1];
                        quantidade_notas[1] = 40;
                        cedulas[0] = 100;
                        cedulas[1] = 50;
                        cedulas[2] = 20;
                        cedulas[3] = 2;
                    break;
                    
                    case 3:
                        quantidade_notas[3] = quantidade_notas[2];
                        quantidade_notas[2] = 40;
                        cedulas[0] = 100;
                        cedulas[1] = 20;
                        cedulas[2] = 10;
                        cedulas[3] = 2;
                    break;
                    
                    default:printf("escolha incorreta!");
                }
                
            case 4: 
                if(op_admin == 4){
                    return;
                }
        }
            do{
                switch(recarga){
        
                    case 1: printf("informe quantas cédulas de %d você quer recarregar: ", cedulas[0]);
                            scanf("%d", &cedula_1);
                            getchar();
                            if(cedula_1 > 0){
                            printf("\nvocê recarregou %d notas de R$%d = R$%d",cedula_1, cedulas[0], cedula_1 * cedulas[0]);
                            quantidade_notas[0] += cedula_1;
                            }
                    break;
        
                    case 2: printf("informe quantas cédulas de %d você quer recarregar: ", cedulas[1]);
                            scanf("%d", &cedula_2);
                            getchar();
                            if(cedula_2 > 0){
                            printf("\nvocê recarregou %d notas de R$%d = R$%d", cedula_2, cedulas[1], cedula_2 * cedulas[1]);
                            quantidade_notas[1] += cedula_2;
                            }
                    break;
        
                    case 3: printf("informe quantas cédulas de %d você quer recarregar: ", cedulas[2]);
                            scanf("%d", &cedula_3);
                            getchar();
                            if(cedula_3 > 0){
                            printf("\nvocê recarregou %d notas de R$%d = R$%d",cedula_3, cedulas[2], cedula_3 * cedulas[2]);
                            quantidade_notas[2] += cedula_3;
                            }
                    break;
                    
                    case 4: printf("informe quantas cédulas de %d você quer recarregar: ", cedulas[1]);
                            scanf("%d", &cedula_4);
                            getchar();
                            if(cedula_4 > 0){
                            printf("\nvocê recarregou %d notas de R$%d = R$%d", cedula_4, cedulas[1], cedula_4 * cedulas[1]);
                            quantidade_notas[1] += cedula_4;
                            }
                    break;        
            
                    default:break;
                }
            }
            while(cedula_1 <= 0 || cedula_2 <= 0 || cedula_3 <= 0 || cedula_4 <= 0);
            
    
    }
    else{
        printf("dados incorretos!");
        return;
    }
        for(i = 0; i < 3; i++){
            quantidade_Cedulas[i] = 0;
        }
    
    }
    
    void inicio(){
        printf("\n\n\t\t\t\t1- Tela inicial\n\nescolha: ");
        scanf("%d", &painel_inicial);
        getchar();
        while(painel_inicial != 1){
            printf("valor incorreto!\nescolha uma opção válida: ");
            scanf("%d", &painel_inicial);
            getchar();
        }
        system("clear");//Obs: se for rodar no windows, troca o "clear" por "cls".
    }
            
    int main(){
    
    do{
        caixa_eletronico();
        
        switch(escolha_user){
            
            case 1:
                user_padrao();
            break;
            
            case 2:
                cad();
            break;
            
            case 3:
                user_admin();
            break;
            
            default: printf("escolha incorreta!\ntente novamente ou encerre sessão");
        }
        inicio();
        while(painel_inicial >=3 && painel_inicial >=0 ){
            printf("valor incorreto!\nescolha uma opção válida: ");
            scanf("%d", &painel_inicial);
            getchar();
        
        }
    }  
    

    while(painel_inicial == 1);
    
    while(painel_inicial != 1){
        printf("escolha inválida!\ninforme um valor válido: ");
        scanf("%d", &painel_inicial);
        getchar();
    }
    
    return 0;
}







