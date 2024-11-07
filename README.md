# 📖 Dictionary Application

A high-performance dictionary application in C++ that efficiently loads and searches for word definitions from large datasets, designed to demonstrate optimized memory management, modular structure, and algorithmic efficiency.

---

## 🛠️ Key Features

- **Dynamic Word Loading**: Reads words and definitions from a CSV file, supporting multi-language dictionaries.
- **Optimized Search**: Allows rapid word lookups, with options for showing the first or all definitions.
- **Event Timing and Logging**: Measures and logs performance for operations using `std::chrono`, providing insights into execution time.
- **Configurable Settings**: Customizable options to display additional details, including part of speech, and time units in nanoseconds, microseconds, or milliseconds.

---

## 🚀 Core Modules

### `settings`

- Manages global application settings such as verbose output and time units for operation durations.

### `event`

- Tracks individual events with name and duration, allowing structured event logging.

### `logger`

- Stores and manages a dynamically sized collection of events.

### `timeMonitor`

- Provides precise time-tracking for operations, supporting start and stop events.

### `dictionary`

- Manages words in memory, supports word searches, and displays definitions based on customizable settings.

---
