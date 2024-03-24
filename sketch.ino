#define trig 9
#define echo  8


void setup() {
  
  pinMode(echo, INPUT);
  //pinMode(trig, OUTPUT);
  Serial.begin(9600);
  for(int x=2; x<=13;x++){
    if (x==8){
      continue;//
    }
    pinMode(x, OUTPUT);
  }

}

void loop() {
  
  
  digitalWrite(trig, LOW);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  int t=pulseIn(echo,HIGH);
  //pulse in pour calculer le temps de l'echo em mode high(5v) en microseconde
  //c'est le temps de l'onde ultrasonique aller/retour de T a R
  int distance=(t/2)*0.0343;
  //la vitesse de son est 343m/s convertit en 0.0343cm/µs


  int n=map(distance, 0, 400, 2, 13);
  //conversion des intervales [0:400] en [2:13]
  for(int x=2; x<=n;x++){
    if (x==8){
      continue;//
    }
    digitalWrite(x, HIGH);
    delay(5);
    digitalWrite(x, LOW);
    
  }
  Serial.print("la distance: ");
  Serial.print( distance);
  Serial.println( "cm");
  delay(30);
  

}
