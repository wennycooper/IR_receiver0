
#include <CppList.h>

//#include <IRremote.h>
//#include <IRremoteInt.h>

#include <IRremote.h>

//int RECV_PIN = 2; // 使用數位腳位2接收紅外線訊號
IRrecv irrecv2(2); // 初始化紅外線訊號輸入
IRrecv irrecv3(3); //

decode_results results; // 儲存訊號的結構

unsigned int flag2, flag3;
void setup()
{
  Serial.begin(115200);
//  irrecv.blink13(true); // 設為true的話，當收到訊號時，腳位13的LED便會閃爍
  irrecv2.enableIRIn(); // 啟動接收
  irrecv3.enableIRIn();
}
unsigned long count = 0;
void loop() {
  flag2 = 0; flag3 = 0;
  if (irrecv2.decode(&results)) { // 接收紅外線訊號並解碼
//    Serial.print("results value is "); // 輸出解碼後的資料
//    Serial.print(results.value, HEX);
//    Serial.print(", bits is ");
//    Serial.print(results.bits);
//    Serial.print(", decode_type is ");
//    Serial.println(results.decode_type);
    //Serial.print("Pin2 got: ");
    //Serial.println(results.value, HEX);
    if (results.value == 0x77E14050) flag2=1;
    irrecv2.resume(); // 準備接收下一個訊號
  }

  if (irrecv3.decode(&results)) { // 接收紅外線訊號並解碼
//    Serial.print("results value is "); // 輸出解碼後的資料
//    Serial.print(results.value, HEX);
//    Serial.print(", bits is ");
//    Serial.print(results.bits);
//    Serial.print(", decode_type is ");
//    Serial.println(results.decode_type);
    //Serial.print("Pin3 got: ");
    //Serial.println(results.value, HEX);
    if (results.value == 0x77E14050) flag3=1;
    irrecv3.resume(); // 準備接收下一個訊號
  }


  if (flag2 && flag3)
    Serial.println("Pin2: True, Pin3: True");
  if (flag2 && !flag3)
    Serial.println("Pin2: True, Pin3: False");
  if (!flag2 && flag3)
    Serial.println("Pin2: False, Pin3: True");
  
}
