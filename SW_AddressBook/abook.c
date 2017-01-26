//
//  abook.c
//  SW_AddressBook
//
//  Created by WANGWENQIAN on 2017/01/26.
//  Copyright © 2017 WANGWENQIAN. All rights reserved.
//

#include "abook.h"

bool addrListClear(ADDR_DT *pList){
    int iCount;
    for (iCount = 0; iCount < 10; iCount++) {
        pList[iCount].iId = 0;
        pList[iCount].cName[0] = '\0';
        pList[iCount].cPCode[0] = '\0';
        pList[iCount].cAddr[0] = '\0';
        pList[iCount].cTel[0] = '\0';
    }
    
    
    
    return false;
}
