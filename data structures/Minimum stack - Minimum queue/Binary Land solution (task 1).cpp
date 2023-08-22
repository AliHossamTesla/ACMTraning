// Problem: Binary Land
// Contest: CodeChef - MAY20A
// URL: https://www.codechef.com/MAY20A/problems/BINLAND
// written by : Tesla
// in 5:49pm 22/8/2023
// The blessings of God to the Prophet Muhammad
#include <bits/stdc++.h>
using namespace std ;
vector<vector<vector<int>>>dp ;
const int MOD = 1e9 + 7 ;
class Matrix{
public:
	void add(string newValue){
		if(Q.empty()){
			current_size ++ ;
			for(int i = 1 ; i <= N ; i ++) {
				for(int j = 1 ; j <= N ; j ++) {
					if(i == j)
						dp[current_size][i][j] = 1 ;
					else
						dp[current_size][i][j] = 0 ;
				}
			}
		}else{
			current_size ++ ;
			for(int i = 1 ; i <= N ; i ++) {
				for(int j = 1 ; j <= N ; j ++){
					for(int dx = -1 ; dx < 2 ; dx ++){
						if(i + dx > N or i + dx <= 0)
							continue ;
						if(top[i + dx - 1] == newValue[i - 1])
							dp[current_size][j][i] = addMod(dp[current_size - 1][j][i + dx],dp[current_size][j][i]) ;
					}
				}
			}
		}
		Q.push(newValue) ;
		top = newValue ;
	}
	Matrix(int N,int Q){
		this->N = N ;
		this->Qu = Q ;
	}
	void remove(){
		if(current_size == 1){
			dp = vector<vector<vector<int>>>(Qu + 5,vector<vector<int>>(N+5,vector<int>(N+5))) ;
			current_size -- ;
			Q.pop() ;
		}else{
			for(int i = current_size ; i > 0 ; i --){
				for(int j = 1 ; j <= N ; j ++)
					for(int k = 1 ; k <= N ; k ++)
						dp[i][j][k] = 0 ;
			}
			Q.pop() ;
			current_size = 1 ;
			queue<string>tmp ;
			top = Q.front() ; Q.pop() ;
			tmp.push(top) ;
			for(int i = 1 ; i <= N ; i ++) {
				for(int j = 1 ; j <= N ; j ++) {
					if(i == j)
						dp[current_size][i][j] = 1 ;
					else
						dp[current_size][i][j] = 0 ;
				}
			}
			while(!Q.empty()){
				string newValue = Q.front() ; Q.pop() ;
				current_size ++ ;
				for(int i = 1 ; i <= N ; i ++) {
					for(int j = 1 ; j <= N ; j ++){
						for(int dx = -1 ; dx < 2 ; dx ++){
							if(i + dx > N or i + dx <= 0)
								continue ;
							if(top[i + dx - 1] == newValue[i - 1])
								dp[current_size][j][i] = addMod(dp[current_size - 1][j][i + dx],dp[current_size][j][i]) ;
						}
					}
				}
				top = newValue ;
				tmp.push(top) ;
			}
			Q = tmp ;
		}
	}
	int sz(){
		return current_size ;
	}
	vector<string> getMatrix(){
		vector<string>matrix ;
		queue<string>tmp = Q ;
		while(!tmp.empty()){
			matrix.push_back(tmp.front()) ;
			tmp.pop() ;
		}
		return matrix ;
	}
private:
	queue<string>Q ;
	int N ;
	int Qu ;
	int start = 1 , end = 1, axis = 1;
	int current_size = 0 ;
	string top ;
	int addMod(int x,int y){
		return ((x % MOD) + (y % MOD)) % MOD;
	}
};
int main() {
	int N , Q ;
	cin >> N >> Q ;
	Matrix Ma = Matrix(N,Q) ;
	dp = vector<vector<vector<int>>>(Q + 5,vector<vector<int>>(N+5,vector<int>(N+5))) ;
	while(Q--){
		string selector ;
		cin >> selector ;
		if(selector == "add"){
			string newValue ;
			cin >> newValue ;
			Ma.add(newValue) ;
		}else if(selector == "remove"){
			Ma.remove() ;
		}else{
			int coordinate1 , coordinate2 ;
			cin >> coordinate1 >> coordinate2 ;
			cout << dp[Ma.sz()][coordinate1][coordinate2] << endl ;
		}
	}
	return 0;
}
