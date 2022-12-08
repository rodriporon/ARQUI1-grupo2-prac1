#include "LedControl.h"
#include "Symbols.h"
#define iterationDelay 300
#define LED 2

LedControl lc = LedControl(11, 13, 10, 6);  //(Pin digital, Pin reloj, Pin CS, No de dispositivos) -> (DIN,CLK,CS,1-8)
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

byte screenAux1[500];
byte screenAux2[500];
byte screenAux3[500];
byte screenAux4[500];
byte screenAux5[500];
byte screenAux6[500];
int sizeFilled = 0;
int textSize = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  for (int i = 0; i < 6; i++) {
    lc.shutdown(i, false);  //(No de dispositivo, estado inicial)
    lc.setIntensity(i, 4);  //(No de dispositivo, intensidad de luz)
    lc.clearDisplay(i);     //(No de dispositivo a limpiar)
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()) {
    String completeText = Serial.readStringUntil('\n');

    if (completeText != "") {
      textSize = completeText.length();
      char textArray[textSize + 1];
      completeText.toCharArray(textArray, textSize + 1);
      fill(textArray);
      cleanScreens();
    }

  }
}

void fill(char textArray[]) {
  //Llenar Matriz general con el mensaje
  for (int i = 0; i < textSize; i++) {
    char singleSymbol = textArray[i];
    if (singleSymbol == ' ') {
      single(A_32, B_32);
    } else if (singleSymbol == '!') {
      single(A_33, B_33);
    } else if (singleSymbol == '"') {
      single(A_34, B_34);
    } else if (singleSymbol == '#') {
      single(A_35, B_35);
    } else if (singleSymbol == '$') {
      single(A_36, B_36);
    } else if (singleSymbol == '%') {
      single(A_37, B_37);
    } else if (singleSymbol == '&') {
      single(A_38, B_38);
    } else if (singleSymbol == '\'') {
      single(A_39, B_39);
    } else if (singleSymbol == '(') {
      single(A_40, B_40);
    } else if (singleSymbol == ')') {
      single(A_41, B_41);
    } else if (singleSymbol == '*') {
      single(A_42, B_42);
    } else if (singleSymbol == '+') {
      single(A_43, B_43);
    } else if (singleSymbol == ',') {
      single(A_44, B_44);
    } else if (singleSymbol == '-') {
      single(A_45, B_45);
    } else if (singleSymbol == '.') {
      single(A_46, B_46);
    } else if (singleSymbol == '/') {
      single(A_47, B_47);
    } else if (singleSymbol == '0') {
      single(A_48, B_48);
    } else if (singleSymbol == '1') {
      single(A_49, B_49);
    } else if (singleSymbol == '2') {
      single(A_50, B_50);
    } else if (singleSymbol == '3') {
      single(A_51, B_51);
    } else if (singleSymbol == 'A') {
      single(A_65, B_65);
    } else if (singleSymbol == 'F') {//Ascii (70-88) Inicio
      single(A_70, B_70);
    } else if (singleSymbol == 'G') {
      single(A_71, B_71);
    } else if (singleSymbol == 'H') {
      single(A_72, B_72);
    } else if (singleSymbol == 'I') {
      single(A_73, B_73);
    } else if (singleSymbol == 'J') {
      single(A_74, B_74);
    } else if (singleSymbol == 'K') {
      single(A_75, B_75);
    } else if (singleSymbol == 'L') {
      single(A_76, B_76);
    } else if (singleSymbol == 'M') {
      single(A_77, B_77);
    } else if (singleSymbol == 'N') {
      single(A_78, B_78);
    } else if (singleSymbol == 'O') {
      single(A_79, B_79);
    } else if (singleSymbol == 'P') {
      single(A_80, B_80);
    } else if (singleSymbol == 'Q') {
      single(A_81, B_81);
    } else if (singleSymbol == 'R') {
      single(A_82, B_82);
    } else if (singleSymbol == 'S') {
      single(A_83, B_83);
    } else if (singleSymbol == 'T') {
      single(A_84, B_84);
    } else if (singleSymbol == 'U') {
      single(A_85, B_85);
    } else if (singleSymbol == 'V') {
      single(A_86, B_86);
    } else if (singleSymbol == 'W') {
      single(A_87, B_87);
    } else if (singleSymbol == 'X') {//Ascii (70-88) Fin
      single(A_88, B_88);
    }
    
      //Ascii (108-126) Inicio
      else if (singleSymbol == 'l') {
      single(A_108, B_108);
    } else if (singleSymbol == 'm') {
      single(A_32, B_109);
    } else if (singleSymbol == 'n') {
      single(A_32, B_110);
    } else if (singleSymbol == 'o') {
      single(A_32, B_111);
    } else if (singleSymbol == 'p') {
      single(A_32, B_112);
    } else if (singleSymbol == 'q') {
      single(A_32, B_113);
    } else if (singleSymbol == 'r') {
      single(A_32, B_114);
    } else if (singleSymbol == 's') {
      single(A_32, B_115);
    } else if (singleSymbol == 't') {
      single(A_116, B_116);
    } else if (singleSymbol == 'u') {
      single(A_32, B_117);
    } else if (singleSymbol == 'v') {
      single(A_32, B_118);
    } else if (singleSymbol == 'w') {
      single(A_32, B_119);
    } else if (singleSymbol == 'x') {
      single(A_32, B_120);
    } else if (singleSymbol == 'y') {
      single(A_32, B_121);
    } else if (singleSymbol == 'z') {
      single(A_32, B_122);
    } else if (singleSymbol == '{') {
      single(A_123, B_123);
    } else if (singleSymbol == '|') {
      single(A_124, B_124);
    } else if (singleSymbol == '}') {
      single(A_125, B_125);
    } else if (singleSymbol == '~') {
      single(A_32, B_126);
    } else if (singleSymbol == 'ñ') {
      single(A_enhe, B_enhe);
    }
  }
  animateText();
}

