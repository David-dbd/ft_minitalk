<h1> ft_minitalk 🧠💬 </h1>

A UNIX signal-based communication system between two independent processes: client and server. This project was developed for the 42 curriculum, under the constraint of using only SIGUSR1 and SIGUSR2 as the protocol for data transmission.

<h2>📦 Project Overview </h2>

The goal of ft_minitalk is to create two programs:

<strong>server:</strong> Awaits messages and displays them.

<strong>client:</strong> Sends a user-defined message to the server using only signals.

The entire communication mechanism relies exclusively on SIGUSR1 and SIGUSR2, meaning you must creatively build your own protocol from scratch.

<h2>📚 Theory Context </h2>

What are signals?
In UNIX systems, a signal is a way for processes to send notifications or interrupts to each other. Each signal has a numeric code and can be intercepted and handled via a signal handler. For this project:

<em>SIGUSR1 → treated as 1</em>

<em>SIGUSR2 → treated as 0</em>

💡 Since signals are asynchronous, the moment one is received, it interrupts the flow of the program, jumping to the signal handler immediately — even if you're in the middle of another function.

Signal Handlers
Using sigaction() in the server, signals are caught and processed bit-by-bit. Once 8 bits are collected, they're decoded and printed as characters.

<h2>💡 How It Works</h2>

<u><strong>Server:</strong></u>
Launched without arguments.

Displays its PID (Process Identifier) on startup.

Waits for signals from the client.

Assembles incoming bits into characters.

Displays the received message in real time.

Sends a confirmation signal (SIGUSR1) to the client after processing each character.

<u><strong>Client:</strong></u>
Launched with the server’s PID and a message string.

Converts each character into binary (8 bits).

Sends one signal per bit (SIGUSR1 for 1, SIGUSR2 for 0).

Waits for confirmation after each character to continue.

Terminates communication by sending an EOT (End Of Transmission) signal.

<h2>🧠 Project Logic </h2>

Initially, I had little experience with bitwise operations. So instead of using masking or shifting techniques, I implemented a buffer-based system that collects each signal as a raw value.

The message transfer sequence is:

Convert each character of the message to binary (8 bits).

Send each bit using SIGUSR1 or SIGUSR2.

Server buffers and reconstructs each character.

Once done, server sends back a confirmation.

Client waits for this confirmation before sending the next character.

🔁 This loop continues until the entire message is sent, followed by an EOT signal.

To avoid timing issues and loss of data, the client uses usleep(50) between bits — but thanks to server confirmations, delays are minimized.

<h2>🔍 Input Validation </h2>

Server receives no arguments.

Client receives two arguments:

The server’s PID.

A message string.

PID is validated for:

Proper length (within expected range).

Strict numeric characters — if it contains letters or is malformed, it’s treated as an error.

<h2>✨ Highlights & Reflections </h2>

At the time, I didn’t fully understand bitwise operations — and that limitation became a challenge I embraced. Designing my own buffer-based method pushed me to think creatively and logically under constraints. The result is a clean, responsive system with minimal delay and clear signal flow — fully functional with just usleep(50) between bits.

<h3>🚀 Build & Run</h3>

bash
<em>Compile</em>
make

<em>Run server in one terminal</em>
./server

<em>Run client in another</em>
./client <server_pid> "Your custom message"
🧪 Example
bash
$ ./server
PID: 12345

$ ./client 12345 "Hello from client!"
Server displays: Hello from client!

<h3>🛠️ Bonus Features</h3>
Custom signal protocol using confirmation signals.

sigaction() for robust signal handling.

Dynamic buffer system without full bitwise arithmetic.

Basic input validation for cleaner UX and error handling.
