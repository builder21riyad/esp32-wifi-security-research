## 🚀 Engineering Upgrades & Modifications
This repository is a heavily modified fork of the original ESP32 Wi-Fi Penetration Tool, updated to meet modern embedded C standards and overcome previous hardware limitations. 

**Key Technical Contributions:**
* **ESP-IDF v5.x Migration:** Completely refactored the legacy v4 build system. Updated `CMakeLists.txt` structures across multiple components to comply with strict v5 component requirements, explicitly linking and resolving dependencies for `esp_wifi` and `esp_event` libraries.
* **Overcoming 8-Bit Architecture Limits:** Rewrote the tool's internal time-limit constraints. Upgraded the attack configuration structures from standard `uint8_t` (255-second maximum) to `uint32_t`. Implemented `uint64_t` mathematical casting within the ESP32 hardware timer logic to prevent integer overflow during long-duration network audits.
* **Full-Stack Payload Integration:** Updated the embedded HTML/JavaScript frontend to successfully pass larger data structures to the backend. Replaced standard form submissions with 7-byte `ArrayBuffer` payloads and `DataView` formatting, ensuring exact memory alignment for C-struct deserialization (`__attribute__((packed))`) on the ESP32.
* **Strict C Compliance:** Resolved implicit function declaration errors (`ntohs`) enforced by modern GNU compilers by integrating and linking proper POSIX network mapping libraries.

> **Disclaimer:** This project and its modifications are intended strictly for educational purposes, embedded systems learning, and authorized network auditing.
