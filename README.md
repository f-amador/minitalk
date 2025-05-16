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
```mermaid
sequenceDiagram
    participant Client
    participant Server

    Note over Server: Starts first<br>Displays PID
    Client->>Server: 1. Sends message length (32 bits)
    Server-->>Client: SIGUSR2 (ACK each bit)
    Client->>Server: 2. Transmits each character (8 bits/char)
    Client->>Server: 3. Sends null terminator
    Server-->>Client: SIGUSR1 (ACK)
    Note over Client: Exits on acknowledgment
