# 🛠️ Task 2 – Arduino Servo Control with Safety Limit

## 📌 Overview

This Arduino project uses a **potentiometer to control a servo motor angle**, while enforcing a **maximum safe limit of 68°**.

An **LED is used as an indicator** when the input exceeds the safe range.

### Behavior:

* 🔵 **LED OFF** → Servo moves normally (0° to 68°)
* 🔴 **LED ON** → Input exceeds 68°, servo is limited to 68°

---

## 📁 Source File

```
```
https://www.tinkercad.com/things/l0tsE5H0gUY/editel?sharecode=9Z9AHgdBax_Z2CllT6nCWsoLEQa15qdDXdVqJ2VG3LE
---

## 🔧 Components Used

* Arduino Uno
* Servo Motor
* Potentiometer
* LED
* Resistor (220Ω)
* Jumper Wires

---

## 🔌 Pin Mapping

| Component     | Pin |
| ------------- | --- |
| Potentiometer | A0  |
| Servo Signal  | D9  |
| LED           | D7  |

---

## ⚙️ Program Flow

1. Read analog value from potentiometer (0–1023)
2. Convert value to angle (0–180°)
3. Apply safety condition:

   * If angle > 68 → limit to 68° and turn ON LED
   * Else → allow normal movement and keep LED OFF
4. Repeat continuously

---

## 🧠 Logic

```
raw_value = analogRead(A0)
angle = map(raw_value, 0, 1023, 0, 180)

if angle > 68:
    servo_angle = 68
    LED = ON
else:
    servo_angle = angle
    LED = OFF
```

---

## 💻 Arduino Code

#include <Servo.h>

Servo myServo;
int potentiometer = A0;
int ledPin = 7;

void setup() {
  myServo.attach(9);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int value = analogRead(potentiometer);
  int angle = map(value, 0, 1023, 0, 180);

  if (angle > 68) {
    myServo.write(68);
    digitalWrite(ledPin, HIGH);
  } else {
    myServo.write(angle);
    digitalWrite(ledPin, LOW);
  }

  delay(10);
}

## 📸 Output Proof

### Includes:

* 📷 Circuit Screenshot
* 🎥 Simulation Video
* 🖼️ Working Output Images

---

## 🎬 Demo Video


[PROJECT DEMO VIDEO] (https://drive.google.com/file/d/17Ctn3ilfuWv5UdQA9g4nA3WO6IB5b8FS/view?usp=sharing)


---

## 🔌 Circuit Diagram


<img width="885" height="652" alt="Screenshot 2026-03-22 225046" src="https://github.com/user-attachments/assets/aa3da45b-e911-49ce-8beb-96b0c5b7b66a" />



---
### 🖼️ Circuit Image

<img width="1280" height="494" alt="Terrific Sango" src="https://github.com/user-attachments/assets/865fc866-46f0-4641-8140-5d5fdbeefa90" />




---

## 🔒 Safety Feature

* Ensures servo does not exceed **68°**
* Prevents mechanical damage
* Provides visual feedback using LED

---

## ✅ Expected Behavior

| Potentiometer Input | Servo Output | LED |
| ------------------- | ------------ | --- |
| 30°                 | 30°          | OFF |
| 50°                 | 50°          | OFF |
| 70°                 | 68°          | ON  |
| 120°                | 68°          | ON  |

---

## 🚀 Conclusion

This project demonstrates:

* Analog input handling
* Servo motor control
* Safety constraints in embedded systems
* Real-time feedback using LED

---
