#include "ACS712.h" //Inclusão da biblioteca de comunicação entre o sensor e o arduino.
#include <Wire.h> // Inclusão de biblioteca de comunicação.

// Estou usando ACS de 05 A. 
// EXISTEM DE: 20A OU 30A ALÉM DESTE 005B-Mudar para o modelo que está usando. Valores possíveis: 5,20 e 30
// Sensor ligado na porta analópgica A0
ACS712 sensor(ACS712_05B, A0);//20A ou 30A

double valor_corrente = 0;//Variável para receber leituras do sensor 

const int Valor_Maximo = ; //Inserir Valores
const int Valor_Minimo = ; //""

const int Concen_Max = ; // Inseir Valores em porcentagem
const int Concen_Min = ; //""

bool pause = true; // Delay de 1 hora


void setup() {

  pinMode(PINO_SENSOR, INPUT); // Sensor de voltagem definido como entrada
  pinMode(PINO_RELE, OUTPUT); // Definindo rele como uma saida do sistema
  digitalWrite(PINO_RELE, LOW); // Inicia o rele com um nível lógico baixo
  Wire.begin(); 

//Calibração do projeto via serial monitor
  Serial.begin(9600);
  Serial.println("Aguarde. Calibrando..."); 
  int zero = sensor.calibrate();
  Serial.println("Done!");
  Serial.println("Zero point for this sensor = " + zero);
  Serial.println( zero);
  Serial.println("Fim da calibração");
}
 
void loop() {
  if(valor_corrente > Concen_Max){ //Se sim
    digitalWrite(PINO_RELE, HIGH); //Rele acionadao
    pausa = false; //Configura a variavel "pausa" como falsa

  } else if (valor_corrente < Concen_Min) { //Caso contrario
    digitalWrite(PINO_RELE, LOW); //O rele se mantem desligado
    pausa = true; //Configura a variavel "pausa" como verdadeira
  }
  //Verifica se a variavel "pausa" e verdadeira
  if(pausa){ //Se sim
    delay(3600000); //Aguarda 1 hora segundos para nova leitura
  } 
}


 
