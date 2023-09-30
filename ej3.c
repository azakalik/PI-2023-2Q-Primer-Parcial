#include <stdio.h>
#include <assert.h>

int isLetter(char c){
    return c >= 'a' && c <= 'z';
}

int anagrama(const char * string1, const char * string2){
    int letters['z' - 'a'] = {0};
    char c;
    for(int i = 0; (c = string1[i]) != '\0'; i++){
        if (isLetter(c))
            letters[c-'a']++;
    }
    for(int i = 0; (c = string2[i]) != '\0'; i++){
        if (isLetter(c))
            letters[c-'a']--;
    }
    for(int i = 0; i < ('z' - 'a'); i++){
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
}