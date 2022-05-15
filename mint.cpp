template<int mod> class mint{
	unsigned int x = 0;
public:
    int get_modular(){return mod;}
	mint inv()const{return pow(mod-2);}
	mint pow(long long t)const{
		assert(t >= 0 && x > 0);
		mint res = 1, cur = x;
		for(; t; t>>=1)
		{
			if(t & 1) res *= cur;
			cur *= cur;
		}
		return res;
	}
	mint() = default;
	mint(unsigned int t): x(t){}
	mint(int t){t%=mod; if(t < 0) t+= mod; x = t;}
	mint(long long t){t%=mod; if(t < 0) t+= mod; x = t;}
	explicit operator int(){return x;}
	
	mint& operator+= (const mint& t){x += t.x; if(x >= mod) x-=mod; return *this; }
	mint& operator-= (const mint& t){x += mod - t.x; if(x >= mod) x-=mod; return *this; }
	mint& operator*= (const mint& t){x = (unsigned long long)x * t.x % mod; return *this;}
	mint& operator/= (const mint& t){*this *= t.inv(); return *this;}
	mint& operator^= (const mint& t){*this = this->pow(t.x); return *this;}
	mint operator+ (const mint& t){return mint(*this) += t;}
	mint operator- (const mint& t){return mint(*this) -= t;}
	mint operator* (const mint& t){return mint(*this) *= t;}
	mint operator/ (const mint& t){return mint(*this) /= t;}
	mint operator^ (const mint& t){return mint(*this) ^= t;}
	bool operator== (const mint& t){return x == t.x;}
	bool operator!= (const mint& t){return x != t.x;}
	bool operator< (const mint& t){return x < t.x;} 
	bool operator<= (const mint& t){return x <= t.x;}
	bool operator> (const mint& t){return x > t.x;}
	bool operator>= (const mint& t){return x >= t.x;}
	friend istream& operator>>(istream& is, mint& t){return is >> t.x;}
	friend ostream& operator<<(ostream& os, const mint& t){return os << t.x;}
	friend mint operator+ (int y, const mint& t){return mint(y)+t.x;}
	friend mint operator- (int y, const mint& t){return mint(y)-t.x;}
	friend mint operator* (int y, const mint& t){return mint(y)*t.x;}
	friend mint operator/ (int y, const mint& t){return mint(y)/t.x;}
};

const int mod = 998244353;
using Mint = mint<mod>;
