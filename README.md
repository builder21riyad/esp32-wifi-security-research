If you are a a complete beginner and wants to use this tool to test your own home Wi-Fi network, the absolute easiest method is to skip the terminal entirely and use a **Web Flasher**. 

Since I already packaged my `.bin` files into  GitHub Release, you don't need to write a single line of code. You just need a Google Chrome or Microsoft Edge browser.

Here is the exact, step-by-step guide you can follow :

### 🛠️ What You Need
* An ESP32 development board.
* A micro-USB or USB-C cable (make sure it transfers data, not just power!).
* A computer with Google Chrome or Microsoft Edge installed.

---

### Step 1: Download the Files
1. Go to my GitHub repository's **Releases** page.
2. Download the latest version of the three required files to a folder on your computer:
   * `bootloader.bin`
   * `partition-table.bin`
   * `esp32-wifi-penetration-tool.bin`

### Step 2: Flash the ESP32 (The Easy Way)
You don't need to install any software to do this. 
1. Plug your ESP32 into your computer.
2. Open your browser and go to the **[Adafruit ESPTool Web Flasher](https://adafruit.github.io/Adafruit_WebSerial_ESPTool/)** (or Espressif's official web flasher).
3. Click **Connect** and select the USB port your ESP32 is plugged into.
4. Once connected, scroll down to the flashing section. You need to assign the three files you downloaded to specific memory addresses:
   * Address **`0x1000`** ➔ Upload `bootloader.bin`
   * Address **`0x8000`** ➔ Upload `partition-table.bin`
   * Address **`0x10000`** ➔ Upload `esp32-wifi-penetration-tool.bin`
5. Click **Program** (or Flash). 
*(Note: If it fails to connect, press and hold the "BOOT" button on your ESP32 until the flashing bar starts moving).*

### Step 3: Connect to the Tool
Once the web flasher says 100% complete, unplug your ESP32 and plug it back in to restart it.
1. Grab your smartphone or laptop and open your Wi-Fi settings.
2. Look for a new Wi-Fi network called **Milestone** and connect to it the password is palestine .
3. Open your web browser and type this address into the search bar: **`192.168.4.1`**

### Step 4: Run the Test
You should now see the tool's dashboard! To test your home network:
1. Click **Scan** to find your home Wi-Fi router.
2. Select your home network from the list.
3. Set the Attack Type to **ATTACK_TYPE_DOS** (Denial of Service).
4. Set the timer. Because of the recent 32-bit upgrade, you can test it for 10 minutes by entering **`600`** seconds.
5. Click **Attack**.

Grab another device connected to your home Wi-Fi and try to load a webpage. If it won't load, the tool is successfully demonstrating a vulnerability in your network's management frames!

---
> **⚠️ Important Security Warning:** This tool is incredibly powerful. You must **only** use this on your own personal home Wi-Fi network, or a network where you have explicit, written permission from the owner to perform security testing. Disrupting networks you do not own is illegal.



If a user prefers using the terminal (Command Prompt or PowerShell) instead of a web browser, they can flash the board using a simple Python tool. This is the fastest method for anyone who already has a bit of technical experience.

Here is the step-by-step terminal guide you can share with them:

### 🛠️ Prerequisites
* An ESP32 development board and a data-capable USB cable.
* **Python** installed on the computer (can be downloaded from python.org).

---

### Step 1: Download the Files
Go to my GitHub repository's **Releases** page and download these three files into a new, empty folder on your computer (for example, make a folder called `esp32-hack` on your Desktop):
* `bootloader.bin`
* `partition-table.bin`
* `esp32-wifi-penetration-tool.bin`

### Step 2: Install the Flasher Tool
Open your Command Prompt or PowerShell, and install Espressif's official flashing tool by typing:
```bash
pip install esptool
```

### Step 3: Find Your ESP32's Port
Plug your ESP32 into your computer via USB. 
* **Windows:** Open "Device Manager" and look under "Ports (COM & LPT)" to find your COM port (e.g., `COM3`, `COM5`).
* **Mac/Linux:** Open terminal and run `ls /dev/tty*`. Look for something like `/dev/ttyUSB0` or `/dev/tty.SLAB_USBtoUART`.

### Step 4: Flash the Board
In your terminal, navigate to the folder where you saved the three `.bin` files. For example:
```bash
cd Desktop\esp32-hack
```

Now, copy and paste the following command. **Important: Change `COM3` to your actual port!**

```bash
python -m esptool --chip esp32 -p COM3 -b 460800 --before default_reset --after hard_reset write_flash --flash_mode dio --flash_size 2MB --flash_freq 40m 0x1000 bootloader.bin 0x8000 partition-table.bin 0x10000 esp32-wifi-penetration-tool.bin
```

*(Troubleshooting tip: If the terminal gets stuck saying `Connecting........_`, press and hold the physical **BOOT** button on your ESP32 until the upload starts!)*

### Step 5: Connect to the Tool
Once the terminal says **"Hard resetting via RTS pin..."**, the upload is finished and the board is running!
1. On your phone or computer, look for a new Wi-Fi network called **ManagementAP** and connect to it.
2. Open your web browser and navigate to **`http://192.168.4.1`**.
3. You are now inside the dashboard. Select your home Wi-Fi, change the Attack Type to **ATTACK_TYPE_DOS**, set a timer (e.g., `600` for 10 minutes), and click **Attack**.

---
> **⚠️ Important Security Warning:** This tool is strictly for educational purposes and authorized network auditing. You must **only** use this on your own personal home Wi-Fi network or a network where you have explicit permission.
