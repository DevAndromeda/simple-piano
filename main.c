#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include "frequency.h"

int makeSound(int keycode) {
    float freq = getFrequency(keycode);
    if (freq < 1) return 0;
    
    return Beep(freq, 500);
}
 
void main() {
    int keycode;
 
    printf("\nApp started! Press ctrl+c to exit!\n");
 
    while(1) {
        if (keycode == 3) break;
        keycode = getch();
        makeSound(keycode);
    }
}