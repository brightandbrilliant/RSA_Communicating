#ifndef _RSA_CODING_H
#define _RSA_CODING_H

#include<vector>
#include<string>
#include<iostream>
#include<time.h>

#define ll long long

std::vector<ll> Extend_Euclid(ll a,ll b);

ll random_prime_number();

ll Inverse_Element(ll a,ll mod);

char RSA_coding_decoding_char(char data,ll mod,ll power);

void RSA_coding_decoding_string(std::string& message, ll mod, ll power);

ll quick_power(ll mod,ll num,ll power);

std::vector<ll> generating_key();


#endif