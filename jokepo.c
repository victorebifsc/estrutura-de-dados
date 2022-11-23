#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

void space(){
    printf("======================================================================\n");
}

void clean(){
    system("cls");
    printf(
        "\e[0;93m\n"
        "   $$$$$\\  $$$$$$\\  $$\\   $$\\ $$$$$$$$\\ $$\\   $$\\ $$$$$$$\\   $$$$$$\\  \n"
        "   \\__$$ |$$  __$$\\ $$ | $$  |$$  _____|$$$\\  $$ |$$  __$$\\ $$  __$$\\ \n"
        "      $$ |$$ /  $$ |$$ |$$  / $$ |      $$$$\\ $$ |$$ |  $$ |$$ /  $$ |\n"
        "      $$ |$$ |  $$ |$$$$$  /  $$$$$\\    $$ $$\\$$ |$$$$$$$  |$$ |  $$ |\n"
        "$$\\   $$ |$$ |  $$ |$$  $$<   $$  __|   $$ \\$$$$ |$$  ____/ $$ |  $$ |\n"
        "$$ |  $$ |$$ |  $$ |$$ |\\$$\\  $$ |      $$ |\\$$$ |$$ |      $$ |  $$ |\n"
        "\\$$$$$$  | $$$$$$  |$$ | \\$$\\ $$$$$$$$\\ $$ | \\$$ |$$ |       $$$$$$  |\n"
        " \\______/  \\______/ \\__|  \\__|\\________|\\__|  \\__|\\__|       \\______/ \n"
        "\e[0m\n"
        "======================================================================\n"
    );
}

char * choice(int ch){
    switch (ch){
    case 1:
        return "Pedra";
    case 2:
        return "Papel";
    case 3:
        return "Tesoura";
    }
}

void jokenpo(){
    int wins[32], defeats[32], ties[32], rounds[32];
    int op, opE;
    clean();
    char game = 's';
    for (int p = 0; p <= 32; p++){
        if (game != 's'){break;}
        wins[p] = 0;
        defeats[p] = 0;
        ties[p] = 0;
        rounds[p] = 0;
        printf("\n\n");
        space();
        for(int g = 1; game == 's';g++){
            while (1){
                printf("Jogo %d:\n", g);
                printf("[0] Terminar\n[1] Pedra\n[2] Papel\n[3] Tesoura\nOpção: ");
                scanf("%d", &op);
                if (op < 0 || op > 3){
                    printf("Opção inválida! tente novamente\n");
                }
                else{break;}
            }
            if (op == 0){
                space();
                printf("Quer adicionar mais um jogador? [s] [n] ");
                scanf(" %c", &game);
                clean();
                rounds[p+1] = 0;
                break;
            }
            clean();
            opE = 1 +(rand() % 3);
            printf("        Você escolheu %s e o computador escolheu %s\n", choice(op), choice(opE));
            if (op == opE){
                printf("                                \e[4;33mEMPATE\n\e[0m");
                ties[p]++;
            }
            else if (op == (opE+1) || op == (opE-2)){
                printf("                                \e[4;32mVITÓRIA\n\e[0m");
                wins[p]++;
            }
            else {
                printf("                                \e[4;31mDERROTA\n\e[0m");
                defeats[p]++;
            }
            rounds[p]++;
            space();
        }
    }
    printf(
       "                                \e[4;37mPLACAR\e[0m                                \n"
       "======================================================================\n"
       " Nº | RODADAS | VITÓRIAS | DERROTAS | EMPATES | %% DE VITÓRIAS        \n"
       "----|---------|----------|----------|---------|-----------------------\n"
    );
    for (int i = 0;i <= 32; i++){
        if (rounds[i] == 0){break;}
        float percent = ((float)wins[i]/((float)defeats[i]+(float)wins[i]))*100;
        printf(" %2d | %7d | %8d | %8d | %7d | %.2f%%\n", i, rounds[i], wins[i], defeats[i], ties[i], percent);
    }
    space();
}

void main(){
    system("mode con:cols=71 lines=30");
    //system("color f0");
    setlocale(LC_ALL, "Portuguese");
    time_t t;
    srand((unsigned) time(&t));

    jokenpo();
}
