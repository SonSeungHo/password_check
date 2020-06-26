#include <stdio.h>
#include <ctype.h>

int main(){
    int charcount=0;
    int upper=0;
    int lower=0;
    int digits=0;
    int triple=0;
    int i;
    int symbols=0;
    int strength;
    char psw[20];
    printf("사용하실 암호를 입력해주세요.\n");
    scanf("%s", psw);
    
    do
    {
        strength=5;
        charcount=0;
        // 패스워드 길이 체크
        for (i = 0; psw[i]; i++)
        {
            charcount += 1;
        }
        if (charcount<8)
        {
            printf("패스워드는 최소 8자리 이상으로 입력해주세요.\n");

        }else if (charcount>20)
        {
            printf("패스워드는 20자 이상으로 입력하지 마세요.\n");

        }


        // 패스워드에 소문자와 대문자가 모두 포함되어있는지 확인
        for ( i = 0; psw[i]!='\0'; i++)
        {
            if (psw[i]>='A' && psw[i]<='Z')
            {
                upper++;
            }
            
            if (psw[i]>='a' && psw[i]<='z')
            {
                lower++;
            }
            
        }
        if (lower==0)
        {
            printf("패스워드에 알파벳 소문자를 포함해주시기 바랍니다.\n");
            strength--;
        }
        if (upper==0)
        {
            printf("패스워드에 알파벳 대문자를 포함해주시기 바랍니다.\n");
            strength--;
        }
        

        // 비밀번호에 숫자가 포함되어있는지 아닌지 확인
        for ( i = 0; psw[i]!='\0'; i++)
        {
            if (psw[i]>='0' && psw[i]<='9')
            {
                digits++;
            }
        }
        if (digits==0)
        {
            printf("패스워드에 최소한 숫자 1개 이상을 쓰시기 바랍니다.\n");
            strength--;
        }
        
        

        // 패스워드에 동일한 문자가 3개 이상 연속되는지를 확인
        triple=0;
        for ( i = 0; psw[i]!='\0'; i++)
        {
            if (psw[i]==psw[i+1] && psw[i+1]==psw[i+2])
            {
                triple++;
            }
            
        }
        
        if (triple!=0)
        {
            printf("패스워드에 동일한 문자를 3개 이상 붙여 쓰지마세요..)\n");
            strength--;
        }


        // 패스워드에 특수문자가 있는지 없는지 확인
        symbols=0;
        for ( i = 0; psw[i]!='\0'; i++)
        {
            if (ispunct(psw[i]))
            {
                symbols++;
            }
            
        }
        if (symbols==0)
        {
            printf("패스워드의 안전성을 위해 특수문자를 포함하는 것을 권고합니다.\n");
            strength--;
        }
        


        if(charcount<8 || charcount>20){
            printf("8자리 이상 20자리 이하로 패스워드를 입력해주시기 바랍니다.\n");
            scanf("%s", psw);
        }
    } while (charcount<8 || charcount>20);
    
    if (strength==5)
    {
        printf("축하합니다! 당신은 매우 강력한 패스워드를 만들어냈습니다!\n");
    }
    if (strength==4)
    {
        printf("당신의 패스워드는 비교적 안전합니다.\n");
    }
    if (strength==3)
    {
        printf("당신의 패스워드는 중간 수준으로 안전합니다.\n");
    }
    if (strength==2)
    {
        printf("당신의 패스워드는 비교적 안전하지 않습니다.\n");
    }
    if(strength==1)
    {
        printf("당신의 패스워드는 안전하지 않습니다.\n");
    }


    return 0;
}
