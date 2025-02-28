/ * - Carro Bluetooth do Arduino - Luca
Itens utilillizados:
- Chassi RC Car Arduino. (Motores, rodas e suporte para pilhas incluídas).
- Módulo HC-06 Bluetooth.
- Módulo Ponte H LN298N.
- Protoboard.
- Jumpers.
- Pilha 9V.
- 8 pilhas 1,5V.
App usado como controle no celular:
- CARRO ARDUINO (UM DIA DE CÓDIGO) - GOOGLE PLAY.
* /

# include  < SoftwareSerial.h >

SoftwareSerial mySerial ( 10 , 11 ); // usando 10 e 11 como Serial 10-RX, 11-TX

  configuração nula () {
  Serial. begin ( 9600 );
  mySerial. begin ( 9600 );
  pinMode ( 7 , SAÍDA); // Motor A +
  pinMode ( 6 , SAÍDA); // Motor A +
  pinMode ( 5 , SAÍDA); // Motor B +
  pinMode ( 4 , SAÍDA); // Motor B -
  pinMode ( 9 , SAÍDA); // Motor A Velocidade
  pinMode ( 3 , SAÍDA); // Motor B Velocidade
 }

 loop vazio ()
 if (mySerial.available ()) {  
  
  int x; // x define o sentido anterior do carrinho (para virar à direita ou à esquerda dependendo do sentido); frente x = 20; ré x = 30;
  char data = mySerial. read (); // leitura das informações do bluetooth;
  
  switch (dados) {
    caso  « F » : // Frente
      analogWrite ( 9 , 255 );
      analogWrite ( 3 , 255 );
      digitalWrite ( 7 , BAIXO);
      digitalWrite ( 6 , ALTO);
      digitalWrite ( 5 , BAIXO);
      digitalWrite ( 4 , ALTO);
      x = 20 ; // x é definido como 20 para o carrinho pode virar para a direita e esquerda e continuar no sentido frente;
      quebrar ;
      
    case  ' S ' : // Parar
      analogWrite ( 9 , 255 );
      analogWrite ( 3 , 255 );
      digitalWrite ( 7 , BAIXO);
      digitalWrite ( 6 , BAIXO);
      digitalWrite ( 5 , BAIXO);
      digitalWrite ( 4 , BAIXO);
      quebrar ;
      
    caso  « E » : // Esquerda
      switch (x) {
        case  20 : // quando X = 20, para permanecer andando para frente, o pino 6 é ativado;
          analogWrite ( 3 , 125 );
          analogWrite ( 9 , 125 );
          digitalWrite ( 7 , BAIXO);
          digitalWrite ( 6 , ALTO);
          digitalWrite ( 5 , BAIXO);
          digitalWrite ( 4 , BAIXO);
          x = 20 ;
          quebrar ;
          
        case  30 : // quando X = 30, para permanecer andando para trás (ré), o pino 5 é ativado;
          analogWrite ( 3 , 125 );
          analogWrite ( 9 , 125 );
          digitalWrite ( 7 , BAIXO);
          digitalWrite ( 6 , BAIXO);
          digitalWrite ( 5 , ALTO);
          digitalWrite ( 4 , BAIXO);
          quebrar ;
       }
      quebrar ;
      
    caso  « D » : // Direita
      switch (x) {
        case  20 : // quando X = 20, para permanecer andando para frente, o pino 4 é ativado;
        analogWrite ( 3 , 125 );
        analogWrite ( 9 , 125 );
        digitalWrite ( 5 , BAIXO);
        digitalWrite ( 4 , ALTO);
        digitalWrite ( 7 , BAIXO);
        digitalWrite ( 6 , BAIXO);
        x = 20 ;
        quebrar ;
        
      case  30 : // quando X = 30, para permanecer andando para trás (ré), o pino 7 é ativado;
        analogWrite ( 3 , 125 );
        analogWrite ( 9 , 125 );
        digitalWrite ( 5 , BAIXO);
        digitalWrite ( 4 , BAIXO);
        digitalWrite ( 7 , ALTO);
        digitalWrite ( 6 , BAIXO);
        x = 30 ;
        quebrar ;
      }
    quebrar ;
    
    caso  « R » :
      analogWrite ( 9 , 125 );
      analogWrite ( 3 , 125 );   
      digitalWrite ( 7 , ALTO);
      digitalWrite ( 6 , BAIXO);
      digitalWrite ( 5 , ALTO);
      digitalWrite ( 4 , BAIXO);
      x = 30 ; // x é definido como 30 para o carrinho pode virar para a direita e para a esquerda e continuar sem sentido;
      quebrar ;
      
      padrão : pausa ;
   }
      Serial. println (dados); // recebe os códigos recebidos do bluetooth (dados) se for realmente definido (x);
   }
   atraso ( 50 ); // Atraso anti-interferencia
