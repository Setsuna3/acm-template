template<class mint = Mint> class Factorials{
	vector<mint> v;
public:
	void init(int n)
	{
		v.resize(n+1);
		v[0] = 1;
		for(int i=1;i<=n;i++) v[i] = v[i-1] * i;
	}
	
	mint operator()(mint x){return operator()((int)x);}
	mint operator()(int x){
		assert(x >= 0);
		if(v.size() > x) return v[x];
		mint res = 1;
		for(int i=1;i<=x;i++) res*=i;
		return res; 
	}
}; Factorials<Mint> Fac;
 
template<class mint = Mint> class Combinatorics{
	vector<vector<mint>> v;
public:
	void init(int n)
	{
		v.resize(n+1);
		for(int i=0;i<=n;i++)
		{
			v[i].resize(n+1);
			v[i][0] = v[i][i] = 1;
			for(int j=1;j<i;j++)
				v[i][j] = v[i-1][j-1] + v[i-1][j];
		}
	}
	
	mint operator()(mint x, mint y){return operator()((int)x, (int)y);}
	mint operator()(int x, int y)
	{
		assert(x >= 0 && y >= 0);
		if(y > x) return 0;
		if(v.size() > x) return v[x][y];
		mint res = 1;
		for(int i=x-y+1; i<=x; i++) res*=i;
		for(int i=2; i<=y; i++) res*=Mint(i).inv();
		return res;
	}
};Combinatorics<Mint> C;
