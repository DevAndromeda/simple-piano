#include<stdio.h>

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
    } else if (note == "D") {
        freq = base * 0.6674;
    } else if (note == "E") {
        freq = base * 0.7491;
    } else if (note == "F") {
        return base * 0.7937;
    } else if (note == "G") {
        freq = base * 0.8908;
    } else if (note == "A") {
        freq = base;
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

    int c3[7] = {122, 120, 99, 118, 98, 110, 109};
    int c4[7] = {113, 119, 101, 114, 116, 121, 117};
    int c5[5] = {105, 111, 112, 91, 93};
    char *notes[7] = { "C", "D", "E", "F", "G", "A", "B" };

    if (has(keycode, c3, 7)) {
        int idx = indexOf(c3, keycode, 7);

        frequency = constructFrequency(220, notes[idx]);
        note = notes[idx];
    } else if (has(keycode, c4, 7)) {
        int idx = indexOf(c4, keycode, 7);

        frequency = constructFrequency(440, notes[idx]);
        note = notes[idx];
    } else if (has(keycode, c5, 5)) {
        int idx = indexOf(c5, keycode, 5);

        frequency = constructFrequency(880, notes[idx]);
        note = notes[idx];
    }
 
    printf("\nKey: %c\tKey Code: %d\tFrequency: %.2f\tDuration: 500ms\tNote: %s\n", keycode, keycode, frequency, note);
 
    return frequency;
}