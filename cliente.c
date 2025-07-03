#include <windows.h>
#include <stdio.h>



void c_yel(HANDLE hc) {
        SetConsoleTextAttribute(hc, FOREGROUND_RED | FOREGROUND_GREEN);
}

void c_red(HANDLE hc) {
        SetConsoleTextAttribute(hc, FOREGROUND_RED);
}

int main() {

    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    c_yel(hc);
    
    //SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);

    system("title MiCkey e DONALD");

    printf("::::    :::: "); c_red(hc); printf(" :::::::::::"); c_yel(hc); printf(" :::::::: "); c_red(hc); printf(" :::    ::: :::::::::: :::   :::       :::::::          \n"); c_yel(hc);
    printf("+:+:+: :+:+:+"); c_red(hc); printf("     :+:    "); c_yel(hc); printf(":+:    :+:"); c_red(hc); printf(" :+:   :+:  :+:        :+:   :+:      :+:   :+:         \n"); c_yel(hc);
    printf("+:+ +:+:+ +:+"); c_red(hc); printf("     +:+    "); c_yel(hc); printf("+:+       "); c_red(hc); printf(" +:+  +:+   +:+         +:+ +:+        +:+ +:+          \n"); c_yel(hc);
    printf("+#+  +:+  +#+"); c_red(hc); printf("     +#+    "); c_yel(hc); printf("+#+       "); c_red(hc); printf(" +#++:++    +#++:++#     +#++:          +#++:  ++#      \n"); c_yel(hc);
    printf("+#+       +#+"); c_red(hc); printf("     +#+    "); c_yel(hc); printf("+#+       "); c_red(hc); printf(" +#+  +#+   +#+           +#+          +#+ +#+#+#       \n"); c_yel(hc);
    printf("#+#       #+#"); c_red(hc); printf("     #+#    "); c_yel(hc); printf("#+#    #+#"); c_red(hc); printf(" #+#   #+#  #+#           #+#         #+#   #+#+        \n"); c_yel(hc);
    printf("###       ###"); c_red(hc); printf(" ###########"); c_yel(hc); printf(" ######## "); c_red(hc); printf(" ###    ### ##########    ###          ##########       \n"); c_yel(hc);

    printf("\n");

    printf(":::::::::   ::::::::  ::::    :::     :::     :::        :::::::::                         \n");
    printf(":+:    :+: :+:    :+: :+:+:   :+:   :+: :+:   :+:        :+:    :+:                        \n");
    printf("+:+    +:+ +:+    +:+ :+:+:+  +:+  +:+   +:+  +:+        +:+    +:+                        \n");
    printf("+#+    +:+ +#+    +:+ +#+ +:+ +#+ +#++:++#++: +#+        +#+    +:+                        \n");
    printf("+#+    +#+ +#+    +#+ +#+  +#+#+# +#+     +#+ +#+        +#+    +#+                        \n");
    printf("#+#    #+# #+#    #+# #+#   #+#+# #+#     #+# #+#        #+#    #+#                        \n");
    printf("#########   ########  ###    #### ###     ### ########## #########                         \n");
    getchar();

    return 0;
}