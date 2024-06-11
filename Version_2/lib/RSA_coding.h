#ifndef _RSA_CODING_H
#define _RSA_CODING_H

#include<vector>
#include<string>
#include<iostream>
#include<time.h>

#define ll long long

std::vector<ll> prime_number_table = {
        457, 461, 463,467, 479, 487, 491, 499, 503, 509, 
        521, 523, 541, 547, 557, 563, 569, 571, 577, 587,
        593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
        647, 653, 659, 661, 673, 677, 683, 691, 701, 709,
        719, 727, 733, 739, 743, 751, 757, 761, 769, 
        773, 787, 797, 809, 811, 821, 823, 827, 829,
        839, 853, 857, 859, 863, 877, 881, 883, 887, 
        907, 911, 919, 929, 937, 941, 947, 953, 967,
        971, 977, 983, 991, 997
    };

std::vector<ll> Extend_Euclid(ll a,ll b);

ll random_prime_number();

ll Inverse_Element(ll a,ll mod);

char RSA_coding_decoding(char data,ll mod,ll power);

ll quick_power(ll mod,ll num,ll power);

std::vector<ll> generating_key();


#endif