![image](https://github.com/user-attachments/assets/4cccac14-546b-4357-8122-6988c2dc6993)


# minitalk - UNIX Signal-Based IPC

![Unix Signals](https://img.shields.io/badge/Platform-UNIX-lightgrey) ![C Language](https://img.shields.io/badge/Language-C-blue) ![IPC](https://img.shields.io/badge/Type-IPC-green)

## Overview

**minitalk** is a lightweight client-server application demonstrating UNIX signal-based inter-process communication (IPC). Implemented in C, this project shows how processes can exchange data using `SIGUSR1` and `SIGUSR2` signals to transmit binary-encoded messages.

## Project Structure

<img src="structure.svg" alt="Project Structure" width="400">


## How It Works

### Communication Protocol

1. **Encoding**:
   - Each character is broken down into 8 bits
   - `SIGUSR1` represents binary `1`
   - `SIGUSR2` represents binary `0`

2. **Transmission**:
   - Client sends signals sequentially (MSB first)
   - Server reconstructs characters from signal patterns
   - Null terminator indicates end of message

### Server Implementation
