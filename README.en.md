<p align="center">
  <a href="README.md">🇪🇸 Español</a> • <a href="README.en.md">🇺🇸 English</a>
</p>

---
# ft_minitalk 🧠💬

**ft_minitalk** is a UNIX signal-based communication system between two independent processes — a client and a server — built as part of the 42 curriculum.  
The challenge: use **only** `SIGUSR1` and `SIGUSR2` to transmit data, forcing the creation of a custom communication protocol from scratch.

---

## 📦 Project Overview

The project consists of two programs:

- **`server`** – Waits for messages and displays them in real time.  
- **`client`** – Sends a user-defined message to the server using only signals.

All communication relies exclusively on `SIGUSR1` and `SIGUSR2`, requiring bit-level encoding, transmission, and decoding.

---

## 📚 Theory Context

**What are signals?**  
In UNIX, signals are software interrupts sent from one process to another.  
Each signal has a unique code and can trigger a custom *signal handler*.

For this project:
- `SIGUSR1` → represents **binary 1**
- `SIGUSR2` → represents **binary 0**

💡 **Asynchronous nature:** When a signal is received, it interrupts the program’s normal execution and immediately calls the registered signal handler, no matter what the program was doing.

**Signal Handling:**  
Using `sigaction()` in the server, each signal is captured and processed **bit-by-bit**.  
Once 8 bits are collected, they are converted back into a character and printed.

---

## 💡 How It Works

### **Server**
1. Starts **without arguments**.
2. Prints its PID (Process ID) at startup.
3. Waits for incoming signals from the client.
4. Collects bits, reconstructs characters, and prints them.
5. Sends a `SIGUSR1` confirmation back to the client after each character.

### **Client**
1. Launched with:
   - The server’s PID.
   - The message string.
2. Converts each character into **8-bit binary**.
3. Sends each bit to the server:
   - `SIGUSR1` for 1
   - `SIGUSR2` for 0
4. Waits for server confirmation before sending the next character.
5. Ends by sending an **EOT (End Of Transmission)** signal.

---

## 🧠 Project Logic

Instead of traditional bitwise masking and shifting, this project uses a **buffer-based system** to collect incoming bits.  
This was a deliberate design choice, as bitwise operations were new to me at the time.

**Message transfer flow:**
1. Convert message characters → binary (8 bits each).
2. Send bits via `SIGUSR1`/`SIGUSR2`.
3. Server buffers and reconstructs characters.
4. Server sends confirmation → Client sends next character.
5. Repeat until message is complete → Send EOT.

**Timing Control:**  
To prevent data loss, the client uses `usleep(50)` between bit transmissions.  
Server confirmations reduce unnecessary delays.

---

## 🔍 Input Validation

- **Server**: Takes no arguments.  
- **Client**: Requires exactly **two arguments**:
  1. Server PID.
  2. Message string.

**PID validation:**
- Must be numeric.
- Must be within expected PID range.
- Invalid formats trigger an error.

---

## ⚡ Reliability & Performance

This buffer-based method, while harder to implement, proved to be **more reliable and robust** than many common implementations.  
Typical versions — often relying on looser timing or lacking confirmation protocols — tend to break or lose data when handling very large messages (e.g., **1,000** or even **10,000 characters**).  

By enforcing strict **bit-by-bit acknowledgments** and using a custom buffering system, this implementation maintains stability even under heavy loads, ensuring **no characters are lost** regardless of message size.

---

## ✨ Highlights & Reflections

- Designed a **custom binary protocol** with only two signals.  
- Learned robust signal handling with `sigaction()`.  
- Built a **synchronous confirmation system** to ensure reliable delivery.  
- Avoided full bitwise arithmetic by creatively using a dynamic buffer.  
- Achieved minimal delay with `usleep(50)` per bit.  
- Proved stable for very large transmissions (10k+ characters).

---

## 🚀 Build & Run

**Compile**
```bash
make
````

**Run Server**

```bash
./server
```

*Output:*

```
PID: 12345
```

**Run Client**

```bash
./client 12345 "Hello from client!"
```

**Server Output:**

```
Hello from client!
```

---

## 🛠️ Bonus Features

* Custom confirmation-based protocol.
* Reliable signal handling with `sigaction()`.
* Dynamic buffer without complex bitwise ops.
* Basic but effective input validation.
* Stable with extremely large messages.


