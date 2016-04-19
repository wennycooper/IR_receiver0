<<<<<<< HEAD
#include <CppList.h>
=======
//#include <IRremote.h>
//#include <IRremoteInt.h>

>>>>>>> fddc0351573d94acbca705c2987e5e5190dfd50a

#include <IRremote.h>

//int RECV_PIN = 2; // 使用數位腳位2接收紅外線訊號
IRrecv irrecv2(2); // 初始化紅外線訊號輸入
IRrecv irrecv3(3); //

decode_results results; // 儲存訊號的結構

void setup()
{
  Serial.begin(115200);
//  irrecv.blink13(true); // 設為true的話，當收到訊號時，腳位13的LED便會閃爍
  irrecv2.enableIRIn(); // 啟動接收
  irrecv3.enableIRIn();
}

void loop() {
  if (irrecv2.decode(&results)) { // 接收紅外線訊號並解碼
//    Serial.print("results value is "); // 輸出解碼後的資料
//    Serial.print(results.value, HEX);
//    Serial.print(", bits is ");
//    Serial.print(results.bits);
//    Serial.print(", decode_type is ");
//    Serial.println(results.decode_type);
    Serial.print("Pin2 got: ");
    Serial.println(results.value, HEX);
    irrecv2.resume(); // 準備接收下一個訊號
  }

  if (irrecv3.decode(&results)) { // 接收紅外線訊號並解碼
//    Serial.print("results value is "); // 輸出解碼後的資料
//    Serial.print(results.value, HEX);
//    Serial.print(", bits is ");
//    Serial.print(results.bits);
//    Serial.print(", decode_type is ");
//    Serial.println(results.decode_type);
    Serial.print("Pin3 got: ");
    Serial.println(results.value, HEX);
    irrecv3.resume(); // 準備接收下一個訊號
  }
  
}
