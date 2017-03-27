//FILAS
int ground[] = {26, 24, 28, 22, 34, 30, 32, 36};

//COLUMNAS
int volt[] = {23, 25, 29, 37, 31, 35, 33,27};
int Ti = 500;
int moving = 3;
int bmoving = 3;

//TABLERO
int board[8][8];

//ARREGLO DE POSICIONES ENCENDIDAS
bool useds[8];
char randomForms [8];
bool filesToMove[8];
int l = 12, r=13;
//CONTADOR DE LIMPIEZA CUANDO LLEGE A 8 PERMITE
//PERMITE LA LIMPIEZA DE 1 O MAS FILAS.
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<8; i++){
    pinMode(ground[i], OUTPUT);
    pinMode(volt[i], OUTPUT);
  }
  pinMode(r, INPUT);
  pinMode(l, INPUT);
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
      for(int i=0; i<8; i++){
          for(int j=0; j<8; j++){
            board[i][j] = 0;
          }
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
//O EN MATRIZ
void O2(int x, int y){
    delay(50);
    if(x >=1 && board[x][y] == 0 && board[x][y+1] == 0){
      //Serial.println("Entro 2");
      
      board[x][y+2] = 0;
      board[x][y-2] = 0;
      board[x-1][y] = 1;
      board[x-1][y+1] = 1;
      
    }
    delay(50);
    if((x == 0 || x >= 1) && board[x][y] == 0 && board[x][y+1] == 0){
      //Serial.println("Entro 1");
      board[x][y] = 1;
      board[x][y+1] = 1; 
    }
}
//LIMPIEZA DE RASTRO DEL O
void O2_erase(int x, int y){
    delay(50);
    if(x >=2 && board[x][y] != 1 && board[x][y+1] != 1){
      board[x-2][y] = 0;
      board[x-2][y+1] = 0;
      board[x-2][y+2] = 0;
      board[x-2][y-1] = 0;
//      if(moving > bmoving){
//      board[x-2][y-2] = 0;
//      bmoving = moving;
//      }else if(moving < bmoving)
//      board[x-2][y+2] = 0;
//      bmoving = moving; 
    }
}
//J EN MATRIZ
void J(int x, int y){
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
    }
    delay(50);
    if(x >=2 && board[x][y] == 0 && board[x][y+1] == 0){
      //Serial.println("Entro 2");
      board[x-2][y] = 1;
    }
}
//LIMPIEZA DE RASTRO DE J
void J_erase(int x, int y){
    delay(50);
    if(x >=2 && board[x][y] != 1 && board[x][y+1] != 1){
      board[x-3][y] = 0;
      board[x-1][y+1] = 0;
      board[x-2][y+1] = 0;
      board[x-3][y+1] = 0;
      board[x-1][y-1] = 0;
      board[x-2][y-1] = 0;
      board[x-3][y-1] = 0;
      
    }
}
//L EN MATRIZ
void L(int x, int y){
    delay(50);
    if((x == 0 || x >= 1) && board[x][y] == 0 && board[x][y+1] == 0){
      //Serial.println("Entro 1");
      board[x][y] = 1;
      board[x][y+1] = 1; 
    }
    delay(50);
    if(x >=1 && board[x][y] == 0 && board[x][y+1] == 0){
      //Serial.println("Entro 2");
      board[x-1][y+1] = 1;
    }
    delay(50);
    if(x >=2 && board[x][y] == 0 && board[x][y+1] == 0){
      //Serial.println("Entro 2");
      board[x-2][y+1] = 1;
    }
}
//LIMPIEZA DE RASTRO DE L
void L_erase(int x, int y){
    delay(50);
    if(x >=2 && board[x][y] != 1 && board[x][y+1] != 1){
      board[x-3][y+1] = 0;
      board[x-1][y] = 0;
      board[x-2][y] = 0;
      board[x-3][y] = 0;
      board[x-1][y+2] = 0;
      board[x-2][y+2] = 0;
      board[x-3][y+2] = 0;
      
      
    }
}

