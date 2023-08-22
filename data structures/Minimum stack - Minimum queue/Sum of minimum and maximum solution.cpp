//  Sum of minimum and maximum elements of all subarrays of size “K” 
// coding ninja : https://www.codingninjas.com/studio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std ;
template <typename T>
class Queue{
private:
	stack<pair<T, pair<T,T>>> s1, s2;
public:
	T minimum (){
		T mn ;
		if (s1.empty() || s2.empty())
			mn = s1.empty() ? s2.top().second.second : s1.top().second.second;
		else
			mn = min(s1.top().second.second, s2.top().second.second);
		return mn ;
	}
	T maximum (){
		T mx ;
		if (s1.empty() || s2.empty())
			mx = s1.empty() ? s2.top().second.first : s1.top().second.first;
		else
			mx = max(s1.top().second.first, s2.top().second.first);
		return mx ;
	}
	void add(T new_element){
		T minimum = s1.empty() ? new_element : min(new_element, s1.top().second.second);
		T maximum = s1.empty() ? new_element : max(new_element, s1.top().second.first) ;
		s1.push({new_element, {maximum,minimum}});
	}
	T remove(){
		if (s2.empty()) {
			while (!s1.empty()) {
				T element = s1.top().first;
				s1.pop();
				T minimum = s2.empty() ? element : min(element, s2.top().second.second);
				T maximum = s2.empty() ? element : max(element, s2.top().second.first);
				s2.push({element, {maximum,minimum}});
			}
		}
		T remove_element = s2.top().first;
		s2.pop();
		return remove_element ;
	}
};
int main(){
	int n , k ;
	cin >> n >> k ;
	vector<int>v(n) ;
	for(int i = 0 ; i < n ; i ++)
		cin >> v[i] ;
	long long sm = 0 ;
	Queue<int>Q ;
	int i ;
	for(i = 0 ; i < k ; i ++)
		Q.add(v[i]) ;
	sm += Q.maximum() + Q.minimum() ;
	for(; i < n ; i ++){
		Q.remove() ;
		Q.add(v[i]) ;
		sm += Q.maximum() + Q.minimum() ;
	}
	cout << sm << endl ;
}
