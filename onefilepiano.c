#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

int has(int num, int nums[], int len) {
    for (int i = 0; i < len; i++) {
        if (nums[i] == num) return 1;
    }
    return 0;
}

int indexOf(int arr[], int findIndex, int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == findIndex) return i;
    }

    return -1;
}

float constructFrequency(int node, char *note) {
    float base = node, freq;

    if (note == "C") {
        freq = base * 0.5946;
    } else if (note == "C#") {
        freq = base * 0.6299;
    } else if (note == "D") {
        freq = base * 0.6674;
    } else if (note == "D#") {
        freq = base * 0.7071;
    } else if (note == "E") {
        freq = base * 0.7491;
    } else if (note == "F") {
        return base * 0.7937;
    } else if (note == "F#") {
        freq = base * 0.8408;
    } else if (note == "G") {
        freq = base * 0.8908;
    } else if (note == "G#") {
        freq = base * 0.9438;
    } else if (note == "A") {
        freq = base;
    } else if (note == "A#") {
        freq = base * 1.0594;
    } else if (note == "B") {
        freq = base * 1.1224;
    } else {
        freq = 0;
    }

    return freq;
}

float getFrequency(int keycode) {
    float frequency = 0;
    char *note = "Unknown";

    // white notes
    int c3[7] = {122, 120, 99, 118, 98, 110, 109};
    int c4[7] = {113, 119, 101, 114, 116, 121, 117};
    int c5[5] = {105, 111, 112, 91, 93};

    // back notes
    int c3f[5] = {115, 100, 103, 104, 106};
    int c4f[5] = {50, 51, 53, 54, 55};
    int c5f[3] = {57, 48, 61};

    char *wnotes[7] = {"C", "D", "E", "F", "G", "A", "B"};
    char *bnotes[7] = {"C#", "D#", "F#", "G#", "A#"};

    // black
    if (has(keycode, c3f, 5)) {
        int idx = indexOf(c3f, keycode, 5);

        frequency = constructFrequency(220, bnotes[idx]);
        note = bnotes[idx];
    } else if (has(keycode, c4f, 5)) {
        int idx = indexOf(c4f, keycode, 5);

        frequency = constructFrequency(440, bnotes[idx]);
        note = bnotes[idx];
    } else if (has(keycode, c5f, 3)) {
        int idx = indexOf(c5f, keycode, 3);

        frequency = constructFrequency(880, bnotes[idx]);
        note = bnotes[idx];
    }

    // white
    else if (has(keycode, c3, 7)) {
        int idx = indexOf(c3, keycode, 7);

        frequency = constructFrequency(220, wnotes[idx]);
        note = wnotes[idx];
    } else if (has(keycode, c4, 7)) {
        int idx = indexOf(c4, keycode, 7);

        frequency = constructFrequency(440, wnotes[idx]);
        note = wnotes[idx];
    } else if (has(keycode, c5, 5)) {
        int idx = indexOf(c5, keycode, 5);

        frequency = constructFrequency(880, wnotes[idx]);
        note = wnotes[idx];
    }

    return frequency;
}

int makeSound(int keycode, int dur) {
    float freq = getFrequency(keycode);
    if (freq < 1) return 0;
    
    return Beep(freq, dur);
}
 
void main() {
    int keycode, dur = 500;
    
    resetLabel:
    printf("\nEnter keypress duration in ms: ");
    scanf("%d", &dur);

    if (dur < 1) dur = 500;

    printf("\nApp started! Press ctrl+c to exit & ctrl+r to restart!\n\n");

    printf(" ___________________________________________________________________________ \n");
    printf("|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | |  |\n");
    printf("|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | |  |\n");
    printf("|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | |  |\n");
    printf("|  |S| |D|  |  |G| |H| |J|  |  |2| |3|  |  |5| |6| |7|  |  |9| |0|  |  |=|  |\n");
    printf("|  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_|  |\n");
    printf("|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |\n");
    printf("|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |\n");
    printf("| Z | X | C | V | B | N | M | Q | W | E | R | T | Y | U | I | O | P | [ | ] |\n");
    printf("|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|\n\n");

    while(1) {


        // close the program
        if (keycode == 3) break;

        // restart
        else if (keycode == 18) {
            keycode = 0;
            system("cls");
            goto resetLabel;
        }

        keycode = getch();

        // update some keys
        // white
        if (keycode == 44) keycode = 113;
        else if (keycode == 46) keycode = 119;
        else if (keycode == 47) keycode = 101;

        // black
        else if (keycode == 108) keycode = 50;
        else if (keycode == 59) keycode = 51;
        makeSound(keycode, dur);
    }
}