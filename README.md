# Blinky Thing 🚀

## Summary:

This project is a dedicated dive back into close-to-the-metal development, moving past high-level abstractions to master a native **ESP-IDF** workflow. By ditching containerization for a custom local environment on **Linux** 🐧, it provides a fast, professional feedback loop for building robust embedded firmware. The hardware implementation uses an **NPN transistor** to drive a series of LEDs, which serves the practical purpose of isolating the 5V load from the **ESP32** logic pins to protect the MCU.

It is a foundational project designed to refresh and sharpen expertise in several core technical domains:

* **Embedded Systems Development** on **Linux** 🐧
* **Professional ESP-IDF Tooling** and the `idf.py` ecosystem
* **C Language** proficiency with a focus on hardware registers and drivers
* **VS Code & IntelliSense Integration** (Feel free to grab my `c_cpp_properties.json`—just swap `/home/jdevs/` for your own home directory)
* **Hardware Interfacing** and Schematic Interpretation

## Component List:

* **ESP32 DevKit V1 (Type-C) x1** — MCU1
* **PN2222 NPN Transistor x1** — Q1
* **Red LEDs x2** — D1, D2
* **Resistors:**
* **220Ω x2** — R1, R2
* **1kΩ x1** — R3


* **Power:** 5V/3V Breadboard module + 25W DC Adapter ⚡

## Development Environment:

* **OS:** Debian 13 (Trixie) 🐧
* **Toolchain:** Native ESP-IDF v5.x
* **Workflow:** `idf.py` CLI for `set-target` and `menuconfig` (configured for 4MB flash)
* **Editor:** VS Code + C/C++ Extension Pack + ESP-IDF + Tabout

## Logic & Circuit:

* **Code:** Written in C using the ESP-IDF GPIO driver and FreeRTOS task scheduler.
* **Control:** GPIO 23 toggles the base of the PN2222 every 800ms.
* **Switching:** The transistor manages the 5V rail to drive the LEDs in series, ensuring the MCU only handles the logic signal.
* **Diagnostics:** `ESP_LOGI` and `ESP_LOGE` are utilized for real-time serial state monitoring and error checking.