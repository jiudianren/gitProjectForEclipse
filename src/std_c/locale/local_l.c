#include <stdio.h>
#include <locale.h>

void main()
{
struct lconv *lv;
setlocale(LC_MONETARY,"en_GB");
lv=localeconv();
printf("Int_Curr_Symbol:%s\n",lv->int_curr_symbol);
printf("Currency_Symbol:%s\n",lv->currency_symbol);
printf("Point:%s\n",lv->decimal_point);


}