#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
  
  char color_code[256];
  char c_c,y_n;
  int R=0,G=0,B=0,count=0,result=0,num=0,i=strlen(color_code),end=0,up_down=0;
  printf("16진수 컬러 코드값을 입력하세요 : ");
  scanf("%s", &color_code);


  for (int i = strlen(color_code) - 1; i >= 0; i--){
    char ch = color_code[i];
    if(count==2){
      B=result;
      result=0;
      num=0;
    }
    if(count==4){
      G=result;
      result=0;
      num=0;
    }
    if(count==6){
      R=result;
      result=0;
      num=0;
    }
    if (ch >= 48 && ch <= 57){
      result += (ch - 48) * pow(16, num);
        }
    else if (ch >= 65 && ch <= 70){
      result += (ch - (65 - 10)) * pow(16, num);
        }
    else if (ch >= 97 && ch <= 102){
      result += (ch - (97 - 10)) * pow(16, num);
        }

    num++;
    count += 1;
    }

  printf("입력한 컬러의 R,G,B 값은(%d, %d, %d)입니다.\n\n", R,G,B);

  
  while(end==0){
    printf("RGB 중 변경할 컬러 채널을 입력하세요 : ");
    scanf(" %c",&c_c);
    if(c_c=='R' || c_c=='r' || c_c=='G' || c_c=='g'  || c_c=='B' || c_c=='b'){
      printf("%c 채널의 증감 정도를 입력하세요 : ",c_c);
      scanf(" %d", &up_down);
      end+=1;

      if(c_c=='R' || c_c=='r'){
        R += up_down;
        if(R>255)
          R=255;
        if(R<0)
          R=0;
        }
      
      if(c_c=='G' || c_c=='g'){
        G += up_down;
        if(G>255)
          G=255;
        if(G<0)
          G=0;
        }
        
      if(c_c=='B' || c_c=='b'){
        B += up_down;
        if(B>255)
          B=255;
        if(B<0)
          B=0;
        }
      }
    else{
      printf("잘못 입력하셨습니다. 다시 입력하세요.\n\n");
    }
    if(end==1){
      
      printf("조정된 컬러의 R,G,B 값은 (%d, %d, %d)이고, 이는 0x%X%X%X 로 저장됩니다.\n",R, G, B, R, G, B);
      printf("계속 컬러를 조정하시겠습니까? (y/n) : ");
      scanf(" %c", &y_n);
      
      if(y_n =='Y' || y_n =='y'){
        end=0;
      } 
    }
  }

  
  return 0;
}