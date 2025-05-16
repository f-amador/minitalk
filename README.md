![image](https://github.com/user-attachments/assets/4cccac14-546b-4357-8122-6988c2dc6993)


# minitalk - UNIX Signal-Based IPC

![Unix Signals](https://img.shields.io/badge/Platform-UNIX-lightgrey) ![C Language](https://img.shields.io/badge/Language-C-blue) ![IPC](https://img.shields.io/badge/Type-IPC-green)

## Overview

**minitalk** is a lightweight client-server application demonstrating UNIX signal-based inter-process communication (IPC). Implemented in C, this project shows how processes can exchange data using `SIGUSR1` and `SIGUSR2` signals to transmit binary-encoded messages.

## Project Structure

<img src="structure.svg" alt="Project Structure" width="400">


## How It Works

## 🔄 Communication Theory

### **Signal-Based IPC Overview**
minitalk demonstrates **UNIX signal inter-process communication (IPC)** using:
- `SIGUSR1` → Binary `1`
- `SIGUSR2` → Binary `0`

### **Client-Server Workflow**
Each character is split into 8 bits (MSB-first):
Key Technical Concepts
1. Bitwise Transmission
Character	Binary Representation	Signal Sequence
'A' (65)	01000001	SIGUSR2 SIGUSR1 SIGUSR2 (x5) SIGUSR1
2. Synchronization
c

// Client timing control
usleep(100); // Between each bit transmission

3. Protocol Phases
Phase	Data Sent	Purpose
1	32-bit integer	Message length
2	N × 8-bit chars	Message content
3	8-bit \0	End-of-message marker
Limitations
Limitation	Implication
No encryption	Signals can be intercepted
No flow control	Potential signal queue overflow
UNIX-only	Incompatible with Windows subsystems
No error correction	Relies on OS signal delivery
Visualization Example

Client: "Hi"
1. Send length (2): 000...00010 (32 bits)
2. Send 'H': 01001000
3. Send 'i': 01101001
4. Send '\0': 00000000

```mermaid
sequenceDiagram
    participant Client
    participant Server
    Client->>Server: SIGUSR1 (bit 1)
    Server-->>Client: SIGUSR2 (ACK)
    Client->>Server: SIGUSR2 (bit 0)
    Server-->>Client: SIGUSR2 (ACK)
    Client->>Server: SIGUSR1 (final bit)
    Server-->>Client: SIGUSR1 (Message complete)
