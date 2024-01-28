#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#define BLUE "\x1b[34m"
#define DEF "\x1b[0m"
#define WHITE_BG  "\x1b[47m"
#define BLACK_TXT "\x1b[30m"
void logic();
void menu()
{
    printf(BLUE);
    printf("[0] Quit\n");
    printf("[1] Calendar\n");
    printf("[2] Age\n");
    printf("[3] Conversion\n");
    printf(DEF);
    printf("----------------------\n");
    printf("Select Option: \n");
}
long shamsi_to_gregorian(long shamsi_year, long shamsi_month, long shamsi_day, long out[]) {
  shamsi_year += 1595;
  long days = -355668 + (365 * shamsi_year) + (((int)(shamsi_year / 33)) * 8) + ((int)(((shamsi_year % 33) + 3) / 4)) + shamsi_day + ((shamsi_month < 7) ? (shamsi_month - 1) * 31 : ((shamsi_month - 7) * 30) + 186);
  long miladi_year = 400 * ((int)(days / 146097));
  days %= 146097;
  if (days > 36524) {
    miladi_year += 100 * ((int)(--days / 36524));
    days %= 36524;
    if (days >= 365) days++;
  }
  miladi_year += 4 * ((int)(days / 1461));
  days %= 1461;
  if (days > 365) {
    miladi_year += (int)((days - 1) / 365);
    days = (days - 1) % 365;
  }
  long miladi_day = days + 1;
  long miladi_month;
  {
    long sal_a[13] = {0, 31, ((miladi_year % 4 == 0 && miladi_year % 100 != 0) || (miladi_year % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (miladi_month = 0; miladi_month < 13 && miladi_day > sal_a[miladi_month]; miladi_month++) miladi_day -= sal_a[miladi_month];
  }
  out[0] = miladi_year;
  out[1] = miladi_month;
  out[2] = miladi_day;
  return out;
}
void taghvim()
{
    int year, month;
    printf("[0] Back To Menu\n----------------\n");
    printf("enter year:");
    scanf("%d", &year);
    if(year == 0)
    {
        logic();
    }
    if (year < 1206 || year > 1484)

    {
    system("cls");
    printf("\aInvalid input! enter 1 to try again\n");
    int enter;
    scanf("%d", &enter);
    if (enter == 1)
    {
        logic();
    }
    }
    printf("enter month:");
    scanf("%d", &month);
    while(month>12 || month<1)

    {

        system("cls");
    printf("\aInvalid input! enter 1 to try again\n");
    int enter;
    scanf("%d", &enter);
    if (enter == 1)
    {
        logic();
    }
break;
    }
    system("cls");
    int c = 0;           // محاسبه تعداد روز ها
    int a = year - 1206; // محاسبه تعداد سال
    int tedadrooz;
    printf(WHITE_BG);
    printf(BLACK_TXT);
    if (month == 1)
    {
        printf("        Farvardin         \n");
    }
    else if (month == 2)
    {
        printf("        Ordibehesht       \n");
    }
    else if (month == 3)
    {
        printf("          Khordad         \n");
    }
    else if (month == 4)
    {
        printf("           Tir            \n");
    }
    else if (month == 5)
    {
        printf("          Mordad          \n");
    }
    else if (month == 6)
    {
        printf("        Shahrivar         \n");
    }
    else if (month == 7)
    {
        printf("           Mehr           \n");
    }
    else if (month == 8)
    {
        printf("           Aban           \n");
    }
    else if (month == 9)
    {
        printf("           Azar           \n");
    }
    else if (month == 10)
    {
        printf("           Dey            \n");
    }
    else if (month == 11)
    {
        printf("          Bahman          \n");
    }
    else if (month == 12)
    {
        printf("          Esfand         \n");
    }
    printf(DEF);
    printf(DEF);
    printf("SH  YE  DO  SE  CH  PA  JO\n");
    if (month == 1 || month == 2 || month == 3 || month == 4 || month == 5 || month == 6)
    {
        tedadrooz = 31;
        c = month * 31;
    }
    else if (month == 7 || month == 8 || month == 9 || month == 10 || month == 11)
    {
        c += 186;
        c += (month - 7) * 30;
        tedadrooz = 30;
    }
    else if (month == 12)
    {
        c += 336;
        tedadrooz = 29;
    }
    for (int i = 1207; i < year; i++)
    {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
        {
            c += 366;
        }
        else
        {
            c += 365;
        }
        c += 364; // bara sal 1206
    }
    if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && month == 12)
        tedadrooz++;
    c %= 7; // روز شروع
    if (year == 1206) c--; // شروع نمایش اعداد روی تقویم
    int daycounter = 1;
    for (int v = 0; v < 6; v++)
    {
        for (int x = 0; x < 7; x++)
        {

            if (v == 0 && x < c)
            {
                printf("    ");
            }
            else if (daycounter <= tedadrooz)
            {
                if (daycounter >= 10)
                    printf("%d  ", daycounter);
                if (daycounter < 10)
                    printf(" %d  ", daycounter);
                daycounter++;
            }
        }
        printf("\n");
        if (daycounter > tedadrooz)
        {
            break;
        }
    }
    printf("\n");
    printf("----------------\n");
    int nextmonth;
    int day_in_month;
    printf("enter a day:");
    scanf("%d",&day_in_month);
    if((c+day_in_month)%7==0) printf("%d is jomeh\n",day_in_month);
        if((c+day_in_month)%7==1) printf("%d is shanbe\n",day_in_month);
    if((c+day_in_month)%7==2) printf("%d is yekSHANBE\n",day_in_month);
    if((c+day_in_month)%7==3) printf("%d is doshanbe\n",day_in_month);
    if((c+day_in_month)%7==4) printf("%d is seshanbe\n",day_in_month);
    if((c+day_in_month)%7==5) printf("%d is chaharshanbe\n",day_in_month);
    if((c+day_in_month)%7==6) printf("%d is panjshanbe\n",day_in_month);

    printf("enter 1 to see next month : ");
    scanf("%d",&nextmonth);
    while(nextmonth==1) {
    int month2=month+1;
    int year2=year;
    showcal(year2,month2);
    break;
    }


    taghvim(year , month);
}
void showcal(int year,int month)
{

    int c = 0;           // محاسبه تعداد روز ها
    int a = year - 1206; // محاسبه تعداد سال
    int tedadrooz;
    printf(WHITE_BG);
    printf(BLACK_TXT);
    if (month == 1)
    {
        printf("        Farvardin         \n");
    }
    else if (month == 2)
    {
        printf("        Ordibehesht       \n");
    }
    else if (month == 3)
    {
        printf("          Khordad         \n");
    }
    else if (month == 4)
    {
        printf("           Tir            \n");
    }
    else if (month == 5)
    {
        printf("          Mordad          \n");
    }
    else if (month == 6)
    {
        printf("        Shahrivar         \n");
    }
    else if (month == 7)
    {
        printf("           Mehr           \n");
    }
    else if (month == 8)
    {
        printf("           Aban           \n");
    }
    else if (month == 9)
    {
        printf("           Azar           \n");
    }
    else if (month == 10)
    {
        printf("           Dey            \n");
    }
    else if (month == 11)
    {
        printf("          Bahman          \n");
    }
    else if (month == 12)
    {
        printf("          Esfand         \n");
    }
    printf(DEF);
    printf(DEF);
    printf("SH  YE  DO  SE  CH  PA  JO\n");
    if (month == 1 || month == 2 || month == 3 || month == 4 || month == 5 || month == 6)
    {
        tedadrooz = 31;
        c = month * 31;
    }
    else if (month == 7 || month == 8 || month == 9 || month == 10 || month == 11)
    {
        c += 186;
        c += (month - 7) * 30;
        tedadrooz = 30;
    }
    else if (month == 12)
    {
        c += 336;
        tedadrooz = 29;
    }
    for (int i = 1207; i < year; i++)
    {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
        {
            c += 366;
        }
        else
        {
            c += 365;
        }
        c += 364; // bara sal 1206
    }
    if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && month == 12)
        tedadrooz++;
    c %= 7; // روز شروع
    if (year % 5 == 0)
        c++;
    if (month >= 1 && month <= 6)
    {
        c += 3;
        if (c > 6)
        {
            c--;
        }
    }
    if (month > 6 && month <= 11)
    {
        c += 4;
        if (c > 6)
            c -= 6;
    }
    if (month == 12)
    {
        c += 4;
        if (c > 6)
            c -= 6;
    }
    if (year == 1206)
        c--; // شروع نمایش اعداد روی تقویم
    int daycounter = 1;
    for (int v = 0; v < 6; v++)
    {
        for (int x = 0; x < 7; x++)
        {

            if (v == 0 && x < c)
            {
                printf("    ");
            }
            else if (daycounter <= tedadrooz)
            {
                if (daycounter >= 10)
                    printf("%d  ", daycounter);
                if (daycounter < 10)
                    printf(" %d  ", daycounter);
                    daycounter++;
            }
        }
        printf("\n");
        if (daycounter > tedadrooz)
        {
            break;
        }
    }
}
void mohasebesen()
{
    printf("[0] Back To Menu\n----------------\n");
    int nyear, nmonth, nday; // n mokhafaf now
    printf("Enter today's date(start with year):\n");
    scanf("%d", &nyear);
    if (nyear == 0)
        logic();
    scanf("%d"
          "%d",
          &nmonth, &nday);
          if(nmonth>12 || nday<1 || nday>31 || nmonth<1 || nyear!=1402)
          {
    system("cls");
    printf("\aInvalid input! enter 1 to try again\n");
    int enter;
    scanf("%d", &enter);
    if (enter == 1)
    {
        logic();
    }

          }
    printf("Enter your birthday(start with year):\n");
    int byear, bmonth, bday; // b mokhafaf birthday
    scanf("%d"
          "%d"
          "%d",
          &byear, &bmonth, &bday);
          if(byear==0) logic();
          if(byear<1300 || byear>1402 || bmonth>12 ||bmonth<1 ||bday>31 ||bday<1)
          {
    system("cls");
    printf("\aInvalid input! enter 1 to try again\n");
    int enter;
    scanf("%d", &enter);
    if (enter == 1)
    {
        logic();
    }
          }
    int oyear = nyear - byear; // o mokhafaf omr
    int omonth;
    if (nmonth >= bmonth)
    {
        omonth = nmonth - bmonth;
        if (omonth == -1)
            omonth = 0;
    }
    else if (nmonth < bmonth)
    {
        omonth = (12 - bmonth) + nmonth;
        oyear--;
    }
    int odays;
    if (nmonth <= 6)
    {
        if (nday >= bday)
        {
            odays = nday - bday;
        }
        else if (nday < bday)
        {
            odays = (31 - nday) + bday;
            omonth--;
        }
    }
    else if (nmonth > 6)
    {
        if (nday >= bday)
        {
            odays = nday - bday;
        }
        else if (nday < bday)
        {
            odays = (30 - bday) + nday + 1;
            omonth--;
        }
    }
    if (nmonth > 6 && odays == 31)
    {
        odays--;
    }

    int omrberoz = oyear * 365 + odays + omonth * 31;
    for (int i = 1206; i < byear; i++)
    {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
        {
            omrberoz++;
        }
    }
    printf("you lived %d year , %d month , %d days", oyear, omonth, odays);
    printf("\nrooz haye gozashte az omr shoma : %d", omrberoz);
    // از یک فروردین سال 1300 شروع میکنیم برای تقویم نگاری
    if (byear > 1402 && byear < 1300)
    {

    system("cls");
    printf("\aInvalid input! enter 1 to try again\n");
    int enter;
    scanf("%d", &enter);
    if (enter == 1)
    {
        logic();
    }
    }
    int tedadrooz = 0;
    for (int i = 1206; i < byear; i++)
    {
        if (byear % 4 == 0 && byear % 100 != 0 || byear % 400 == 0)
        {
            tedadrooz += 366;
        }
        else
        {
            tedadrooz += 365;
        }
    }
    if (bmonth == 1 || bmonth == 2 || bmonth == 3 || bmonth == 4 || bmonth == 5 || bmonth == 6)
    {
        tedadrooz += bmonth * 31;
    }
    else if (bmonth == 7 || bmonth == 8 || bmonth == 9 || bmonth == 10 || bmonth == 11)
    {
        tedadrooz += 186;
        tedadrooz += (bmonth - 7) * 30;
    }

    int rooz = (tedadrooz + bday + 1) % 7;
    if (rooz == 0)
        printf("\n Your birthday was in Panjshanbe");
    if (rooz == 1)
        printf("\n Your birthday was in Jomeh");
    if (rooz == 2)
        printf("\n Your birthday was in shanbe");
    if (rooz == 3)
        printf("\n Your birthday was in Yekshanbe");
    if (rooz == 4)
        printf("\n Your birthday was in Doshanbe");
    if (rooz == 5)
        printf("\n Your birthday was in Seshanbe");
    if (rooz == 6)
        printf("\n Your birthday was in Chaharshanbe");
    printf("\n");
    printf("----------------\n");
    mohasebesen();
}
void tabdiltarikh()
{
    long y_in,m_in,d_in,ymd_out[3];
    printf("\n----------------\n[0] Back To Menu\n----------------\n");
    int options;
    printf("[1] baraye tabdil miladi be ghamari\n[2] baraye tabdil shamsi be miladi va ghamari\nselect option : ");
    scanf("%d",&options);
    if(options==0) logic();
    if(options==1)
    {
        printf("enter year : ");
        scanf("%ld",&y_in);
        printf("enter month : ");
        scanf("%ld",&m_in);
        printf("enter day : ");
        scanf("%ld",&d_in);

    }
    if(options==2)
    {
        printf("enter year : ");
        scanf("%ld",&y_in);
        if(y_in==0) logic();
        if(y_in<0) {
                system("cls");
    printf("\aInvalid input! enter 1 to try again\n");
    int enter;
    scanf("%d", &enter);
    if (enter == 1)
    {
        logic();
    }
        }
        printf("enter month : ");
        scanf("%ld",&m_in);
        if(m_in>12 || m_in < 1)
        {
                system("cls");
    printf("\aInvalid input! enter 1 to try again\n");
    int enter;
    scanf("%d", &enter);
    if (enter == 1)
    {
        logic();
    }
        }
        printf("enter day : ");
        scanf("%ld",&d_in);
        if(d_in>31 || d_in<1)
        {
                system("cls");
    printf("\aInvalid input! enter 1 to try again\n");
    int enter;
    scanf("%d", &enter);
    if (enter == 1)
    {
        logic();
    }
        }
        shamsi_to_gregorian(y_in,m_in,d_in,ymd_out);
        printf("miladi : %d/%d/%d",ymd_out[0],ymd_out[1],ymd_out[2]);
    }
    if(options>2 ||options<0)
    {
    system("cls");
    printf("\aInvalid input! enter 1 to try again\n");
    int enter;
    scanf("%d", &enter);
    if (enter == 1)
    {
        logic();
    }
    }

    if(options==2 || options==1) tabdiltarikh();
}
void logic()
{
    system("cls");
    menu();
    int gozine;
    scanf("%d", &gozine);
    system("cls");
    if (gozine == 1)
    {
        taghvim();
    }
    else if (gozine == 2)
    {
        mohasebesen();
    }
    else if (gozine == 3)
    {
        tabdiltarikh();
    }
    if (gozine == 0)
    {
        system("cls");
        printf("Bye!");
        close(0);
    }
    if (gozine > 3 || gozine < 0)
    {
    system("cls");
    printf("\aInvalid input! enter 1 to try again\n");
    int enter;
    scanf("%d", &enter);
    if (enter == 1)
    {
        logic();
    }
    }
}
int close(int)
{
    return 0;
}
int main()
{
    logic();
}
