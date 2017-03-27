//FILAS
int ground[] = {26, 24, 28, 22, 34, 30, 32, 36};

//COLUMNAS
int volt[] = {23, 25, 29, 37, 31, 35, 33,27};
int Ti = 1150;

//TABLERO
int board[8][8];

//ARREGLO DE POSICIONES ENCENDIDAS
bool useds[8];

bool filesToMove[8];

//CONTADOR DE LIMPIEZA CUANDO LLEGE A 8 PERMITE
//PERMITE LA LIMPIEZA DE 1 O MAS FILAS.
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<8; i++){
    pinMode(ground[i], OUTPUT);
    pinMode(volt[i], OUTPUT);
  }
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      board[i][j] = 0;
    }
    useds[i] = false;  
  }
  for(int i=0; i<8; i++){
    filesToMove[i] = false;
  }
  Clear();
  Serial.begin(9600);
//  for(int i=0; i<8; i++){
//        board[7][i] = 1;   
//     }
//     board[7][3] = 0;
//     board[7][4] = 0;
}
//LIMPIA TODA LA MATRIZ LED DEJANDOLA APAGADA DEL TODO
void Clear() {
      for(int i=0; i<8; i++){
          digitalWrite(ground[i],LOW);//LOW APAGA LAS FILAS - HIGH LAS ENCIENDE.
          digitalWrite(volt[i], HIGH);//HIGH APAGA LAS COLUMNAS - LOW LAS ENCIENDE.
      }
}
//LIMPIA LA FILA QUE ESTE ENCENDIDA DEL TODO
//A MODO DE DEJAR ESA FILA APAGADA.
void clearLine(int file) {
      for(int i=0; i<8; i++){
          board[file][i] = 0;
      }
}

//BUSCA SI LA FILA TIENE VALORES ACTIVOS
bool searchBoard(int i){
  for(int j=0; j<8; j++){
      if(board[i][j] == 1){
        return true;
      }
    }
    return false;  
}
//REFRESCA LA MATRIZ PARA VERIFICAR
//QUE PARTES ESTAN ENCENDIDAS Y APAGAS
void reloadBoard(){
  
  for(int t=0; t<Ti; t++){
    if(useds[0] == true){
      //COLUMNA 0
      digitalWrite(volt[0], LOW);
      for(int i=0; i<8; i++){
        if(board[0][i] == 1)
          digitalWrite(ground[i],  HIGH);  
      }
      delay(1);
      //COLUMNA 0 
      digitalWrite(volt[0], HIGH);
      for(int i=0; i<8; i++){
        if(board[0][i] == 1)
          digitalWrite(ground[i],  LOW);  
      }
    }
    if(useds[1] == true){
      //COLUMNA 1
      digitalWrite(volt[1], LOW);
      for(int i=0; i<8; i++){
        if(board[1][i] == 1)
          digitalWrite(ground[i],  HIGH);  
      }
      delay(1);
      //COLUMNA 1 
      digitalWrite(volt[1], HIGH);
      for(int i=0; i<8; i++){
        if(board[1][i] == 1)
          digitalWrite(ground[i],  LOW);    
      }
    }
    if(useds[2] == true){
      //COLUMNA 2
      digitalWrite(volt[2], LOW);
      for(int i=0; i<8; i++){
        if(board[2][i] == 1)
          digitalWrite(ground[i],  HIGH);  
      }
      delay(1);
      //COLUMNA 2 
      digitalWrite(volt[2],HIGH);
      for(int i=0; i<8; i++){
        if(board[2][i] == 1)
          digitalWrite(ground[i],  LOW);    
      }
    }
    if(useds[3] == true){
      //COLUMNA 3
      digitalWrite(volt[3],LOW);
      for(int i=0; i<8; i++){
        if(board[3][i] == 1)
          digitalWrite(ground[i],  HIGH);  
      }
      delay(1);
      //COLUMNA 3 
      digitalWrite(volt[3],HIGH);
      for(int i=0; i<8; i++){
        if(board[3][i] == 1)
          digitalWrite(ground[i],  LOW);  
      }
    }
    if(useds[4] == true){
      //COLUMNA 4
      digitalWrite(volt[4],LOW);
      for(int i=0; i<8; i++){
        if(board[4][i] == 1)
          digitalWrite(ground[i],  HIGH);  
      }
      delay(1);
      //COLUMNA 4 
      digitalWrite(volt[4], HIGH);
      for(int i=0; i<8; i++){
        if(board[4][i] == 1)
          digitalWrite(ground[i],  LOW);  
      }
    }
    if(useds[5] == true){
      //COLUMNA 5
      digitalWrite(volt[5], LOW);
      for(int i=0; i<8; i++){
        if(board[5][i] == 1)
          digitalWrite(ground[i],  HIGH);
      }
      delay(1);
      //COLUMNA 5 
      digitalWrite(volt[5],HIGH);
      for(int i=0; i<8; i++){
        if(board[5][i] == 1)
          digitalWrite(ground[i],  LOW);  
      }
    }
    if(useds[6] == true){
      //COLUMNA 6
      digitalWrite(volt[6],LOW);
      for(int i=0; i<8; i++){
        if(board[6][i] == 1)
          digitalWrite(ground[i],  HIGH);  
      }
      delay(1);
      //COLUMNA 6 
      digitalWrite(volt[6],HIGH);
      for(int i=0; i<8; i++){
        if(board[6][i] == 1)
          digitalWrite(ground[i],  LOW);  
      }
    }
    if(useds[7] == true){
      //COLUMNA 7
      digitalWrite(volt[7],LOW);
      for(int i=0; i<8; i++){
        if(board[7][i] == 1)
          digitalWrite(ground[i],  HIGH);  
      }
      delay(1);
      //COLUMNA 7
      digitalWrite(volt[7],HIGH);
      for(int i=0; i<8; i++){
        if(board[7][i] == 1)
         digitalWrite(ground[i], LOW);  
      }
    }
  }
}
//CUADRO EN MATRIZ
void O2(int x, int y){
    delay(50);
    if((x == 0 || x >= 1) && board[x][y] == 0 && board[x][y+1] == 0){
      //Serial.println("Entro 1");
      board[x][y] = 1;
      board[x][y+1] = 1; 
    }
    delay(50);
    if(x >=1 && board[x][y] == 0 && board[x][y+1] == 0){
      //Serial.println("Entro 2");
      board[x-1][y] = 1;
      board[x-1][y+1] = 1;
    }
}
//LIMPIEZA DE RASTRO DEL CUADRO
void O2_erase(int x, int y){
    delay(50);
    if(x >=2 && board[x][y] != 1 && board[x][y+1] != 1){
      board[x-2][y] = 0;
      board[x-2][y+1] = 0; 
    }
}

