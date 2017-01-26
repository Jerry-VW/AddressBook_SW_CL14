//
//  abook.h
//  SW_AddressBook
//
//  Created by WANGWENQIAN on 2017/01/26.
//  Copyright © 2017 WANGWENQIAN. All rights reserved.
//

#ifndef abook_h
#define abook_h

#include <stdio.h>
#include <stdbool.h>

typedef struct ADD_DT{
    int iId;
    char cName[40];
    char cPCode[10];
    char cAddr[100];
    char cTel[20];
} ADDR_DT;

bool addrListClear(ADDR_DT *);

#endif /* abook_h */
