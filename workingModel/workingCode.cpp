#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//Constants
#define MOD 1000000007
const long long int INF = 1e9;
const double pi = 3.141592653589793238;

//Aliases
typedef long long lli;
#define vr(v) v.begin(),v.end()
#define rv(v) v.end(),v.begin()
#define in insert
#define fi(i,a,n) for(lli i=a;i<n;i++)
#define fir(i,a,n) for(lli i=n-1;i>=a;i--)
#define vl vector<lli>
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second
#define bg begin()
#define ed end()
#define mp(x, y) make_pair(x, y)
#define mt make_tuple
#define min3(x1, x2, x3) (x3 > min(x1, x2) ? min(x2, x1) : x3)
#define max3(x1, x2, x3) (x3 < max(x1, x2) ? max(x1, x2) : x3)
using ull = unsigned long long;
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define ARRAYSIZE(a) (sizeof(a)) / (sizeof(a[0]))
typedef long double ld;

// Mathematical Functions
lli gcd(lli a, lli b) {if (b == 0)return a; return gcd(b, a % b);} //__gcd
lli lcm(lli a, lli b) {return (a / gcd(a, b) * b);}
lli moduloMultiplication(lli a, lli b, lli mod) {lli rea = 0; a %= mod; while (b) {if (b & 1)rea = (rea + a) % mod; b >>= 1;} return rea;}
lli powermod(lli x, lli y, lli p) {lli rea = 1; x = x % p; if (x == 0) return 0; while (y > 0) {if (y & 1)rea = (rea * x) % p; y = y >> 1; x = (x * x) % p;} return rea;}
lli mpow(lli x, lli y)//Returna (x^y)%MOD
{
  lli res = 1;

  while (y > 0)
  {
    if (y % 2 == 1)
    {
      res = (res * x) % MOD;
    }
    y = y / 2;
    x = (x * x) % MOD;
  }
  return (lli)res;
}
lli mask(lli i) {
  return (lli(1) << i) - 1;
}

bool inc(lli a, lli b, lli c) {
  return a <= b && b <= c;
}

/*Graph-dfs
bool gone[MN];
vector<lli> adj[MN];
void dfs(lli loc) { gone[loc] = true; for (auto x : adj[loc])if (!gone[x])dfs(x);}
*/

//Sorting
bool sorta(const pair<lli, lli> &a, const pair<lli, lli> &b) {return (a.second < b.second);}
bool sortd(const pair<lli, lli> &a, const pair<lli, lli> &b) {return (a.second > b.second);}

//Bits
string decToBinary(lli n) {string a = ""; lli i = 0; while (n > 0) {a = to_string(n % 2) + a; n = n / 2; i++;} return a;}
lli binaryToDecimal(string n) {string num = n; lli dec_value = 0; lli baae = 1; lli len = num.length(); for (lli i = len - 1; i >= 0; i--) {if (num[i] == '1')dec_value += baae; baae = baae * 2;} return dec_value;}
lli topbit(signed t) {
  return t == 0 ? -1 : 31 - __builtin_clz(t);
}
lli topbit(lli t) {
  return t == 0 ? -1 : 63 - __builtin_clzll(t);
}
lli botbit(signed a) {
  return a == 0 ? 32 : __builtin_ctz(a);
}
lli botbit(lli a) {
  return a == 0 ? 64 : __builtin_ctzll(a);
}
lli popcount(signed t) {
  return __builtin_popcount(t);
}
lli popcount(lli t) {
  return __builtin_popcountll(t);
}