void printAll(){
  Serial.println("MATRIZ OF INTS");
  for(int i=0; i<8; i++){
     for(int j=0; j<8; j++){
      Serial.print(board[i][j]);
     }
     Serial.println("");  
  }
}
int c=0;
int s=0;
int a=0;
int f=0;

void loop() {
     if(c<8){
       if(c>2){
        O2(c,0);
       }else{
        O2(c,0);
       }
       c++;
     }
     else if(c>=8 && s<8){
      if(s>2){
        O2(s,2);
       }else{
        O2(s,2);
       }
       s++;
     }
     else if(c>=8 && s>=8 && a<8){
      if(a>2){
        O2(a,4);
       }else{
        O2(a,4);
       }
       a++;
     }
     else if(c>=8 && s>=8 && a>=8 && f<8){
      if(f>2){
        O2(f,6);
       }else{
        O2(f,6);
       }
       f++;
     }
     delay(100);
     for(int i=0; i<8; i++){
        useds[i] = searchBoard(i);
     }
     reloadBoard();
     printAll();
     if(c<8){
      O2_erase(c,0);
     }
     else if(c>=8 && s<8){
      O2_erase(s,2);
     }
     else if(c>=8 && s>=8 && a<8){
      O2_erase(a,4);
     }
     else if(c>=8 && s>=8 && a>=8 && f<8){
      O2_erase(f,6);
     }

     else{
     //VERIFICADOR DE LINEAS COMPLETAS
     //SI ESTAN COMPLETAS LAS ELIMINA
     for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
        if(board[i][j]==0){
          //Serial.println("Esta incompleta");
          counter = 0;
          continue;
        }else{
          //Serial.println("Sumando al counter");
          filesToMove[i] = true;
          counter++;
        }
        }
        if(counter==8){
          clearLine(i);
          filesToMove[i] = false;
          counter = 0;
        }
        }
        for(int r=7; r>=0; r--){
         if(filesToMove[r]==false){
            if((r-1)>0){
              if(filesToMove[r-1]==true){
                for(int w=0; w<8; w++){
                  board[r][w] = board[r-1][w];
                }
                clearLine(r-1);
              }
              filesToMove[r-1] = false;
            }
         }
       }
     }
}

