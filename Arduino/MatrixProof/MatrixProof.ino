#include "LedControl.h"
#define iterationDelay 500

LedControl lc = LedControl(11,13,10,6);//(Pin digital, Pin reloj, Pin CS, No de dispositivos) -> (DIN,CLK,CS,1-8)

byte screen1[8] = {
  B00000000,
  B00000000, 
  B00000000,   
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000  
};

byte screen2[8] = {
  B00000000,
  B00000000, 
  B00000000,   
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000  
};

byte screen3[8] = {
  B00000000,
  B00000000, 
  B00000000,   
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000  
};

byte screen4[8] = {
  B00000000,
  B00000000, 
  B00000000,   
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000  
};

byte screen5[8] = {
  B00000000,
  B00000000, 
  B00000000,   
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000  
};

byte screen6[8] = {
  B00000000,
  B00000000, 
  B00000000,   
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000  
};

byte hA[8] = {
  B00000000,
  B11111111, 
  B11111111,   
  B10000000,
  B10000000,
  B11111111,
  B11111111,
  B00000000  
};

byte hB[8] = {
  B00000000,
  B11111111, 
  B11111111,  
  B00000001,
  B00000001,
  B11111111,
  B11111111,
  B00000000  
};

byte oA[8] = {
  B00000000,
  B11111100, 
  B00111110,   
  B00000111,
  B00000111,
  B00111110,
  B11111100,
  B00000000  
};

byte oB[8] = {
  B00000000,
  B00111111, 
  B01111100,   
  B11100000,
  B11100000,
  B01111100,
  B00111111,
  B00000000  
};

byte lA[8] = {
  B00000000,
  B11111111, 
  B11111111,   
  B11111111,
  B00000000,
  B00000000,
  B00000000,
  B00000000  
};

byte lB[8] = {
  B00000000,
  B11111111, 
  B11111111,   
  B11111111,
  B11100000,
  B11100000,
  B11100000,
  B00000000  
};

byte aA[8] = {
  B00000000,
  B11111000, 
  B11111111,   
  B10000111,
  B10000111,
  B11111111,
  B11111000,
  B00000000  
};

byte aB[8] = {
  B00000000,
  B11111111,
  B11111111,  
  B00000011,
  B00000011,
  B11111111,
  B11111111,
  B00000000  
};

byte dosA[8] = {
  B0111100,
  B01111110, 
  B00001111,   
  B00000111,
  B10001111,
  B11111100,
  B01111100,
  B00000000
};

byte dosB[8] = {
  B11100000,
  B11100000, 
  B11111000,   
  B11111110,
  B11100111,
  B11100001,
  B11100000,
  B00000000
};

byte tresA[8] = {
  B0111100,
  B01111110, 
  B00001111,   
  B00000111,
  B10001111,
  B11111100,
  B01111100,
  B00000000
};

byte tresB[8] = {
  B00011110,
  B01111110, 
  B11110000,   
  B11100000,
  B11110001,
  B00111111,
  B00111110,
  B00000000  
};

byte completeTextA[50];
byte completeTextB[50];
byte screenAux1[50];
byte screenAux2[50];
byte screenAux3[50];
byte screenAux4[50];
byte screenAux5[50];
byte screenAux6[50];
int sizeFilled = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 6; i++){
    lc.shutdown(i,false);//(No de dispositivo, estado inicial)
    lc.setIntensity(i,4);//(No de dispositivo, intensidad de luz)
    lc.clearDisplay(i);//(No de dispositivo a limpiar)
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  fill();
}

void fill(){
  for(int i = 0; i < 4; i++){
    if(i == 0){
      for(int j = 0; j < 8; j++){
        completeTextA[sizeFilled] = hA[j];
        screenAux1[sizeFilled] = hA[j];
        screenAux2[sizeFilled] = hA[j];
        screenAux3[sizeFilled] = hA[j];

        completeTextB[sizeFilled] = hB[j];
        screenAux4[sizeFilled] = hB[j];
        screenAux5[sizeFilled] = hB[j];
        screenAux6[sizeFilled] = hB[j];
        sizeFilled++;
      }
    }
    else if(i == 1){
      for(int j = 0; j < 8; j++){
        completeTextA[sizeFilled] = oA[j];
        screenAux1[sizeFilled] = oA[j];
        screenAux2[sizeFilled] = oA[j];
        screenAux3[sizeFilled] = oA[j];

        completeTextB[sizeFilled] = oB[j];
        screenAux4[sizeFilled] = oB[j];
        screenAux5[sizeFilled] = oB[j];
        screenAux6[sizeFilled] = oB[j];
        sizeFilled++;
      }
    }
    else if(i == 2){
      for(int j = 0; j < 8; j++){
        completeTextA[sizeFilled] = lA[j];
        screenAux1[sizeFilled] = lA[j];
        screenAux2[sizeFilled] = lA[j];
        screenAux3[sizeFilled] = lA[j];

        completeTextB[sizeFilled] = lB[j];
        screenAux4[sizeFilled] = lB[j];
        screenAux5[sizeFilled] = lB[j];
        screenAux6[sizeFilled] = lB[j];
        sizeFilled++;
      }
    }
    else if(i == 3){
      for(int j = 0; j < 8; j++){
        completeTextA[sizeFilled] = aA[j];
        screenAux1[sizeFilled] = aA[j];
        screenAux2[sizeFilled] = aA[j];
        screenAux3[sizeFilled] = aA[j];

        completeTextB[sizeFilled] = aB[j];
        screenAux4[sizeFilled] = aB[j];
        screenAux5[sizeFilled] = aB[j];
        screenAux6[sizeFilled] = aB[j];
        sizeFilled++;
      }
    }
  }
  animateText();
}

