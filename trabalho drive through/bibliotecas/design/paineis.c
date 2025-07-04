#include "colors.c"
#include "../functions/documentos.c"

void logo() {

        c_yel();

        printf("\n\n");

        printf("        ::::    :::: "); c_red(); printf(" :::::::::::"); c_yel(); printf(" :::::::: "); c_red(); printf(" :::    ::: :::::::::: :::   :::       :::::::          \n"); c_yel();
        printf("        +:+:+: :+:+:+"); c_red(); printf("     :+:    "); c_yel(); printf(":+:    :+:"); c_red(); printf(" :+:   :+:  :+:        :+:   :+:      :+:   :+:         \n"); c_yel();
        printf("        +:+ +:+:+ +:+"); c_red(); printf("     +:+    "); c_yel(); printf("+:+       "); c_red(); printf(" +:+  +:+   +:+         +:+ +:+        +:+ +:+          \n"); c_yel();
        printf("        +#+  +:+  +#+"); c_red(); printf("     +#+    "); c_yel(); printf("+#+       "); c_red(); printf(" +#++:++    +#++:++#     +#++:          +#++:  ++#      \n"); c_yel();
        printf("        +#+       +#+"); c_red(); printf("     +#+    "); c_yel(); printf("+#+       "); c_red(); printf(" +#+  +#+   +#+           +#+          +#+ +#+#+#       \n"); c_yel();
        printf("        #+#       #+#"); c_red(); printf("     #+#    "); c_yel(); printf("#+#    #+#"); c_red(); printf(" #+#   #+#  #+#           #+#         #+#   #+#+        \n"); c_yel();
        printf("        ###       ###"); c_red(); printf(" ###########"); c_yel(); printf(" ######## "); c_red(); printf(" ###    ### ##########    ###          ##########       \n"); c_yel();

        printf("\n");

        printf("                 :::::::::   ::::::::  ::::    :::     :::     :::        :::::::::                  \n");
        printf("                 :+:    :+: :+:    :+: :+:+:   :+:   :+: :+:   :+:        :+:    :+:                 \n");
        printf("                 +:+    +:+ +:+    +:+ :+:+:+  +:+  +:+   +:+  +:+        +:+    +:+                 \n");
        printf("                 +#+    +:+ +#+    +:+ +#+ +:+ +#+ +#++:++#++: +#+        +#+    +:+                 \n");
        printf("                 +#+    +#+ +#+    +#+ +#+  +#+#+# +#+     +#+ +#+        +#+    +#+                 \n");
        printf("                 #+#    #+# #+#    #+# #+#   #+#+# #+#     #+# #+#        #+#    #+#                 \n");
        printf("                 #########   ########  ###    #### ###     ### ########## #########                  \n");

}

void cardapio() {

        logo();
        c_white();

        printf("\n\n                              Seja Bem-Vindo! O que deseja pedir hoje?                               ");
        printf("\n\n\n");
        printf("   =  == ==================================== CARDAPIO ====================================== ==  =    \n");

        printf("\n     Minha Sacola: %s. Total a Pagar: R$ %.2f\n", sacola, totalPagamento);

        listProducts();

        printf("\n                              p. Pagar");
        printf("\n                              0. Sair");

        printf("\n\n\n");

}

void pagamento() {

        logo();
        c_white();

        printf("\n\n                            Otimas Escolhas! Como deseja pagar o pedido?                             ");
        printf("\n\n\n");
        printf("   =  == ==================================== PAGAMENTO ===================================== ==  =    \n");
        printf("\n     Minha Sacola: %s. Total a Pagar: R$ %.2f\n", sacola, totalPagamento);
        printf("\n                                        Metodos de Pagamento!\n");
        printf("                                        1. Dinheiro\n");
        printf("                                        2. Cartao de Credito\n");
        printf("                                        3. PIX\n");

        printf("\n                                        0. Cancelar\n");

}

void administrador() {

        logo();
        c_white();

        printf("\n\n                              Ola Administrador! O que deseja consultar?                             ");
        printf("\n\n\n");
        printf("   =  == ================================== ADMINISTRADOR =================================== ==  =    \n\n");

        printf("                                        1. Adicionar Produtos\n");
        printf("                                        2. Consultar Pagamentos\n");
        printf("                                        3. Consultar Cartoes\n");
        printf("                                        4. Consultar Fila\n");
        printf("                                        5. Desenfileirar\n");
        

        printf("\n                                        0. Voltar\n");

}