# Blinky Thing

An ESP32 project focused on manual toolchain setup and C implementation run a professional, highly customizable native ESP-IDF environment on Debian.

## Parts List
- ESP-WROOM-32 (DevKit V1 Type-C)
- **1x NPN Transistor (PN2222)** 
- **LEDs:** 2x Red LEDs (D1, D2)
- **Resistors:** * 2x 220Ω (R1, R2) 
-   * 1x 1kΩ (R3 - Base resistor)
* **Power:** 5V/3V Breadboard module + 25W DC Adapter

## Environment & Tooling (Native Setup)
* **OS:** Debian 13 (Trixie)
* **Toolchain:** ESP-IDF (installed locally in `~/.espressif`)
* **Workflow:** `idf.py` CLI for `set-target` and `menuconfig` (configured for 4MB flash)
* **Editor:** VS Code + C/C++ Extension Pack + Tabout

## Logic & Circuit
* **Code:** Written in C using the FreeRTOS task scheduler.
* **Control:** GPIO 23 toggles the base of the PN2222 every 800ms.
* **Switching:** The transistor handles the 5V rail to drive the LEDs in series, keeping the load off the MCU.
* **Diagnostics:** `ESP_LOGI` used for serial state monitoring.