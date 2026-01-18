#include "Slist.h"
int main() {
    Slistnode* plist = NULL; 
    SlistPushBack(&plist, 1);
    SlistPushBack(&plist, 2);
    SlistPushBack(&plist, 3);
    SlistPrint(plist);  
    SlistPushFront(&plist, 0);
    SlistPrint(plist);  
    Slistnode* pos = SlistFind(plist, 2);
    SlistInsert(&plist, pos, 99);
    SlistPrint(plist); 
    SlistInsertAfter(&plist, pos, 100);
    SlistPrint(plist);  
    SlistErase(&plist, pos);
    SlistPrint(plist);  
    SlistPopFront(&plist);
    SlistPopBack(&plist);
    SlistPrint(plist); 
    SlistDestroy(&plist);
    return 0;
}
