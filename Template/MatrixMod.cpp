struct matrix {
    // Matrix with every element in range [0, MOD)
    // DEFINE MOD!
    public:
    matrix(int sz): nums(vector<vector<int>>(sz, vector<int>(sz))) {}
    matrix(int x, int y): nums(vector<vector<int>>(x, vector<int>(y))) {}
    static matrix identity(int sz) {
        matrix ret(sz);
        for (int i = 0; i < sz; i++) ret.nums[i][i] = 1;
        return ret;
    }

    vector<vector<int>> nums;

    vector<int> sz() const {
        return vector<int> {(int)nums.size(), nums.size() ? (int)nums[0].size() : 0LL};
    }
    matrix operator*(const matrix &o) const {
        if (sz()[1] != o.sz()[0]) {
            throw invalid_argument("Matrix cannot be multiplied: size mismatch");
        }
        matrix ret(sz()[0], o.sz()[1]);
        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = 0; j < (int)o.nums[0].size(); j++) {
                for (int k = 0; k < (int)o.nums.size(); k++) {
                    ret.nums[i][j] += nums[i][k] * o.nums[k][j];
                    ret.nums[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    matrix operator+(const matrix &o) const {
        if (sz()[0] != o.sz()[0]) {
            throw invalid_argument("Matrix cannot be added: size mismatch at first index");
        }
        if (sz()[1] != o.sz()[1]) {
            throw invalid_argument("Matrix cannot be added: size mismatch at second index");
        }
        matrix ret(sz()[0], sz()[1]);
        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = 0; j < (int)nums[0].size(); j++) {
                ret.nums[i][j] = (nums[i][j] + o.nums[i][j]) % MOD;
            }
        }
        return ret;
    }
    matrix operator-() const {
        matrix ret(sz()[0], sz()[1]);
        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = 0; j < (int)nums[0].size(); j++) {
                ret.nums[i][j] = (MOD - nums[i][j]) % MOD;
            }
        }
        return ret;
    }
    matrix pow(int exp) const {
        if (!exp) return matrix::identity(sz()[0]);
        matrix ret = pow(exp/2);
        ret = ret * ret;
        if (exp%2) ret = ret * (*this);
        return ret;
    }

};