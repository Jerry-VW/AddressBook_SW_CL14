//
//  main.c
//  SW_AddressBook
//
//  Created by WANGWENQIAN on 2017/01/26.
//  Copyright © 2017 WANGWENQIAN. All rights reserved.
//
//  住所録：連番、名前、郵便番号、住所、電話番号
//  address.binで保存、データ表示、修正などできる
//
// 所有文件相关处理在main.c，所有内容处理使用头文件

#include "abook.h"

//#define Debug
#define MAC 0 //platform switch
#define WIN 1
#define PLATFORM MAC

//define global variables
//for MAC only
#ifdef MAC
char cABookPath[100] = "/Users/Jerry/Desktop/CL14/SW_AddressBook/address.bin";
#endif
//for WIN only
#if PLATFORM == WIN
//for MSVC _s functions
errno_t error;
#endif

//funciton prototype
bool openFromFile(ADDR_DT *);
bool saveToFile(ADDR_DT *);

bool openFromFile(ADDR_DT *addrBook){
    //define variables
    FILE *pAddressBookFile;
    
    //Load address book from file
    //open file
#if PLATFORM == MAC
    if ((pAddressBookFile = fopen(cABookPath, "rb+")) == NULL) {
        printf("File opening error\n");
        exit(EXIT_FAILURE);
    }
#endif
#if PLATFORM == WIN
    if ((error = fopen_s(pAddressBook, "address.bin", "rb+")) != 0) {
        clearAddrItem(addrBook);
    }
#endif
    //load records
    fread(addrBook, sizeof(ADDR_DT), 10, pAddressBookFile);
    //close file
    if (fclose(pAddressBookFile) == EOF) {
        printf("File closing error.\n");
        exit(EXIT_FAILURE);
    }
    
    return true;
}

//SAVE address book back to file
bool saveToFile(ADDR_DT *addrBook){
    FILE *pAddressBookFile;
    ADDR_DT test;
    
    //open file in wb mode
#if PLATFORM == MAC
    if ((pAddressBookFile = fopen(cABookPath, "wb+")) == NULL) {
        printf("File opening error\n");
        exit(EXIT_FAILURE);
    }
#endif
#if PLATFORM == WIN
    if ((error = fopen_s(pAddressBook, "address.bin", "wb+")) != 0) {
        clearAddrItem(addrBook);
    }
#endif
    //write back
    for (int i = 0; i < RECORDSIZE; i++) {
        fwrite(&addrBook[i], sizeof(ADDR_DT), 1, pAddressBookFile);
    }
    
#ifdef Debug
    rewind(pAddressBookFile);
    fread(&test, sizeof(ADDR_DT), 1, pAddressBookFile);
    printf("Name of 1st record: %s\n",test.cName);
#endif
    
    //close file
    if (fclose(pAddressBookFile) == EOF) {
        printf("File closing error.\n");
        exit(EXIT_FAILURE);
    }

    return true;
}

int main(int argc, const char * argv[]) {
    //define variables
    ADDR_DT addrBook[10];
    int iSelect;
    
    clearAddrItem(addrBook);
    
    //load data
    //openFromFile(addrBook);
    
#ifdef Debug
    //Debug load test data
    //dbgLoadTestData(addrBook);
#endif
    
    //MAIN process <UI>
    while (1) {
        printf("====== Address Book ======\n[1].show all record\n[2].show 1 record\n[3].edit record\n[4].save to file\n[5].load from file\n[other].Exit\n");
        printf("Select funfion:\n>");
        scanf("%d", &iSelect);
#if PLATFORM == MAC
        system("clear");
#endif
#if PLATFORM == WIN
        system("cls");
#endif
        if ((iSelect < 1) || (iSelect > 5)) {
            break;
        }
        switch (iSelect) {
            case 1:
                //FUNCTION: SHOW ALL
                showAllOf(addrBook);
                break;
            case 2:
                //FUNCTION: SHOW ONE
                showRecordOf(addrBook);
                break;
            case 3:
                //FUNCTION: EDIT RECORD
                editRecordOf(addrBook);
                break;
            case 4:
                //FUNCTION: SAVE
                saveToFile(addrBook);
                break;
            case 5:
                //FUNCTION: LOAD
                openFromFile(addrBook);
                break;
            default:
                break;
        }
        printf("Done.\n");
    }
    printf("Good bye!\n");
    return 0;
}
