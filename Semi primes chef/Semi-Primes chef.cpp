#include <fstream>
#include <algorithm>
#include <bitset>

using namespace std;

ifstream fin("q.in");
ofstream fout("qq.out");

const int DM = 2e2 + 1;

int N,T;
bitset <DM> bs;
int primeList[DM];
int sPrimesList[DM * DM];
int nrPrimes, nrSprimes;
bool yes = true;

void findSprimes(int np) {
    nrSprimes = 0;
    
    for(int i = 1; i <= np; i++)
        for(int j = 1; j <= np; j++)
            if(i != j)
                sPrimesList[++nrSprimes] = primeList[i] * primeList[j];
    
}

void findPrimes(int N) {
    nrPrimes = 0;
    
    for(int i = 2; i <= N; i++)
        if(!bs[i]) {
            primeList[++nrPrimes] = i;
            for(int j = i * 2; j <= N; j += i)
                bs[j] = 1;
            
        }
    
}

bool SP(int x, int lo, int hi) {
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        
        if(sPrimesList[mid] < x)
            lo = mid + 1;
        else
            hi = mid;
    }
    
    if(sPrimesList[lo] == x)
        return true;
    return false;
    
}


int main() {
    fin >> T;
    for(int i = 1; i <= T; i++) {
        fin >> N;
        
        findPrimes(N);
        findSprimes(nrPrimes);
        sort(sPrimesList + 1, sPrimesList + 1 + nrSprimes);
        
        yes = false;
        
        for(int a = 2; a < N; a++) {
            if(SP(a, 1, nrSprimes)) {
                int b = N - a;
                if(SP(b, 1, nrSprimes)) {
                    yes = true;
                    break;
                }
            }
        }
        
        if(yes)
            fout << "YES" << '\n';
        else
            fout << "NO" << '\n';
        
        
    }
}



