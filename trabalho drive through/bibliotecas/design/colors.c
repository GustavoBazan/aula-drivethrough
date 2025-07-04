#include "../default.c"

HANDLE hc;

void c_white() {
        SetConsoleTextAttribute(hc, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void c_yel() {
        SetConsoleTextAttribute(hc, FOREGROUND_RED | FOREGROUND_GREEN);
}

void c_red() {
        SetConsoleTextAttribute(hc, FOREGROUND_RED);
}

void c_green() {
        SetConsoleTextAttribute(hc, FOREGROUND_GREEN);
}

void c_blue() {
        SetConsoleTextAttribute(hc, FOREGROUND_BLUE);
}

void c_purple() {
        SetConsoleTextAttribute(hc, FOREGROUND_BLUE | FOREGROUND_RED);
}