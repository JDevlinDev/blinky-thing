# Blinky Thing

## Summary:
An ESP32 project that blinks some LEDs using a transistor. It has the advantage of using the transistor to keep the load off the MCU. It is a foundational project that serves to refresh and build on knowledge in the following areas:
* **Embedded Systems Development** on **Linux**
* **ESP-IDF Development**
* **C/C++ Programming**
* **VS Code & Intellisense Ecosystem** (Steal my c_cpp_properties.json and replace `/home/jdevs/` with your own home directory)
* **Circuit Diagraming**

## Component List:
* **ESP32 DevKit V1 x1** - MCU1
* **PN2222 NPN Transistor x1** - Q1
* **Red LEDs x2** - D1, D2
* **Resistors:**
   * **220Ω x2** - R1, R2
   * **1kΩ x1** - R3
* **Power:** 5V/3V Breadboard module + 25W DC Adapter

## Development Environment:
* **OS:** Debian 13 (Trixie)
* **Toolchain:** Native ESP-IDF
* **Workflow:** `idf.py` CLI for `set-target` and `menuconfig` (configured for 4MB flash)
* **Editor:** VS Code + C/C++ Extension Pack + ESP-IDF + Tabout

## Logic & Circuit:
* **Code:** Written in C using the GPIO driver and FreeRTOS task scheduler.
* **Control:** GPIO 23 toggles the base of the PN2222 every 800ms.
* **Switching:** The transistor handles the 5V rail to drive the LEDs in series, keeping the load off the MCU.
* **Diagnostics:** `ESP_LOGI` used for serial state monitoring.