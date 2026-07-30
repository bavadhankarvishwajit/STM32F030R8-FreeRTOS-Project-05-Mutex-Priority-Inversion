# STM32F030R8 FreeRTOS Project 5

## Mutex, Priority Inversion and Priority Inheritance

This repository contains Project 5 of the STM32F030R8 FreeRTOS learning series.

The project demonstrates:

- FreeRTOS task scheduling
- Shared resource management
- UART protection using mutexes
- Priority inversion
- Priority inheritance
- Context switching
- Task blocking and unblocking

---

## Hardware

| Component | Description |
|------------|--------------|
| MCU | STM32F030R8 |
| Core | ARM Cortex-M0 |
| Clock | 8 MHz |
| IDE | STM32CubeIDE |
| RTOS | FreeRTOS V11 |
| UART | USART2 |
| Terminal | RealTerm |

---

## Project 5

### Objective

Protect a shared UART resource using a mutex.

### Architecture

```text
High Task
Medium Task
Low Task
     │
     ▼
   Mutex
     │
     ▼
   USART2
     │
     ▼
 RealTerm
```

---

### Project 5 Poster

<p align="center">
    <img src="Posters/project_5_mutex.png" width="900">
</p>

---

### Project Description

This project demonstrates:

- Mutex creation
- Shared resource protection
- Mutual exclusion
- Scheduler operation
- Context switching
- UART synchronization

---

### APIs used

```c
xSemaphoreCreateMutex()
xSemaphoreTake()
xSemaphoreGive()
vTaskDelay()
xTaskCreate()
vTaskStartScheduler()
```

---

### Files

```text
Inc/
│
├── FreeRTOSConfig.h
├── gpio.h
├── mutex_demo.h
├── system.h
└── uart.h

Src/
│
├── gpio.c
├── hooks.c
├── main.c
├── mutex_demo.c
├── system.c
└── uart.c
```

---

## Project 5.1

### Objective

Demonstrate priority inversion and priority inheritance.

---

### Project 5.1 Poster

<p align="center">
    <img src="Posters/project_5_1_priority_inversion.png" width="900">
</p>

---

### Project Description

This project demonstrates:

- Priority inversion
- Priority inheritance
- Scheduler behaviour
- Task synchronization
- Context switching
- Mutex ownership

---

### Task priorities

| Task | Priority |
|------|------------|
| HighTask | 3 |
| MediumTask | 2 |
| LowTask | 1 |

---

### Execution sequence

```text
LOW
 │
 ▼
Locks mutex
 │
 ▼
HIGH waits
 │
 ▼
MEDIUM executes
 │
 ▼
Priority inheritance
 │
 ▼
LOW releases mutex
 │
 ▼
HIGH executes
```

---

### Expected output

```text
LOW : Mutex acquired

HIGH : Waiting for mutex

MEDIUM : Running

LOW : Mutex released

HIGH : Mutex acquired
```

---

## Scheduler state diagram

```text
READY
   │
   ▼
RUNNING
   │
   ▼
BLOCKED
   │
   ▼
READY
```

---

## Project Comparison

This section compares Project 5 and Project 5.1.

---

### Comparison Poster

<p align="center">
    <img src="Posters/project_5_comparison.png" width="900">
</p>

---

### Comparison table

| Feature | Project 5 | Project 5.1 |
|----------|------------|--------------|
| Mutex | ✅ | ✅ |
| Shared resources | ✅ | ✅ |
| Priority inversion | ❌ | ✅ |
| Priority inheritance | ❌ | ✅ |
| Task synchronization | ✅ | ✅ |
| Context switching | Basic | Advanced |
| Scheduler analysis | Basic | Advanced |

---

### Scheduler timeline

```text
LOW
 │
 ▼
Locks mutex

HIGH
 │
 ▼
Blocked

MEDIUM
 │
 ▼
Running

LOW
 │
 ▼
Priority inherited

HIGH
 │
 ▼
Running
```

---

## Build environment

- STM32CubeIDE
- ARM GCC
- FreeRTOS V11
- CMSIS

---

## Build instructions

1. Import the project into STM32CubeIDE.

2. Build the project.

3. Flash the firmware to the STM32F030R8 board.

4. Open RealTerm.

5. Select 115200 baud.

6. Observe the UART output.

---

## Learning outcomes

- FreeRTOS scheduler
- Mutexes
- Shared resources
- Task synchronization
- Priority inversion
- Priority inheritance
- Context switching
- UART communication

---

## Repository structure

```text
STM32F030R8-FreeRTOS-Project-05
│
├── Core
├── FreeRTOS
├── README.md
│
├── Posters
│   ├── project_5_mutex.png
│   ├── project_5_1_priority_inversion.png
│   └── project_5_comparison.png
│
└── Screenshots
```

---

## Author

**Vishwajit Mahesh Bavadhankar**

Embedded Systems Engineer | Firmware Developer | RTOS Developer
