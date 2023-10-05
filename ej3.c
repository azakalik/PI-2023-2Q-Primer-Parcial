#include <stdio.h>
#include <assert.h>
#define LETTERS ('z' -'a')
#define CHARTONUM(c) (c-'a') //translates ascii letters to numbers 0-26

int isLetter(char c){
    return c >= 'a' && c <= 'z';
}

int anagrama(const char * string1, const char * string2){
    int letters[LETTERS] = {0};
    char c;
    for(int i = 0; (c = string1[i]) != '\0'; i++){
        if (isLetter(c))
            letters[CHARTONUM(c)]++;
    }
    for(int i = 0; (c = string2[i]) != '\0'; i++){
        if (isLetter(c))
            letters[CHARTONUM(c)]--;

        if (letters[CHARTONUM(c)] < 0) //si algun espacio tiene un valor negativo, ya se que no es un anagrama
            return 0;
    }
    for(int i = 0; i < (LETTERS); i++){
        if(letters[i] != 0)
            return 0;
    }
    return 1;
}

int main(){
    char * s = "anagrama";
    assert(anagrama(s, "amar gana"));
    assert(anagrama("enrique", "quieren"));
    assert(anagrama(s, s));
    assert(anagrama(" ", ""));
    assert(anagrama("amar gana", s));
    assert(anagrama("", ""));
    assert(anagrama("a gentleman", "elegant man"));
    assert(anagrama("a", "") == 0);
    assert(anagrama("mar", "amar") == 0);
    printf("OK\n");
}