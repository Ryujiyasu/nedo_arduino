const int PIN_PWM_X = 3;
const int PIN_PWM_Y = 9;
String cmd;
void setup() {
  Serial.begin( 9600 );     // シリアル通信を初期化する。通信速度は9600bps
  analogWrite( PIN_PWM_X, (int)(50/100*255)); 
  analogWrite( PIN_PWM_Y, (int)(50/100*255)); 
}

void loop() {

  // 受信データがあった時だけ、処理を行う
  if ( Serial.available() ) {       // 受信データがあるか？
    uint8_t data = Serial.read();
    if (data <= 100){
      uint8_t X = data;
      Serial.println(data);
      analogWrite( PIN_PWM_X, (int)((X*255)/100)); 
    }else if (data <= 200){
      uint8_t Y = data - 100;
      analogWrite( PIN_PWM_Y, (int)((Y*255)/100));
    }
  }
}
