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
// This constant can be avoided by explicitly
// calculating height of Huffman Tree
unordered_map<char, vector<lli>> mm1;
#define MAX_SIZE 100

class HuffmanTreeNode {
public:
  // Stores character
  char data;

  // Stores frequency of
  // the character
  int freq;

  // Left child of the
  // current node
  HuffmanTreeNode* left;

  // Right child of the
  // current node
  HuffmanTreeNode* right;

  // Initializing the
  // current node
  HuffmanTreeNode(char character,
                  int frequency)
  {
    data = character;
    freq = frequency;
    left = right = NULL;
  }
};

// Custom comparator class
class Compare {
public:
  bool operator()(HuffmanTreeNode* a,
                  HuffmanTreeNode* b)
  {
    // Defining priority on
    // the basis of frequency
    return a->freq > b->freq;
  }
};

// Function to generate Huffman
// Encoding Tree
HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*,
                              vector<HuffmanTreeNode*>,
                              Compare> pq)
{

  // We keep on looping till
  // only one node remains in
  // the Priority Queue
  while (pq.size() != 1) {

    // Node which has least
    // frequency
    HuffmanTreeNode* left = pq.top();

    // Remove node from
    // Priority Queue
    pq.pop();

    // Node which has least
    // frequency
    HuffmanTreeNode* right = pq.top();

    // Remove node from
    // Priority Queue
    pq.pop();

    // A new node is formed
    // with frequency left->freq
    // + right->freq

    // We take data as '$'
    // because we are only
    // concerned with the
    // frequency
    HuffmanTreeNode* node = new HuffmanTreeNode('$',
        left->freq + right->freq);
    node->left = left;
    node->right = right;

    // Push back node
    // created to the
    // Priority Queue
    pq.push(node);
  }

  return pq.top();
}

// Function to print the
// huffman code for each
// character.

// It uses arr to store the codes
void printCodes(HuffmanTreeNode* root,
                int arr[], int top)
{
  // Assign 0 to the left node
  // and recur
  if (root->left) {
    arr[top] = 0;
    printCodes(root->left,
               arr, top + 1);
  }

  // Assign 1 to the right
  // node and recur
  if (root->right) {
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }

  // If this is a leaf node,
  // then we print root->data

  // We also print the code
  // for this character from arr
  if (!root->left && !root->right) {
    vector<lli> v(top);

    //cout << root->data << " ";
    for (int i = 0; i < top; i++) {
      v[i] = arr[i];
    }
    mm1[root->data] = v;
    //cout << endl;
  }
}

void HuffmanCodes(char data[],
                  int freq[], int size)
{

  // Declaring priority queue
  // using custom comparator
  priority_queue<HuffmanTreeNode*,
                 vector<HuffmanTreeNode*>,
                 Compare>
                 pq;

  // Populating the priority
  // queue
  for (int i = 0; i < size; i++) {
    HuffmanTreeNode* newNode
      = new HuffmanTreeNode(data[i], freq[i]);
    pq.push(newNode);
  }

  // Generate Huffman Encoding
  // Tree and get the root node
  HuffmanTreeNode* root = generateTree(pq);

  // Print Huffman Codes
  int arr[MAX_SIZE], top = 0;
  printCodes(root, arr, top);
}
vector<int> vmax;
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
  string s;
  getline(cin, s);
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
  cout << "Encrypting the input file text: " << endl;
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
  cout << endl;
  cout << "Decrypting the original text back: " << endl;
  //Getting the original string back from mm1:
  //Try using bits instead of vector to save more space
  //We cannot use vector as keys with unordered maps, but can do it with maps.
  lli nbs = vmax.size();
  string ans = "";
  string cur = "";
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

  return 0;
}
