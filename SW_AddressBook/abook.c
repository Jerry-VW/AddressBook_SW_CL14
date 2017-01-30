//
//  abook.c
//  SW_AddressBook
//
//  Created by WANGWENQIAN on 2017/01/26.
//  Copyright © 2017 WANGWENQIAN. All rights reserved.
//

#include "abook.h"

bool showAllOf(ADDR_DT *pABook){
    printf("Showing all records:\n");
    printf("-------------------\n");
    for (int i = 0; i < 10; i++, pABook++) {
        printf("ID: %d\n", pABook -> iId);
        printf("Name: %s\n", pABook -> cName);
        printf("PostCode: %s\n", pABook -> cPCode);
        printf("Add: %s\n", pABook -> cAddr);
        printf("Tel: %s\n", pABook -> cTel);
        printf("-------------------\n");
    }
    //printf("Done.\n");
    return true;
}

bool showRecordOf(ADDR_DT *pABook){
    int iSelect;
    printf("Enter the ID of the record:\n>");
    scanf("%d", &iSelect);
    for (int i = 0; i < RECORDSIZE; i++) {
        if (pABook[i].iId == iSelect) {
            printf("Showing record:\n");
            printf("-------------------\n");
            printf("ID: %d\n", pABook[i].iId);
            printf("Name: %s\n", pABook[i].cName);
            printf("PostCode: %s\n", pABook[i].cPCode);
            printf("Add: %s\n", pABook[i].cAddr);
            printf("Tel: %s\n", pABook[i].cTel);
            printf("-------------------\n");
            return true;
        }
    }
    printf("No match record.\n");
    return false;
}

bool clearAddrItem(ADDR_DT *pABook){
    int iCount;
    for (iCount = 0; iCount < 10; iCount++) {
        pABook[iCount].iId = 0;
        pABook[iCount].cName[0] = '\0';
        pABook[iCount].cPCode[0] = '\0';
        pABook[iCount].cAddr[0] = '\0';
        pABook[iCount].cTel[0] = '\0';
    }
    
    return true;
}

bool editRecordOf(ADDR_DT *pABook){
    int iSelect;
    char cBuffer[100];
    
    printf("Enter the ID of the record:\n>");
    scanf("%d", &iSelect);
    for (int i = 0; i < RECORDSIZE; i++) {
        if (pABook[i].iId == iSelect) {
            printf("Editing record:\n");
            printf("-------------------\n");
//            printf("ID: %d -> ", pABook[i].iId);
//            scanf("%d", &(pABook[i].iId));
            printf("ID: %d\n", pABook[i].iId);
            printf("Name: %s -> ", pABook[i].cName);
            scanf("%s", cBuffer);
            strcpy(pABook[i].cName, cBuffer);
            fflush(stdin);
            printf("PostCode: %s ->", pABook[i].cPCode);
            scanf("%s", cBuffer);
            strcpy(pABook[i].cPCode, cBuffer);
            printf("Add: %s\n->", pABook[i].cAddr);
            scanf("%s", cBuffer);
            strcpy(pABook[i].cAddr, cBuffer);
            printf("Tel: %s ->", pABook[i].cTel);
            scanf("%s", cBuffer);
            strcpy(pABook[i].cTel, cBuffer);
            printf("-------------------\n");
            return true;
        }
    }
    printf("No match record.\n");
    return false;
}

#ifdef Debug
bool dbgLoadTestData(ADDR_DT *pABook){
    strcpy(pABook[0].cName, "BotJack");
    strcpy(pABook[1].cName, "BotLim");
    strcpy(pABook[2].cName, "BotKat");
    strcpy(pABook[3].cName, "BotDante");
    strcpy(pABook[4].cName, "BotMitchel");
    strcpy(pABook[5].cName, "BotJerry");
    strcpy(pABook[6].cName, "BotZoe");
    strcpy(pABook[7].cName, "BotLucy");
    strcpy(pABook[8].cName, "BotAda");
    strcpy(pABook[9].cName, "BotLeon");
    
    for (int i = 0; i < 10; i++, pABook++) {
        pABook -> iId = 1000 + i;
        strcpy(pABook -> cPCode, "150-0042");
        strcpy(pABook -> cAddr, "Shibuya");
        strcpy(pABook -> cTel, "030-0000-0012");
    }
    return true;
}
#endif
