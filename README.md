# CPPBWH library

This library contains some bitwise template functions for competitive programming. You can research and modify it as you wish.

# Examples:

Swap two arithmetic variables without temporary buffer:

```cpp
cppbwh::xorswap( x, y );
```

Reverse all bits in arithmetic variable:

```cpp
cppbwh::reverse( x ); // 00101000 -> 00010100
```

Getting lowest set bit of a number:

```cpp
cppbwh::lsb( x ); // 01010010 -> 00000010
```

Getting highest set bit of a number:

```cpp
cppbwh::lsb( x ); // 01010010 -> 01000000
```

Get binary code of an arithmetic variable:

```cpp
cppbwh::tobin( x, out, false ); // 5 -> "00000101"
cppbwh::tobin( x, out, true ); // 5 -> "101"
```

Swap odd and even bits:

```cpp
cppbwh::swapn( x ); // 10100010 -> 01010001
```

Log2 for unsigned integer variables:

```cpp
cppbwh::floor_log2( x ); // 8 -> 3, 9 -> 3
```

Example of multiplication integer by 3.5:

```cpp
cppbwh::mul_3_5( x ); // 4 -> 14
```

Next power of 2:

```cpp
cppbwh::nlpo2( x ); // 5 -> 8, 14 -> 16, 27 -> 32
```

Set, clear and check bit at n’th position:

```cpp
cppbwh::setbit( x, 5 ); // Set bit at 5
cppbwh::clearbit( x, 5 ); // Clear bit at 5
cppbwh::checkbit( x, 5 ); // Check bit at 5 and return true or false
```

Rotate bits in a number:

```cpp
cppbwh::rotate_left( x, 3 ); // 00101000 -> 01000001
cppbwh::rotate_right( x, 3 ); // 00101000 -> 00000101
```

Convert data to hex format:

```cpp
cppbwh::hex( const char* in, unsigned int length, char* out );
cppbwh::hex( const char* in, unsigned int length, std::string& out );
cppbwh::hex( const T x, char* out, bool skip_zero = false );
cppbwh::hex( const T x, std::string& out, bool skip_zero = false );
```

Convert data from hex to bin format:

```cpp
cppbwh::unhex( const char* in, unsigned int length, char* out );
cppbwh::unhex( const char* in, unsigned int length, std::string& out );
cppbwh::unhex( const char* in, T& x );
```

**See source code for more details.**

# Compilation:

```bash
g++ -std=c++14 -m64 -O2 -mavx cppbwh_test.cpp -o cppbwh_test
```
