# File Stream Positioning Functions

## tellg() and tellp()

These functions are used to get the current position of the file pointer in input and output streams respectively.

- `tellg()`: Returns the current position of the get pointer (input stream)
- `tellp()`: Returns the current position of the put pointer (output stream)

Both functions return a value of type `streampos` which represents the current position in the stream.

### Example:
```cpp
#include <fstream>
#include <iostream>

int main() {
    std::fstream file("example.txt");
    
    // Get current position
    std::streampos getPos = file.tellg();  // For input
    std::streampos putPos = file.tellp();  // For output
    
    std::cout << "Get pointer position: " << getPos << std::endl;
    std::cout << "Put pointer position: " << putPos << std::endl;
    
    return 0;
}
```

## seekg() and seekp()

These functions are used to set the position of the file pointer in input and output streams respectively.

- `seekg()`: Sets the position of the get pointer (input stream)
- `seekp()`: Sets the position of the put pointer (output stream)

### Syntax:
```cpp
// Absolute positioning
seekg(pos);    // For input
seekp(pos);    // For output

// Relative positioning
seekg(offset, direction);    // For input
seekp(offset, direction);    // For output
```

### Direction Constants:
- `ios::beg`: Beginning of the file
- `ios::cur`: Current position
- `ios::end`: End of the file

### Example:
```cpp
#include <fstream>
#include <iostream>

int main() {
    std::fstream file("example.txt");
    
    // Absolute positioning
    file.seekg(10);    // Move get pointer to position 10
    file.seekp(20);    // Move put pointer to position 20
    
    // Relative positioning
    file.seekg(5, std::ios::cur);    // Move 5 bytes forward from current position
    file.seekp(-3, std::ios::end);   // Move 3 bytes backward from end
    
    return 0;
}
```

## Common Use Cases

1. **Reading from specific positions:**
```cpp
file.seekg(100);  // Move to position 100
char buffer[50];
file.read(buffer, 50);  // Read 50 bytes from position 100
```

2. **Writing at specific positions:**
```cpp
file.seekp(200);  // Move to position 200
file.write("Hello", 5);  // Write "Hello" at position 200
```

3. **Getting file size:**
```cpp
file.seekg(0, std::ios::end);  // Move to end
std::streampos size = file.tellg();  // Get position (file size)
```

## Important Notes

1. These functions are available for both binary and text files
2. For text files, the exact position might not be what you expect due to line ending conversions
3. Always check if the file is open before using these functions
4. The positions are zero-based (0 is the first byte)
5. Negative offsets are only valid when using `ios::cur` or `ios::end` as the direction
