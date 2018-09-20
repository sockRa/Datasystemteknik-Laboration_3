#include "strang.h"

int stringLenght(char* string){
    int counter = 0;
   
    do{
        string += CONST_FOUR_BYTE;
        counter++;

    }while(*string != '\0');
    
    return counter;
}

void stringCopy(char* stringOrg, char* stringNew){

   stringNew = stringOrg;

}

char* stringAdd(char* stringStart, char* stringEnd){
    int size = 0;
    int i = 0;
    size = stringLenght(stringStart) + stringLenght(stringEnd) + 1; //Size + 1 för radslut

    //Debug print
    printf("Size = %d",size);

    char *newString;
    
    newString = (char *) malloc(size);

    char *p = newString;
    char *s1 = stringStart;
    char *s2 = stringEnd;
    //Kopierar första strängen till newString
    size = stringLenght(stringStart);
    for(size=0;i<size;i++){

        *p = *s1;
        p += CONST_FOUR_BYTE;
        s1 += CONST_FOUR_BYTE;
    }
    //Kopierar andra strängen till newString
    i = 0;
    size = stringLenght(stringEnd);
    for(size=0;i<size;i++){

        *p = *s2;
        p += CONST_FOUR_BYTE;
        s2 += CONST_FOUR_BYTE;
    }

    // Add \0
    p += CONST_FOUR_BYTE;
    *p = '\0';
    
    return newString; 
}

int stringCompare(char* firstString, char* secoundString){

    int minLenght = 0;
    int i = 0;
    char* tempFirstString = stringLowerToUpper(firstString);
    char* tempSecoundString = stringLowerToUpper(secoundString);

    /*
    1. Hitta den kortaste strängen
    2. jämföra strängarna tecken för tecken
    3. om lika retunera 0
    4. 
    */
    if(stringLenght(firstString) <= stringLenght(secoundString)){
        
        minLenght = stringLenght(firstString);
    }else{
        
        minLenght = stringLenght(secoundString);
    }

    for(i=0;i<minLenght;i++){
        if(&tempFirstString != &tempSecoundString){
           if(&tempFirstString < &tempSecoundString){
               return 1;
           }else{
               return -1;
           }
           
        }
        tempFirstString += CONST_FOUR_BYTE;
        tempSecoundString += CONST_FOUR_BYTE;
    }

     if(stringLenght(firstString) < stringLenght(secoundString)){
        
        return 1;
    }else{
        return -1;
    }

}

char *stringLowerToUpper(char* string){
    /*
        1. kolla storlek på sträng
        2. Gör om sträng till uppercase
    */
  
    char* tempString = (char *) malloc(stringLenght(string));
    char *pTempString = tempString;
   int i = 0;
   char *p = string;
   for(i=0;i<stringLenght(string); i++){

      *pTempString = charLowerToUpper(*p);
      tempString += CONST_FOUR_BYTE;
       p += CONST_FOUR_BYTE;
   }
   return tempString;
}


char charLowerToUpper(char lower){

    //Kolla om det är en liten bokstav
    int lower_int = (int) lower;

    if((int)lower >= CONST_ASCII_a && (int)lower <= CONST_ASCII_z){

            lower = lower - CONST_ASCII_DIF;
            return (char) lower;

    }
    return lower;
}

char* stringReverse(char* string){
    
    char * tempString = (char*)malloc(stringLenght(string));
    char * pEnd = string + (CONST_FOUR_BYTE * stringLenght(string) - 1);
    int i;

    for(i=0;i<stringLenght(string);i++){

       * tempString = *pEnd;
       pEnd -= CONST_FOUR_BYTE;
    }

    return tempString;
}

char * stringShift(char* string, int userChoice){

    char * pEnd = string + (CONST_FOUR_BYTE * stringLenght(string) - 1);
    char temp = *string;

    if(userChoice == CONST_MENU_CHOICE_7){

    *string = * pEnd;

    }else{

    temp = *pEnd;
    *string = temp;
    }

    return string;
}



