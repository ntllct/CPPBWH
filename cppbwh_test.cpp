// Copyright (c) 2018 Alexander Alexeev [ntllct@protonmail.com] 
// g++ -std=c++14 -m64 -O2 -mavx cppbwh_test.cpp -o cppbwh_test

#include <iostream>
#include <cstddef>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <random>
#include <chrono>

#include "cppbwh.hpp"

std::mt19937_64 random64;

using namespace ntllct;

void TEST( bool compare_result, const char* prefix ) {
	std::cout << prefix << ": " << "\033[1m";
	if( compare_result )
		std::cout << "\033[32m" << "OK!" << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Failed!" << "\033[0m" << std::endl;
}

void test_xorswap() {
	size_t val1 = random64() >> 2;
	size_t val2 = random64() >> 2;
	size_t val3 = val1;
	size_t val4 = val2;
	
	unsigned long ul_val1 = val1;
	unsigned long ul_val2 = val2;
	unsigned long ul_val3 = val3;
	unsigned long ul_val4 = val4;
	unsigned int ui_val1 = val1;
	unsigned int ui_val2 = val2;
	unsigned int ui_val3 = val3;
	unsigned int ui_val4 = val4;
	unsigned short us_val1 = val1;
	unsigned short us_val2 = val2;
	unsigned short us_val3 = val3;
	unsigned short us_val4 = val4;
	unsigned char uc_val1 = val1;
	unsigned char uc_val2 = val2;
	unsigned char uc_val3 = val3;
	unsigned char uc_val4 = val4;
	
	long l_val1 = -val1;
	long l_val2 = val2;
	long l_val3 = -val3;
	long l_val4 = val4;
	int i_val1 = -val1;
	int i_val2 = val2;
	int i_val3 = -val3;
	int i_val4 = val4;
	short s_val1 = -val1;
	short s_val2 = val2;
	short s_val3 = -val3;
	short s_val4 = val4;
	char c_val1 = -val1;
	char c_val2 = val2;
	char c_val3 = -val3;
	char c_val4 = val4;
	
	cppbwh::xorswap( val1, val2 );
	TEST( val1 == val4 && val2 == val3, "xorswap (size_t)" );
	
	cppbwh::xorswap( ul_val1, ul_val2 );
	TEST( ul_val1 == ul_val4 && ul_val2 == ul_val3,
										"xorswap (unsigned long)" );
	
	cppbwh::xorswap( ui_val1, ui_val2 );
	TEST( ui_val1 == ui_val4 && ui_val2 == ui_val3,
										"xorswap (unsigned int)" );
	
	cppbwh::xorswap( us_val1, us_val2 );
	TEST( us_val1 == us_val4 && us_val2 == us_val3,
										"xorswap (unsigned short)" );
	
	cppbwh::xorswap( uc_val1, uc_val2 );
	TEST( uc_val1 == uc_val4 && uc_val2 == uc_val3,
										"xorswap (unsigned char)" );
	
	
	cppbwh::xorswap( l_val1, l_val2 );
	TEST( l_val1 == l_val4 && l_val2 == l_val3,
												"xorswap (long)" );
	
	cppbwh::xorswap( i_val1, i_val2 );
	TEST( i_val1 == i_val4 && i_val2 == i_val3,
												"xorswap (int)" );
	
	cppbwh::xorswap( s_val1, s_val2 );
	TEST( s_val1 == s_val4 && s_val2 == s_val3,
												"xorswap (short)" );
	
	cppbwh::xorswap( c_val1, c_val2 );
	TEST( c_val1 == c_val4 && c_val2 == c_val3,
												"xorswap (char)" );
	
	std::cout << std::endl;
}
void test_bit_reverse() {
	
	size_t val1 = random64();
	
	unsigned long ul_val1 = val1;
	unsigned int ui_val1 = val1;
	unsigned short us_val1 = val1;
	unsigned char uc_val1 = val1;
	
	std::string bit_str1_;
	std::string bit_str2_;
	
	bit_str1_.clear();
	bit_str2_.clear();
	cppbwh::tobin( val1, bit_str1_ );
	std::reverse( bit_str1_.begin(), bit_str1_.end() );
	cppbwh::reverse( val1 );
	cppbwh::tobin( val1, bit_str2_ );
	TEST( bit_str1_.compare( bit_str2_ ) == 0,
										"reverse (size_t)" );
	
	bit_str1_.clear();
	bit_str2_.clear();
	cppbwh::tobin( ul_val1, bit_str1_ );
	std::reverse( bit_str1_.begin(), bit_str1_.end() );
	cppbwh::reverse( ul_val1 );
	cppbwh::tobin( ul_val1, bit_str2_ );
	TEST( bit_str1_.compare( bit_str2_ ) == 0,
										"reverse (unsigned long)" );
	
	bit_str1_.clear();
	bit_str2_.clear();
	cppbwh::tobin( ui_val1, bit_str1_ );
	std::reverse( bit_str1_.begin(), bit_str1_.end() );
	cppbwh::reverse( ui_val1 );
	cppbwh::tobin( ui_val1, bit_str2_ );
	TEST( bit_str1_.compare( bit_str2_ ) == 0,
										"reverse (unsigned int)" );
	
	bit_str1_.clear();
	bit_str2_.clear();
	cppbwh::tobin( us_val1, bit_str1_ );
	std::reverse( bit_str1_.begin(), bit_str1_.end() );
	cppbwh::reverse( us_val1 );
	cppbwh::tobin( us_val1, bit_str2_ );
	TEST( bit_str1_.compare( bit_str2_ ) == 0,
										"reverse (unsigned short)" );
	
	bit_str1_.clear();
	bit_str2_.clear();
	cppbwh::tobin( uc_val1, bit_str1_ );
	std::reverse( bit_str1_.begin(), bit_str1_.end() );
	cppbwh::reverse( uc_val1 );
	cppbwh::tobin( uc_val1, bit_str2_ );
	TEST( bit_str1_.compare( bit_str2_ ) == 0,
										"reverse (unsigned char)" );
	
	std::cout << std::endl;
}
void test_lsb() {
	
	size_t val1 = random64();
	val1 |= 1UL;
	val1 <<= 5;
	
	unsigned long ul_val1 = val1;
	unsigned int ui_val1 = val1;
	unsigned short us_val1 = val1;
	unsigned char uc_val1 = val1;
	
	TEST( cppbwh::lsb( val1 ) == 1UL << 5,
									"lsb (size_t)" );
	TEST( cppbwh::lsb( ul_val1 ) == 1UL << 5,
									"lsb (unsigned long)" );
	TEST( cppbwh::lsb( ui_val1 ) == 1UL << 5,
									"lsb (unsigned int)" );
	TEST( cppbwh::lsb( us_val1 ) == 1UL << 5,
									"lsb (unsigned short)" );
	TEST( cppbwh::lsb( uc_val1 ) == 1UL << 5,
									"lsb (unsigned char)" );
	
	std::cout << std::endl;
}
void test_tobin() {
	
	size_t val1 = 0b00000100'00000000'00000000'00001000'00000000'00000100'10000000'10010001;
	
	unsigned long ul_val1 = val1;
	unsigned int ui_val1 = val1;
	unsigned short us_val1 = val1;
	unsigned char uc_val1 = val1;
	
	char buf_[65]{0};
	cppbwh::tobin( val1, buf_, false );
	
	TEST( strcmp(	"00000100000000000000000000001000"
					"00000000000001001000000010010001", buf_ ) == 0,
									"tobin (size_t)" );
	memset( buf_, 0, 65 );
	cppbwh::tobin( ul_val1, buf_, false );
	TEST( strcmp(	"00000100000000000000000000001000"
					"00000000000001001000000010010001", buf_ ) == 0,
									"tobin (unsigned long)" );
	memset( buf_, 0, 65 );
	cppbwh::tobin( ui_val1, buf_, false );
	TEST( strcmp(	"00000000000001001000000010010001", buf_ ) == 0,
									"tobin (unsigned int)" );
	memset( buf_, 0, 65 );
	cppbwh::tobin( us_val1, buf_, false );
	TEST( strcmp(	"1000000010010001", buf_ ) == 0,
									"tobin (unsigned short)" );
	memset( buf_, 0, 65 );
	cppbwh::tobin( uc_val1, buf_, false );
	TEST( strcmp(	"10010001", buf_ ) == 0,
									"tobin (unsigned char)" );
	
	memset( buf_, 0, 65 );
	cppbwh::tobin( val1, buf_, true );
	TEST( strcmp(	"100000000000000000000001000"
					"00000000000001001000000010010001", buf_ ) == 0,
									"tobin (size_t)" );
	memset( buf_, 0, 65 );
	cppbwh::tobin( ul_val1, buf_, true );
	TEST( strcmp(	"100000000000000000000001000"
					"00000000000001001000000010010001", buf_ ) == 0,
									"tobin (unsigned long)" );
	memset( buf_, 0, 65 );
	cppbwh::tobin( ui_val1, buf_, true );
	TEST( strcmp(	"1001000000010010001", buf_ ) == 0,
									"tobin (unsigned int)" );
									
	
	
	std::string bin_val_;
	cppbwh::tobin( val1, bin_val_, false );
	
	TEST( strcmp(	"00000100000000000000000000001000"
					"00000000000001001000000010010001", bin_val_.c_str() ) == 0,
									"tobin (size_t)" );
	bin_val_.clear();
	cppbwh::tobin( ul_val1, bin_val_, false );
	TEST( strcmp(	"00000100000000000000000000001000"
					"00000000000001001000000010010001", bin_val_.c_str() ) == 0,
									"tobin (unsigned long)" );
	bin_val_.clear();
	cppbwh::tobin( ui_val1, bin_val_, false );
	TEST( strcmp(	"00000000000001001000000010010001", bin_val_.c_str() ) == 0,
									"tobin (unsigned int)" );
	bin_val_.clear();
	cppbwh::tobin( us_val1, bin_val_, false );
	TEST( strcmp(	"1000000010010001", bin_val_.c_str() ) == 0,
									"tobin (unsigned short)" );
	bin_val_.clear();
	cppbwh::tobin( uc_val1, bin_val_, false );
	TEST( strcmp(	"10010001", bin_val_.c_str() ) == 0,
									"tobin (unsigned char)" );
	
	bin_val_.clear();
	cppbwh::tobin( val1, bin_val_, true );
	TEST( strcmp(	"100000000000000000000001000"
					"00000000000001001000000010010001", bin_val_.c_str() ) == 0,
									"tobin (size_t)" );
	bin_val_.clear();
	cppbwh::tobin( ul_val1, bin_val_, true );
	TEST( strcmp(	"100000000000000000000001000"
					"00000000000001001000000010010001", bin_val_.c_str() ) == 0,
									"tobin (unsigned long)" );
	bin_val_.clear();
	cppbwh::tobin( ui_val1, bin_val_, true );
	TEST( strcmp(	"1001000000010010001", bin_val_.c_str() ) == 0,
									"tobin (unsigned int)" );
	
	std::cout << std::endl;
}
void test_swapn() {
	
	size_t val1 = 0b10101010'10101010'10101010'10101010'10101010'10101010'10101010'10101010;
	size_t val2 = 0b01010101'01010101'01010101'01010101'01010101'01010101'01010101'01010101;
	
	unsigned long ul_val1 = val1;
	unsigned long ul_val2 = val2;
	unsigned int ui_val1 = val1;
	unsigned int ui_val2 = val2;
	unsigned short us_val1 = val1;
	unsigned short us_val2 = val2;
	unsigned char uc_val1 = val1;
	unsigned char uc_val2 = val2;
	
	cppbwh::swapn( val1 );
	TEST( val1 == val2, "swapn (size_t)" );
	cppbwh::swapn( ul_val1 );
	TEST( ul_val1 == ul_val2, "swapn (unsigned long)" );
	cppbwh::swapn( ui_val1 );
	TEST( ui_val1 == ui_val2, "swapn (unsigned int)" );
	cppbwh::swapn( us_val1 );
	TEST( us_val1 == us_val2, "swapn (unsigned short)" );
	cppbwh::swapn( uc_val1 );
	TEST( uc_val1 == uc_val2, "swapn (unsigned char)" );
	
	val1 = 0b10101010'10101010'10101010'10101010'10101010'10101010'10101010'10011001;
	val2 = 0b01010101'01010101'01010101'01010101'01010101'01010101'01010101'01100110;
	
	ul_val1 = val1;
	ul_val2 = val2;
	ui_val1 = val1;
	ui_val2 = val2;
	us_val1 = val1;
	us_val2 = val2;
	uc_val1 = val1;
	uc_val2 = val2;
	
	cppbwh::swapn( val1 );
	TEST( val1 == val2, "swapn (size_t)" );
	cppbwh::swapn( ul_val1 );
	TEST( ul_val1 == ul_val2, "swapn (unsigned long)" );
	cppbwh::swapn( ui_val1 );
	TEST( ui_val1 == ui_val2, "swapn (unsigned int)" );
	cppbwh::swapn( us_val1 );
	TEST( us_val1 == us_val2, "swapn (unsigned short)" );
	cppbwh::swapn( uc_val1 );
	TEST( uc_val1 == uc_val2, "swapn (unsigned char)" );
	
	std::cout << std::endl;
}
void test_floor_log2() {
	
	for( unsigned int i = 0; i < 5; ++i ) {
		size_t val1 = random64();
		
		unsigned long ul_val1 = val1;
		unsigned int ui_val1 = val1;
		unsigned short us_val1 = val1;
		unsigned char uc_val1 = val1;
		
		TEST( cppbwh::floor_log2( val1 )	== static_cast<size_t>( std::floor( std::log2( val1 ) ) ),
										"floor_log2 (size_t)" );
		TEST( cppbwh::floor_log2( ul_val1 )	== static_cast<unsigned long>( std::floor( std::log2( ul_val1 ) ) ),
										"floor_log2 (unsigned long)" );
		TEST( cppbwh::floor_log2( ui_val1 )	== static_cast<unsigned int>( std::floor( std::log2( ui_val1 ) ) ),
										"floor_log2 (unsigned int)" );
		TEST( cppbwh::floor_log2( us_val1 )	== static_cast<unsigned short>( std::floor( std::log2( us_val1 ) ) ),
										"floor_log2 (unsigned short)" );
		TEST( cppbwh::floor_log2( uc_val1 )	== static_cast<unsigned char>( std::floor( std::log2( uc_val1 ) ) ),
										"floor_log2 (unsigned char)" );
	}
	std::cout << std::endl;
}
void test_mul_3_5() {
	
	for( unsigned int i = 0; i < 5; ++i ) {
		size_t val1 = random64() >> 2;
		val1 >>= 2;
		unsigned long ul_val1 = val1;
		//ul_val1 >>= 2;
		unsigned int ui_val1 = val1;
		ui_val1 >>= 2;
		unsigned short us_val1 = val1;
		us_val1 >>= 2;
		unsigned char uc_val1 = val1;
		uc_val1 >>= 2;
		std::cout << "Can be errors! (Round errors)" << std::endl;
		TEST( cppbwh::mul_3_5( val1 )	== static_cast<size_t>( std::floor( static_cast<long double>( val1 ) * 3.5 ) ),
										"test_mul_3_5 (size_t)" );
		std::cout << cppbwh::mul_3_5( val1 )	<< ", " << static_cast<size_t>( std::floor( static_cast<long double>( val1 ) * 3.5 ) ) << std::endl;
		TEST( cppbwh::mul_3_5( ul_val1 )	== static_cast<unsigned long>( std::floor( static_cast<long double>( ul_val1 ) * 3.5 ) ),
										"test_mul_3_5 (unsigned long)" );
		TEST( cppbwh::mul_3_5( ui_val1 )	== static_cast<unsigned int>( std::floor( static_cast<long double>( ui_val1 ) * 3.5 ) ),
										"test_mul_3_5 (unsigned int)" );
		TEST( cppbwh::mul_3_5( us_val1 )	== static_cast<unsigned short>( std::floor( static_cast<long double>( us_val1 ) * 3.5 ) ),
										"test_mul_3_5 (unsigned short)" );
		TEST( cppbwh::mul_3_5( uc_val1 )	== static_cast<unsigned char>( std::floor( static_cast<long double>( uc_val1 ) * 3.5 ) ),
										"test_mul_3_5 (unsigned char)" );
	}
	std::cout << std::endl;
}
void test_nlpo2() {
	
	size_t val1 = random64();
	val1 |= 0x8000000000000000;
	val1 >>= 2;
	
	unsigned long ul_val1 = val1;
	ul_val1 |= 0x8000000000000000;
	ul_val1 >>= 2;
	unsigned int ui_val1 = val1;
	ui_val1 |= 0x80000000;
	ui_val1 >>= 2;
	unsigned short us_val1 = val1;
	us_val1 |= 0x8000;
	us_val1 >>= 2;
	unsigned char uc_val1 = val1;
	uc_val1 |= 0x80;
	uc_val1 >>= 2;
	
	TEST( cppbwh::nlpo2( val1 )		== 0x4000000000000000,
									"nlpo2 (size_t)" );
	TEST( cppbwh::nlpo2( ul_val1 )	== 0x4000000000000000,
									"nlpo2 (unsigned long)" );
	TEST( cppbwh::nlpo2( ui_val1 )	== 0x40000000,
									"nlpo2 (unsigned int)" );
	TEST( cppbwh::nlpo2( us_val1 )	== 0x4000,
									"nlpo2 (unsigned short)" );
	TEST( cppbwh::nlpo2( uc_val1 )	== 0x40,
									"nlpo2 (unsigned char)" );
	std::cout << std::endl;
}
void test_msb() {
	
	size_t val1 = random64();
	val1 |= 0x8000000000000000;
	val1 >>= 5;
	
	unsigned long ul_val1 = val1;
	unsigned int ui_val1 = val1;
	ui_val1 |= 0x80000000;
	ui_val1 >>= 5;
	unsigned short us_val1 = val1;
	us_val1 |= 0x8000;
	us_val1 >>= 5;
	unsigned char uc_val1 = val1;
	uc_val1 |= 0x80;
	uc_val1 >>= 5;
	
	TEST( cppbwh::msb( val1 ) == 0x8000000000000000 >> 5,
									"msb (size_t)" );
	TEST( cppbwh::msb( ul_val1 ) == 0x8000000000000000 >> 5,
									"msb (unsigned long)" );
	TEST( cppbwh::msb( ui_val1 ) == 0x80000000 >> 5,
									"msb (unsigned int)" );
	TEST( cppbwh::msb( us_val1 ) == 0x8000 >> 5,
									"msb (unsigned short)" );
	TEST( cppbwh::msb( uc_val1 ) == 0x80 >> 5,
									"msb (unsigned char)" );
	
	std::cout << std::endl;
}
void test_rotate_left() {
	
	size_t val1 = 1UL << 6;
	
	unsigned long ul_val1 = val1;
	unsigned int ui_val1 = val1;
	unsigned short us_val1 = val1;
	unsigned char uc_val1 = val1;
	
	std::cout << static_cast<unsigned int>( cppbwh::rotate_left( uc_val1,  7 ) ) << std::endl;
	TEST( cppbwh::rotate_left( val1,  7 )		== 1UL << 13, "rotate_left (size_t)" );
	TEST( cppbwh::rotate_left( ul_val1,  7 )	== 1UL << 13, "rotate_left (unsigned long)" );
	TEST( cppbwh::rotate_left( ui_val1,  7 )	== 1UL << 13, "rotate_left (unsigned int)" );
	TEST( cppbwh::rotate_left( us_val1,  7 )	== 1UL << 13, "rotate_left (unsigned short)" );
	TEST( cppbwh::rotate_left( uc_val1,  7 )	== 1UL << 5, "rotate_left (unsigned char)" );
	
	val1 = 0b01010101'01010101'01010101'01010101'01010101'01010101'01010101'01100110;
	
	ul_val1 = val1;
	ui_val1 = val1;
	us_val1 = val1;
	uc_val1 = val1;
	
	std::cout << static_cast<unsigned int>( cppbwh::rotate_left( uc_val1,  7 ) ) << std::endl;
	TEST( cppbwh::rotate_left( val1,  7 )		== 0b1'01010101'01010101'01010101'01010101'01010101'01010101'01100110'0101010, "rotate_left (size_t)" );
	TEST( cppbwh::rotate_left( ul_val1,  7 )	== 0b1'01010101'01010101'01010101'01010101'01010101'01010101'01100110'0101010, "rotate_left (unsigned long)" );
	TEST( cppbwh::rotate_left( ui_val1,  7 )	== 0b1'01010101'01010101'01100110'0101010, "rotate_left (unsigned int)" );
	TEST( cppbwh::rotate_left( us_val1,  7 )	== 0b1'01100110'0101010, "rotate_left (unsigned short)" );
	TEST( cppbwh::rotate_left( uc_val1,  7 )	== 0b00110011, "rotate_left (unsigned char)" );
	
	std::cout << std::endl;
}
void test_rotate_right() {
	
	size_t val1 = 1UL << 7;
	
	unsigned long ul_val1 = val1;
	unsigned int ui_val1 = val1;
	unsigned short us_val1 = val1;
	unsigned char uc_val1 = val1;
	
	std::cout << static_cast<unsigned int>( cppbwh::rotate_right( uc_val1,  5 ) ) << std::endl;
	TEST( cppbwh::rotate_right( val1,  5 )		== 1UL << 2, "rotate_right (size_t)" );
	TEST( cppbwh::rotate_right( ul_val1,  5 )	== 1UL << 2, "rotate_right (unsigned long)" );
	TEST( cppbwh::rotate_right( ui_val1,  5 )	== 1UL << 2, "rotate_right (unsigned int)" );
	TEST( cppbwh::rotate_right( us_val1,  5 )	== 1UL << 2, "rotate_right (unsigned short)" );
	TEST( cppbwh::rotate_right( uc_val1,  5 )	== 1UL << 2, "rotate_right (unsigned char)" );
	
	val1 = 0b01010101'01010101'01010101'01010101'01010101'01010101'01010101'01100110;
	
	ul_val1 = val1;
	ui_val1 = val1;
	us_val1 = val1;
	uc_val1 = val1;
	
	std::cout << static_cast<unsigned int>( cppbwh::rotate_right( uc_val1,  7 ) ) << std::endl;
	TEST( cppbwh::rotate_right( val1,  7 )		== 0b1100110'01010101'01010101'01010101'01010101'01010101'01010101'01010101'0, "rotate_right (size_t)" );
	TEST( cppbwh::rotate_right( ul_val1,  7 )	== 0b1100110'01010101'01010101'01010101'01010101'01010101'01010101'01010101'0, "rotate_right (unsigned long)" );
	TEST( cppbwh::rotate_right( ui_val1,  7 )	== 0b1100110'01010101'01010101'01010101'0, "rotate_right (unsigned int)" );
	TEST( cppbwh::rotate_right( us_val1,  7 )	== 0b1100110'01010101'0, "rotate_right (unsigned short)" );
	TEST( cppbwh::rotate_right( uc_val1,  7 )	== 0b11001100, "rotate_right (unsigned char)" );
	
	std::cout << std::endl;
}
void test_hex_unhex() {
	
	size_t val1 = random64();
	size_t val2 = 0;
	char buff1_[17]{0};
	char buff2_[9]{0};
	
	unsigned long ul_val1 = val1;
	unsigned long ul_val2 = 0;
	unsigned int ui_val1 = val1;
	unsigned int ui_val2 = 0;
	unsigned short us_val1 = val1;
	unsigned short us_val2 = 0;
	unsigned char uc_val1 = val1;
	unsigned char uc_val2 = 0;
	
	
	memset( buff1_, 0, sizeof( buff1_ ) );
	memset( buff2_, 0, sizeof( buff2_ ) );
	const char str1_[] = "Test";
	const char str2_[] = "Test!";
	cppbwh::hex( str1_, strlen( str1_ ), buff1_ );
	cppbwh::unhex( buff1_, strlen( buff1_ ), buff2_ );
	TEST( strcmp( buff2_, str1_ ) == 0,
									"test_hex_unhex (str1_)" );
	
	memset( buff1_, 0, sizeof( buff1_ ) );
	memset( buff2_, 0, sizeof( buff2_ ) );
	cppbwh::hex( str2_, strlen( str2_ ), buff1_ );
	cppbwh::unhex( buff1_, strlen( buff1_ ), buff2_ );
	TEST( strcmp( buff2_, str2_ ) == 0,
									"test_hex_unhex (str2_)" );
	
	memset( buff1_, 0, sizeof( buff1_ ) );
	memset( buff2_, 0, sizeof( buff2_ ) );
	cppbwh::hex( val1, buff1_ );
	cppbwh::unhex( buff1_, val2 );
	TEST( val1 == val2, "test_hex_unhex (size_t)" );
	
	memset( buff1_, 0, sizeof( buff1_ ) );
	memset( buff2_, 0, sizeof( buff2_ ) );
	cppbwh::hex( ul_val1, buff1_ );
	cppbwh::unhex( buff1_, ul_val2 );
	TEST( ul_val1 == ul_val2, "test_hex_unhex (unsigned long)" );
	
	memset( buff1_, 0, sizeof( buff1_ ) );
	memset( buff2_, 0, sizeof( buff2_ ) );
	cppbwh::hex( ui_val1, buff1_ );
	cppbwh::unhex( buff1_, ui_val2 );
	TEST( ui_val1 == ui_val2, "test_hex_unhex (unsigned int)" );
	
	memset( buff1_, 0, sizeof( buff1_ ) );
	memset( buff2_, 0, sizeof( buff2_ ) );
	cppbwh::hex( us_val1, buff1_ );
	cppbwh::unhex( buff1_, us_val2 );
	TEST( us_val1 == us_val2, "test_hex_unhex (unsigned short)" );
	
	memset( buff1_, 0, sizeof( buff1_ ) );
	memset( buff2_, 0, sizeof( buff2_ ) );
	cppbwh::hex( uc_val1, buff1_ );
	cppbwh::unhex( buff1_, uc_val2 );
	TEST( uc_val1 == uc_val2, "test_hex_unhex (unsigned char)" );
	
	
	
	
	std::string out_;
	memset( buff1_, 0, sizeof( buff1_ ) );
	cppbwh::hex( str1_, strlen( str1_ ), out_ );
	cppbwh::unhex( out_.c_str(), out_.size(), buff2_ );
	TEST( strcmp( buff2_, str1_ ) == 0,
									"test_hex_unhex (str1_)" );
	
	out_.clear();
	memset( buff1_, 0, sizeof( buff1_ ) );
	cppbwh::hex( str2_, strlen( str2_ ), out_ );
	cppbwh::unhex( out_.c_str(), out_.size(), buff2_ );
	TEST( strcmp( buff2_, str2_ ) == 0,
									"test_hex_unhex (str2_)" );
	
	out_.clear();
	memset( buff1_, 0, sizeof( buff1_ ) );
	cppbwh::hex( val1, out_ );
	cppbwh::unhex( out_.c_str(), val2 );
	TEST( val1 == val2, "test_hex_unhex (size_t)" );
	
	out_.clear();
	memset( buff1_, 0, sizeof( buff1_ ) );
	cppbwh::hex( ul_val1, out_ );
	cppbwh::unhex( out_.c_str(), ul_val2 );
	TEST( ul_val1 == ul_val2, "test_hex_unhex (unsigned long)" );
	
	out_.clear();
	memset( buff1_, 0, sizeof( buff1_ ) );
	cppbwh::hex( ui_val1, out_ );
	cppbwh::unhex( out_.c_str(), ui_val2 );
	TEST( ui_val1 == ui_val2, "test_hex_unhex (unsigned int)" );
	
	out_.clear();
	memset( buff1_, 0, sizeof( buff1_ ) );
	cppbwh::hex( us_val1, out_ );
	cppbwh::unhex( out_.c_str(), us_val2 );
	TEST( us_val1 == us_val2, "test_hex_unhex (unsigned short)" );
	
	out_.clear();
	memset( buff1_, 0, sizeof( buff1_ ) );
	cppbwh::hex( uc_val1, out_ );
	cppbwh::unhex( out_.c_str(), uc_val2 );
	TEST( uc_val1 == uc_val2, "test_hex_unhex (unsigned char)" );
	
	
	
	std::cout << std::endl;
}
void test_bit_set_clear_check() {
	size_t val1 = 0;
	
	unsigned long ul_val1 = val1;
	unsigned int ui_val1 = val1;
	unsigned short us_val1 = val1;
	unsigned char uc_val1 = val1;
	
	size_t bpos_ = 0;
	for( unsigned int i = 0; i < 10; ++i ) {
		bpos_ = random64() % ( sizeof( size_t ) * 8 );
		cppbwh::setbit( val1, bpos_ );
		TEST( cppbwh::checkbit( val1, bpos_ ), "set and check bit (size_t)" );
		cppbwh::clearbit( val1, bpos_ );
		TEST( !cppbwh::checkbit( val1, bpos_ ), "clear and check bit (size_t)" );
		
		bpos_ = random64() % ( sizeof( unsigned long ) * 8 );
		cppbwh::setbit( ul_val1, bpos_ );
		TEST( cppbwh::checkbit( ul_val1, bpos_ ), "set and check bit (unsigned long)" );
		cppbwh::clearbit( ul_val1, bpos_ );
		TEST( !cppbwh::checkbit( ul_val1, bpos_ ), "clear and check bit (unsigned long)" );
		
		bpos_ = random64() % ( sizeof( unsigned int ) * 8 );
		cppbwh::setbit( ui_val1, bpos_ );
		TEST( cppbwh::checkbit( ui_val1, bpos_ ), "set and check bit (unsigned int)" );
		cppbwh::clearbit( ui_val1, bpos_ );
		TEST( !cppbwh::checkbit( ui_val1, bpos_ ), "clear and check bit (unsigned int)" );
		
		bpos_ = random64() % ( sizeof( unsigned short ) * 8 );
		cppbwh::setbit( us_val1, bpos_ );
		TEST( cppbwh::checkbit( us_val1, bpos_ ), "set and check bit (unsigned short)" );
		cppbwh::clearbit( us_val1, bpos_ );
		TEST( !cppbwh::checkbit( us_val1, bpos_ ), "clear and check bit (unsigned short)" );
		
		bpos_ = random64() % ( sizeof( unsigned char ) * 8 );
		cppbwh::setbit( uc_val1, bpos_ );
		TEST( cppbwh::checkbit( uc_val1, bpos_ ), "set and check bit (unsigned char)" );
		cppbwh::clearbit( uc_val1, bpos_ );
		TEST( !cppbwh::checkbit( uc_val1, bpos_ ), "clear and check bit (unsigned char)" );
	}
	
	val1 = 0b00100010'00100100'10010000'0010000'00100100'00100001'00010000'01000000;
	size_t val2 = 0b00100010'00100100'10010000'0010000'00100100'00100001'00010000'01000000;
	
	ul_val1 = val1;
	unsigned long ul_val2 = val1;
	ui_val1 = val1;
	unsigned int ui_val2 = val1;
	us_val1 = val1;
	unsigned short us_val2 = val1;
	uc_val1 = val1;
	unsigned char uc_val2 = val1;
	
	cppbwh::setbit( val1, 62 );
	TEST( cppbwh::checkbit( val1, 62 ), "set and check bit (size_t)" );
	cppbwh::clearbit( val1, 62 );
	TEST( val1 == val2, "clear and check bit (size_t)" );
	
	cppbwh::setbit( ul_val1, 59 );
	TEST( cppbwh::checkbit( ul_val1, 59 ), "set and check bit (unsigned long)" );
	cppbwh::clearbit( ul_val1, 59 );
	TEST( ul_val1 == ul_val2, "clear and check bit (unsigned long)" );
	
	cppbwh::setbit( ui_val1, 30 );
	TEST( cppbwh::checkbit( ui_val1, 30 ), "set and check bit (unsigned int)" );
	cppbwh::clearbit( ui_val1, 30 );
	TEST( ui_val1 == ui_val2, "clear and check bit (unsigned int)" );
	
	cppbwh::setbit( us_val1, 13 );
	TEST( cppbwh::checkbit( us_val1, 13 ), "set and check bit (unsigned short)" );
	cppbwh::clearbit( us_val1, 13 );
	TEST( us_val1 == us_val2, "clear and check bit (unsigned short)" );
	
	cppbwh::setbit( uc_val1, 4 );
	TEST( cppbwh::checkbit( uc_val1, 4 ), "set and check bit (unsigned char)" );
	cppbwh::clearbit( uc_val1, 4 );
	TEST( uc_val1 == uc_val2, "clear and check bit (unsigned char)" );
	
	
}

int main() {
	std::chrono::high_resolution_clock::time_point d_ =
						std::chrono::high_resolution_clock::now();
	unsigned seed_ = d_.time_since_epoch().count();
	random64.seed( seed_ );
	
	test_xorswap();
	test_bit_reverse();
	test_lsb();
	test_tobin();
	test_swapn();
	test_floor_log2();
	test_mul_3_5();
	test_nlpo2();
	test_msb();
	test_rotate_left();
	test_rotate_right();
	test_hex_unhex();
	test_bit_set_clear_check();
	
	return( EXIT_SUCCESS );
}

