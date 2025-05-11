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