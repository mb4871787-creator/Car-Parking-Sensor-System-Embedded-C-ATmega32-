# Car Parking Sensor System — Embedded C (ATmega32)

A real-time car parking sensor system built in **Embedded C** on an **ATmega32** microcontroller. Uses an **HC-SR04 ultrasonic sensor** to measure the distance to obstacles and provides visual (LED) and audible (buzzer) feedback, with distance displayed live on an **LCD**.

---

## How It Works

The system continuously measures the distance to the nearest object and responds based on proximity zones:

| Distance | LEDs On | Buzzer | LCD |
|----------|---------|--------|-----|
| > 20 cm | None | OFF | Distance value |
| 16 – 20 cm | 🔴 Red only | OFF | Distance value |
| 11 – 15 cm | 🔴 Red + 🟢 Green | OFF | Distance value |
| 6 – 10 cm | 🔴 Red + 🟢 Green + 🔵 Blue | OFF | Distance value |
| ≤ 5 cm | 🔴🟢🔵 Flashing | **ON** | "STOP!" |

---

## Hardware Components

| Component | Purpose |
|-----------|---------|
| ATmega32 | Main microcontroller |
| HC-SR04 Ultrasonic Sensor | Distance measurement (ICU-based) |
| 16×2 LCD | Display distance or STOP warning |
| Red LED | Close proximity indicator |
| Green LED | Medium proximity indicator |
| Blue LED | Very close proximity indicator |
| Buzzer | Danger zone alert (≤ 5 cm) |

---

## Driver Modules

```
parking_project/
├── car_parking_project.c   # Main application logic
├── ultrasonic_sensor.c/.h  # HC-SR04 driver (ICU pulse timing)
├── lcd.c/.h                # 16×2 LCD driver
├── LED.c/.h                # LED control driver (RED, GREEN, BLUE)
├── BUZZER.c/.h             # Buzzer driver
├── icu.c/.h                # Input Capture Unit driver
├── adc.c/.h                # ADC driver
├── gpio.c/.h               # GPIO abstraction layer
├── std_types.h             # Standard embedded type definitions
└── common_macros.h         # Bit manipulation macros
```

---

## Concepts Demonstrated

- **ICU (Input Capture Unit)** — precise pulse-width measurement for ultrasonic echo
- **Layered driver architecture** — HAL abstraction over raw registers
- **GPIO abstraction** — port/pin configuration through reusable `gpio.h`
- **Real-time polling loop** — continuous sensor reading and decision making
- **Multi-output feedback** — simultaneous LCD, LED, and buzzer responses

---

## Tools & Environment

| Tool | Purpose |
|------|---------|
| Eclipse IDE (AVR plugin) | Development environment |
| AVR-GCC | Compiler for ATmega32 |
| Proteus | Circuit simulation |
| Embedded C | Language |

---

## Author

**Mohamed Baiomy Abdelkader**  
Mechatronics & Robotics Engineering Student — Ain Shams University  
[LinkedIn](https://linkedin.com/in/mohamed-baiomy) · [GitHub](https://github.com/mb4871787-creator)