//Check
bool isPrime(lli n) {if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (lli i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false; return true;}
bool isPowerOfTwo(lli n) {if (n == 0)return false; return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(lli x) {if (x >= 0) {lli ar = sqrt(x); return (ar * ar == x);} return false;}


//Fenwick Tree/BIT : vay and BIT both are of aize n+1, vay elements are cin ned from 1 to n, update while cin , query after cin :
void update(lli index, lli value, lli* BIT, lli n) {

  for (; index <= n; index += index & (-index)) {
    BIT[index] += value;
  }
}
lli query(lli index, lli* BIT) {
  lli sum = 0;
  for (; index > 0; index -= index & (-index)) {
    sum += BIT[index];
  }
  return sum;
}

//Prefix & Suffix
lli sumvec(vl &v) {lli n = v.size(); lli s = 0; fi(i, 0, n)s += v[i]; return s;}
vl prs(vl &v) {lli n = v.size(); vl hj; if (!n) return hj; vl out(n); out[0] = v[0]; fi(i, 1, n) out[i] = out[i - 1] + v[i]; return out;}
vl sfs(vl &v) {lli n = v.size(); vl hj; if (!n) return hj; vl out(n); out[n - 1] = v[n - 1]; fir(i, 0, n - 1) out[i] = out[i + 1] + v[i]; return out;}
vl pfmax(vl &v) {lli n = v.size(); vl hj; if (!n) return hj; vl out(n); out[0] = v[0]; fi(i, 1, n) out[i] = max(out[i - 1], v[i]); return out;}
vl sfmax(vl &v) {lli n = v.size(); vl hj; if (!n) return hj; vl out(n); out[n - 1] = v[n - 1]; fir(i, 0, n - 1) out[i] = max(out[i + 1], v[i]); return out;}
vl pfmin(vl &v) {lli n = v.size(); vl hj; if (!n) return hj; vl out(n); out[0] = v[0]; fi(i, 1, n) out[i] = min(out[i - 1], v[i]); return out;}
vl sfmin(vl &v) {lli n = v.size(); vl hj; if (!n) return hj; vl out(n); out[n - 1] = v[n - 1]; fir(i, 0, n - 1) out[i] = min(out[i + 1], v[i]); return out;}


//Print
void pv(vl &v) {fi(i, 0, v.size())cout << v[i] << " "; cout << endl;}
void prv(vl &v) {fir(i, 0, v.size())cout << v[i] << " "; cout << endl;}
unordered_map<char, vector<lli>> mm1;
unordered_map<char, unsigned char> mmUS;
#define MAX_SIZE 100

class HuffmanTreeNode {
public:
  char data;
  int freq;
  HuffmanTreeNode* left;
  HuffmanTreeNode* right;
  HuffmanTreeNode(char character,
                  int frequency)
  {
    data = character;
    freq = frequency;
    left = right = NULL;
  }
};
class Compare {
public:
  bool operator()(HuffmanTreeNode* a,
                  HuffmanTreeNode* b)
  {
    return a->freq > b->freq;//Defining priority
  }
};

HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq)
{
  while (pq.size() != 1)
  {
    HuffmanTreeNode* left = pq.top();
    pq.pop();
    HuffmanTreeNode* right = pq.top();//least frequency node
    pq.pop();
    HuffmanTreeNode* node = new HuffmanTreeNode('$',
        left->freq + right->freq);
    node->left = left;
    node->right = right;
    pq.push(node);
  }

  return pq.top();
}
unsigned char binary_to_decimal(string& in)
{
  int result = 0;
  for (int i = 0; i < in.size(); i++)
    result = result * 2 + in[i] - '0';
  result = result % 251;//251 is the biggest prime up until 255
  unsigned char pp = result - '0';
  return pp;
}

void printCodes(HuffmanTreeNode* root,
                int arr[], int top)
{
  //0 to left & 1 to right
  if (root->left)
  {
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }

  if (root->right)
  {
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }

  if (!root->left && !root->right) {
    vector<lli> v(top);
    string sv = "";
    for (int i = 0; i < top; i++)
    {
      sv += to_string(arr[i]);
      v[i] = arr[i];
    }
    mm1[root->data] = v;
    unsigned char xy = binary_to_decimal(sv);
    mmUS[root->data] = xy;
  }
}

void HuffmanCodes(char data[], int freq[], int size)
{
  priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq;

  for (int i = 0; i < size; i++)
  {
    HuffmanTreeNode* newNode = new HuffmanTreeNode(data[i], freq[i]);
    pq.push(newNode);
  }

  HuffmanTreeNode* root = generateTree(pq);
  int arr[MAX_SIZE], top = 0;
  printCodes(root, arr, top);
}
vector<int> vmax;
vector<unsigned char> vmUS;
// Driver code
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outAaa3.txt", "w", stdout);
#endif
  /*
  ifstream inputFile;
  inputFile.open("inputFileName.extension");
  ofstream outputFile;
  outputFile.open("outputFileName.extension");
  */
//Press ctrl + C if runtime loop hang, or select cancel build from tools option.

  //cout << "Enter the number of test cases" << endl;

  /* string mmk;
   if (pok % 10 == 1) mmk = "st";
   else if (pok % 10 == 2) mmk = "nd";
   else if (pok % 10 == 3) mmk = "rd";
   else mmk = "th";
   cout << "Enter your " << pok << mmk << " test case/input file which you want to process" << endl;
   */
  string s = "";
  string hbn;
  while (getline(cin, hbn))
  {
    s += hbn;
  }
  unordered_map<char, lli> mp;
  lli n = s.length();
  for (lli i = 0; i < n; i++)
    mp[s[i]]++;

  lli ns = mp.size();
  char arr[ns];
  int freq[ns];
  int i = 0;
  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    arr[i] = it->first;
    freq[i] = it->second;
    i++;
  }
  HuffmanCodes(arr, freq, ns);
  cout << "First way of representing encryption using binary codes: " << endl << endl;
  cout << "Encryption phase: " << endl;
  cout << "Binary code assigned to characters based on their frequencies: " << endl;
  for (auto it = mm1.begin(); it != mm1.end(); it++)
  {
    cout << it->first << " ";
    vector<lli> temp = (it->second);
    lli tsn = temp.size();
    for (lli j = 0 ; j < tsn; j++)
    {
      cout << temp[j] ;
    }
    cout << endl;
  }
  cout << endl;
  cout << "Encrypting the input file text as: " << endl;
  for (lli i = 0; i < n ; i++)
  {
    vector<lli> temp = (mm1[s[i]]);
    lli tsn = temp.size();
    for (lli j = 0 ; j < tsn; j++)
    {
      cout << temp[j] ;
      vmax.pb(temp[j]);
    }
  }
  cout << endl << endl;
  cout << "Decrypting the original text back: " << endl;
  //Getting the original string back from mm1:
  //We cannot use vector as keys with unordered maps, but can do it with maps.
  lli nbs = vmax.size();
  vector<lli> mcur;
  map< vector<lli> , char> mm2;
  for (auto it = mm1.begin(); it != mm1.end(); it++)
    mm2[it->second] = it->first;
  lli sm = 0;
  for (lli i = 0; i < nbs; i++)
  {
    mcur.pb(vmax[i]);
    //copy(vmax.begin()+sm,vmax.begin()+sm+i+1,back_inserter(mcur));
    if (mm2.find(mcur) != mm2.end())
    {
      cout << mm2[mcur];
      mcur.clear();
    }
  }
  cout << endl;
  cout << endl << endl << endl << endl;
  cout << "Second way of representing encryption using unsigned characters: " << endl << endl;
  cout << "Encryption phase: " << endl;
  cout << "Unsigned chars assigned to input characters based on their frequencies: " << endl;
  map<unsigned char, char> mmUS2;
  for (auto it = mmUS.begin(); it != mmUS.end(); it++)
  {
    cout << it->first << " " << it->second << endl;
    mmUS2[it->second] = it->first;
  }
  cout << endl;
  cout << "Encrypting the input file text as: " << endl;
  for (lli i = 0; i < n ; i++)
  {
    cout << mmUS[s[i]];
    vmUS.pb(mmUS[s[i]]);
  }
  cout << endl << endl;
  cout << "Decrypting the original text back: " << endl;
  nbs = vmUS.size();
  for (lli i = 0; i < nbs; i++)
  {
    if (s[i] == ' ')
      cout << s[i];
    else
      cout << mmUS2[vmUS[i]];
  }
  cout << endl;
  return 0;
}
