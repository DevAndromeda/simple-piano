#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include "frequency.h"

int makeSound(int keycode, int dur) {
    float freq = getFrequency(keycode);
    if (freq < 1) return 0;
    
    return Beep(freq, dur);
}
 
void main() {
    int keycode, dur = 500;
    
    printf("\nEnter keypress duration in ms: ");
    scanf("%d", &dur);

    if (dur < 1) dur = 500;

    printf("\nApp started! Press ctrl+c to exit!\n");

    while(1) {
        if (keycode == 3) break;
        keycode = getch();
        makeSound(keycode, dur);
    }
}