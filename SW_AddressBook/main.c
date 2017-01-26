//
//  main.c
//  SW_AddressBook
//
//  Created by WANGWENQIAN on 2017/01/26.
//  Copyright © 2017 WANGWENQIAN. All rights reserved.
//
//  住所録：連番、名前、郵便番号、住所、電話番号
//  address.binで保存、データ表示、修正、保存などできる
//


#include <stdlib.h>
#include <string.h>
#include "abook.h"

#define Debug


int main(int argc, const char * argv[]) {
    //define variables
    char cABookPath[100] = "/Users/Jerry/Desktop/CL14/SW_AddressBook/address.bin";
    ADDR_DT addrBook[10];
    FILE *pRecordFile;
    int iMenu;
    errno_t error;
    
    //open file process
    if ((error = fopen_s(&pRecordFile, cABookPath, "rb")) != 0) {
        addrListClear(addrBook);
    }
    
    //normal process
    
    //close file process
    
    
    
    printf("Hello, World!\n");
    return 0;
}