void single(byte A[], byte B[]) {
  for (int j = 0; j < 8; j++) {
    screenAux1[sizeFilled] = A[j];
    screenAux2[sizeFilled] = A[j];
    screenAux3[sizeFilled] = A[j];

    screenAux4[sizeFilled] = B[j];
    screenAux5[sizeFilled] = B[j];
    screenAux6[sizeFilled] = B[j];
    sizeFilled++;
  }
}

void animateText() {
  //int sizeCompleteText = sizeof(completeTextA)/sizeof(completeTextA[0]);
  for (int i = 0; i < sizeFilled + 32; i++) {
    //Mostrar matriz
    for (int j = 0; j < 8; j++) {
      lc.setRow(0, j, screen1[j]);  //(No de dispositivo, fila, valor)
      lc.setRow(1, j, screen2[j]);  //(No de dispositivo, fila, valor)
      lc.setRow(2, j, screen3[j]);  //(No de dispositivo, fila, valor)
      lc.setRow(3, j, screen4[j]);  //(No de dispositivo, fila, valor)
      lc.setRow(4, j, screen5[j]);  //(No de dispositivo, fila, valor)
      lc.setRow(5, j, screen6[j]);  //(No de dispositivo, fila, valor)
    }

    //Desplazamiento
    for (int j = 0; j < 8; j++) {
      if (j < 7) {
        screen1[j] = screen1[j + 1];
        screen4[j] = screen4[j + 1];
      } else {
        screen1[j] = screenAux1[0];
        screen4[j] = screenAux4[0];
        for (int k = 0; k < sizeFilled; k++) {
          screenAux1[k] = screenAux1[k + 1];
          screenAux4[k] = screenAux4[k + 1];
        }
      }
    }
    if (i > 7) {
      for (int j = 0; j < 8; j++) {
        if (j < 7) {
          screen2[j] = screen2[j + 1];
          screen5[j] = screen5[j + 1];
        } else {
          screen2[j] = screenAux2[0];
          screen5[j] = screenAux5[0];
          for (int k = 0; k < sizeFilled; k++) {
            screenAux2[k] = screenAux2[k + 1];
            screenAux5[k] = screenAux5[k + 1];
          }
        }
      }
    }
    if (i > 15) {
      for (int j = 0; j < 8; j++) {
        if (j < 7) {
          screen3[j] = screen3[j + 1];
          screen6[j] = screen6[j + 1];
        } else {
          screen3[j] = screenAux3[0];
          screen6[j] = screenAux6[0];
          for (int k = 0; k < sizeFilled; k++) {
            screenAux3[k] = screenAux3[k + 1];
            screenAux6[k] = screenAux6[k + 1];
          }
        }
      }
    }
    delay(iterationDelay);
  }
}

void cleanScreens() {
  for (int i = 0; i < 50; i++) {
    screenAux1[i] = B00000000;
    screenAux2[i] = B00000000;
    screenAux3[i] = B00000000;
    screenAux4[i] = B00000000;
    screenAux5[i] = B00000000;
    screenAux6[i] = B00000000;
  }
  for (int i = 0; i < 8; i++) {
    screen1[i] = B00000000;
    screen2[i] = B00000000;
    screen3[i] = B00000000;
    screen4[i] = B00000000;
    screen5[i] = B00000000;
    screen6[i] = B00000000;
  }
  sizeFilled = 0;
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
