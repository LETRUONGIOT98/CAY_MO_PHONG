#include <SoftwareSerial.h>

// Khai báo chân UART
#define RX_PIN 2
#define TX_PIN 3

// Khai báo chân điều khiển đèn
#define LED_PIN_1 13
#define LED_PIN_2 12
#define LED_PIN_3 11
#define LED_PIN_4 10

// Khai báo chân PWM
#define PWM_PIN 9  //Chân kết nối với IN1 L298

// Khởi tạo đối tượng SoftwareSerial với RX_PIN và TX_PIN
SoftwareSerial mySerial(RX_PIN, TX_PIN);

void setup() {
  // Khởi tạo cổng Serial với tốc độ 9600 bps
  Serial.begin(9600);

  // Khởi tạo cổng UART ảo với tốc độ 9600 bps
  mySerial.begin(9600);

  // Khởi tạo các chân điều khiển đèn là đầu ra
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);

  // Khởi tạo chân PWM là đầu ra
  pinMode(PWM_PIN, OUTPUT);
}

void loop() {
  // Kiểm tra nếu có dữ liệu nhận được từ UART ảo
  if (mySerial.available() > 0) {
    // Đọc dữ liệu từ UART ảo
    String input = mySerial.readStringUntil('\n');

    // Kiểm tra xem dữ liệu có chứa chuỗi "ON1" không
    if (input == "ON1") {
      // Bật đèn 1
      digitalWrite(LED_PIN_1, HIGH);
    } 
    // Kiểm tra xem dữ liệu có chứa chuỗi "OFF1" không
    else if (input == "OFF1") {
      // Tắt đèn 1
      digitalWrite(LED_PIN_1, LOW);
    }
    // Kiểm tra xem dữ liệu có chứa chuỗi "ON2" không
    else if (input == "ON2") {
      // Bật đèn 2
      digitalWrite(LED_PIN_2, HIGH);
    } 
    // Kiểm tra xem dữ liệu có chứa chuỗi "OFF2" không
    else if (input == "OFF2") {
      // Tắt đèn 2
      digitalWrite(LED_PIN_2, LOW);
    }
    // Kiểm tra xem dữ liệu có chứa chuỗi "ON3" không
    else if (input == "ON3") {
      // Bật đèn 3
      digitalWrite(LED_PIN_3, HIGH);
    } 
    // Kiểm tra xem dữ liệu có chứa chuỗi "OFF3" không
    else if (input == "OFF3") {
      // Tắt đèn 3
      digitalWrite(LED_PIN_3, LOW);
    }
    // Kiểm tra xem dữ liệu có chứa chuỗi "ON4" không
    else if (input == "ON4") {
      // Bật đèn 4
      digitalWrite(LED_PIN_4, HIGH);
    } 
    // Kiểm tra xem dữ liệu có chứa chuỗi "OFF4" không
    else if (input == "OFF4") {
      // Tắt đèn 4
      digitalWrite(LED_PIN_4, LOW);
    }
    // Kiểm tra xem dữ liệu có chứa giá trị từ 0 đến 255 không
    else {
      // Chuyển đổi dữ liệu thành số nguyên
      int value = input.toInt();

      // Giới hạn giá trị từ 0 đến 255
      value = constrain(value, 0, 255);

      // Thực hiện điều khiển PWM tại chân 9 với giá trị từ 0 đến 255
      analogWrite(PWM_PIN, value);
    }
  }
}
