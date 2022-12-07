#include "LedControl.h"
#include "Symbols.h"
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

void cleanScreens() {
  for(int i = 0; i < 50; i++){
    screenAux1[i] = B00000000;
    screenAux2[i] = B00000000;
    screenAux3[i] = B00000000;
    screenAux4[i] = B00000000;
    screenAux5[i] = B00000000;
    screenAux6[i] = B00000000;
  }
  for(int i = 0; i < 8; i++){
    screen1[i] = B00000000;
    screen2[i] = B00000000;
    screen3[i] = B00000000;
    screen4[i] = B00000000;
    screen5[i] = B00000000;
    screen6[i] = B00000000;
  }
  sizeFilled = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
    fill();
    cleanScreens();
}

void fill() {
  //Llenar Matriz general con el mensaje
  for(int i = 0; i < 6; i++){
    if(i == 1){
      for(int j = 0; j < 8; j++){
        screenAux1[sizeFilled] = A_38[j];
        screenAux2[sizeFilled] = A_38[j];
        screenAux3[sizeFilled] = A_38[j];

        screenAux4[sizeFilled] = B_38[j];
        screenAux5[sizeFilled] = B_38[j];
        screenAux6[sizeFilled] = B_38[j];
        sizeFilled++;
      }
    }else if(i == 2){
      for(int j = 0; j < 8; j++){
        screenAux1[sizeFilled] = A_39[j];
        screenAux2[sizeFilled] = A_39[j];
        screenAux3[sizeFilled] = A_39[j];

        screenAux4[sizeFilled] = B_39[j];
        screenAux5[sizeFilled] = B_39[j];
        screenAux6[sizeFilled] = B_39[j];
        sizeFilled++;
      }
    }else if(i == 3){
      for(int j = 0; j < 8; j++){
        screenAux1[sizeFilled] = A_40[j];
        screenAux2[sizeFilled] = A_40[j];
        screenAux3[sizeFilled] = A_40[j];

        screenAux4[sizeFilled] = B_40[j];
        screenAux5[sizeFilled] = B_40[j];
        screenAux6[sizeFilled] = B_40[j];
        sizeFilled++;
      }
    }else if(i == 4){
      for(int j = 0; j < 8; j++){
        screenAux1[sizeFilled] = A_37[j];
        screenAux2[sizeFilled] = A_37[j];
        screenAux3[sizeFilled] = A_37[j];

        screenAux4[sizeFilled] = B_37[j];
        screenAux5[sizeFilled] = B_37[j];
        screenAux6[sizeFilled] = B_37[j];
        sizeFilled++;
      }
    } else if(i == 5){
      for(int j = 0; j < 8; j++){
        screenAux1[sizeFilled] = A_36[j];
        screenAux2[sizeFilled] = A_36[j];
        screenAux3[sizeFilled] = A_36[j];

        screenAux4[sizeFilled] = B_36[j];
        screenAux5[sizeFilled] = B_36[j];
        screenAux6[sizeFilled] = B_36[j];
        sizeFilled++;
      }
    }
  }
  animateText();
}

void animateText() {
  //int sizeCompleteText = sizeof(completeTextA)/sizeof(completeTextA[0]);
  for(int i = 0; i < sizeFilled + 32; i++){
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
        for(int k = 0; k < sizeFilled; k++){
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
          for(int k = 0; k < sizeFilled; k++){
            screenAux2[k] = screenAux2[k+1];
            screenAux5[k] = screenAux5[k+1];
          }
        }
      }
    }
    if(i > 15){
      for(int j = 0; j < 8; j++){
        if(j < 7){
          screen3[j] = screen3[j+1];
          screen6[j] = screen6[j+1];
        }else{
          screen3[j] = screenAux3[0];
          screen6[j] = screenAux6[0];
          for(int k = 0; k < sizeFilled; k++){
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