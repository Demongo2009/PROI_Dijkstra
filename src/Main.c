#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <wchar.h>
#include <locale.h>
#include <math.h>


uint64_t hashFunction(wchar_t str[]){
  uint64_t hash=0;
  int positionCounter=0;
  int countDown=0;
  while(str&&(*str)!='\0'){
    hash += (((*str)) * pow(229,positionCounter));
    // hash += 15487429;
    if(positionCounter>5){
      countDown=1;
    }
    if(positionCounter<3){
      countDown=0;
    }
    if(countDown){
      --positionCounter;
    }else{
      ++positionCounter;
    }
    ++str;
  }
  return hash;
}

//229
int main(void){
  // setlocale(LC_ALL,"en_US.utf8");
  printf("%d\n", 'ą');
  printf("%d\n", 'ć');
  printf("%d\n", 'ę');
  printf("%d\n", 'ł');
  printf("%d\n", 'ń');
  printf("%d\n", 'ó');
  printf("%d\n", 'ś');
  printf("%d\n", 'ź');
  printf("%d\n", 'ż');

  wchar_t str[50] = L"Żrafa fa wysoka jest jak żółć";
  wchar_t strPL[200] = L"Zażółć gęślą jaźń";

  uint64_t hashed = hashFunction(strPL);
  printf("%" PRIu64 "\n", hashed);
}
