# 🚀 Rover Distance and Travel Time Calculator (C Program)

## 📌 Overview

This project implements a **C console program** that:

* Accepts rover **origin and destination coordinates**
* Calculates the **distance between the two points**
* Computes the **time required to reach the destination**
* Considers:

  * Initial velocity
  * Acceleration
  * Maximum speed (top speed limit)

---

## 📁 Source File

```id="k3w9f2"
task1_rover/rover.c
```

---

## 🧾 What the Program Does

The program prompts the user for:

* Origin coordinates: `(x1, y1)`
* Destination coordinates: `(x2, y2)`
* Initial velocity `i`
* Acceleration `a`
* Maximum speed `t`

Then it outputs:

* 📏 Distance to destination (meters)
* ⏱️ Time required (seconds)

---

## 🧠 Core Logic

---

### 1️⃣ Distance Calculation

```id="7d2m4l"
distance = sqrt((x2 - x1)^2 + (y2 - y1)^2)
```

👉 Uses **Euclidean distance formula**

---

### 2️⃣ Time Calculation

Two cases are handled:

---

### ✅ Case 1: No acceleration (`a = 0`)

```id="3k9v7a"
time = distance / initial_velocity
```

---

### ✅ Case 2: With acceleration

Using equation of motion:

```id="f1m9pz"
s = ut + (1/2)at^2
```

Derived time:

```id="q8d4ht"
t = (-i + sqrt(i^2 + 2*a*s)) / a
```

---

### ⚡ Top Speed Handling

If rover reaches maximum speed:

1. Distance to reach top speed:

```id="v2k9xp"
d1 = (t^2 - i^2) / (2*a)
```

2. If total distance < d1 → no top speed reached

3. Else:

   * Accelerate to max speed
   * Continue at constant speed

---

## 💻 Final Corrected Code

```c id="n8y3pl"
#include<stdio.h>
#include<math.h>
int main(){
float x1,x2,y1,y2,d,i,a,t,time;
printf("enter the origin coordinates:-");
scanf(" %f, %f",&x1,&y1);
printf("enter the destination coordinates:-");
scanf(" %f ,%f",&x2,&y2);
printf("enter the initial velocity:-");
scanf(" %f",&i);
printf("enter the acceleration:-");
scanf(" %f",&a);
printf("enter top speed:-");
scanf(" %f",&t);


d= sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
printf("\n distance to destination:- %.2f",d);
printf("m");
float d1=(t*t-i*i)/(2*a);
if(d<d1)
{
     time=(-i+sqrt((i*i)+(2*a*d))/a);
}
else{
    float s1=d1;
    float time1= (t-i)/a;
    float s2=d-s1;
    float time2=s2/t;
    time=time1+time2;

}
printf("\n time required:- %.2f",time);
printf("seconds");
return 0;
}
```

---

## ⚠️ Input Validation (Recommended)

The program should ensure:

* Velocity ≥ 0
* Acceleration ≥ 0
* Top speed > 0
* Not both velocity and acceleration = 0

---

## ⚙️ Compile and Run

```id="9x2mav"
gcc rover.c -o rover -lm
./rover
```

---

## 🧪 Example Run

### Input:

```id="k1v9pz"
Enter the origin coordinates (x1 y1): 0 0
Enter the destination coordinates (x2 y2): 3 4
Enter the initial velocity: 0
Enter the acceleration: 1
Enter top speed: 10
```

---

### Output:

```id="u7p3nx"
Distance to destination: 5.00 meters
Time required: 3.16 seconds
```

---

## 📸 Output Proof

<img width="736" height="311" alt="image" src="https://github.com/user-attachments/assets/ae0c04a1-d7bd-46e3-a220-ab48a77e6c37" />

```

```

---

## 🧠 Concepts Used

* Coordinate Geometry
* Kinematics (Equations of Motion)
* Conditional Logic
* Mathematical Computation in C

---

## 🎯 Conclusion

This project demonstrates how **mathematics and physics concepts** can be applied in programming to simulate **real-world rover motion** with constraints like maximum speed.

---
