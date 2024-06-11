#include  "RSA_coding.h"

std::vector<ll> Extend_Euclid(ll a,ll b){
    std::vector<ll> res(3,0);

    if(b==0){
        return {1,0,a};
    }

    std::vector<ll> reduction = Extend_Euclid(b,a%b);
    res[0] = reduction[1];
    res[1] = reduction[0] - (a/b)*reduction[1];
    res[2] = reduction[2];

    return res;
}

ll Inverse_Element(ll a,ll mod){
    std::vector<ll> res = Extend_Euclid(a,mod);
    return res[0];
}

ll quick_power(ll mod,ll num,ll power){
    if(power == 0) return 1;

    ll x = quick_power(mod,num,power/2);

    if(power%2){
        return (num*x*x)%mod;
    }
    else
        return x*x%mod;
}

char RSA_coding_decoding(char data,ll mod,ll power){
    //power is e when coding and d when decoding
    ll a1 = (ll)data;
    ll a2 = quick_power(mod,a1,power);
    return (char)a2;
}

ll random_prime_number(){
    srand((unsigned)time(NULL));
    int size = prime_number_table.size();
    ll index = rand()%size;
    return prime_number_table[index];
}

std::vector<ll> generating_key(){
    ll p1 = random_prime_number();
    ll p2 = random_prime_number();
    ll e = random_prime_number();
    while(p1==p2){
        p2 = random_prime_number();
    }

    while(e==p1||e==p2){
        e = random_prime_number();
    }

    ll N = p1*p2;
    ll mod = (p1-1)*(p2-1);
    ll d = Inverse_Element(e,mod);
    return {e,d,N};
}