//S EN MATRIZ
void S(int x, int y){
    delay(50);
    if((x == 0)&& board[x][y-1] == 0 && board[x][y] == 0&& board[x-1][y+1] == 0){
      //Serial.println("Entro 1");
      board[x][y-1] = 1;
      board[x][y] = 1;
    }
    delay(50);
    if(x >=1 && board[x][y-1] == 0 && board[x][y] == 0 && board[x-1][y+1] == 0){
      //Serial.println("Entro 2");
      board[x][y] = 1;
      board[x][y-1] = 1;
      board[x-1][y] = 1;
      board[x-1][y+1] = 1;
      
    }
}
//LIMPIEZA DE RASTRO DE S
void S_erase(int x, int y){
    delay(50);
    if(x >=2 && board[x][y] != 1 && board[x-1][y+1] != 1 && board[x][y-1] !=1){
      board[x-1][y-1] = 0;
      board[x-2][y-1] = 0;
      board[x-2][y+1] = 0;
      board[x-2][y] = 0;  
    }
}

//Z EN MATRIZ
void Z(int x, int y){
    delay(50);
    if((x == 0)&& board[x][y+1] == 0 && board[x][y] == 0&& board[x-1][y-1] == 0){
      //Serial.println("Entro 1");
      board[x][y+1] = 1;
      board[x][y] = 1;
    }
    delay(50);
    if(x >=1 && board[x][y+1] == 0 && board[x][y] == 0 && board[x-1][y-1] == 0){
      //Serial.println("Entro 2");
      board[x][y] = 1;
      board[x][y+1] = 1;
      board[x-1][y] = 1;
      board[x-1][y-1] = 1;
      
    }
}
//LIMPIEZA DE RASTRO DE Z
void Z_erase(int x, int y){
    delay(50);
    if(x >=2 && board[x][y] != 1 && board[x-1][y-1] != 1 && board[x][y+1] !=1){
      board[x-1][y+1] = 0;
      board[x-2][y-1] = 0;
      board[x-2][y+1] = 0;
      board[x-2][y] = 0;  
    }
}

