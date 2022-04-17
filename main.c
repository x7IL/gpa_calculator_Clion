#include <stdio.h>
#include <string.h>

unsigned char atoi(char *token);

// gcc main.c
// ./a.out "A,3" "B,2" "B,9" "E,5"
// ./a.out "D,20" "B,1" "C,2" | cat -e
// ./a.out "A,6" "E,6"
// ./a.out "D,1" "E,1000"
// ./a.out ; echo $?

char spe(char *tab){
    return tab[0];
}

int main(int argc, char ** argv) {
    if(argv[1] == NULL){
        return 84;
    }
    const char s[2] = ",";
    char *token;
    int tempSomme = 0;
    int tempDiv = 0;
    float somme = 0;
    for(int i = 1; i < argc; i++){
        token = strtok(argv[i], s);
        (spe(token) == 'A') ? (tempSomme = 4) : (spe(token) == 'B') ? (tempSomme = 3) : (spe(token) == 'C') ? (tempSomme = 2) : spe(token) ? (tempSomme = 0) : 0;
        token = strtok(NULL, s);
        somme += (tempSomme * atoi(token));
        tempDiv += atoi(token);
    }
    printf("%0.2f\n",somme/tempDiv);
    return 0;
}

