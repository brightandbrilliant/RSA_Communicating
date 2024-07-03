#ifndef _RSA_CODING_H
#define _RSA_CODING_H

#include<vector>
#include<string>
#include<iostream>
#include<time.h>

#define ll long long

std::vector<ll> Extend_Euclid(ll a,ll b);

ll random_prime_number();

ll Inverse_Element(ll a,ll mod);//如果逆元是负数将会导致解密错误，必须使用正数逆元才行

ll RSA_coding_decoding_char(char data,ll mod,ll power);

std::string RSA_coding_string(const std::string& message, ll mod, ll power);

std::string RSA_decoding_string(const std::string& message, ll mod, ll power);

ll quick_power(ll mod,ll num,ll power);

std::vector<ll> generating_key();

std::string test_coding(const std::string& message);

std::string test_decoding(const std::string& message);

#endif