//T EN MATRIZ
void T(int x, int y){
    delay(50);
    if(x >=1 && board[x][y+1] == 0 && board[x][y] == 0 && board[x-1][y-1] == 0){
      //Serial.println("Entro 2");
      board[x-1][y] = 1;
    }
    delay(50);
    if((x == 0 || x >=1)&& board[x][y+1] == 0 && board[x][y-1] == 0&& board[x][y] == 0){
      //Serial.println("Entro 1");
      board[x][y+1] = 1;
      board[x][y] = 1;
      board[x][y-1] = 1;
    }
}
//LIMPIEZA DE RASTRO DE T
void T_erase(int x, int y){
    delay(50);
    if(x >=2 && board[x][y] != 1 && board[x][y-1] != 1 && board[x][y+1] !=1){
      board[x-1][y+1] = 0;
      board[x-1][y-1] = 0;
      board[x-2][y] = 0;
      board[x-2][y-1] = 0;
      board[x-2][y+1] = 0;  
    }
}
//I EN MATRIZ
void I(int x, int y){
    delay(50);
    if((x == 0 || x >=1)&& board[x][y] == 0 ){
      //Serial.println("Entro 1");
      board[x][y] = 1;
    }
    delay(50);
    if(x >=1 && board[x][y] == 0){
      //Serial.println("Entro 2");
      board[x][y] = 1;
      board[x-1][y] = 1;
    }
    delay(50);
    if(x >=2 && board[x][y] == 0){
      //Serial.println("Entro 2");
      board[x][y] = 1;
      board[x-1][y] = 1;
      board[x-2][y] = 1;
      
    }
    
}
//LIMPIEZA DE RASTRO DE I
void I_erase(int x, int y){
    delay(50);
    if(x >=2 && board[x][y] != 1){
      board[x-3][y] = 0;
      board[x-1][y+1] = 0;
      board[x-2][y+1] = 0;
      board[x-3][y+1] = 0;
      board[x-1][y-1] = 0;
      board[x-2][y-1] = 0;
      board[x-3][y-1] = 0;
        
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
char getForm(){
  int tmp = random(0, 8);
  switch(tmp){
    case 0:
      return 'O';
    break;
    
    case 1:
      return 'L';
    break;
      
    case 2:
      return 'J';
    break;
    
    case 3:
      return 'S';
    break;
    
    case 4:
      return 'Z';
    break;
    
    case 5:
      return 'T';
    break;
    
    case 6:
      return 'I';
    break;
    
    default :
      return 'O';
    break;
  }
}
void you_lose()
{
  for(int time=0;time<=100;time++)
  {
  for(int i=0;i<=4;i++)
   {
   digitalWrite(ground[2],LOW);
   digitalWrite(volt[1],LOW); 
   digitalWrite(volt[3],LOW); 
   digitalWrite(ground[3],HIGH);     // ojos 
   delay(1);
   digitalWrite(volt[1],HIGH); 
   digitalWrite(volt[3],HIGH); 
   digitalWrite(ground[3],LOW);
   
   
   digitalWrite(volt[0],LOW);      //primera parte 
   digitalWrite(volt[4],LOW); 
   digitalWrite(ground[0],HIGH);
   delay(1);
   digitalWrite(volt[0],HIGH); 
   digitalWrite(volt[4],HIGH); 
   digitalWrite(ground[0],LOW);
   
   
    digitalWrite(volt[1],LOW);      //base de la sonrisa 
   digitalWrite(volt[2],LOW); 
   digitalWrite(volt[3],LOW); 
   digitalWrite(ground[1],HIGH);
   digitalWrite(ground[2],LOW);
   delay(1);
   digitalWrite(volt[1],HIGH); 
   digitalWrite(volt[2],HIGH);
  digitalWrite(volt[3],HIGH);  
   digitalWrite(ground[1],LOW);
  }
  }
}

int c=0;
int a=0;
int f=0;
char form;
bool next_form = true;
int ri = 0, le = 0;
void loop() {
     Serial.println("Tope");
     delay(100);
     if(digitalRead(r) ==1){
        ri = 1;
     }else if(digitalRead(l) ==1){
        Serial.println(moving);
        Serial.println(bmoving);
        Serial.println("Izquierda");
        le = 1;
     }
     
     if(next_form){
        Serial.println("Iniciando");
        form = 'I';
        next_form = false;
        c = 0;
     }
     delay(100);
     Serial.print("Moving: ");
     Serial.println(moving);
     Serial.print("Before Moving: ");
     Serial.println(bmoving);
     if(form=='O'&& c<8 && moving>=0 && moving<7){
       O2(c,moving);
       c++;
     }
     else if(form=='L' && c<8 && moving >=0 && moving <7){
       L(c,moving);
       c++;
     }
     else if(form=='J' && c<8 && moving >=0 && moving <7){
       J(c,moving);
       c++;
     }
     else if(form=='S' && c<8 && moving >0 && moving <7){
       S(c,moving);
       c++;
     }
     else if(form=='Z' && c<8 && moving >0 && moving <7){
       Z(c,moving);
       c++;
     }
     else if(form=='T' && c<8 && moving >0 && moving <7){
       T(c,moving);
       c++;
     }
     else if(form=='I' && c<8 && moving >=0 && moving <=7){
       I(c,moving);
       c++;
     }
     
     delay(100);
     for(int i=0; i<8; i++){
        useds[i] = searchBoard(i);
     }
     reloadBoard();
     //printAll();

     if(form=='O' && c<8){
        if(c<8){
        O2_erase(c,moving);
        }  
     }
     else if(form=='L' && c<8){
        if(c<8){
        L_erase(c,moving);
        }  
     }
     else if(form=='J' && c<8){
        if(c<8){
        J_erase(c,moving);
        }  
     }
     else if(form=='S' && c<8){
        if(c<8){
        S_erase(c,moving);
        }  
     }
     else if(form=='Z' && c<8){
        if(c<8){
        Z_erase(c,moving);
        }  
     }
     else if(form=='T' && c<8){
        if(c<8){
        T_erase(c,moving);
        }  
     }
     else if(form=='I' && c<8){
        if(c<8){
        I_erase(c,moving);
        }  
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
       for(int e=0; e<8; e++){
          if(board[0][e] == 1){
            Clear();
            you_lose();
            next_form = true;
            c=0;
            break;
          }
       }
       Serial.println("Termino");
       next_form = true;
     }
     
     if(ri == 1){
        moving--;
        ri=0;
     }else if(le == 1){
        moving++;
        le=0;
     }
     
}

