# System File

## Basic File Access Modes in C++
Here are the basic file access modes available in C++:

1. `ios::in` - Open for reading
```cpp
std::ifstream inFile("input.txt", std::ios::in);
```

2. `ios::out` - Open for writing (creates new file or truncates existing)
```cpp
std::ofstream outFile("output.txt", std::ios::out);
```

3. `ios::app` - Open for appending (adds to end of file)
```cpp
std::ofstream appendFile("append.txt", std::ios::app);
```

4. `ios::ate` - Open and seek to end of file
```cpp
std::fstream ateFile("ate.txt", std::ios::ate);
```

5. `ios::binary` - Open in binary mode
```cpp
std::fstream binaryFile("binary.bin", std::ios::binary);
```

6. `ios::trunc` - Truncate file if it exists
```cpp
std::ofstream truncFile("trunc.txt", std::ios::trunc);
```

### Common Combinations

You can combine these modes using the bitwise OR operator (`|`):

```cpp
// Read and write
std::fstream rwFile("readwrite.txt", std::ios::in | std::ios::out);

// Append and binary
std::fstream appendBinary("append.bin", std::ios::app | std::ios::binary);
```

### Important Notes
- Always check if files opened successfully using `is_open()`
- Remember to close files when done using `close()`
- Use appropriate stream types:
  - `ifstream` for reading
  - `ofstream` for writing
  - `fstream` for both reading and writing

## File State Flags

C++ provides several state flags to check the status of file operations:

1. `good()` - Returns true if no error flags are set
```cpp
if (file.good()) {
    // File is in good state
}
```

2. `eof()` - Returns true if end-of-file is reached
```cpp
if (file.eof()) {
    // Reached end of file
}
```

3. `fail()` - Returns true if a non-fatal error occurred
```cpp
if (file.fail()) {
    // Operation failed but stream is still usable
}
```

4. `bad()` - Returns true if a fatal error occurred
```cpp
if (file.bad()) {
    // Serious error occurred, stream is unusable
}
```

5. `clear()` - Clears all error flags
```cpp
file.clear(); // Reset error state
```

### Example Usage
```cpp
std::ifstream file("example.txt");
if (!file.is_open()) {
    std::cerr << "Error opening file" << std::endl;
    return;
}

while (file.good()) {
    std::string line;
    std::getline(file, line);
    
    if (file.eof()) {
        break;  // End of file reached
    }
    
    if (file.fail()) {
        std::cerr << "Error reading file" << std::endl;
        break;
    }
    
    // Process the line
    std::cout << line << std::endl;
}

file.close();
```