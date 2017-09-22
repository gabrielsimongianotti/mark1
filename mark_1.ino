
const int vermelho1 = 7;
const int preto1 = 8;
const int vermelho2 = 5;
const int preto2 = 6;
#define eixoX A1
#define eixoY A0
#define eixoZ 9

void setup(){
  pinMode(vermelho1, OUTPUT);
  pinMode(preto1, OUTPUT);  
  pinMode(preto2, OUTPUT);
  pinMode(vermelho2, OUTPUT);
  pinMode(eixoX, INPUT);
  pinMode(eixoY, INPUT);
  pinMode(eixoZ, INPUT_PULLUP);
  Serial.begin(9600);
}
void  traz(){
  digitalWrite(vermelho1, HIGH); 
  digitalWrite(preto1, LOW);
  digitalWrite(vermelho2, HIGH);
  digitalWrite(preto2, LOW);
  }
void frente(){
  digitalWrite(vermelho1, LOW);
  digitalWrite(preto1, HIGH);
  digitalWrite(vermelho2, LOW);
  digitalWrite(preto2, HIGH);
  }
void girod(){
  digitalWrite(vermelho1, HIGH);
  digitalWrite(preto1, LOW);
  digitalWrite(vermelho2, LOW);
  digitalWrite(preto2, HIGH);
  }
void giroe(){
  digitalWrite(vermelho1, LOW);
  digitalWrite(preto1, HIGH);
  digitalWrite(vermelho2, HIGH);
  digitalWrite(preto2, LOW);
  }
void direita(){
  digitalWrite(vermelho1, LOW);
  digitalWrite(preto1, HIGH);
  digitalWrite(vermelho2, LOW);
  digitalWrite(preto2, LOW);
  }
void esquerda(){
  digitalWrite(vermelho1, LOW);
  digitalWrite(preto1, LOW);
  digitalWrite(vermelho2, LOW);
  digitalWrite(preto2, HIGH);  
  }
void esquerdatraz(){
  digitalWrite(vermelho1,LOW);
  digitalWrite(preto1, LOW);
  digitalWrite(vermelho2, HIGH);
  digitalWrite(preto2,LOW); 
  }
void parar(){
  digitalWrite(vermelho1, HIGH);
  digitalWrite(preto1, HIGH);
  digitalWrite(vermelho2, HIGH);
  digitalWrite(preto2, HIGH);  
  }
void loop(){
  int valorX = analogRead(eixoX);
  int valorY = analogRead(eixoY);
  bool botao = digitalRead(eixoZ);
  Serial.print("eixo X:");
  Serial.print(valorX);
  Serial.print(", eixo Y:");
  Serial.print(valorY);
  Serial.print(", eixo Z");
  Serial.println(botao);
  
  if (valorX > 490 && valorX < 540 && valorY < 600 && valorY > 440 ){
    parar();
  }else if (valorX > 600 && valorY < 600 && valorY > 400){
    frente();
  }else if (valorX< 500 && valorY < 600 && valorY > 400){
    traz();
  }else if( valorX > 600 && valorY > 600 ){
    direita();  
  }else if(valorX > 600 && valorY <400){
    esquerda();
  }else if(valorX < 600 && valorX >400 && valorY < 400){
    girod();
  }else if(valorX < 600 && valorX > 400 && valorY > 600){
    giroe();
  }else if(valorX < 400 && valorY <400){
    esquerdatraz();
  }else { 
    parar();
  }
     
}
