//
//  abook.h
//  SW_AddressBook
//
//  Created by WANGWENQIAN on 2017/01/26.
//  Copyright © 2017 WANGWENQIAN. All rights reserved.
//

#ifndef abook_h
#define abook_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef Debug
#define Debug
#endif

#define ARRAYSIZE(a) (sizeof(a)/sizeof(a[0]))
#define RECORDSIZE 10

typedef struct ADDR_DT{
    int iId;//id
    char cName[40];//name
    char cPCode[10];//post code
    char cAddr[100];//address
    char cTel[20];//tel number
} ADDR_DT;

bool showAllOf(ADDR_DT *);//show all records
bool showRecordOf(ADDR_DT *);//show record specified
bool clearAddrItem(ADDR_DT *);//clear address book
bool editRecordOf(ADDR_DT *);//edit item specified

bool dbgLoadTestData(ADDR_DT *);//load test data

#endif /* abook_h */