void animateText(){
  int sizeCompleteText = sizeof(completeTextA)/sizeof(completeTextA[0]);
  for(int i = 0; i < 32; i++){
    //Mostrar matriz 
    for(int j = 0; j < 8; j++){ 
      lc.setRow(0,j,screen1[j]);//(No de dispositivo, fila, valor)
      lc.setRow(1,j,screen2[j]);//(No de dispositivo, fila, valor)
      lc.setRow(2,j,screen3[j]);//(No de dispositivo, fila, valor)
      lc.setRow(3,j,screen4[j]);//(No de dispositivo, fila, valor)
      lc.setRow(4,j,screen5[j]);//(No de dispositivo, fila, valor)
      lc.setRow(5,j,screen6[j]);//(No de dispositivo, fila, valor)
    }
    
    //Desplazamiento
    for(int j = 0; j < 8; j++){
      if(j < 7){
        screen1[j] = screen1[j+1];
        screen4[j] = screen4[j+1];
      }else{
        screen1[j] = screenAux1[0];
        screen4[j] = screenAux4[0];
        for(int k = 0; k < sizeCompleteText; k++){
          screenAux1[k] = screenAux1[k+1];
          screenAux4[k] = screenAux4[k+1];
        }
      }
    }
    if(i > 7){
      for(int j = 0; j < 8; j++){
        if(j < 7){
          screen2[j] = screen2[j+1];
          screen5[j] = screen5[j+1];
        }else{
          screen2[j] = screenAux2[0];
          screen5[j] = screenAux5[0];
          for(int k = 0; k < sizeCompleteText; k++){
            screenAux2[k] = screenAux2[k+1];
            screenAux5[k] = screenAux5[k+1];
          }
        }
      }
    }
    if(i > 14){
      for(int j = 0; j < 8; j++){
        if(j < 7){
          screen3[j] = screen3[j+1];
          screen6[j] = screen6[j+1];
        }else{
          screen3[j] = screenAux3[0];
          screen6[j] = screenAux6[0];
          for(int k = 0; k < sizeCompleteText; k++){
            screenAux3[k] = screenAux3[k+1];
            screenAux6[k] = screenAux6[k+1];
          }
        }
      }
    }  
    delay(iterationDelay);  
  }
}

/*void animateText(){
  for(int i = 0; i < 32; i++){
    for(int j = 0; j < 8; j++){
      if(i < 8){screen1[j] = completeText[j] >> 7-i;}
      else{screen1[j] = completeText[j] << i-7;}
      lc.setRow(0,j,screen1[j]);//(No de dispositivo, fila, valor)
    }
    if(i > 8){
      for(int j = 0; j < 8; j++){
        if(i < 16){screen2[j] = completeText[j] >> 15-i;}
        else{screen2[j] = completeText[j] << i-15;}
        lc.setRow(1,j,screen2[j]);//(No de dispositivo, fila, valor)
      }
    }
    if(i > 16){
      for(int j = 0; j < 8; j++){
        if(i < 24){screen3[j] = completeText[j] >> 23-i;}
        else{screen3[j] = completeText[j] << i-23;}
        lc.setRow(2,j,screen3[j]);//(No de dispositivo, fila, valor)
      }
    }    
    delay(demora);    
  } 
}*/

/*void animate_0(){
  for(int i = 0; i < 32; i++){
    for(int j = 0; j < 8; j++){
      if(i < 8){aux[j] = cero[j] >> 7-i;}
      else{aux[j] = cero[j] << i-7;}
      lc.setRow(0,j,aux[j]);//(No de dispositivo, fila, valor)
    }
    if(i > 8){
      for(int j = 0; j < 8; j++){
        if(i < 16){aux2[j] = cero[j] >> 15-i;}
        else{aux2[j] = cero[j] << i-15;}
        lc.setRow(1,j,aux2[j]);//(No de dispositivo, fila, valor)
      }
    }
    if(i > 16){
      for(int j = 0; j < 8; j++){
        if(i < 24){aux3[j] = cero[j] >> 23-i;}
        else{aux3[j] = cero[j] << i-23;}
        lc.setRow(2,j,aux3[j]);//(No de dispositivo, fila, valor)
      }
    }    
    delay(demora);    
  } 
}

void mostrar_0(){
  for(int i = 0; i < 8; i++){
    lc.setRow(0,i,cero[i]);//(No de dispositivo, fila, valor)
  }  
}

void mostrar_1(){
  for(int i = 0; i < 8; i++){
    lc.setRow(0,i,uno[i]);//(No de dispositivo, fila, valor)
  }  
}

void mostrar_2(){
  for(int i = 0; i < 8; i++){
    lc.setRow(0,i,dos[i]);//(No de dispositivo, fila, valor)
  }  
}

void mostrar_3(){
  for(int i = 0; i < 8; i++){
    lc.setRow(0,i,tres[i]);//(No de dispositivo, fila, valor)
  }  
}*/