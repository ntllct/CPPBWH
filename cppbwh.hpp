/*!
 * @file       cppbwh.hpp
 * @brief      C++ Bitwise Hacks for Competitive Programming
 * @author     Alexander Alexeev &lt;ntllct@protonmail.com&gt;
 * @date       Oct 15, 2018
 * @copyright  Copyright &copy; 2018 Alexander Alexeev.
 *             This project is released under the MIT License.
 */

/*********************************************************************
 * MIT License
 * 
 * Copyright (c) 2018 Alexander Alexeev [ntllct@protonmail.com] 
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *********************************************************************/

#pragma once

#include <type_traits>
#include <string>
#include <nmmintrin.h>

namespace ntllct {
namespace cppbwh {

// Swap two variables using XOR operation
template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, void>::type
xorswap( T& a, T& b ) {
	a ^= b;
	b ^= a;
	a ^= b;
}

// Reverse all bits
// 00101000 -> 00010100
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 8, void>::type
reverse( T& x ) {
	x = (((x & 0xaaaaaaaaaaaaaaaa) >> 1) |
				((x & 0x5555555555555555) << 1));
	x = (((x & 0xcccccccccccccccc) >> 2) |
				((x & 0x3333333333333333) << 2));
	x = (((x & 0xf0f0f0f0f0f0f0f0) >> 4) |
				((x & 0x0f0f0f0f0f0f0f0f) << 4));
	x = (((x & 0xff00ff00ff00ff00) >> 8) |
				((x & 0x00ff00ff00ff00ff) << 8));
	x = (((x & 0xffff0000ffff0000) >> 16) |
				((x & 0x0000ffff0000ffff) << 16));
	x = ( ( x >> 32 ) | ( x << 32 ) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 4, void>::type
reverse( T& x ) {
	x = (((x & 0xaaaaaaaa) >> 1) |
				((x & 0x55555555) << 1));
	x = (((x & 0xcccccccc) >> 2) |
				((x & 0x33333333) << 2));
	x = (((x & 0xf0f0f0f0) >> 4) |
				((x & 0x0f0f0f0f) << 4));
	x = (((x & 0xff00ff00) >> 8) |
				((x & 0x00ff00ff) << 8));
	x = ( ( x >> 16 ) | ( x << 16 ) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 2, void>::type
reverse( T& x ) {
	x = (((x & 0xaaaa) >> 1) |
				((x & 0x5555) << 1));
	x = (((x & 0xcccc) >> 2) |
				((x & 0x3333) << 2));
	x = (((x & 0xf0f0) >> 4) |
				((x & 0x0f0f) << 4));
	x = ( ( x >> 8 ) | ( x << 8 ) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 1, void>::type
reverse( T& x ) {
	x = (((x & 0xaa) >> 1) |
				((x & 0x55) << 1));
	x = (((x & 0xcc) >> 2) |
				((x & 0x33) << 2));
	x = ( ( x >> 4 ) | ( x << 4 ) );
}

// Getting lowest set bit of a number
// 01010010 -> 00000010
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, T>::type
lsb( T x ) {
	return( x ^ ( x & ( x - 1 ) ) );
}

// Getting highest set bit of a number
// 01010010 -> 01000000
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 8, T>::type
msb( T x ) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);
	x |= (x >> 32);
	return( x & ~( x >> 1 ) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 4, T>::type
msb( T x ) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);
	return( x & ~( x >> 1 ) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 2, T>::type
msb( T x ) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	return( x & ~( x >> 1 ) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 1, T>::type
msb( T x ) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	return( x & ~( x >> 1 ) );
}

// Get binary code of a number
// Destination buffer (char*) must be already allocated
// unsigned char val = 5;
// tobin( val, out ) -> out contains "00000101"
// tobin( val, out, true ) -> out contains "101"
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, void>::type
tobin( T x, char* out, bool skip_first_zero = false ) {
	for( T i = 1UL << sizeof( T ) * 8 - 1; i != 0; i >>= 1 ) {
		if( skip_first_zero && ( x & i ) == 0 )
			continue;
		skip_first_zero = false;
		if( ( x & i ) != 0 )
			*out++ = '1';
		else
			*out++ = '0';
	}
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, void>::type
tobin( T x, std::string& out, bool skip_first_zero = false ) {
	for( T i = 1UL << sizeof( T ) * 8 - 1; i != 0; i >>= 1 ) {
		if( skip_first_zero && ( x & i ) == 0 )
			continue;
		skip_first_zero = false;
		if( ( x & i ) != 0 )
			out.push_back( '1' );
		else
			out.push_back( '0' );
	}
}

// Swap odd and even bits
// 10100010 -> 01010001
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 8, void>::type
swapn( T& x ) {
	x = ( ( (x & 0xaaaaaaaaaaaaaaaa) >> 1)
			| ((x & 0x5555555555555555) << 1) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 4, void>::type
swapn( T& x ) {
	x = ( ( (x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 2, void>::type
swapn( T& x ) {
	x = ( ( (x & 0xaaaa) >> 1) | ((x & 0x5555) << 1) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 1, void>::type
swapn( T& x ) {
	x = ( ( (x & 0xaa) >> 1) | ((x & 0x55) << 1) );
}

// Log2 for unsigned integer variables
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value && sizeof( T ) == 8
, T>::type
floor_log2( T x ) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);
	x |= (x >> 32);
	return( _mm_popcnt_u64( x >> 1 ) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value && sizeof( T ) == 4
, T>::type
floor_log2( T x ) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);
	return( _mm_popcnt_u64( x >> 1 ) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value && sizeof( T ) == 2
, T>::type
floor_log2( T x ) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	return( _mm_popcnt_u64( x >> 1 ) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value && sizeof( T ) == 1
, T>::type
floor_log2( T x ) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	return( _mm_popcnt_u64( x >> 1 ) );
}

// Example of multiplication integer by 3.5
// You can change the value
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, T>::type
mul_3_5( T x ) {
	return( ( x << 1 ) + x + ( x >> 1 ) );
}

// Next power of 2
// 5 -> 8
// 14 -> 16
// 27 -> 32
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 8, T>::type
nlpo2( T x ) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);
	x |= (x >> 32);
	return( x + 1 );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 4, T>::type
nlpo2( T x ) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);
	return( x + 1 );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 2, T>::type
nlpo2( T x ) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	return( x + 1 );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value &&
sizeof( T ) == 1, T>::type
nlpo2( T x ) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	return( x + 1 );
}

// Set, clear and check bit at n’th position
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, void>::type
setbit( T& x, unsigned int pos ) {
	x |= 1UL << pos;
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, void>::type
clearbit( T& x, unsigned int pos ) {
	x &= ~( 1UL << pos );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, bool>::type
checkbit( const T& x, unsigned int pos ) {
	return( !!( x & ( 1UL << pos ) ) );
}

// Rotate bits in a number
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, T>::type
rotate_left( T x, unsigned int count ) {
	count %= sizeof( x ) * 8;
	return( x << count | x >> ( sizeof( x ) * 8 - count ) );
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, T>::type
rotate_right( T x, unsigned int count ) {
	count %= sizeof( x ) * 8;
	return( x << ( sizeof( x ) * 8 - count ) | x >> count );
}

// Convert data to hex format
void hex( const char* in, unsigned int length, char* out ) {
	const char* hex_char_ = "0123456789abcdef";
	unsigned char buf;
	unsigned char mask = 0x0F;
	for(unsigned int i = 0; i < length; i++) {
		buf = *in;
		buf >>= 4;
		buf &= mask;
		*out++ = hex_char_[buf];
		buf = *in++;
		buf &= mask;
		*out++ = hex_char_[buf];
	}
	*out = '\0';
}
void hex( const char* in, unsigned int length, std::string& out ) {
	const char* hex_char_ = "0123456789abcdef";
	unsigned char buf;
	unsigned char mask = 0x0F;
	for(unsigned int i = 0; i < length; i++) {
		buf = *in;
		buf >>= 4;
		buf &= mask;
		out.push_back( hex_char_[buf] );
		buf = *in++;
		buf &= mask;
		out.push_back( hex_char_[buf] );
	}
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, void>::type
hex( const T x, char* out, bool skip_zero = false ) {
	const char* hex_char_ = "0123456789abcdef";
	const char* in_ = reinterpret_cast<const char*>( &x );
	in_ += sizeof( x ) - 1;
	unsigned char buf;
	unsigned char mask = 0x0F;
	for(unsigned int i = 0; i < sizeof( x ); i++, in_-- ) {
		if( skip_zero && *in_ == 0 )
			continue;
		skip_zero = false;
		buf = *in_;
		buf >>= 4;
		buf &= mask;
		*out++ = hex_char_[buf];
		buf = *in_;
		buf &= mask;
		*out++ = hex_char_[buf];
	}
	*out = '\0';
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, void>::type
hex( const T x, std::string& out, bool skip_zero = false ) {
	const char* hex_char_ = "0123456789abcdef";
	const char* in_ = reinterpret_cast<const char*>( &x );
	in_ += sizeof( x ) - 1;
	unsigned char buf;
	unsigned char mask = 0x0F;
	for( unsigned int i = 0; i < sizeof( x ); i++, in_-- ) {
		if( skip_zero && *in_ == 0 )
			continue;
		skip_zero = false;
		buf = *in_;
		buf >>= 4;
		buf &= mask;
		out.push_back( hex_char_[buf] );
		buf = *in_;
		buf &= mask;
		out.push_back( hex_char_[buf] );
	}
}

// Convert data from hex to bin format
// Number of input bytes must be an even
void unhex( const char* in, unsigned int length, char* out ) {
	for(unsigned int i = 0; i < length; i++, in++ ) {
		if( isxdigit( *in ) ) {
			if( i % 2 == 0 )
				*out = 0;
			else
				*out <<= 4;
		} else {
			break;
		}
		
		if( isdigit( *in ) ) {
			*out |= *in - '0';
		} else if( isxdigit( *in ) ) {
			if( isupper( *in ) )
				*out |= *in - 'A' + 10;
			else
				*out |= *in - 'a' + 10;
		}
		if( i % 2 == 1 )
			*out++;
	}
}
void unhex( const char* in, unsigned int length, std::string& out ) {
	char buf_ = 0;
	for(unsigned int i = 0; i < length; i++, in++ ) {
		if( isxdigit( *in ) ) {
			if( i % 2 == 0 )
				buf_ = 0;
			else
				buf_ <<= 4;
		} else {
			if( i % 2 == 1 )
				out.push_back( buf_ );
			break;
		}
		
		if( isdigit( *in ) ) {
			buf_ |= *in - '0';
		} else if( isxdigit( *in ) ) {
			if( isupper( *in ) )
				buf_ |= *in - 'A' + 10;
			else
				buf_ |= *in - 'a' + 10;
		}
		
		if( i % 2 == 1 )
			out.push_back( buf_ );
		else if( i == length - 1 )
			out.push_back( buf_ );
	}
}
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, void>::type
unhex( const char* in, T& x ) {
	x = 0;
	for(unsigned int i = 0; i < sizeof( x ) * 2; i++, in++ ) {
		if( isdigit( *in ) ) {
			x <<= 4;
			x |= *in - '0';
		} else if( isxdigit( *in ) ) {
			x <<= 4;
			if( isupper( *in ) )
				x |= *in - 'A' + 10;
			else
				x |= *in - 'a' + 10;
		} else {
			break;
		}
	}
}

} // cppbwh
} // ntllct

